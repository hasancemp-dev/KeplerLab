# Lesson 2.07 — `static`, `friend`, `namespace`

**Module 2 — Classes and Object Lifetime**
Project: `Lesson_2_07_StaticFriendNamespace`

Where this sits: 2.04 gave us constructors/destructors, 2.05 the Rule of 3, 2.06 the
Rule of 5 / Rule of 0. All of those are about *one object at a time*. This lesson is
the first time we ask a question that no single object can answer: **"how many of you
are there?"** That question belongs to the class, not to any instance — and that is
exactly what `static` is for.

---

## Task 1 — `static` (implemented)

### 1.1 The problem

Every `Enemy` has its own `name`, `health`, `damage`. Three enemies means three copies
of each of those. Good — those are per-object facts.

But "there are currently 3 enemies alive" is not a fact about `g1`, or about `g2`. It
is a fact about the *class*. If you stored it as a normal member, every enemy would
carry its own private, useless copy of the count.

### 1.2 A static data member

```cpp
class Enemy
{
private:
    static int enemyCount;    // ONE copy, shared by every Enemy that will ever exist
    std::string name;
    int health, damage;
    // ...
};
```

`static int enemyCount;` inside the class is a **declaration**, not a definition. It
says "somewhere, a single `int` called `Enemy::enemyCount` exists." It does not create
it and it does not allocate storage. The class body is a blueprint; it can appear in
dozens of translation units via the header, so it must not create anything.

### 1.3 Defining it — the part everyone forgets

The storage has to be created exactly once, in a `.cpp`:

```cpp
// Enemy.cpp
int Enemy::enemyCount = 0;   // static member — file scope, WITHOUT a class wrapper
```

Three details that trip people up:

- **No `static` keyword here.** It is already static from the declaration. Writing
  `static` again in the `.cpp` would mean something completely different (internal
  linkage — a file-local variable), and you would get a linker error about
  `Enemy::enemyCount` being undefined.
- **The `Enemy::` prefix is mandatory.** Without it you have just declared a plain
  global `int enemyCount`, unrelated to the class, and the linker will tell you so.
- **It lives outside the class braces**, at file scope — even though the member is
  `private`. Access control does not apply to the definition.

If you skip this line entirely, the code compiles fine and then fails at **link**
time: `unresolved external symbol "private: static int Enemy::enemyCount"`. That error
means "you promised me this exists; where is it?" — a linker error, not a compiler
error, and the distinction is the whole lesson.

### 1.4 A static member function

```cpp
static int GetEnemyCount();
```

```cpp
int Enemy::GetEnemyCount()   // again: no 'static' in the definition
{
    return enemyCount;
}
```

A static member function belongs to the class, so:

- It has **no `this` pointer.**
- It therefore **cannot touch `name`, `health`, or `damage`** — those only exist
  inside some particular object, and there is no particular object here.
- It **can** touch `enemyCount`, because that is shared class-level state.
- You call it through the class: `Enemy::GetEnemyCount()`. No instance needed — which
  is the point, since the answer might be zero.

It is still `public` in the normal sense, so it is the legal read-only window onto a
`private` static. Classic encapsulation: the counter is private, the *reading* of it
is public.

### 1.5 Keeping the count honest

The counter is only correct if it is maintained at exactly the two moments an
`Enemy` comes into and goes out of existence:

```cpp
Enemy::Enemy(const std::string& n, int h, int d)
    : name(n), health(h), damage(d)
{
    enemyCount++;   // one more Enemy exists
}

Enemy::~Enemy()
{
    enemyCount--;   // one fewer
}
```

This is the same discipline as the Rule of 3 in 2.05: **whatever the constructor
claims, the destructor must give back.** There it was heap memory, here it is a slot
in a counter. Same shape, different resource.

> ⚠️ Rule-of-3 trap, worth writing down now: the moment you add a copy constructor to
> `Enemy`, you must increment there too. A copy is a *new object* and will run the
> destructor exactly once, decrementing. If the copy constructor forgets to increment,
> the count drifts negative. The compiler-generated copy constructor does **not** run
> your `Enemy(const std::string&, int, int)` body — it copies members one by one and
> never touches `enemyCount`. Right now `Enemy` is copied nowhere, so the code is
> correct; it is a landmine, not a bug.

### 1.6 Proving it works — scope as an experiment

```cpp
void EnemyQuery()
{
    int count = Enemy::GetEnemyCount();   // ask once and keep

    if (count == 1)     { std::cout << "There is only " << count << " enemy"  << std::endl; }
    else if (count > 1) { std::cout << "There are "     << count << " enemies"<< std::endl; }
    else                { std::cout << "There is no enemy"                    << std::endl; }
}

int main()
{
    EnemyQuery();          // 0
    {
        Enemy g1 = { "Goblin", 40, 10 };
        Enemy g2 = { "Goblin", 40, 10 };
        Enemy g3 = { "Goblin", 40, 10 };

        EnemyQuery();      // 3
    }                      // <-- g3, g2, g1 destroyed here, in reverse order
    EnemyQuery();          // 0

    return 0;
}
```

Expected output:

```
There is no enemy
There are 3 enemies
There is no enemy
```

The bare `{ ... }` block is the trick that makes the lesson visible. It is a scope
with no `if` or `for` attached — just a lifetime boundary. At the closing brace the
three locals are destroyed automatically, in **reverse order of construction**
(`g3`, `g2`, `g1`), each destructor firing `enemyCount--`. Nothing in `main` says
"clean up"; the language does it. Returning to 0 is the proof that construction and
destruction are balanced.

Note `EnemyQuery` asks **once** and stores the result. Calling `GetEnemyCount()`
separately in each branch would be three calls that could, in principle, disagree —
and it makes the printed number and the tested number two different reads. Ask once,
decide, print.

Note also `Enemy g1 = { "Goblin", 40, 10 };` — copy-list-initialization. The braces
pick the 3-argument constructor. It reads like aggregate initialization from 2.01, but
it is not: `Enemy` has private members and a user-declared constructor, so this is an
ordinary constructor call.

### 1.7 C++17: `inline static`

Modern C++ lets you skip the separate `.cpp` definition:

```cpp
class Enemy
{
    inline static int enemyCount = 0;   // declared AND defined, header only
};
```

`inline` here means "this may appear in many translation units; linker, keep one." Use
it when you want header-only classes. The two-step version in `Enemy.cpp` is the
classic form and the one you must be able to read, so we are keeping it — but know
that this shortcut exists.

### 1.8 The three unrelated meanings of `static`

`static` is one of the most overloaded keywords in the language. These are genuinely
different features:

| Context | Meaning |
|---|---|
| Class member | Shared by all instances; belongs to the class |
| Local variable in a function | Initialized once, survives across calls |
| Global / free function at file scope | Internal linkage — invisible to other `.cpp` files |

Only the first is this lesson. Do not let the shared spelling convince you they are
related.

---

## Task 2 — `friend` (pending)

### 2.1 The problem

`private` is airtight, which is normally what you want. But occasionally a function
that is *not* a member genuinely needs the internals. The canonical case is
`operator<<`: it must be a free function, because the left operand is the stream, not
your class — you write `std::cout << enemy`, so `std::cout` would have to be the
object whose member is called, and you cannot add members to `std::ostream`.

### 2.2 Syntax

```cpp
class Enemy
{
private:
    static int enemyCount;
    std::string name;
    int health, damage;

public:
    Enemy(const std::string& n, int h, int d);
    ~Enemy();
    static int GetEnemyCount();

    friend void DebugPrint(const Enemy& e);            // free function
    friend std::ostream& operator<<(std::ostream& os, const Enemy& e);
};
```

```cpp
void DebugPrint(const Enemy& e)
{
    // reaches straight into privates — legal only because of the friend declaration
    std::cout << e.name << " hp:" << e.health << " dmg:" << e.damage << '\n';
}
```

### 2.3 What `friend` actually is

- It is a **grant of access**, not a member. `DebugPrint` is a plain free function;
  it is called as `DebugPrint(g1)`, never `g1.DebugPrint()`. It has no `this`.
- The declaration can sit in `private:`, `public:`, or `protected:` — the section
  makes **no difference**. Friendship is not a member, so access specifiers do not
  apply to it. Put it wherever it reads best (usually `public:`, or right next to the
  members it uses).
- **The class grants friendship; the friend cannot claim it.** Only `Enemy` can decide
  who sees `Enemy`'s internals. This is why `friend` does not actually break
  encapsulation — the class is still the sole authority on its own access list.
- Friendship is **not symmetric** (a friend of `Enemy` does not make `Enemy` a friend
  of anything), **not transitive** (your friend's friend is a stranger), and **not
  inherited** (a class derived from `Enemy` does not inherit `Enemy`'s friends).

### 2.4 Friend classes

```cpp
class Enemy
{
    friend class Spawner;   // Spawner may touch every private member of Enemy
};
```

Use sparingly — this is a much bigger grant than a single function. Two tightly
coupled types that are really one concept (a container and its iterator) justify it;
"it was easier than writing a getter" does not.

### 2.5 Task 2 goal

Add a `friend std::ostream& operator<<(std::ostream&, const Enemy&)` to `Enemy` so
that `std::cout << g1 << '\n';` prints the enemy's name, health and damage. Return
`os` so the calls chain.

---

## Task 3 — `namespace` (pending)

### 3.1 The problem

`Enemy` is a name nobody owns. Pull in a third-party library that also defines
`Enemy` and the two collide — a hard compile error with no good local fix. As a
project grows this stops being hypothetical.

### 3.2 Syntax

```cpp
// Enemy.h
namespace Kepler
{
    class Enemy
    {
        // ...
    };
}
```

```cpp
// Enemy.cpp — reopen the namespace, do not repeat it in the qualified names
namespace Kepler
{
    int Enemy::enemyCount = 0;

    Enemy::Enemy(const std::string& n, int h, int d)
        : name(n), health(h), damage(d)
    {
        enemyCount++;
    }
}
```

```cpp
// main.cpp
int count = Kepler::Enemy::GetEnemyCount();
```

The full name is now `Kepler::Enemy`. `Kepler::Enemy` and `SomeLib::Enemy` are
different types and coexist happily.

### 3.3 Rules and habits

- Namespaces are **open**: you can reopen `namespace Kepler { }` in as many files as
  you like and keep adding to it. Classes are not open like this — the contrast is
  worth noticing.
- They **nest**: `namespace Kepler { namespace Combat { ... } }`, or since C++17 the
  compact `namespace Kepler::Combat { ... }`. Full name: `Kepler::Combat::Enemy`.
- **Never write `using namespace X;` in a header.** It silently forces that choice on
  every file that includes the header, and you have handed the collision problem back
  to everyone downstream. In a `.cpp`, after the includes, it is fine.
- Prefer a targeted `using Kepler::Enemy;` over dragging in a whole namespace.
- `std` is exactly this mechanism, which is why `std::string` and `std::cout` are
  spelled the way they are. Nothing special about it — just a namespace that ships
  with the library.

### 3.4 Anonymous namespaces

```cpp
namespace
{
    int helperCounter = 0;   // visible only inside this .cpp
}
```

The modern replacement for file-scope `static` (meaning 3 in the table above). Same
effect, works for types as well as variables.

### 3.5 Task 3 goal

Wrap `Enemy` in `namespace Kepler`, update `Enemy.cpp` and `main.cpp`, and confirm the
program still prints `0 → 3 → 0`.

---

## Checklist

- [x] `static` data member declared in the class
- [x] Defined once in the `.cpp` with the `Enemy::` prefix and no `static` keyword
- [x] `static` member function reading it, called as `Enemy::GetEnemyCount()`
- [x] Constructor increments, destructor decrements
- [x] Nested scope proving `0 → 3 → 0`
- [ ] `friend operator<<` for `Enemy` (Task 2)
- [ ] `namespace Kepler` wrapping (Task 3)

## Self-check questions

1. Why does `int Enemy::enemyCount = 0;` not repeat the `static` keyword — and what
   breaks if you add it?
2. Why can `GetEnemyCount()` read `enemyCount` but not `name`?
3. If you delete the definition line from `Enemy.cpp`, is the failure at compile time
   or link time? Why?
4. `Enemy g4 = g1;` compiles today. What does `enemyCount` do afterwards, and why is
   that wrong?
5. Does `friend` weaken encapsulation? Argue both sides in one sentence each.
6. Why is `using namespace std;` acceptable in `main.cpp` but not in `Enemy.h`?

## Practice

1. Add `static int GetTotalEverSpawned()` — a second counter that only ever goes up.
   The destructor must not touch it.
2. Write the copy constructor so `enemyCount` stays correct, then test with
   `Enemy g4 = g1;` inside the nested scope. Expect `4`, then `0`.
3. Switch `enemyCount` to `inline static int enemyCount = 0;` in the header, delete
   the `.cpp` definition, and confirm the output is unchanged.
4. Do Tasks 2 and 3.

---

**Next:** Lesson 2.08 — inheritance and `virtual`.

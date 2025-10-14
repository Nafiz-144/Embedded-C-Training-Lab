# Master C Fundamentals — Notes

Short, practical notes for common C concepts used in embedded systems. This file is a cleaned, Markdown-formatted version of the original `Note.text` with examples, common pitfalls, and quick exercises. Links at the end point to example `.c` files in this folder.

## Table of contents

- [Learning objectives](#learning-objectives)
- [<stdint.h>](#stdint.h)
- [volatile](#volatile)
- [const](#const)
- [structs and unions](#structs-and-unions)
- [Struct vs Union — quick comparison](#struct-vs-union---quick-comparison)
- [Common pitfalls](#common-pitfalls)
- [Exercises](#exercises)
- [See also](#see-also)
- [Key takeaways](#key-takeaways)

## Learning objectives

- Know why `<stdint.h>` is important for embedded systems.
- Understand `volatile` and when to use it.
- Understand `const` and pointer constness.
- Know the difference between `struct` and `union`, and how padding affects `sizeof()`.

## <stdint.h>

`<stdint.h>` defines fixed-width integer types like `uint8_t`, `int16_t`, `uint32_t`, etc. These types guarantee integer widths across platforms — critical for embedded code, device registers, and binary protocols.

When to prefer these:

- For hardware registers and memory-mapped IO.
- For protocol fields with specified bit-widths.

Example:

```c
#include <stdint.h>

uint8_t  small_val;   // exactly 8-bit unsigned
int16_t  temperature; // exactly 16-bit signed
uint32_t flags;       // exactly 32-bit unsigned
```

## volatile

`volatile` tells the compiler that a variable's value may change at any time without explicit action in the current code path (for example, by hardware or an ISR). The compiler must not optimize away accesses to volatile objects.

Example (ISR / main loop):

```c
volatile int flag = 0; // shared with an interrupt or hardware

void ISR_timer(void) {
    flag = 1; // set by interrupt
}

int main(void) {
    while (!flag) {
        // the compiler must actually read `flag` each loop iteration
    }
    // continue once flag is set
}
```

Notes:

- `volatile` is not a synchronization primitive; it does not guarantee atomicity or ordering between threads/cores. Use proper atomics or mutexes for concurrency.
- Common uses: memory-mapped I/O registers, ISR-shared flags, variables modified by signal handlers.

## const

`const` marks data as read-only after initialization. It documents intent and allows the compiler to catch accidental writes.

Pointer constness examples:

```c
int x = 5;
const int *p_to_const = &x; // cannot modify *p_to_const
int * const const_ptr = &x; // pointer value cannot change
const int * const both = &x; // both pointer and pointee are const
```

Use `const` to protect configuration data and to communicate immutability to callers and tools.

## structs and unions

A `struct` groups different members, each with its own memory. A `union` overlays members in the same memory location. Use `struct` for related fields that coexist and `union` when different interpretations of the same memory are needed.

Struct example:

```c
struct Person {
    char name[50];
    int age;
    float height;
};

struct Person p;
```

Union example:

```c
union Data {
    int i;
    float f;
    char str[20];
};

union Data d;
```

Example showing `sizeof()` and padding:

```c
#include <stdio.h>
#include <stdint.h>

struct S {
    uint8_t a;
    uint32_t b;
};
union U {
    uint8_t a;
    uint32_t b;
};

int main(void) {
    printf("sizeof(struct S) = %zu\n", sizeof(struct S)); // likely 8 (padding)
    printf("sizeof(union U)  = %zu\n", sizeof(union U));  // likely 4
}
```

Explanation: `struct` members are laid out with alignment and padding rules; `union` size equals largest member.

## Struct vs Union — quick comparison

- Struct: each member has its own storage; all members can hold values simultaneously.
- Union: members share storage; only one member can meaningfully hold a value at a time.
- Size: `sizeof(struct)` ≈ sum(members) + padding; `sizeof(union)` = max(size_of_members).

## Common pitfalls

- Using `volatile` to solve concurrency issues — it doesn't provide atomicity or memory ordering.
- Assuming union type-punning is defined behavior — reading a different member than was last written may be undefined; prefer `memcpy` or `std::bit_cast`-like safe methods.
- Ignoring struct padding when using `sizeof()` for communication protocols — prefer packed attributes only when you understand alignment consequences.
- Misunderstanding pointer `const` placement (which applies to the pointer vs pointee).

## Exercises

1. What does `volatile` guarantee? When is it insufficient?
2. Given a union with `int` and `float`, what happens if you write the `int` and then read the `float`? Is this portable?
3. Write a small program that prints `sizeof()` for a struct with fields `uint8_t, uint32_t, uint8_t` and explain the output.

Answers (brief):

1. `volatile` guarantees accesses are not optimized away; it doesn't provide atomicity or cross-thread ordering.
2. Reading a different union member than last written may invoke undefined behavior per strict aliasing rules; results are implementation-defined or undefined. Use `memcpy` for safe reinterpretation.
3. The size will typically show padding between members to satisfy alignment — the exact value depends on ABI; common result is 8 or 12 depending on packing/alignment.

## See also

- `Bit_operator_And_bit_masking.c` — bit operations examples
- `Const.c` — examples about `const` usage
- `Data_type_and_memory_size.c` — data sizes and behavior
- `Structs_and_Union.c` — examples comparing struct and union
- `Volatile.c` — volatile example

## Key takeaways

- Use `<stdint.h>` for predictable integer sizes.
- Use `volatile` for hardware/ISR-shared variables, but not as a concurrency mechanism.
- Use `const` to document/read-only data and catch errors.
- Understand struct padding and union layout when working with binary data.

---

If you'd like, I can replace the original `Note.text` with this `Note.md` (or keep both). I can also expand any section with more examples or add hidden-answer exercises.

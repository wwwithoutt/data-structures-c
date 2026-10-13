# Data Structures & Algorithms in C

[![Language: C99](https://img.shields.io/badge/Language-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Compiler: GCC / Clang](https://img.shields.io/badge/Compiler-GCC%20%7C%20Clang-orange.svg)](https://gcc.gnu.org/)
[![Memory: Valgrind Safe](https://img.shields.io/badge/Valgrind-0%20Leaks-brightgreen.svg)](https://valgrind.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A robust, low-level library of fundamental data structures and algorithms implemented in ISO C99. Designed with an emphasis on idiomatic C design patterns, rigorous dynamic memory management (`malloc`, `realloc`, `free`), zero tolerance for memory leaks, and formal algorithmic complexity guarantees.

---

## Key Highlights

- **Zero Memory Leaks:** 100% verified leak-free test suite using Valgrind and LLVM AddressSanitizer (`ASan`).
- **Encapsulation via Opaque Pointers:** Internal struct layouts remain private; consumers interact strictly through public APIs exposed in `include/`.
- **Defensive Engineering:** Strict boundary checks, proactive `NULL`-pointer validations, and robust memory allocation failure handling across all operations.
- **Strict Compiler Standards:** Compiles without warnings under `-Wall -Wextra -Werror -pedantic -std=c99`.

---

## Repository Architecture

```text
.
├── include/ds/        # Public API headers (module contracts)
├── src/               # Implementation files & internal logic
│   └── lists/         # Linked list implementations
├── tests/             # Unit and integration test suites
├── Makefile           # Build automation, sanitizers, and profiling targets
└── README.md          # Project documentation
```

---

## Implemented Modules & Complexity Analysis

### Linked Lists

| Data Structure | Access | Search | Insertion (Head) | Insertion (Tail) | Deletion | Space Complexity |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Singly Linked List** | O(n) | O(n) | O(1) | O(1)* | O(n) | O(n) |
| **Doubly Linked List** | O(n) | O(n) | O(1) | O(1) | O(1)** | O(n) |
| **Circular Linked List** | O(n) | O(n) | O(1) | O(1) | O(n) | O(n) |

> `*` — Requires maintaining an explicit `tail` pointer.  
> `**` — Assumes a direct pointer reference to the target node is provided.

---

## Build & Test

### Prerequisites
- Compiler: `gcc` (>= 9.0) or `clang` (>= 11.0)
- Build System: `make`
- Profiling & Memory Analysis: `valgrind` (Linux) or `AddressSanitizer` (macOS / Linux)

### 1. Compile Binaries & Test Suites
```bash
# Build all modules and test executables in standard debug mode
make all

# Build with AddressSanitizer (ASan) and UndefinedBehaviorSanitizer (UBSan) enabled
make sanitize
```

### 2. Execute Tests
```bash
make test
```

### 3. Run Memory Leak Audits (Valgrind)
```bash
make memcheck
```

---

## Roadmap

- [x] **Linear Lists:**
  - [x] Singly Linked List (`singly_linked_list`)
  - [x] Doubly Linked List (`doubly_linked_list`)
  - [x] Circular Linked List (`circular_linked_list`)
- [ ] **Sequential Abstract Data Types:**
  - [ ] Array-based & Linked Stacks (`stack`)
  - [ ] Queues (FIFO) and Double-Ended Queues (`queue`, `deque`)
  - [ ] Priority Queue / Binary Heap (`binary_heap`)
- [ ] **Tree Structures:**
  - [ ] Binary Search Tree (`BST`)
  - [ ] Self-Balancing AVL Tree (`AVL_tree`)
  - [ ] Red-Black Tree (`Red-Black_tree`)
- [ ] **Associative Arrays & Graphs:**
  - [ ] Hash Map with collision resolution (`hash_map`)
  - [ ] Graph representations (Adjacency List / Matrix) with BFS and DFS traversals

---

## License

This project is licensed under the [MIT License](LICENSE).

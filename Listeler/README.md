# Data Structures & Algorithms in C

[![Language: C99](https://img.shields.io/badge/Language-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Compiler: GCC / Clang](https://img.shields.io/badge/Compiler-GCC%20%7C%20Clang-orange.svg)](https://gcc.gnu.org/)
[![Memory: Valgrind Safe](https://img.shields.io/badge/Valgrind-0%20Leaks-brightgreen.svg)](https://valgrind.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

Низкоуровневая библиотека классических структур данных и алгоритмов на чистом Си (C99). Проект ориентирован на строгое соблюдение идиоматического стиля C, изолированное управление динамической памятью (`malloc`, `realloc`, `free`), отсутствие утечек памяти (zero leak tolerance) и детальную оценку асимптотической сложности.

---

## Особенности реализации

- **Zero Memory Leaks:** 100% покрытие тестов утилитой Valgrind и Clang AddressSanitizer (`ASan`).
- **Строгая инкапсуляция:** Внутренние структуры скрыты (Opaque Pointers), манипуляция данными выполняется строго через публичный интерфейс API в `include/`.
- **Защита от сбоев:** Проверка граничных условий, нулевых указателей (`NULL`-checks) и обработка ошибок выделения памяти на каждом уровне вызова.
- **Strict Compiler Flags:** Сборка без предупреждений с флагами `-Wall -Wextra -Werror -pedantic -std=c99`.

---

## Архитектура проекта

```text
.
├── include/ds/        # Публичные заголовочные файлы (API структур)
├── src/               # Реализации алгоритмов и логики работы с памятью
│   └── lists/         # Модули связанных списков
├── tests/             # Модульные и интеграционные тесты
├── Makefile           # Правила сборки, линковки и санитайзеров
└── README.md          # Документация проекта

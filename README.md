# C++ Module 00 — 42KL

> An introduction to C++: namespaces, classes, member functions, I/O streams, and the basics of object-oriented programming.

## Overview

Module 00 is the entry point into C++ at 42. Coming from C, most concepts feel familiar at first — but C++ introduces a fundamentally different way of organising code around data and the operations that act on it. This module covers the absolute basics: how classes work, how to control access to data, how the C++ I/O system replaces `printf`, and how to design classes from a specification.

The exercises range from simple (converting strings to uppercase) to more structured (building a phone book application with input/output formatting) to design-from-spec (reconstructing a `BankAccount` class whose behaviour is defined entirely by a given log file).

## The Challenge

The three exercises deliberately increase in complexity:
- `ex00` tests familiarity with C++ string handling and `std::cout`
- `ex01` requires designing a non-trivial class hierarchy with private members, getters/setters, and formatted console output
- `ex02` requires reading a class interface from a header file and implementing it to produce output that exactly matches a provided reference log — testing your ability to implement against a contract without being told how

## Concepts Introduced

- **Namespaces**: `std::` and the `using namespace` directive
- **Classes**: the `class` keyword, `public`/`private`/`protected` access specifiers
- **Member functions**: methods defined inside and outside the class body
- **Constructors and destructors**: object lifecycle management
- **`this` pointer**: referencing the current object inside a method
- **Getters and setters**: encapsulating private member access
- **Static members**: data and methods shared across all instances of a class
- **`std::cin` / `std::cout`**: C++ stream-based I/O as a replacement for `scanf` / `printf`
- **`std::string`**: C++'s managed string type versus raw `char *`
- **`std::setw` / `std::setfill`**: output stream formatting for field-width alignment

## Learning Outcomes

After completing this module you will have:
- Written your first C++ classes with proper encapsulation
- Understood the relationship between C-style structs and C++ classes
- Used stream I/O including formatted output with field widths
- Implemented a class from a header-only specification (no implementation hints provided)
- Understood static members and how they differ from instance members

## Exercises

### ex00 — Megaphone
Reads command-line arguments and prints them in uppercase. Introduces `std::string`, `std::toupper`, and `std::cout`.

```bash
./megaphone "hello world" "42"
# HELLO WORLD 42
```

### ex01 — PhoneBook
A terminal-based phone book that stores up to 8 contacts. Tests class design with private fields, formatted table output using `std::setw`, and input trimming.

```bash
./PhoneBook
> ADD         # prompts for first name, last name, nickname, phone, secret
> SEARCH      # displays index table, prompts for row number, prints full contact
> EXIT
```

### ex02 — Account
Implement `Account.cpp` from `Account.hpp` alone. Your implementation must produce output that exactly matches a reference log file showing account creation, deposits, withdrawals, and balance changes. Tests reading a class contract and fulfilling it without guidance.

## How to Build

```bash
cd ex00 && make && ./megaphone sponge bob square pants
cd ex01 && make && ./PhoneBook
cd ex02 && make && ./account
```

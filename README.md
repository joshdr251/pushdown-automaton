# Pushdown Automata – C++ & CMake
A collection of two small, standalone C++ console programs that simulate a pushdown automaton for palindromes, designed as a learning project to practice the fundamentals of C++: strings, the standard library, recursion, and working with CMake.

Each program has its own `main()` and is **completely independent** of the other. They only share a single `CMakeLists.txt` that builds both of them at once.

## ✨ | Programs

### 📏 Deterministic Pushdown Automaton
Checks whether a word is a palindrome with a separator. The word has the form `w X wᴿ` over the alphabet `{a, b}`, where `X` marks the middle and `wᴿ` is `w` reversed. The program reads the word once from left to right: the front half is pushed onto a stack, and the back half is compared with the top of the stack letter by letter.

**Highlights:**
- Two states: `q0` (front half, push) and `q1` (back half, compare and pop)
- Additional `reject` state as soon as a mismatch occurs or the stack runs empty too early
- The word is accepted if no `reject` was reached and the stack is empty at the end
- The program takes no input: the example word (`abXba`) is set in `main()`
  | State | Meaning |
  |---|---|
  | `q0` | Front half: every letter is pushed onto the stack |
  | `q1` | Back half: every letter has to match the top of the stack |
  | `reject` | Word is not a palindrome |
### 🔀 Nondeterministic Pushdown Automaton
Checks whether a word is a palindrome **without** a separator, so the middle of the word is unknown. Since a real nondeterministic automaton can "guess" the middle, the program simulates this by trying every possibility with recursion. The word is read from the user.

**Highlights:**
- Input validation: the character `#` is rejected because it is used as the bottom marker of the stack
- Works for palindromes of even and odd length
- Every call of `q0_iterate` tries three paths, and the word is accepted if at least one of them succeeds
- Stack, state transitions, and input handling are split into separate functions
  | Path | Meaning |
  |---|---|
  | `straight` | The middle is right here (even length): switch to `q1` at the current position |
  | `odd` | The current letter is the middle (odd length): skip it and switch to `q1` |
  | `further_iteration` | The middle is further ahead: push the letter and continue in `q0` |
## 🛠️ | Technologies & Libraries
* ``C++20`` - Language standard
* ``CMake`` - Build system for both programs
* ``iostream`` - Console input and output
* ``string`` - Storing and reading the word
* ``list`` - Used as the stack of the automaton (`push_front`, `pop_front`)
## 📁 | Project Structure
```
pushdown-automata/
│
├── CMakeLists.txt                  # Builds both programs
├── det_pushdown_automaton.cpp      # Deterministic version (with separator X)
├── nondet_pushdown_automaton.cpp   # Nondeterministic version (simulated via recursion)
└── .gitignore
```

## 🚀 | Installation

1. Clone the repository
```bash
   git clone https://github.com/YOUR_USERNAME/pushdown-automata.git
   cd pushdown-automata
```

2. Build both programs
```bash
   cmake -B build
   cmake --build build
```

3. Run a program of your choice (the exact location of the executables depends on your compiler, e.g. `build/` or `build/Debug/`)
```bash
   ./build/det_pushdown_automaton
   ./build/nondet_pushdown_automaton
```

You need a C++20-capable compiler and CMake 3.20 or newer.

## 🗂️ | Usage

**Deterministic Pushdown Automaton** needs no input and checks the word set in `main()`:

```
Success: Palindrome
```

To try other words, change the `palindrome` variable in `det_pushdown_automaton.cpp`. A word that is not accepted prints:

```
Error: Word is not a palindrome
```

**Nondeterministic Pushdown Automaton** asks for a word and tells whether it is a palindrome:

```
Enter the palindrome you want to check:
abcba
Success
```

```
Enter the palindrome you want to check:
abca
Error
```

Words containing `#` are rejected and the program asks again:

```
Enter the palindrome you want to check:
ab#ba
Not allowed to input #
Enter the palindrome you want to check:
```

## 📕 | Notes
* The programs were developed using C++20 and CLion
* The deterministic version only accepts words of the form `w X wᴿ` with `w ∈ {a, b}*`
* The nondeterministic version is case-sensitive and accepts every character except `#`, including spaces
* This is an ongoing learning project
## 🪲 | Bugs
* Feel free to report any bugs
 
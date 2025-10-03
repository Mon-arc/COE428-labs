# COE428 — Software Systems

#### This repository contains my Lab work for Algorithm and Data-Structures (COE428) at TMU. Each folder corresponds to one lab assignment. Below is a summary of each lab with links to the official TMU lab specifications.  If you are a student at TMU, do not copy/plagiarize my work (Policy 60). 

---

## Lab Summaries

### [Lab 1 – C Review & Test-Driven Workflow](https://www.ee.torontomu.ca/~courses/coe428/labs/lab1.pdf)
- Warm-up in C with a small sorting program (`mySort` + `sortMain`).
- Compile and link with `gcc`, practice `stdout` vs `stderr`, and extend `main` to accept command-line arguments.
- Emphasis on **incremental development, testing, error handling, and defensive programming**.

---

### [Lab 2 – Recursion & I/O Discipline (Towers of Hanoi)](https://www.ee.torontomu.ca/~courses/coe428/labs/lab2.pdf)
- Implement a recursive Hanoi solver that prints moves to `stdout` and debugging/tracing to `stderr`.
- Add CLI parsing (disk count, tower IDs) with exit codes and argument validation.
- Emphasis on **recursion mechanics, proper I/O separation, and robust CLI handling**.

---

### [Lab 3 – Sorting with Metrics (2 weeks)](https://www.ee.torontomu.ca/~courses/coe428/labs/lab3.pdf)
- Implement **InsertionSort** and **MergeSort** under a unified `mySort` interface.
- Instrument sorting with provided metric hooks (`myCompare`, `myCopy`, `mySwap`).
- Analyze best/average/worst-case complexity.
- Emphasis on **algorithm analysis, abstraction via interfaces, performance metrics, and Makefiles**.

---

### [Lab 4 – Finite State Machine Simulator (2 weeks)](https://www.ee.torontomu.ca/~courses/coe428/labs/lab4.pdf)
- Build `simState` to simulate and modify a DFA-like machine.
- Commands include:  
  - `0` / `1` for transitions  
  - `c` to patch transitions  
  - `p` to print configuration  
  - `g` to identify unreachable (garbage) states  
  - `d` to delete unreachable or named states
- Requires a state diagram and testing.
- Emphasis on **data structures, graph/automata representation, command parsing, and reachability analysis**.

---

### [Lab 5 – XML + Heap + Stacks (2 weeks)](https://www.ee.torontomu.ca/~courses/coe428/labs/lab5.pdf)
- **Part 1:** Validate simplified XML using a string stack to check proper nesting and case-sensitive tags.  
- **Part 2:** Implement an integer heap and stack:  
  - Build heap from input integers  
  - Print heap as XML  
  - Output descending order via repeated delete-max  
  - Output ascending order via stack pop
- Emphasis on **stacks, trees, heaps, parsing, and representing structures in XML**.

---

## Notes
- All official lab instructions are available on the [TMU COE428 Lab Page](https://www.ee.torontomu.ca/~courses/coe428/labs/).
- This repo only contains my **solutions and supporting files**, not the official handouts.

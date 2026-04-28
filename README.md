# OOP & Systems Simulation (C++)
## University Assignment - Object Oriented Programming

This repository contains a multi-part assignment focused on the core pillars of C++ and Object-Oriented logic. The project demonstrates proficiency in manual memory management, recursion, and structuring real-world systems using modular code.

---

## 🚀 Featured Modules

### 1. University Management System (The "OOP" Core)
A structured system simulating a university environment using linked data structures and dynamic memory.
* **Entities:** Student, Teacher, Course, Grade, and RetakeRequest.
* **Functionalities:** Admin control (Add student/teacher/course), Teacher actions (Assign grades, generate class reports), and Student actions (Enrollment, GPA calculation).
* **Memory Management:** Implements deep cleanup to prevent memory leaks in dynamic arrays of pointers.

### 2. Smart Grid & Teleportation Game
A logic-based game where a player moves on a dynamic 2D grid.
* **Dynamic Grid:** Created and resized using pointer-to-pointer (`int**`) logic.
* **Mechanics:** Random teleportation placement and boundary-checked player movement.

### 3. Advanced Recursion Challenges
* **Hollow Diamond Pattern:** A complex nested recursion implementation to render geometric shapes.
* **String Reversal:** Reversing words in a sentence using pure recursion without standard library iteration.

### 4. Jagged Array Operations
Manual implementation of a "Jagged Array" (an array of arrays where each row has a different length).
* Custom allocation, input, row-sum calculation, and systematic deallocation.

---

## 🛠 Technical Skills Demonstrated
* **OOP Concepts:** Encapsulation via structs, modular function design, and state management.
* **Manual Memory Management:** Heavy use of `new`, `delete`, and `delete[]` for 2D and Jagged structures.
* **Algorithm Design:** Recursive logic for string manipulation and pattern printing.
* **C++ Fundamentals:** Pointer arithmetic, `#pragma once` header guards, and modular file organization (`.h` vs `.cpp`).

---

## 📂 Project Structure
* `University.h`: Struct definitions and logic for the University System.
* `GameBoard.h`: Game mechanics and grid management.
* `Header.h`: Prototypes for recursion and jagged array tasks.
* `main.cpp`: Driver code with a menu-driven interface.

---

## 💻 How to Run
1. Clone the repository.
2. Compile using any C++ compiler (e.g., G++):
   ```bash
   g++ main.cpp -o oop_assignment

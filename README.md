♔ N-Queens Solver
=================

🚀 **Efficiently Solve the Classic N-Queens Problem**

🛠 Purpose of the Program
-------------------------

The **N-Queens Problem** is a famous combinatorial problem where the goal is to place **N queens** on an **N × N chessboard** such that **no two queens attack each other**.

This program **efficiently solves the problem using backtracking** and outputs valid board configurations. It can be used for:

✅ **Algorithm Learning** -- Understanding backtracking & constraint satisfaction\
✅ **AI & Game Theory** -- Exploring heuristic search & optimization\
✅ **Mathematical Puzzles** -- Experimenting with different board sizes\
✅ **Chess AI Development** -- Integrating advanced move calculations

* * * * *

📌 Features
-----------

✅ **Backtracking Algorithm** for efficient search\
✅ **Supports any board size (N ≥ 1)**\
✅ **Fast Execution** with optimized pruning\
✅ **Command-line Interface (CLI)** for flexible input/output\
✅ **Makefile included** for easy compilation

* * * * *

🛠 How It Works
---------------

This program takes an **integer N** (size of the chessboard) and finds **all valid solutions** where N queens can be placed without attacking each other.

It uses a **recursive backtracking approach**, which:\
🔹 Places queens **row by row**\
🔹 Checks if the placement is **safe** (no other queen in the same column, row, or diagonal)\
🔹 **Backtracks** when no valid position is found\
🔹 **Stores & prints** all valid solutions

* * * * *

🔍 Understanding the Input & Output
-----------------------------------

### 📥 **Input File (e.g., `simple-input.txt`)**

Each line contains a **single integer N**, representing the **size of the board**.

📌 **Example Input (`simple-input.txt`):**

`4`  
`8`  

This means the program will solve **4-Queens** and **8-Queens** problems.

* * * * *

### 📤 **Output File (e.g., `simple-output.txt`)**

Each solution is printed as a **board configuration**, with:

-   `Q` representing a queen
-   `.` representing an empty space
-   Solutions separated by a blank line

📌 **Example Output (`simple-output.txt`) for N = 4:**

`. Q . .`  
`. . . Q`  
`Q . . .`  
`. . Q .`  

`. . Q .`  
`Q . . .`  
`. . . Q`  
`. Q . .`  

This shows **two valid solutions** for a **4 × 4 board**.

* * * * *

🚀 Performance & Constraints
----------------------------

⚡ **Optimized Execution:**

-   **Uses backtracking** to prune invalid branches early
-   **Handles large values of N efficiently**
-   **Runs in under 2 minutes for reasonable N values**

🔹 **Error Handling:**

-   If no solution exists, prints `No solution exists for N = X`
-   Can handle edge cases like **N = 1 or N = 2**

* * * * *

📦 Installation & Usage
-----------------------

### 📥 1. Clone the Repository

`git clone https://github.com/your-repo/N-Queens-Solver.git`  
`cd N-Queens-Solver`

### 🏗 2. Build the Program

`make`

This will create an **executable** named `nqueens`.

### ▶️ 3. Run the Program

`./nqueens simple-input.txt simple-output.txt`

📌 **Explanation:**

-   `simple-input.txt` contains **board sizes (N values)**.
-   `simple-output.txt` stores the **generated solutions**.
-   **To use your own dataset**, replace `simple-input.txt` with a custom file.

* * * * *

📂 File Structure
-----------------

- 📂 N-Queens-Solver
- ├── 📄 Makefile           # Automates compilation
- ├── 📄 nqueens.cpp        # Main program logic
- ├── 📄 nqueens.o          # Compiled object file
- ├── 📄 simple-input.txt   # Sample input queries
- ├── 📄 simple-output.txt  # Generated output
- ├── 📄 README.md          # This file`

* * * * *

🎯 Algorithm Overview
---------------------

1️⃣ **Place queens row by row**\
2️⃣ **Check if each position is valid**\
3️⃣ **Use recursion to explore solutions**\
4️⃣ **Backtrack when needed**\
5️⃣ **Print all valid solutions**

* * * * *

📜 Fun Facts About the N-Queens Problem!
----------------------------------------

♔ **Earliest known solution:** Proposed by Carl Friedrich Gauss in the 19th century\
♔ **Total solutions for N = 8:** **92**\
♔ **First AI approach:** Used constraint satisfaction techniques

* * * * *

💡 Want to Improve It?
----------------------

🔹 **Implement bitwise operations** for faster execution\
🔹 **Explore AI-based optimizations** (e.g., genetic algorithms)\
🔹 **Extend to solve 3D chess problems**

* * * * *

🏆 Built With
-------------

🔹 **C++** for efficiency\
🔹 **Backtracking Algorithm**\
🔹 **Makefile** for seamless compilation

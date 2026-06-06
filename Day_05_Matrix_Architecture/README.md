# Day 5: Matrix Architecture (2D Arrays)

## The Engineering Problem
A standard 1D array can only represent a flat line of data. Game engines frequently require 2D spatial representation (e.g., tile maps, inventory grids, chess boards). We need a memory structure capable of handling dual-axis (X/Y or Row/Column) traversal.

## The Architecture: Matrices & Nested Traversal
A 2D matrix in modern C++ is constructed as a vector of vectors (`std::vector<std::vector<int>>`). To traverse this grid, we deploy an outer loop to control the Y-axis (Rows) and an inner loop to control the X-axis (Columns). 

While it conceptually represents a grid, at the hardware level, standard static 2D arrays are mapped to contiguous 1D memory blocks (Row-Major Order in C++). This means traversing row-by-row is cache-friendly and highly optimal, whereas traversing column-by-column causes CPU cache misses.

## Execution Rules
1. Traverse rows using an outer loop: `for(int i = 0; i < rows; i++)`
2. Traverse columns using an inner loop: `for(int j = 0; j < cols; j++)`
3. Access specific memory blocks using coordinate syntax: `matrix[i][j]`

## Complexity Profile
* **Time Complexity:** $O(n \times m)$ - Where $n$ is the number of rows and $m$ is the number of columns. In a worst-case search, every cell must be checked.
* **Space Complexity:** $O(1)$ - The search algorithm requires zero extra heap allocation.
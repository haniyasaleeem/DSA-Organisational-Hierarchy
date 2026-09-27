# Organisational Hierarchy Using Tree and Searching Algorithms

## Student Details

* Name: Fathima Haniya CP
* Course: Data Structures and Algorithms
* Programming Language: C

## 1. Problem Statement

A company has the following organisational hierarchy:

```text
CEO → HR, Finance, IT
IT → Development, Testing
Development → Frontend, Backend
```

The objectives are:

1. Represent the hierarchy using a suitable tree structure.
2. Construct the tree in C.
3. Display the hierarchy using level-order traversal.
4. Store department names in a searchable representation.
5. Compare Linear Search and Binary Search.
6. Record the number of comparisons for at least three searches.
7. Analyse tree height, traversal behaviour, search comparisons, and complexity.
8. Determine the suitability of the selected representation for organisational reporting and department searching.

## 2. Organisational Hierarchy

```text
CEO
├── HR
├── Finance
└── IT
    ├── Development
    │   ├── Frontend
    │   └── Backend
    └── Testing
```

## 3. Data Structures Used

### General Tree

A general tree is used to represent the organisational hierarchy.

Each node contains:

* Department name
* Number of children
* Array of pointers to child nodes

A general tree is suitable because an organisational department can have different numbers of sub-departments.

### Queue

A queue is used for level-order traversal.

Level-order traversal visits the nodes level by level from left to right.

### Sorted Array

The department names are stored in an alphabetically sorted array:

```text
Backend, CEO, Development, Finance, Frontend, HR, IT, Testing
```

The sorted array is used for Binary Search.

## 4. Source Code

The complete C source code is available in:

```text
organisation.c
```

## 5. Input Data

The hierarchy, department names, and search targets used for the experiment are available in:

```text
input.txt
```

## 6. Compilation and Execution

Compile the program using GCC:

```bash
gcc organisation.c -o organisation
```

Run the program on Linux or macOS:

```bash
./organisation
```

Run the program on Windows:

```bash
organisation.exe
```

## 7. Program Output

The complete program output is available in:

```text
output.txt
```

The level-order traversal is:

```text
CEO HR Finance IT Development Testing Frontend Backend
```

The tree height is:

```text
Height in levels: 4
Height in edges: 3
```

## 8. Tree Height

The longest path in the tree is:

```text
CEO → IT → Development → Frontend
```

Therefore:

* Height in levels: 4
* Height in edges: 3

## 9. Level-Order Traversal

The level-order traversal is:

```text
CEO HR Finance IT Development Testing Frontend Backend
```

The traversal visits every node once.

Therefore:

* Time complexity: O(n)
* Space complexity: O(w)

Here, `n` is the number of departments and `w` is the maximum width of the tree.

## 10. Search Results

| Search Target | Linear Search Comparisons | Binary Search Comparisons | Result |
| ------------- | ------------------------: | ------------------------: | ------ |
| CEO           |                         2 |                         2 | Found  |
| Frontend      |                         5 |                         3 | Found  |
| Testing       |                         8 |                         4 | Found  |

## 11. Complexity Analysis

| Operation             | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Tree construction     | O(n)            | O(n)             |
| Level-order traversal | O(n)            | O(w)             |
| Height calculation    | O(n)            | O(h)             |
| Linear search         | O(n)            | O(1)             |
| Binary search         | O(log n)        | O(1)             |
| Freeing tree memory   | O(n)            | O(h)             |

Where:

* `n` = number of departments
* `h` = height of the tree
* `w` = maximum width of the tree

## 12. Linear Search

Linear search compares the target with each department from the beginning.

### Advantages

* Simple to implement.
* Works with sorted or unsorted data.
* Useful for small lists.

### Disadvantages

* Can require many comparisons.
* Worst-case time complexity is O(n).

## 13. Binary Search

Binary search compares the target with the middle element and eliminates approximately half of the remaining data at each step.

### Advantages

* Efficient for large sorted lists.
* Worst-case time complexity is O(log n).
* Suitable for repeated searches.

### Disadvantages

* Requires sorted data.
* Maintaining a sorted array can require rearranging elements after insertion or deletion.

## 14. Final Conclusion

The general tree is suitable for representing the organisational hierarchy because it clearly shows the relationship between the CEO, departments, and sub-departments.

Level-order traversal is suitable for organisational reporting because it displays the hierarchy level by level in a readable manner.

For department searching, Binary Search is suitable when the department list is sorted, especially when the list is large or many searches are performed. Binary Search requires O(log n) time in the worst case, while Linear Search requires O(n) time.

However, Linear Search is acceptable for a small unsorted list.

Therefore, the selected approach is:

* Use a general tree for organisational representation.
* Use level-order traversal for organisational reporting.
* Use a sorted array with Binary Search for repeated department searching.

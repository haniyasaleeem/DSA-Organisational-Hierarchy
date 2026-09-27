# Complexity Analysis

## 1. Tree Construction

The organisational hierarchy is represented using a general tree.

Each tree node stores:

- Department name
- Number of children
- Pointers to child nodes

If the tree contains `n` departments, creating all nodes and connecting them takes:

- Time complexity: O(n)
- Space complexity: O(n)

## 2. Level-Order Traversal

Level-order traversal uses a queue.

The algorithm:

1. Inserts the root node into the queue.
2. Removes one node from the queue.
3. Displays the node.
4. Inserts all its children into the queue.
5. Repeats until the queue becomes empty.

Every department is visited once.

- Time complexity: O(n)
- Space complexity: O(w)

Here, `w` is the maximum width of the tree. In the worst case, the space complexity is O(n).

## 3. Tree Height Calculation

The height function recursively visits every node.

- Time complexity: O(n)
- Space complexity: O(h)

Here, `h` is the height of the tree and represents the recursion stack space.

For this hierarchy:

- Height in levels: 4
- Height in edges: 3

The longest path is:

```text
CEO → IT → Development → Frontend
```

## 4. Linear Search

Linear search checks department names one by one.

- Best-case time complexity: O(1)
- Average-case time complexity: O(n)
- Worst-case time complexity: O(n)
- Space complexity: O(1)

Linear search does not require sorted data.

## 5. Binary Search

Binary search works on the sorted department array.

At every step, approximately half of the remaining elements are discarded.

- Best-case time complexity: O(1)
- Average-case time complexity: O(log n)
- Worst-case time complexity: O(log n)
- Space complexity: O(1)

Binary search requires the department names to be sorted.

## 6. Freeing the Tree

The `freeTree()` function releases the memory used by every node.

- Time complexity: O(n)
- Space complexity: O(h)

## 7. Overall Complexity Table

| Operation | Time Complexity | Space Complexity |
|---|---:|---:|
| Create one node | O(1) | O(1) |
| Construct complete tree | O(n) | O(n) |
| Add one child | O(1) | O(1) |
| Level-order traversal | O(n) | O(w) |
| Calculate tree height | O(n) | O(h) |
| Linear search | O(n) | O(1) |
| Binary search | O(log n) | O(1) |
| Free the tree | O(n) | O(h) |

Where:

- `n` = number of departments
- `h` = height of the tree
- `w` = maximum width of the tree

# Complexity Analysis

## 1. Tree Construction

The organisational hierarchy is represented using a general tree.

Each tree node stores:

- Department name
- Number of children
- Array of pointers to child nodes

If the tree contains `n` departments, creating all the nodes requires:

- Time complexity: O(n)
- Space complexity: O(n)

The `addChild()` function inserts a child directly into the parent's children array. Since the array has a fixed maximum size, adding one child takes O(1) time.

Therefore, for the given implementation:

- Tree construction time complexity: O(n)
- Tree space complexity: O(n)

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

Here, `w` is the maximum width of the tree. In the worst case, the space complexity can be O(n).

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

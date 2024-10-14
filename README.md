# Data Sturctures and Algorithms
Data structures are fundamental concepts in computer science and programming that define how data is organized, stored, and manipulated in a computer's memory or storage. They provide a way to efficiently store and access data, enabling various operations and algorithms to be performed effectively. Data structures can be categorized into two main types:

## Primitive Data Structures:
These are basic data types provided by programming languages, such as integers, floating-point numbers, characters, and booleans. They represent individual pieces of data and are used as building blocks for more complex data structures.

## Abstract Data Structures (ADTs):
Abstract data structures are higher-level data structures that are not directly implemented in most programming languages but are created using primitive data types. They define a set of operations and rules for manipulating data but do not specify how the data is actually stored or implemented. Common abstract data structures include:

## 1. Data Structures
Data structures are ways to organize and store data efficiently, enabling easy access, modification, and management.

#### Arrays: 
Fixed-size sequential collections of elements of the same type.
#### Linked Lists:
A sequence of elements where each element points to the next one.
#### Singly Linked List: 
Nodes point to the next node.
#### Doubly Linked List: 
Nodes point to both next and previous nodes.
#### Stacks: 
Follows the Last In, First Out (LIFO) principle. Operations include push, pop, and peek.
#### Queues: 
Follows the First In, First Out (FIFO) principle. Operations include enqueue and dequeue.
Priority Queues: Elements are dequeued based on priority.
Dequeue: Double-ended queue, allows insertion and removal from both ends.
Hash Tables: Stores key-value pairs and allows for fast access using a hash function.
Trees: Hierarchical data structures with a root node, branches, and leaves.
Binary Tree: Each node has up to two children.
Binary Search Tree (BST): A binary tree where the left child is smaller and the right child is greater than the parent node.
AVL Tree: A self-balancing BST.
Heap: A special tree-based data structure that satisfies the heap property (min-heap or max-heap).
Graphs: A collection of nodes (vertices) connected by edges. Graphs can be directed or undirected, weighted or unweighted.
Adjacency Matrix and Adjacency List are common ways to represent graphs.
2. Algorithms
Algorithms are step-by-step procedures for solving problems or performing tasks efficiently.

Sorting Algorithms:
Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order.
Selection Sort: Finds the minimum element from the unsorted portion and swaps it with the first unsorted element.
Insertion Sort: Builds the sorted array by inserting elements into their correct position.
Merge Sort: A divide-and-conquer algorithm that divides the array, sorts each part, and then merges them.
Quick Sort: Another divide-and-conquer algorithm that picks a pivot and partitions the array into two sub-arrays around the pivot.
Searching Algorithms:
Linear Search: Sequentially checks each element until the target is found.
Binary Search: Efficient search algorithm for sorted arrays that divides the array in half to find the target.
Graph Algorithms:
Depth-First Search (DFS): Explores as far as possible along each branch before backtracking.
Breadth-First Search (BFS): Explores all neighbors at the current depth before moving to nodes at the next depth level.
Dijkstra's Algorithm: Finds the shortest path between nodes in a weighted graph.
Prim's and Kruskal's Algorithms: Used to find the Minimum Spanning Tree (MST) in a graph.
Dynamic Programming (DP): Solves complex problems by breaking them down into overlapping subproblems and solving each just once, storing the results.
Greedy Algorithms: Makes the locally optimal choice at each step with the hope of finding the global optimum.
Divide and Conquer: Breaks a problem into smaller subproblems, solves each subproblem recursively, and combines the results.
Backtracking: Tries all possible solutions and backtracks when a solution doesn't work.
3. Common Techniques and Problems
Recursion: A function that calls itself to solve a smaller instance of the problem.
Memoization: Storing the results of expensive function calls to avoid redundant calculations.
Bit Manipulation: Operations that manipulate individual bits to solve problems efficiently.
Tree Traversals: Techniques to visit all nodes in a tree (Inorder, Preorder, Postorder).
Graph Traversals: DFS and BFS for exploring graphs.
Understanding and mastering these topics can help in problem-solving and optimizing your code for efficiency.

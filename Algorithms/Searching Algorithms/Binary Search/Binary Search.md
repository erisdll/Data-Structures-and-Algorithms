# Binary Search

## Description

Binary search is a search algorithm used to find the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half until the target value is found or the interval is empty. The search interval is halved by comparing the target element with the middle value of the search space. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N).

## Conditions to apply

- The data structure must be sorted
- Access to any element of the data structure takes constant time

## Implementation

The Binary Search Algorithm can be implemented in the following two ways:

- Iterative Binary Search Algorithm
- Recursive Binary Search Algorithm

## Algorithm

- Divide: split the search space into two halves by finding the middle index.
- Comapare: compare the middle element of the search space with the key.
- Found: If the key is found at middle element, terminate the process.
- Move: If the key is not found, choose which half will be searched next.
- Smaller: if the key is smaller than the middle element, use left side as next the search space.
- Bigger: if the key is bigger than the middle element, use the right side as the next search space.
- Not found: if the key is not found after total search space is exausted, return that the element is not in the data set.

## Time and Space Complexity:

#### Time Complexity:

**O(log N)**

#### Auxiliary Space:

**O(1)**

## Applications:

- Binary search can be used as a abuilding block for more complex algorithms used in marchine learning, such as algorithms for training neural networkds, or finding the optimal hyperparameters of a model.
- It can be used for searching in computer graphics such as algorithms for ray tracing or texture mapping.
- It can be used for searching a database.

## Advantages

- Binary search is faster than linear search, especially for large arrays.
- More efficient than other searching algorithms with a similar time complexity such as interpolation search or exponential search.
- Binary search is well-suited for searching large datasets that are stores in external memoery, such as on a hard drive or in the cloud.

## Disadvantages

- The array should be sorted.
- Binary search requires that the data structure being searched be stored in contigous memory locations.
- Binary search requires that the elements of the array be comparible, meaning that they must be able to be ordered.
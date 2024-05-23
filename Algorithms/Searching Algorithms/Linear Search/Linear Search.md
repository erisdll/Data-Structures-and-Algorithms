# Linear Search

## Description:

**Linear search**, also known as **Sequential Search**, is defined as a search algorithm that starts at one end and goes through each element of a list until the desired element is found. Otherwise, the search continues until the end of the dataset. In linear search, each element of the collection is visited one by one in a sequential fashion to find the desired element.

## Algorithm:

- Start: Begin at the first element of the collection of elements.
- Compare: Compare the current element with the desired element.
- Found: If the current element is equal to the desired element, return true or index to the current element.
- Move: Othewise, move to the next element in the collection.
- Repeat: Repeat steps 2-4 until we have reached the end of the collection.
- Not found: If the end of the collection is reached without finding the desired element, return that the desired element is not in the collection.

## Time and Space Complexity:

#### Time Complexity:

- Best Case: In the best case, the key might be present at the first index. So the best case complexity is O(1)

- Worst Case: In the worst case, the key might be present at the last index i.e., opposite to the end from which the search has started in the list. So the worst-case complexity is O(N) where N is the size of the list.

- Average Case: O(N)

- Auxiliary Space: O(1) as except for the variable to iterate through the list, no other variable is used.

## Applications

- **Unsorted Lists**: When we have an unsorted array or list, linear search is most commonly used to find any element in the collection.
- **Small Data Sets**: Linear Search is preferred over binary search when we have small data sets.
- **Searching Linked Lists**: In linked list implementations, linear search is commonly used to find elements within the list. Each node is checked sequentially until the desired element is found.
- **Simple Implementation**: Linear Search is much easier to understand and implement as compared to Binary Search or Ternary Search.

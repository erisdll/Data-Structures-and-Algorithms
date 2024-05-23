# Selection Sort

## Description:

Selection sort is a simple and efficient sorting algorithm that works by repeatedly selecting the smallest (or largest) element of a list and moving it to the sorted portion. The algorithm selects the smallest (or largest) element from the unsorted portion and swaps it with the first element of the unsorted portion. This process is repeated for the remaining unsorted portion until the entire list is sorted.

## Step-by-Step:

1. Selection: The algorithm divides the input array into two parts: the sorted sublist at the beginning and the unsorted sublist at the end. (Sorted sublist is initially empty).
2. Finding smallest element: Itereate through the unsorted sublist to find the smallest element.
3. Swap: Once the smallest element is found, swap it with the first element of the unsorted sublist.
4. Expand Sorted Sublist: Move the boundary of the sorted sublist one element to the right, making the sorted sublist one element larger and the unsorted sublist one element smaller.
5. Repeat: Repeat steps 2-4 until the entire array is sorted. The algorith terminates when the unsorted sublist becomes empty.


#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void iterativeSelectionSort(int array[], int arraySize)
{
    int outerItt, innerItt, minIndex;

    //Traverse through the entire array
    for (outerItt = 0; outerItt < arraySize - 1; outerItt++)
    {
        // Assume current index as minimum
        minIndex = outerItt;

        // Find the index of the minimum element in the unsorted list
        for (innerItt = outerItt + 1; innerItt < arraySize; innerItt++)
        {
            if (array[innerItt]< array[minIndex])
            {
                minIndex = innerItt;
            }
        }

        // Swap the minimum element with the current element
        if (minIndex != outerItt) 
        {
            swap(&array[outerItt], &array[minIndex]);
        }
    }
}
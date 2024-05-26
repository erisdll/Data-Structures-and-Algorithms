#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Iterative selection sort
void iterativeSelectionSort(int array[], int arraySize)
{
    int outerItt, innerItt, minIndex;

    // Traverse through the entire array
    for (outerItt = 0; outerItt < arraySize - 1; outerItt++)
    {
        // Assume current index as minimum
        minIndex = outerItt;

        // Find the index of the minimum element in the unsorted list
        for (innerItt = outerItt + 1; innerItt < arraySize; innerItt++)
        {
            if (array[innerItt] < array[minIndex])
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

void recursiveSelectionSort(int array[], int arraySize, int currentIndex)
{
    if (currentIndex >= arraySize - 1 ) return;
    
    int minIndex = currentIndex;

    for (int iterator = currentIndex + 1; iterator < arraySize; iterator++)
    {
        if (array[iterator] < array[minIndex]) 
        {
            minIndex = iterator;
        }
    }

    if (minIndex != currentIndex)
    {
        swap(&array[minIndex], &array[currentIndex]);
    }

    recursiveSelectionSort(array, arraySize, currentIndex + 1); 
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arraySize, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int *array = (int*)malloc(arraySize * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    printf("Choose implementation:\n");
    printf("1. Iterative selection sort\n");
    printf("2. Recursive selection sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            iterativeSelectionSort(array, arraySize);
            break;
        case 2:
            recursiveSelectionSort(array, arraySize, 0);
            break;
        default:
            printf("Invalid choice!\n");
            free(array);
            return 1;
    }

    printf("Sorted array: ");
    printArray(array, arraySize);

    free(array);
    
    return 0;
}
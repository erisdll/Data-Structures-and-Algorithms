#include <stdio.h>
#include <stdlib.h>

// BINARY SEARCH ALGORITHM IMPLEMENTATIONS //

int iterativeBinarySearch(int sortedArray[], int leftIndex, int rightIndex, int keyValue)
{
    while (leftIndex <= rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (sortedArray[middleIndex] == keyValue)
        {
            return middleIndex;
        }

        else if (sortedArray[middleIndex] <= keyValue)
        {
            leftIndex = middleIndex + 1;
        }

        else if (sortedArray[middleIndex] >= keyValue)
        {
            rightIndex = middleIndex - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int sortedArray[], int leftIndex, int rightIndex, int keyValue)
{
    if (leftIndex <= rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (sortedArray[middleIndex] == keyValue)
        {
            return middleIndex;
        }

        if (sortedArray[middleIndex] <= keyValue)
        {
            return recursiveBinarySearch(sortedArray, middleIndex + 1, rightIndex, keyValue);
        }

        else
        {
            return recursiveBinarySearch(sortedArray, leftIndex, middleIndex - 1, keyValue);
        }
    }
}

// DRIVER //

int main(void)
{
    int arraySize;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &arraySize);

    int *sortedArray = (int *)malloc(arraySize * sizeof(int));
    if (sortedArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements in ascending order:\n", arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &sortedArray[i]);
    }

    int keyValue;
    printf("Enter the element to search for: ");
    scanf("%d", &keyValue);

    int choice;
    printf("Choose the search method:\n");
    printf("1. Iterative Binary Search\n");
    printf("2. Recursive Binary Search\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    int resultIndex;
    if (choice == 1)
    {
        resultIndex = iterativeBinarySearch(sortedArray, 0, arraySize - 1, keyValue);
    }
    else if (choice == 2)
    {
        resultIndex = recursiveBinarySearch(sortedArray, 0, arraySize - 1, keyValue);
    }
    else
    {
        printf("Invalid choice\n");
        free(sortedArray);
        return 1;
    }

    if (resultIndex != -1)
    {
        printf("Element found at index %d\n", resultIndex);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    free(sortedArray);
    return 0;
}
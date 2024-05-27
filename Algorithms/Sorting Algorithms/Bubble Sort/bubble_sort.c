#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[], int arraySize)
{
    int i, j;
    bool swapped;
    for (i = 0; i < arraySize - 1; i++)
    {
        swapped = false;
        for (j = 0; j < arraySize - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        printf("%d", array[i]);
    }
}

int main()
{
    int arraySize;
    printf("Enter desired array size: ");
    scanf("%d", &arraySize);

    int *array = (int*)malloc(arraySize * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers: ", arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, arraySize);

    printf("Sorted array: ");
    printArray(array, arraySize);

    free(array);
    return 0;
}
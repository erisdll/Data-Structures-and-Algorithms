#include <stdio.h>
#include <stdlib.h>

// LINEAR SEARCH ALGORITHM //

int linearSearch(int array[], int arrayLength, int desiredElement)
{
    for (int iterator = 0; iterator < arrayLength; iterator++)
    {
        if (array[iterator] == desiredElement)
        {
            return iterator;
        }
    }
    return -1;
}

// DRIVER //

int main(void)
{
    int arrayLength;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &arrayLength);
    printf("\n");

    int *array = malloc(arrayLength * sizeof(int));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    int desiredElement;
    printf("Enter the element to search for: ");
    scanf("%d", &desiredElement);
    printf("\n");

    int result = linearSearch(array, arrayLength, desiredElement);
    (result == -1)
        ? printf("Element is not present in the array\n\n")
        : printf("Element is present at index %d\n\n", result);

    free(array);
    return 0;
}

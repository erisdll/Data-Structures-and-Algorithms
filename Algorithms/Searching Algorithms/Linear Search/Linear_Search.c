#include <stdio.h>
#include <stdlib.h>

// LINEAR SEARCH ALGORITHM //

int linear_search(int array[], int array_length, int desired_element)
{
    for (int iterator = 0; iterator < array_length; iterator++)
    {
        if (array[iterator] == desired_element)
        {
            return iterator;
        }
    }
    return -1;
}

// DRIVER //

int main(void)
{
    int array_length;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &array_length);
    printf("\n");

    int *array = malloc(array_length * sizeof(int));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < array_length; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    int desired_element;
    printf("Enter the element to search for: ");
    scanf("%d", &desired_element);
    printf("\n");

    int result = search(array, array_length, desired_element);
    (result == -1)
        ? printf("Element is not present in the array\n\n")
        : printf("Element is present at index %d\n\n", result);

    free(array);
    return 0;
}
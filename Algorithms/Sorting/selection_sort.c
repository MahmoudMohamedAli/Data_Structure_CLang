#include <stdio.h>

void print_arr(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int *arr, int n)
{
    for (size_t i = 0; i < (n - 1); i++)
    {
        int min_index = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

int main()
{
    int arr[] = {4, 3, 6, 10, 1, 2, 11};
    print_arr(arr, 7);
    selection_sort(arr, 7);
    print_arr(arr, 7);
    return 0;
}
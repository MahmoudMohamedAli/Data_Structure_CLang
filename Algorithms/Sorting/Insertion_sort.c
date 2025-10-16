#include <stdio.h>

void print_arr(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Insertion_sort(int *arr, int n)
{
    for (size_t i = 1; i < (n - 1); i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {4, 3, 6, 10, 1, 2, 11};
    print_arr(arr, 7);
    Insertion_sort(arr, 7);
    print_arr(arr, 7);
    return 0;
}
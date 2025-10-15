#include <stdio.h>

void print_arr(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Bubble_sort(int *arr, int n)
{
    for (size_t i = 0; i < (n - 1); i++)
    {
        int swap_flag = 0;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_flag = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (swap_flag == 0)
            break;
    }
}

int main()
{
    int arr[] = {4, 3, 6, 10, 1, 2, 11};
    print_arr(arr, 7);
    Bubble_sort(arr, 7);
    print_arr(arr, 7);
    return 0;
}
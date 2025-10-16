#include <stdio.h>

void print_arr(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int tmp_r[n2];
    int tmp_l[n1];
    for (size_t i = 0; i < n1; i++)
    {
        tmp_l[i] = arr[left + i];
    }
    for (size_t i = 0; i < n2; i++)
    {
        tmp_r[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (tmp_l[i] < tmp_r[j])
        {
            arr[k] = tmp_l[i];
            i++;
        }
        else
        {
            arr[k] = tmp_r[j];
            j++;
        }
        k++;
    }
    // cope remaning for left
    while (i < n1)
    {
        arr[k] = tmp_l[i];
        k++;
        i++;
    }
    // cope remaning for Right
    while (j < n2)
    {
        arr[k] = tmp_r[j];
        k++;
        j++;
    }
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; //
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {4, 3, 6, 10, 1, 2, 11, 100};
    print_arr(arr, 8);
    merge_sort(arr, 0, 8);
    print_arr(arr, 8);
    return 0;
}
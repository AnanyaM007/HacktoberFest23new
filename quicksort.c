#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot, i, temp, j;
    pivot = arr[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int n, arr[50], k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    quickSort(arr, 0, n - 1);
    printf("The %dth largest element is: %d", k, arr[n - k]);
    return 0;
}

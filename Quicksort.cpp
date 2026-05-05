#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) // Received array, low index and high index from quickSort function
{
    int pivot = arr[high]; // Initialized pivot variable and the value of high index of received array will be the value of pivot

    int i, j;                                 // Initialized index variable i and j
    for (i = low - 1, j = low; j < high; j++) // Written loop with condition, j less than high
    {
        if (arr[j] < pivot) // If the value of j-th index is less than pivot, these statements will execute
        {
            i++;                  // The value of i will be increased by one
            swap(arr[i], arr[j]); // The value of i-th index and j-th index will be swapped with each other
        }
    }

    swap(arr[high], arr[i + 1]); // The value of high index and (i + 1)-th index will be swapped with each other
    return i + 1;                // This function will return the sum of (i + 1)
}

void quickSort(int arr[], int low, int high) // Received array, low and high index from main function
{
    if (low >= high) // If the low index is greater or equal to high index, these statement will execut
    {
        return; // quickSort function will be returned to the calling function
    }

    int p = partition(arr, low, high); // Initialized p varaible to receive the value from partition function
    quickSort(arr, low, p - 1);        // quickSort will call itself and pass array, low index and  (p - 1) index as arguments
    quickSort(arr, p + 1, high);       // quickSort will call itself and pass array, (p + 1) index and high index as arguments
}

int main()
{
    int arraySize;    // Initialized a variable named arraySize to take input of array size
    cin >> arraySize; // Taken input from the user

    int arr[arraySize];                 // Initialized an array named arr and the size of this array is the value of arraySize variable
    for (int i = 0; i < arraySize; i++) // Written a loop to take input of the entire array
    {
        cin >> arr[i]; // Taken input of each element one by one in every iteration
    }

    quickSort(arr, 0, arraySize - 1); // Called quickSort function and passed array, low index value and high index value as arguments

    for (int i = 0; i < arraySize; i++) // Written loop to print the sorted array
    {
        cout << arr[i] << " "; // Printed each element of the array one by one in every iteration
    }

    return 0;
}

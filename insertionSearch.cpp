#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int arraySize) // Received array and array size from main function
{
    int item; // Initialized variable named item for storing current value

    for (int i = 0; i < arraySize; i++) // Written loop to sort the array
    {
        item = arr[i]; // The value of item will be the value of index i
        int j = i - 1; // Initialized variable named j for nested loop and set the value of j to the previous of i

        while (j >= 0 && arr[j] > item) // Written nested loop with conditions, if j is greater or equal of 0 and the value of j-th index is greater than item variable
        {
            arr[j + 1] = arr[j]; // The value of next j-th index will be the current j-th index's value
            j = j - 1;           // The value of j will be changed to one value less than the current of j
        }

        arr[j + 1] = item; // After breaking the nested loop, the value of the next index of current j will be the value of current item variable's value
    }
}

int main()
{
    int arraySize;    // Initialized a variable named arraySize to take input of array size
    cin >> arraySize; // Taken input from the user

    int arr[arraySize];                 // Initialized an array named arr of the size - arraySize
    for (int i = 0; i < arraySize; i++) // Written a loop to take input of the entire array
    {
        cin >> arr[i]; // Taken input of each element one by one in every iteration
    }

    insertionSort(arr, arraySize); // Called insertionSort function and passed array and array size to the function to sort using insertion sort algorithm

    for (int i = 0; i < arraySize; i++) // Written loop to print the sorted array
    {
        cout << arr[i] << " "; // Printed each element of the array one by one in every iteration
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int arraySize) // Received array and array size from main function
{
    for (int i = 0; i < arraySize - 1; i++) // Written loop to sort the array
    {
        int minIndex = i; // Initialized minIndex variable to store the index of minimum value and stored value of the variable i

        for (int j = i + 1; j < arraySize; j++) // Written nested loop for comparison
        {
            if (arr[j] < arr[minIndex]) // Checking if the value of j-th index is less than the value of current minimum index
            {
                minIndex = j; // If the value of j-th index is less than the value of curren minimum index, the current minimum index will be the index j
            }
        }

        if (minIndex != i) // Checking if the current minimum index and the index i same or not
        {
            swap(arr[i], arr[minIndex]); // If the current minimum index and the index i is not same, the value of index i and the value of current minimum index will be swapped
        }
    }
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

    selectionSort(arr, arraySize); // Called selectionSort function and passed array and array size to the function to sort using selection sort algorithm

    for (int i = 0; i < arraySize; i++) // Written loop to print the sorted array
    {
        cout << arr[i] << " "; // Printed each element of the array one by one in every iteration
    }

    return 0;
}

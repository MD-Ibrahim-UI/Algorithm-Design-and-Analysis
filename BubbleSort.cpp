#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int arraySize) // Received array and array size from main function
{
    for (int i = 0; i < arraySize; i++) // Outer loop from index 0 to arraySize - 1
    {
        for (int j = 0; j < arraySize - i - 1; j++) // Inner loop from index 0 to arraySize - i - 1
        {
            if (arr[j] > arr[j + 1]) // If the left element is greater than the right element, values will be swappped
            {
                swap(arr[j], arr[j + 1]); // Values are swapped usgin built in swap function
            }
        }
    }
}

int main()
{
    int arraySize;    // Declared variable to take input of array size
    cin >> arraySize; // Taken input of array size from user

    int arr[arraySize];                 // Declared array of the size which user has given as input
    for (int i = 0; i < arraySize; i++) // Writtern for loop to take input of array elements
    {
        cin >> arr[i]; // Taken array element as input
    }

    bubbleSort(arr, arraySize); // Called bubble sort function to sort the array

    for (int i = 0; i < arraySize; i++) // Written for loop to print every element of the array
    {
        cout << arr[i] << " "; // Printed every element of the array
    }

    return 0;
}

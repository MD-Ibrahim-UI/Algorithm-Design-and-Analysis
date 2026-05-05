#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) // Received array, left index, mid index, right index from divide function
{
    int leftSize = mid - left + 1; // Initialized size of left array as leftSize variable and set the size of left array as one value greater than the difference of mid index and left index
    int rightSize = right - mid;   // Initialized size of right array as rightSize variable and set the size of right array as the difference of right and mid index

    int leftArray[leftSize];   // Initialized left array of size leftSize
    int rightArray[rightSize]; // Initialzied right array of size rightSize

    for (int i = 0; i < leftSize; i++)
    {                                 // Written loop for storing value in the left array
        leftArray[i] = arr[left + i]; // The value of i-th index in left array will be the value of (left + i)th index value of received array
    }

    for (int i = 0; i < rightSize; i++)
    {                                     // Written loop for storing value in the right array
        rightArray[i] = arr[mid + 1 + i]; // The value of i-th index in right array will be the value of (mid + 1 + i)th index value of received array
    }

    int leftIndex = 0;  // Initialized left index varialbe named leftIndex
    int rightIndex = 0; // Initialized right index variable named rightIndex

    int newIndex; // Initialized newIndex variable to store index

    for (newIndex = left; leftIndex < leftSize && rightIndex < rightSize; newIndex++)
    { // Written loop with conditions, leftIndex < leftSize and rightIndex < rightSize
        if (leftArray[leftIndex] < rightArray[rightIndex])
        {                                         // If the value of left index in the left array is less than the value of right index in right array, these statements will be executed
            arr[newIndex] = leftArray[leftIndex]; // The value of newIndex in the received array will be the value of left index in the left array
            leftIndex += 1;                       // The value of left index will increase by one
        }
        else
        {                                           // If the value of left index in the left array is greater than the value of right index in right array, these statements will be executed
            arr[newIndex] = rightArray[rightIndex]; // The value of newIndex in the received array will be the value of right index in the right array
            rightIndex += 1;                        // The value of right index will increase by one
        }
    }

    while (leftIndex < leftSize)
    {                                         // Written loop with condition, leftIndex < leftSize
        arr[newIndex] = leftArray[leftIndex]; // The value of newIndex in the received array will be the value of left index in the left array
        leftIndex += 1;                       // The value of left index will increase by one
        newIndex += 1;                        // The value of newIndex wil increase by one
    }

    while (rightIndex < rightSize)
    {                                           // Written loop with condition, rightIndex < rightSize
        arr[newIndex] = rightArray[rightIndex]; // The value of newIndex in the received array will be the value of right index in the right array
        rightIndex += 1;                        // The value of right index will increase by one
        newIndex += 1;                          // The value of newIndex wil increase by one
    }
}

void divide(int arr[], int left, int right)
{ // Received array, left index, mid index, right index from main function
    if (left >= right)
    {           // Checking if the left index is greater or equal than the right index
        return; // If the left index is greater or equal than the right index, this function will return to the calling function
    }

    int mid = left + (right - left) / 2; // Initialized mid varialbe and stored mid value

    divide(arr, left, mid);       // divide function is called and passed array, left index and mid index passed as argument
    divide(arr, mid + 1, right);  // divide function is called and passed array, (mid + 1) index, right index as argument
    merge(arr, left, mid, right); // merge function is called and passed array, left index, mid index, right index as argument
}

int main()
{
    int arraySize;    // Initialized a variable named arraySize to take input of array size
    cin >> arraySize; // Taken input from the user

    int arr[arraySize]; // Initialized an array named arr and the size of this array is the value of arraySize variable
    for (int i = 0; i < arraySize; i++)
    {                  // Written a loop to take input of the entire array
        cin >> arr[i]; // Taken input of each element one by one in every iteration
    }

    divide(arr, 0, arraySize); // Called divide function and passed array and array size to the function to divide the array and inside the divide function, merge function is called to merge the array

    for (int i = 0; i < arraySize; i++)
    {                          // Written loop to print the sorted array
        cout << arr[i] << " "; // Printed each element of the array one by one in every iteration
    }

    return 0;
}

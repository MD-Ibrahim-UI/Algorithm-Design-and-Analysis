#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;    // Declared a variable named a
    cin >> a; // Taken input of a

    int b[a]; // Declared an array of size a
    for (int i = 0; i < a; i++)
    { // Taken input from user
        cin >> b[i];
    }

    int x;    // Declared varible named x
    cin >> x; // Taken input of x

    sort(b, b + a); // Sorted array to ascending order

    int leftIndex = 0;      // Initialized left index
    int rightIndex = a - 1; // Initialized right Index
    
    int index = -1;  // Initialized index variable

    while (leftIndex <= rightIndex)
    {                                           // Checks if left index is less than or equal to right index
        int mid = (leftIndex + rightIndex) / 2; // Calculates mid index

        if (b[mid] == x)
        {                // Checks if the value of mid index is equal to x
            index = mid; // The index will be mid
            rightIndex = mid - 1; // The right index will be previous index of mid
        }
        else if (b[mid] > x)
        {                         // Checks if the value of mid is greater than x
            rightIndex = mid - 1; // The right index will be the previous index of mid
        }
        else
        {                        // The value of mid is less than the x
            leftIndex = mid + 1; // the left index will be the next index of mid
        }
    }

    if (index == -1)
    { // If the value of flag is true, the output will be Yes
        cout << "Element isn't found\n";
    }
    else
    { // If the value of flag is false, the output will be No
        cout << "The leftmost index of " << x << " is " << index;
    }

    return 0;
}
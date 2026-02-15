#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;    // Declared a variable named a
    cin >> a; // Taken input of a

    int b[a]; // Declared an array of size a
    for (int i = 0; i < a; i++)
    { // Taken input from
        cin >> b[i];
    }

    int x;    // Declared varible named x
    cin >> x; // Taken input of x

    bool flag = false; // Declared variable to track x
    for (int i = 0; i < a; i++)
    { // Traversing the entire array to find x
        if (b[i] == x)
        {                // Checking if the value of this index is x
            flag = true; // If the current number is x, the value of flag will be true
            break;       // If the number is found, the loop breaks
        }
    }

    if (flag == true)
    { // If the value of flag is true, the output will be Yes
        cout << "Yes\n";
    }
    else
    { // If the value of flag is false, the output will be No
        cout << "No\n";
    }

    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 45, 6, 7, 8};
    for (auto &x : arr) // It affects the value
    {
        //cout << x << endl;
        ++x;
    }

    // for (auto x : arr)
    // {
    //     //cout << x << endl;
    //     ++x;
    // }
    for (auto x : arr)
    {
        cout << x << endl;
    }
    return 0; 
}
// make names from std visible without std:: (§2.4.2) // square a double precision floating-point number
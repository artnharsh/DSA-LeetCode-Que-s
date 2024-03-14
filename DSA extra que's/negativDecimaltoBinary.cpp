#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter a negative decimal number: ";
    cin >> num;
    
    cout << "Binary representation: ";
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        cout << bit;
    }
    
    return 0;
}

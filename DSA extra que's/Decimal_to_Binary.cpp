#include<iostream>
using namespace std;

int main(){
    int n,i = 1;
    cin >> n;
    int bit;
    int ans = 0;
    while(n > 0){
        bit = n & 1; //bitwise AND operation to get the last set bit in n. If it is 0 then no set bits are left else there is at least one set bit
        ans = (bit * (1 * i)) + ans;
        n >>= 1; //right shift
        i *= 10;
    }
    cout<<ans;
    return 0;
}
    

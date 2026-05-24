#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;cin>>n;
    int val_n = 1;
    int val_np1 = 0;

    for(int t=n-1;t>=0;t--)
    {
        int new_val = val_n + val_np1;
        val_np1= val_n;
        val_n= new_val;
    }
    return val_n;
}
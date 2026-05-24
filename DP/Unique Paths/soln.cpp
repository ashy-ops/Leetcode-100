#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long nCr(long long n, long long r)
    {
        long long ans = 1;
        for(int i=0;i<r;i++)
        {
            ans *= (n-i);
            ans /= (i+1);
        }
        return ans;
    }

    int uniquePaths(int m, int n) {
        long long  z = m+n-2;
        long long r =  min(n-1,m-1);
        return nCr(z,r);
    }
};
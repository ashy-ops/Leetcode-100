#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int cmin=1,cmax=1;
        int ans =INT_MIN;
        for(int i=0;i<a.size();i++)
        {
            ans = max(ans,a[i]);
            if(a[i]==0)
            {
                cmin=1;
                cmax=1;
            }
            else
            {
                int temp = cmax;
                cmax= max(cmin*a[i],cmax*a[i]);
                cmax = max(cmax,a[i]);

                cmin= min(cmin*a[i],temp*a[i]);
                cmin = min(cmin,a[i]);

                ans = max(ans,cmax);
                }
        }

        return ans;

    }
};
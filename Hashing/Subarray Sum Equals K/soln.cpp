#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k)
    {

        int n = nums.size();
        
        unordered_map<int,int> hash;        
        int ans = 0;
        int pref= 0;
        hash[pref]++;

        for(int i=0;i<n;i++)
        {
            int cur_pref = nums[i] +pref;
            if(hash.count(cur_pref-k)!=0) ans+= hash[cur_pref-k];
            hash[cur_pref]++;
            pref=cur_pref;
        }

        return ans;
    }
};




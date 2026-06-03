#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            int jumps = nums[i];
            if(i+nums[i]>=n-1){
                ans++;
                break;
            }
            
            int max_jumps = 0;
            int next_start_index = -1;
            while(jumps--)
            {
                i++;
                if(nums[i]+i>max_jumps)
                {
                    max_jumps=nums[i]+i;
                    next_start_index = i;
                }
            }
            ans++;
            i = next_start_index-1;    //adjustment
        }
        return ans; 
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index_reach =0;
        int n = nums.size();

        for(int i=0;i<n-1;i++) //looping till n-1!
        {
            max_index_reach = max(max_index_reach,nums[i]+i);
            if(i==max_index_reach) return false;
        }

        return true;
    }
};
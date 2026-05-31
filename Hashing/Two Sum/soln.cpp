#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            int rem = target-nums[i];
            if(hash.count(rem)!=0 && hash[rem]!=i) return  {i,hash[rem]};
            hash[nums[i]] =i;

        }
        return {};
    }
};

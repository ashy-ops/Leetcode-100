#include <bits/stdc++.h>
using namespace std;

/*

Options-Take or not take,if take you go to next next, otherwise if not take then you go to next

dp[0] --> max(1+f(2),  f(1))
dp[1] ---> max(1+f(3), f(2))

base case if(i>=nums.size()) return 0;

*/


class Solution {
public:

    int solve(int i, vector<int>&dp,vector<int>& nums)
    {
        if(i>=nums.size()) return 0; 
        else if(dp[i]!=-1) return dp[i];
        else return dp[i] = max(solve(i+1,dp,nums),nums[i]+solve(i+2,dp,nums));
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,dp,nums);
    }
};

/*

In this solution, we are using tabulation method to solve the problem. 
We are filling the dp array from the end to the beginning.
So the recursion stack space that was allocate is gone.

*/




class Solution2 {
public:

    int solve(int i, vector<int>&dp,vector<int>& nums)
    {
        if(i>=nums.size()) return 0; 
        else if(dp[i]!=-1) return dp[i];
        else return dp[i] = max(solve(i+1,dp,nums),nums[i]+solve(i+2,dp,nums));
    }

    int rob(vector<int>& nums)
    {
        vector<int> dp(nums.size()+2,-1);
        dp[nums.size()]=0;
        dp[nums.size()+1] = 0;

        for(int i=nums.size()-1;i>=0;i--)
        {
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);    
        }
        return dp[0];
    }
};

/*
In this solution we have optimized the space complexity to O(1) by using two
variables to store the previous two values of the dp array.
*/
class Solution3{
public:
    int rob(vector<int>& nums)
    {
        int prev = 0;
        int prev2 = 0;

        for(int i=nums.size()-1;i>=0;i--)
        {
            int cur = max(nums[i]+prev2,prev);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
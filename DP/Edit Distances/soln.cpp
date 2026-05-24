#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static inline int min3(vector<vector<int>> &dp, int i,int j)
    {
        int min1 = min(dp[i+1][j],dp[i][j+1]);
        return min(min1,dp[i+1][j+1]);
    }

    int minDistance(string word1, string word2) {
        int m = word1.size()+1;
        int n = word2.size()+1;
        
        vector<vector<int>> dp(n,vector<int> (m));
        
        for(int i=0;i<m;i++) dp[n-1][i]= m-1-i;
        for(int i=0;i<n;i++) dp[i][m-1] = n-1-i;



        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(word1[j]==word2[i]) dp[i][j] = dp[i+1][j+1];
                else
                {

                    dp[i][j] = 1 + min3(dp,i,j);
                }
            }
        }     
        return dp[0][0];   
    }

};

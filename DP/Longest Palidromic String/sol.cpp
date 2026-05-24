#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1001][1001] = {false};
        int n = s.size();

        pair<int,int> ans = {0,0};
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
            if(i+1<n&& s[i]==s[i+1]){
                dp[i][i+1]=true;
                ans = {i,i+1};
            }
        }


        for(int w=2;w<n;w++)
        {
            for(int i=0;i+w<n;i++)
            {
                if(s[i]==s[i+w] && dp[i+1][i+w-1]==1)
                {
                    ans = {i,i+w};
                    dp[i][i+w] = true;
                }
            }
        }
        return s.substr(ans.first,ans.second-ans.first+1);

    }
};

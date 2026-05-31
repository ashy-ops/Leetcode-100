#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> ele;
        for(auto &i:nums) ele.insert(i);
        int ans = 0;
        int temp = 0;
        int cons = -1;


        for(auto &i:ele)
        {
            if(temp ==0)
            {
                temp++;
                cons = i;
            }
            
            else
            {
                if(cons+1==i){
                    cons++;
                    temp++;
                }
                else
                {
                    ans=max(temp,ans);
                    temp=1;
                    cons=i;
                }
            }
        }
        ans = max(temp,ans);
        return ans;
    }
};


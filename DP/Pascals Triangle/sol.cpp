#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> rp = {1};
        vector<vector<int>> ans= {rp};

        for(int i=2;i<=numRows;i++)
        {
            vector<int> nr = {1};
            
            for(int j=1;j<i-1;j++) nr.push_back(rp[j] + rp[j-1]);

            nr.push_back(1);
            ans.push_back(nr);
            rp = std::move(nr);
        }

        return ans;
    }
};
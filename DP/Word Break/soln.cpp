#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        set<string> dict;
        for (auto& i : wordDict)
            dict.insert(i);

        vector<bool> dp(sz + 1, false);
        dp[0] = true;

        for (int i = 0; i < sz; i++) {
            for (int j = i; j >= 0; j--) {
                int len = i - j + 1;
                string subs = s.substr(j, len);
                if (dict.count(subs) != 0 && dp[j] == true) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }

        return dp[sz];
    }
};
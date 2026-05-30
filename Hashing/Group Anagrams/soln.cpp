#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash;
        for(auto &s:strs)
        {
            auto s_sorted = s;
            sort(s_sorted.begin(),s_sorted.end());
            hash[s_sorted].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &p:hash)
        {
            vector<string> anagrams;
            for(auto s:p.second) anagrams.push_back(s);
            ans.push_back(anagrams);
        }

        return ans;
    }
};
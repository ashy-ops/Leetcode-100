#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> track;
        vector<int> parts;
        int n = s.size();

        for(int i=0;i<n;i++) track[s[i]] = i;

        int partition = 0;
        int size = 0;
        for(int i=0;i<n;i++)
        {
            size++;
            partition = max(partition,track[s[i]]);
            if(partition==i)
            {
                parts.push_back(size);
                partition = 0;
                size = 0;
            }

        }

        return parts;
    }
};
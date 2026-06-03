#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline bool match(char top,char n)
    {
        switch(n)
        {
            case '}':
                if(top=='{') return true;
                break;
            case ')':
                if(top=='(') return true;
                break;
            case ']':
                if(top=='[') return true;
                break;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(st.empty()) st.push(c);
            else if(match(st.top(),c)) st.pop();
            else st.push(c);
        }
        return st.empty();
    }
};
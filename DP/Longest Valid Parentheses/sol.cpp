#include<bits/stdc++.h>
using namespace std;

//Soln-1
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> container;
        container.push(-1);
        int ans = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')  container.push(i);
            else 
            {
                container.pop();
                if(container.empty()) container.push(i);
                else ans = max(ans,i-container.top());
                
            }
        }
        return ans;
    }
};

//soln-2
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> container;
        int invalid_last = -1;
        int ans = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')  container.push(i);
            else if(s[i]==')')
            {
                if(container.empty()){
                    invalid_last = i;
                }
                else
                {
                    container.pop();
                    if(container.empty()) ans = max(ans,i-invalid_last);
                    else ans = max(ans,i-container.top());
                }
            }
        }

        return ans;
    }
};
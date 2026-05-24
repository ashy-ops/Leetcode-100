Initial Approach-

Observations- If treating '(' as +1 and ')' -1 at every point for the longest substring
the continuous sum should only be +ve or 0, if it becomes negative at any point its invalid
and if it doesn't become 0 at any point its invalid again.

So you only start from wherever there is a +1 it creates a seperate branch.

```cpp
class Solution {
public:
    int solve(string &s,int i)
    {
        int longest = 0;
        int pairs = 0;
        int  sum = 1;

        for(int j=i+1;j<s.size();j++)
        {
            if(s[j]=='(') sum++;
            else
            {
                sum--;
                pairs+=2;
                if(sum==0) longest = pairs;
                else if(sum<0) break;
            }
        }
        return longest;
    }

    int longestValidParentheses(string s){
        int ans = 0;
        int len=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                ans = max(ans,solve(s,i));
            }
        }
        return ans;
    }
};
```  

Problem with this is that its O(n^2) which is not very ideal.

# 2.) Stack approach-
Basically we keep a stack. Stacks are in general a good approach for matching pair type of questions.

```cpp
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
```
Basically I keep a invalid_last variable and keep it as -1.
What it basically represents is the last index from which longest substrings are valid onwards.

If I encounter a `(` I push it to the stack.

If I encounter a `)` I check two things.
If the stack is already empty- I just set last invalid to =i
because all the substrings will be valid thereafter.

Now if the stack is not empty(aka there are `(` indexes in the stack)
Now Firstly I pop the top most element.
If the stack becomes empty this tells me that from the last invalid to all the way upto here all the pairs have been paired. Hence I do `ans = max(ans,i-invalid_last)`
Do dry run on `(()()`

If the stack does not become empty after poping it means all the pairs have not been paired yet hence the last point from where the substrings are valid is the last unpaird `(` bracket. It kinda acts like invalid_last only, but invalid_last here specifically is assigned for `)`.
eg- `((())` or `())`

Alternatively I can insert -1 in the stack directly and modify the code a little to satisfy the conditions.
```cpp
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
```

I took the starting point as 0, and moved up till I hit the two base cases
```cpp
if(t==n) return 1;
else if(t>n) return 0;
```
Each path that leads to t == n leads to an addition in the solution.

To convert it to tabular form, since my dp formula is
dp(n) =dp(n+1) + dp(n+2)

and from base case I can infer that f(n) = 1
and f(n+1) = 0
I iterate from t=n-1 till t = 0
and t =0 gives the solution.


## Alternatively can be done as simple fibonaaci as well.

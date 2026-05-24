Basically we break down the subproblem into that can
we make a valid breakage.
Lets take the example- aaaaaaaa
dict=[aaa,aaaa]

now
    0 1 2 3 4 5 6 7
T   a a a a a a a a
We treat the base case as T
now we start from 0, can we make a valid segemnt?NO
hence we mark dp[1] = F
From 1-a no,can aa(0-1) NO, hence F
dp[2] =F

not at i=2,we check downward,
aaa (0-3 is valid),and dp[1](aka before the 0th i is True)
hence the condition is that
dp[i] should have a valid segment, and the point where we are introducing breakage, should have a valid segment present before it(in sense it can have multiple or be valid in itself).

So on and we get our soln

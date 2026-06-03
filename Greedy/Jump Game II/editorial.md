Basically each index has a range of elements it allows us to jump to.
Now suppose- 2,3,0,1,4
2 allows us to jump till 3 and 0
So we check at those indexes which index gives us the next max possible range to jump to!
in this case from 3, it covers index 1 to index last
0 is a dead end.
hence that is how I have approached the solution.
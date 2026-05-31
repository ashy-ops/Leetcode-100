Basically,sincewe aretalking about subarray, its alwaysc contigious

take this example
1 1 1 3 3 4
If I make a prefix sum->
1 2 3 6 9 13

now for each position if I take like this suppose 1 1 1 3 for k=3

1 1 1 3
it sums to x
now if I want a subarray that sums up to k
there should be a prefix sum which sums upto x-k
1 1 1 3
1 2 3 6

at 3
3-3 = 0(aka it exists by itself, but we still store 0 as a prefix value in hash)

divides it in 1 1 1 ,"", so this gives us 1 1 1 as an answer.

then when we move to 3,
6-3=3
hence it divides 1,1,1 and 3
but 1,1,1 has already been counted, hence ans+=1
hence final answer is 1+1=2


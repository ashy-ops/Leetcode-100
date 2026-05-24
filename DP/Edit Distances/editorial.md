Think of it in this way,
we compare pointer by pointer in each position.
If two characters are equal at a position then whats the answer for minium to converting word1 to word2?
It is the ans of the next two characters for both (aka i+1 and j+1) right!
So this is the sub problem.

Now lets say if they are not equal, then in that case, we try every possible thing.
we can delete a character,-i+1,j(pointer for word1 moves)
we can insert a character,i,j+1(pointer for word2 moves)
we can replace a character,i+1,j+1 (pointer for both move)

Hence we tabulate it.
Now the base cases are, if one of the pointer reaches the end, then the amount of moves taken to make it equal to the other is exactly the word length of the other word

   h o r s e    <---i
r  3 3 2 3 3 3 
o  3 2 2 2 2 2 
s  4 3 2 1 1 1 
   5 4 3 2 1 0 
^
|
j pointer
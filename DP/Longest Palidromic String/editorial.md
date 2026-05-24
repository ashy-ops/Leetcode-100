Thinking of it in smaller chunks. 
Single characters are always palindrome.
Double characters will only be palindrome if they are same.
Triple will be same if the middle(aka excluding the ends) is a palindrome, hence this is what we memoize in a 2D tabular DP.
Also use bool for storing a singular state(save a lot of memory,can be represented as a bit whereas an int is represtend as 32bit for each index aka 32x) 
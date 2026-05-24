Basically due to the constrains we can only go n-1 times right and m-1 times left.

So basically we can choose that in any order we want, which gives us (n+m-2)! and since there are n-1 and m-1 duplicate values we divide by them.

Now treating n+m-2 = z, m-1 or n-1 can be written as z-r where r can be m-1 or n-1.
Hence it is basically zCr.

To calculate zCr we just write a simple function in such a way that ensures proper division with no fractions.

See this, firstly brute force is that, we generate all
possible subsequences and then find maximum product, in O(n^2) time complexity.

What is however better is that, we observe.
Even if product goes negative, if somewhere even number of negatives are included,
that negative becomes positive.

If all positive, then include all.
If even negatives include all.
If odd negative you break around those odd negatives.
If somewhere 0 break there and you treat each breakage as a seperate array and find their max with the above conditions.


Hence we keep track of a max and min. At each iteration,we update curmax, and curmin.
and treat ans as max of prev and new cmax.

Soln refered for understanding-https://www.youtube.com/watch?v=lXVy6YWFcRM


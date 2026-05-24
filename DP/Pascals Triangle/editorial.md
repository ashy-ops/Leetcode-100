In each row , the elements between 1 to row_index-1 are the sum of the jth index in the previous row and the j-1th index.

To make the operation faster and deal with dangling pointers I used rp = std::move(nr)
as if I did np=rp, it will copy the values which is very slow.

**Alternatively I could have set rp = ans[i-1] inside the for loop, won't have to use even move in that case.**



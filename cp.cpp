#include <bits/stdc++.h>
using namespace std;

/*
-Unusual square of an nxn square matrix is 1r*1c+2r*2c+3r*3c+....nthR*nthC
- q queries
-1.)given a row index, flip all values in ith row
-2.)given a col index, flip all values in ith col
-3.)print the unsual square
Flipping ith row causes the ith index of each col to flip
Flipping ith col causes the ith index of each row to flip

*/

static inline void flip(int &i)
{
    i = i^1;
}

void print_answer(set<int> fr,set<int>fc,vector<vector<int>> &mat)
{
    int ans = 0;
    int n = mat.size();
    for(int i=0;i<n;i++)
    {
        int ans_temp;
        for(int j=0;j<n;j++)
        {
            //i represents the ith row and ith col
            //j represents the index of the ith row or ith col
            int rv = mat[i][j];
            int cv = mat[j][i];
            if(fr.count(i)!=0) flip(rv);
            if(fc.count(j)!=0) flip(cv);
            
            if(fr.count(j)!=0) flip(cv);
            if(fc.count(i)!=0) flip(rv);
            ans_temp+= rv*cv;
        }
        ans += ans_temp%2;
    }
    ans = ans%2;
    cout<<ans;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(auto &i:mat) for(auto &j:i) cin>>j;

    int q;cin>>q;
    set<int> fliped_rows;
    set<int> fliped_cols;
    while(q--)
    {
        int query;cin>>query;
        int val1 = query/10;
        int val2 = query%10;
        val2--; //to bring 0 based indexing!

        switch (val1)
        {
        case 0:
            print_answer(fliped_rows,fliped_cols,mat);
            break;
        case 1:
            /*flip row*/
            if(fliped_rows.count(val2)==0) fliped_rows.insert(val2);
            else fliped_rows.erase(val2);
            break;
        case 2:
            /*flip col*/
            if(fliped_cols.count(val2)==0) fliped_cols.insert(val2);
            else fliped_cols.erase(val2);
            break;
        }
    }
}
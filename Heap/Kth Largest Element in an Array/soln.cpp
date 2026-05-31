#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    void heapify(vector<int>&nums,int i, int n) //min heap
    {
        while(true)
        {
            int leftchild = 2*i+1;
            int rightchild =leftchild+1;

            int smallest = i;

            if(leftchild<n && nums[smallest]>nums[leftchild]) smallest = leftchild;
            if(rightchild<n && nums[smallest]>nums[rightchild]) smallest = rightchild;

            if(smallest !=i)
            {
                swap(nums[smallest],nums[i]);
                i = smallest;
            }
            else return;
        }
    }
        void heapSort(vector<int> &nums,int n)
        {
            vector<int> arr;
            while(n>0)
            {
                swap(nums[0],nums[n-1]);
                n--;
                heapify(nums,0,n);
            }
        }
    int findKthLargest(vector<int>& nums, int k)
    {
        int n=nums.size();
        for(int i=n/2-1; i>=0;i--)heapify(nums,i,n);
        heapSort(nums,n);
        return nums[k-1];
    }
};
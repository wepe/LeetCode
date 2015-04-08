##1、题目
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]. 


##2、wepon的解法
###2.1 解析

遍历一遍，首先找到与A[0]不等的，放到A[1]，再找与A[1]不等的，放到A[2]，以此类推。如果去找 “相等”的，操作起来麻烦一点。

###2.2 代码

**C++**
    
    class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n==0) return 0;
            int m=0;
            for(int i=1;i<n;i++)
               {
                   if(A[m]!=A[i])
                     {
                       m++;
                       A[m]=A[i];
                     }
               } 
            return m+1;
        }
    };
##1、题目
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 

##2、wepon的解法
###2.1 解析
与  [26.Remove Duplicates from Sorted Array]()  这道题不同，题目要求允许每个数最多重复两次，怎么办？可以设置一个标志位flag用于标记。

###2.2 代码

**C++**

    class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n==0)  return 0;
            int flag=1;      //标记变量，表示重复的个数
            int index=0;
            for(int i=1;i<n;i++)
            {
            if(A[index]==A[i] && flag==1)
              { A[++index]=A[i];  flag=2;}
            else if(A[index]!=A[i])
              { A[++index]=A[i];  flag=1;}
            }
            return index+1;    //下标加1  表个数
        }
    };
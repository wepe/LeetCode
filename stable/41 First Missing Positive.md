##1、题目

 Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 

##2、wepon的解法
###2.1 解析

注意，[6,4,5]缺的第一个是1，[1,2,3]缺的第一个是4。多考虑几个测试用例，有助于自己对题目的理解。

本题我想到的第一种是用哈希表的方法，思路如下面代码方法一中所述，非常简单，当然，空间复杂度O(n)，不符合要求。第二种方法，利用桶排序的思想，交换数组元素，使得数组中第i位存放的数值为(i+1)，即当A[i]!=i+1时，交换A[i]和A[A[i]-1]（直到没法交换为止，什么情况才算是没法交换？当A[i]<=0或A[i]>n时，A[i]-1就超出了数组边界，此时没法交换，当A[i]==A[A[i]-1]时，不用交换，也不能交换，否则造成程序死循环）。最后再判断数组中的一个A[i]不等于i+1的，返回i+1。

###2.2 代码

**C++**

    //哈希表法
    class Solution {
    public:
        /*
        建立一个哈希表Map<int,bool>，遍历一轮，将数组中有出现的数字（忽略负数）作为key，其val置为true，并且在这一轮遍历中，记下最小的数minnum
        如果minnum不为0和1，则缺少的第一个正数就是1
        其他情况，则从minnum开始，在哈希表中查找是否有该数,有的话，minnum++并继续查找，直到在哈希表中找不到minnum，输出该数
        */
        int firstMissingPositive(int A[], int n) {
          //  if(n==0) return 1;
            map<int,bool> Map;
            int minnum=1;
            for(int i=0;i<n;i++)
            {
                if(A[i]>=0) 
                {
                Map[A[i]]=true;
                minnum=minnum>A[i]?A[i]:minnum;
                }
            }
            if(minnum!=1&&minnum!=0) return 1;
            while(Map.find(minnum)!=Map.end()) minnum++;
            return minnum; 
        }
    };
    
    
    
    //桶排序的思想
    class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
          bucket_sort(A,n);
          for(int i=0;i<n;i++)
          {if(A[i]!=i+1)   return i+1;}
          return n+1;
        }
    private:
         void bucket_sort(int A[],int n)
         {
             for(int i=0;i<n;i++)
               while(A[i]!=i+1)
               {   
                   if(A[i]<=0 || A[i]>n || A[i]==A[A[i]-1] ) break;  //这三种情况都不能swap
                   swap(A[i],A[A[i]-1]);
               }
         }
    };

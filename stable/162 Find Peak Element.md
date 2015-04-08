##1、题目

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2



##2、wepon的解法
###2.1 解析
###2.2 代码

**C++**

    //linear scan of array,O(n) time complexity 
    class Solution {
    public:
        int findPeakElement(const vector<int> &num) {
             int len=num.size();
             for(int i=1;i<len-1;i++){
                 if(num[i]>num[i+1]&&num[i]>num[i-1]){
                     return i;
                 }
             }
             if(num[0]>num[1]) return 0;
             if(num[len-1]>num[len-2]) return len-1;
        }
    };
    
    //Divide and Conquer,O(logn) time complexity
    class Solution {
    public:
        int findPeakElement(const vector<int> &num) {
             return findPeakElement(num,0,num.size()-1);
        }
    private:
        int findPeakElement(const vector<int> &num,int start,int end){
             if (start==end) return start;
             if(end-start==1) return num[start]>num[end]?start:end;
             int mid=(end+start)/2;
             if(num[mid]>num[mid-1]&&num[mid]>num[mid+1]) return mid;
             else if(num[mid]<num[mid-1])  return findPeakElement(num,start,mid-1);
             else return findPeakElement(num,mid+1,end);
        }
    };
    
##3、有更好的解法？快来占位吧 ^_^
    
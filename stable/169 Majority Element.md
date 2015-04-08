##1、题目

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.


##2、wepon的解法
###2.1 解析

/*solutions
1、Runtime: O(n2) — Brute force solution: Check each element if it is the majority element.
2、Runtime: O(n), Space: O(n) — Hash table: Maintain a hash table of the counts of each element, then find the most common one.
3、Runtime: O(n log n) — Sorting: Find the longest contiguous identical element in the array after sorting.
4、Average runtime: O(n), Worst case runtime: Infinity — Randomization: Randomly pick an element and check if it is the majority element. If it is not, do the random pick again until you find the majority element. As the probability to pick the majority element is greater than 1/2, the expected number of attempts is < 2.
5、Runtime: O(n log n) — Divide and conquer: Divide the array into two halves, then find the majority element A in the first half and the majority element B in the second half. The global majority element must either be A or B. If A == B, then it automatically becomes the global majority element. If not, then both A and B are the candidates for the majority element, and it is suffice to check the count of occurrences for at most two candidates. The runtime complexity, T(n) = T(n/2) + 2n = O(n log n).
6、Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
If the counter is 0, we set the current candidate to x and the counter to 1.
If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
After one pass, the current candidate is the majority element. Runtime complexity = O(n).
7、Runtime: O(n) — Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number’s ith bit must be the one bit that has the greater count.

*/

###2.2 代码

**C++**

    /*
    hash table
    */
    class Solution {
    public:
        int majorityElement(vector<int> &num) {
            unordered_map<int,int> map;
            int len=num.size();
            for(int i=0;i<len;i++){
                if(map.find(num[i])==map.end()) map[num[i]]=0;
                else   map[num[i]]++;
            
                if(map[num[i]]>=len/2) return num[i];
            }
        }
    };


##3、有更好的解法？快来占位吧 ^_^

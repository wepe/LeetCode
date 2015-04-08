##1、题目
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9

Output: index1=1, index2=2 

##2、wepon的解法
###2.1 解析
###2.2 代码

**C++**

    /*
    哈希表法
    遍历一遍，存入哈希表
    再从头到尾遍历，哈希表中查询target-num[i]
    */
    class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
           unordered_map<int,int> my_map;
           vector<int> result; 
           for(int i=0; i<numbers.size(); i++)
                   my_map[numbers[i]]=i;   
           for(int i=0; i<numbers.size();i++)
                {
                  const int gap=target-numbers[i];
                  if(my_map.find(gap)!=my_map.end()  && my_map[gap]>i)   //find(),也可以用count()
                          {result.push_back(i+1); result.push_back(my_map[gap]+1); break; }
                }
           return result;
        }
    };
    
##3、有更好的解法？快来占位吧 ^_^
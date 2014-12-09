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
##1、题目

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 



##2、wepon的解法
###2.1 解析
###2.2 代码

**C++**

    class Solution {
    public:
        int titleToNumber(string s) {
            int result=0;
            int base=1;
            for(int i=s.size()-1;i>=0;i--){
                result+=(s[i]-'A'+1)*base;
                base*=26;
            }
            return result;
        }
    };
    
    
##3、有更好的解法？快来占位吧 ^_^
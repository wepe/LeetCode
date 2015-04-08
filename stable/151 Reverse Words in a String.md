##1、题目

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space. 

##2、wepon的解法
###2.1 解析
###2.2 代码

    /*
    思路：
    使用字符串输入流istringstream将字符串S读入流，然后将字符串流里的字符串按单词逐个装入容器。
    清空S，将单词反向逐个装回S
    */
    
    class Solution {
    public:
        void reverseWords(string &s) {
            istringstream istr(s);     //istr从s读取字符，以空白作为分隔符
    		vector<string> vec; 
    		string word;
    		while(istr>>word) 
    			vec.push_back(word);
    		s="";  //s清空
    		if(!vec.empty()){
    	    	for(vector<string>::iterator i=vec.end()-1;i!=vec.begin();i--)
    		    	s=s+*i+" ";
    	    	s=s+vec[0];
    		}
        }
    };
    
    
##3、有更好的解法？快来占位吧 ^_^
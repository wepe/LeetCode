##1、题目
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

##2、wepon的解法
###2.1 解析
###2.2 代码
**C++**

    string convertToTitle(int n) {
            string str;
            while(n){
                int r=n%26;
                n=n/26;
                if(r==0){   //为26的整数倍，该位设置为Z，n减掉1
                    str+='Z';
                    n--;
                }else{
                    str+=('A'+r-1);
                }
            }
            //反转
            string result;
            for(int i=str.size()-1;i>=0;i--){
                result+=str[i];
            }
            return result;
        }
    
    
    
    /*
    Another good solution,better than mine:
    string convertToTitle(int n) {
            string ans = "";
            while(n) {
                ans = string(1, ((n - 1) % 26 + 'A')) + ans;
                n = (n - 1) / 26;
            }
            return ans;
        }
    
    */
    
##3、有更好的解法？快来占位吧 ^_^
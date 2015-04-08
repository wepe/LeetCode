##1、题目

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

    0.1 < 1.1 < 1.2 < 13.37


##2、wepon的解法
###2.1 解析
###2.2 代码

**C++**
    class Solution {
    public:
        int compareVersion(string version1, string version2) {
            vector<int> result1=getInt(version1);
            vector<int> result2=getInt(version2);
            int len1=result1.size();
            int len2=result2.size();
            if(len2<len1) return -1*compareVersion(version2, version1);
            int i=0;
            while(i<len1 && result1[i]==result2[i]) i++;
            
            if(i==len1){    //str1和str2前len1位都相等，则看看str2后面的len2-len1位是否都为0即可判断它们的大小
                int j=len2-1;
                while(j >= len1){
                    if(result2[j--]!=0) return  -1;
                }
                return 0;
            }else{       //str1和str2前len1位不都相等，直接判断第i位
                if(result1[i]<result2[i]) return -1;
                else return 1;
            }
        }
    private:
    //将version字符串按'.'拆成多个，转化为整型放入容器
        vector<int> getInt(string version){
            vector<int> result;
            int len=version.size();
            int pre=0;
            for(int i=0;i<len;i++){
                if(version[i]=='.'){
                    string str(version.begin()+pre,version.begin()+i);  //注意这种初始化形式，左闭右开，即str不包括version[version.begin()+i]
                    result.push_back(stoi(str));
                    pre=i+1;
                }
            }
    		string str(version.begin()+pre,version.end());
            result.push_back(stoi(str));
            return result;
        }
    };
    
##3、有更好的解法？快来占位吧 ^_^
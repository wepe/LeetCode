/*
题目解析请参考博客：http://blog.csdn.net/u012162613/article/details/41995715
*/

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
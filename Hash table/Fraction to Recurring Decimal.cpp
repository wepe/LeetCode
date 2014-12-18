/*
题目解析请参考博客：http://blog.csdn.net/u012162613/article/details/41998617
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string result;
        if(numerator<0 ^ denominator<0 ) result+='-';   //异或，numerator<0和denominator<0仅有一个为真
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。
        long long int n=numerator,d=denominator;
        n=abs(n);d=abs(d);              
        
        result+=to_string(n/d);  //整数部分
        long long int r=n%d;    //余数r
        if(r==0) return result;
        else result+='.';
        //下面处理小数部分，用哈希表
        unordered_map<int,int> map;
        while(r){
            //检查余数r是否在哈希表中，是的话则开始循环了
            if(map.find(r)!=map.end()){
                result.insert(map[r],1,'(');   //http://www.cplusplus.com/reference/string/basic_string/insert/
                result+=')';
                break;
            }
            map[r]=result.size();    //这个余数对应于result的哪个位置
            //正常运算
            r*=10;
            result+=to_string(r/d);
            r=r%d;
        }
        return result;
    }
};
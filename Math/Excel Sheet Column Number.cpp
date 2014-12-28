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
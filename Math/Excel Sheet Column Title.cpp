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
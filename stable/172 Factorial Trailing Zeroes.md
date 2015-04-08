##1、题目

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

##2、wepon的解法

###2.1 解析
###2.2 代码
    /*
    这道题如果暴力求解，会遇到很多麻烦，13！已经超出超出INT_MAX，所以不可能先求出n！,即便你可以求出n！，但时间复杂度早已不符合要求，肯定TL。
    比较好的解法，也是目前能想到的方法，就是因数分解。对1～n每个数进行因数分解，累计每个数的分解式中的2、5的个数，每一对2、5相乘会产生一个0.
    example:
    10！=1*2*3*(2*2)*5*(2*3)*7*(2*2*2)*9*(2*5)=3628800
    2的个数累计为：num_2=8
    5的个数累计为：num_5=2
    因为5的个数为2，一共有2对2*5,所以10的阶乘10！末尾有2个0。
    */
    class Solution {
    public:
        int trailingZeroes(int n) {
            if(0==n) return 0;
            int num_2=0,num_5=0;
            while(n){
                int i=n--;
                while(!(i%2)) {num_2++;i/=2;}
                while(!(i%5)) {num_5++;i/=5;}
            }
            return num_2>num_5?num_5:num_2;
        }
    };
    
    
    /*
    上面的解法可以改进
    事实上，num_5肯定小于num_2。
    证明：
    合数：指自然数中除了能被1和本身整除外，还能被其他的数整除（不包括0)的数——>n!肯定是合数(除了1!)。
    
    质因数分解：每个合数都可以写成几个质数相乘的形式——>n!=2^x * 3^y * 5^z *.....
    
    
    对于阶乘的数来说，分解后肯定有：x>z,因此起作用的是z，即num_5
    
    */
    class Solution {
    public:
        int trailingZeroes(int n) {
            if(0==n) return 0;
            int num_5=0;
            while(n){
                int i=n--;
                while(!(i%5)) {num_5++;i/=5;}
            }
            return num_5;
        }
    };
    

##3、有更好的解法？快来占位吧 ^_^
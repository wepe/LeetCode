##1、题目

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

##2、wepon的解法
###2.1 解析
这是一道很简单的题目，考察位移操作符的使用。
题意是求给定整数的二进制表示中1的个数。我们知道，1的二进制表示是“000...0001”，仅末位为1，任何整数n与1相与，结果非0即1，比如：4的二进制表示为“0000...0100”，则1&4的结果为0；5的二进制表示为“0000...0101”，则1&5的结果为1。

利用这一点，我们可以将整数n与1相与，每相与完一次，就右移一位，因为整数有32位，所以进行32次相与操作。


###2.2 代码

**C++**

    class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int num = 0;
            for(int i=0;i<32;i++){
                num += n&1;
                n = n>>1;
            }
            return num;
        }
    };




**Python**

    class Solution:
        # @param n, an integer
        # @return an integer
        def hammingWeight(self, n):
            num = 0
            for i in range(32):
                num += n&1
                n = n>>1
            return num



##3、有更好的解法？快来占位吧 ^_^
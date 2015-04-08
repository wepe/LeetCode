##1、题目

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

##2、wepon的解法
###2.1 解析
这是一道很简单的题目。题意是给定一个整数，要求返回这个整数的二进制形式“反转”之后所得到的整数。看下面的例子，一目了然：

- 整数5的二进制表示为“000...00101”，即2^0+2^2=5

- 整数5的二进制形式反转之后为“101000..000”，得到的整数为2^31+2^29= 2684354560

也就是说，原先指数为0的，反转后指数为31；原先指数为2的，反转后指数为29....以此类推。




###2.2 代码

**C++**

    class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t result=0;
            uint32_t A[32];
            for(int i=31;i>=0;i--){
                A[31-i] = pow(2.0,i);
            }
            for(int j=0;j<32;j++){
                if(n&1){
                    result += A[j];
                }
                n = n>>1;
            }
            return result;
        }
    };



**python**

    class Solution:
        # @param n, an integer
        # @return an integer
        def reverseBits(self, n):
            table = []
            result = 0
            for i in range(32)[::-1]:
                table.append(2**i)
            for j in range(32):
                if n&1:
                    result += table[j]
                n = n>>1
            return result
            


##3、有更好的解法？快来占位吧 ^_^
"""
C++

"""

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
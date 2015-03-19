"""
python

"""
class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        num = 0
        for i in range(32):
            num += n&1
            n = n>>1
        return num


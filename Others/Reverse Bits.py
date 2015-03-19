
"""
python

"""
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
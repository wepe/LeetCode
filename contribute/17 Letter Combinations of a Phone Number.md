1、题目
Letter Combinations of a Phone Number

##2、解法

###2.1 解析
###用python中字典的方法，将电话号码的键和对应的字母存储到字典中，使用python的reduce函数和lambda一实现。

2.2 code
**python**
<pre><code>
class Solution:
    # @return a list of strings, [s1, s2]
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        if '' == digits: return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])
</code></pre>

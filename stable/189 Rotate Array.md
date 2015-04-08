##1、题目

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]



##2、wepon的解法
###2.1 解析
###2.2 代码

**Python**

    #runtime:222ms
    class Solution:
        # @param nums, a list of integer
        # @param k, num of steps
        # @return nothing, please modify the nums list in-place.
        def rotate(self, nums, k):
            length = len(nums)
            if k>=length:
                k = k-length
            for i in range(k):
                nums.insert(0,nums.pop())
    
    
    #runtime:99ms 
    class Solution:
        # @param nums, a list of integer
        # @param k, num of steps
        # @return nothing, please modify the nums list in-place.
        def rotate(self, nums, k):
            n = len(nums)
            k = k % n
            nums[:] = nums[n-k:] + nums[:n-k]


**C++**

    //O(n)time,O(n)space
    class Solution {
    public:
        void rotate(int nums[], int n, int k) {
            k = k%n;
            if(k){
                vector<int> p,q;
                for(int i=n-k;i<n;i++){
                    p.push_back(nums[i]);
                }
                for(int i=0;i<n-k;i++){
                    q.push_back(nums[i]);
                }
                for(int i=0;i<k;i++){
                    nums[i]=p[i];
                }
                for(int i=k;i<n;i++){
                    nums[i]=q[i-k];
                }
            } 
        }
    };
    
    
    //o(n)time,o(1)space
    class Solution {
    public:
        void rotate(int nums[], int n, int k) {
            int nowIndex = 0, nextIndex;
            int tmp1, tmp2 = nums[0];
            for(int j=0,i=0; j<n; j++){
                tmp1 = tmp2;
                nowIndex = (k + nowIndex) % (n);
                tmp2 = nums[nowIndex];
                nums[nowIndex] = tmp1;
                if(nowIndex == i) {
                    nowIndex = ++i;
                    tmp2 = nums[nowIndex];
                }
            }
        }
    };


##3、有更好的解法？快来占位吧 ^_^


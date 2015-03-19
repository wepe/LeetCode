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

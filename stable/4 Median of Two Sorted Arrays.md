##1、题目

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

##2、wepon的解法
###2.1 解析

**求两个已排序数组的中值，时间复杂度要求O(log(m+n))。**

这是个经典的问题，更一般的问题是：求两个已排序数组中第k大的值。

- 最笨的方法：采用插入排序（二分查找优化），假如m>n，则将n插入到m中，时间复杂度是O（n*logm）。排好序后输出第k个。

- 线性复杂度的方法：其实我们只是要找出第k大的数，所以只需要排序前面k个数，不用排完所有数。可以使用类似与merge sort的方法，设置两个指针Pa、Pb和一个计数变量num，Pa和Pb分别指向数组A和B的首位，比较二者，较小的就输出，并且指针往前移一位，num++；再比较二者，小的输出......如此迭代进行，直到num==k。 这种方法时间复杂度是O(k)；【对本题来说为O（（m+n）/2）即O(m+n)】

- O(log (m+n))方法：O（k）方法是一个一个比的，可以用更快的方法，要找到A和B数组中第k大的数，可以比较A[k/2-1]以及B[k/2-1]，假如A[k/2-1]比较小，则说明A[0]~A[k/2-1]都小于第k大的数，删除这k/2个数，得到新的A'。接下来，问题转化为求A'和B中第k/2大的数........如此循环直到k/2=1.。 由 k/2^n=1推算得这个方法的复杂度是O(logk)。【对本题来说是O(log(m+n))】


需要注意的是，A或者B的个数不一定有k/2个，比如m<k/2时，作为比较的数据应该是A[m]和B[k-m]，即满足[]内两个数加起来的和为k。可以这样： int ia=min(k/2,m),ib=k-ia;   比较A[ia] 与 B[ib]


###2.2 代码

    class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            //分m+n为偶数和奇数两种情况
            int total=m+n;
            if(total & 0x1)   //奇数
               return find_kth( A, m, B, n,total/2+1);
            else
               return (find_kth( A, m, B, n,total/2)+find_kth( A, m, B, n,total/2+1))/2.0;
            
        }
    private:
        static int find_kth(int A[],int m,int B[],int n,int k){
                //规定传入的参数m<=n
                if(m>n) return find_kth(B,n,A,m,k);    
                if(m==0)  return B[k-1];    //一个为空
                if(k==1)  return min(A[0],B[0]);
                int ia=min(k/2,m),ib=k-ia;
                if(A[ia-1]<B[ib-1])  return find_kth(A+ia,m-ia,B,n,k-ia);
                else if(A[ia-1]>B[ib-1])  return find_kth(A,m,B+ib,n-ib,k-ib);
                else return A[ia-1];
                 }
    };
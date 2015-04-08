##1、题目

 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem. 

##2、wepon的解法
###2.1 解析

题目大意就是将数组按0，1，2的顺序排好，如{0,1,2,2,1,1,0,0,2}排成{0,0,0,1,1,1,2,2,2}。

方法有很多种，one pass的，two pass的，直接调用库函数解决的，详见下面代码及分析。

###2.2 代码

**C++**

    
    //最简单的方法，就是先遍历一轮，统计0、1、2的个数，然后遍历第二轮，置相应个数的0、1、2。
    class Solution {
    public:
        void sortColors(int A[], int n) {
            int count[3]={0,0,0};
            for(int i=0;i<n;i++)
              count[A[i]]++;
            int i=0;
            while(count[0]--) A[i++]=0;
            while(count[1]--) A[i++]=1;
            while(count[2]--) A[i++]=2;
        }
    };
    
    //调用库函数，快速排序的partition()，先按0分割，再按1分割
    class Solution {
    public:
        void sortColors(int A[], int n) {
          partition( partition(A,A+n,bind1st(equal_to<int>(),0)),A+n,bind1st(equal_to<int>(),1));
        }
    };
    
    //题目要求是one pass，下面这个方法也不是严格的one pass
    class Solution {
    public:
    /*
    双指针，i指向头，j指向尾
    当A[i]等于0，i++
    当A[i]等于1，则置为0，并且记录1的个数的num加一
    当A[i]等于2，则swap(A[i],A[j]),这样确保j处的元素是2，然后j--
    循环这个过程，直到i==j跳出循环
    此时还需判断A[j]是否为0，如果不为0，则该位的元素不用管，还是其原来的数（1或者2），然后从j-1处，开始往后置num个1
    */
        void sortColors(int A[], int n) {
            int i=0,j=n-1,num=0;
            while(i<j)
            {
                if(A[i]==0) i++;
                else if(A[i]==1)  { num++;A[i]=0; i++;}
                else  {int tmp=A[j];A[j]=A[i];A[i]=tmp;j--;}
            }
            if(A[j]!=0)  j--;
            while(num--) A[j--]=1;
        }
    };
    
    
    // one pass，设置下标red=0，blue=n-1
    //遍历一轮，发现0则与A[red]交换，red++，i++；发现2则与A[blue]交换，blue--
    class Solution {
    public:
        void sortColors(int A[], int n) {
            int red=0,blue=n-1;
            for(int i=0;i<blue+1;)
            {
                if(A[i]==0) swap(A[i++],A[red++]);  //交换过后，A[i]肯定不是2，因为2肯定已经被交换到后面。只能是0或者1，可以不用管，直接i++
                else if(A[i]==2) swap(A[i],A[blue--]);
                else i++;
            }
        }
    };
#include<iostream>
#include<vector>
using namespace std;
/*
Solution0: linear scan of array,O(n) time complexity 
Solution1: Divide and Conquer,O(logn) time complexity
*/
class Solution0 {
public:
    int findPeakElement(const vector<int> &num) {
         int len=num.size();
         for(int i=1;i<len-1;i++){
             if(num[i]>num[i+1]&&num[i]>num[i-1]){
                 return i;
             }
         }
         if(num[0]>num[1]) return 0;
         if(num[len-1]>num[len-2]) return len-1;
    }
};

class Solution1 {
public:
    int findPeakElement(const vector<int> &num) {
         return findPeakElement(num,0,num.size()-1);
    }
private:
    int findPeakElement(const vector<int> &num,int start,int end){
         if (start==end) return start;
         if(end-start==1) return num[start]>num[end]?start:end;
         int mid=(end+start)/2;
         if(num[mid]>num[mid-1]&&num[mid]>num[mid+1]) return mid;
         else if(num[mid]<num[mid-1])  return findPeakElement(num,start,mid-1);
         else return findPeakElement(num,mid+1,end);
    }
};


int main(){
	vector<int> num;
	num.push_back(1);num.push_back(2);num.push_back(3);num.push_back(4);num.push_back(5);num.push_back(4);num.push_back(3);
	Solution0 solution0;Solution1 solution1;
	cout<<solution0.findPeakElement(num)<<" "<<solution1.findPeakElement(num);
	return 0;

}


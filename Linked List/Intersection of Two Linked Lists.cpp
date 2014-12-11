/*

Refer to my blog for detailed discuss
Blog address:http://blog.csdn.net/u012162613/article/details/41560337

*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA,*pb=headB;
        int lengthA=0,lengthB=0;
        while(pa) {pa=pa->next;lengthA++;}
        while(pb) {pb=pb->next;lengthB++;}
        if(lengthA<=lengthB){
            int n=lengthB-lengthA;
            pa=headA;pb=headB;
            while(n--) {pb=pb->next;}
        }else{
            int n=lengthA-lengthB;
            pa=headA;pb=headB;
            while(n--) {pa=pa->next;}
        }
        while(pa!=pb){
            pa=pa->next;
            pb=pb->next;
        }
        return pa;
    }
};
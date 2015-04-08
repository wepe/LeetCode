##1、题目

Sort a linked list in O(n log n) time using constant space complexity.

##2、wepon的解法
###2.1 解析

题目要求时间复杂度为O(nlogn)，空间复杂度为O(1)，满足要求的排序算法有快速排序，归并排序，堆排序.....
一般来说，单链表排序用归并，双链表排序用快排，代码比较容易写。
本题是单链表，用归并会比较容易，并且利用了另一道题Merge Two Sorted Lists的代码。

###2.2 代码

**C++**

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    class Solution {
    public:
        /*归并排序*/
        ListNode *sortList(ListNode *head) {   
            if(!head || !head->next) return head;     //空或者只有一个元素，直接return
            ListNode dummy(-1);dummy.next=head;
            ListNode *pslow=&dummy,*pfast=&dummy;   //快慢指针，找出链表的中间节点，然后对左右两个子链表递归地调用归并排序
            while(pfast&&pfast->next)
            {
                pslow=pslow->next;
                pfast=pfast->next->next;
            }
            ListNode *right_begin=pslow->next;
            pslow->next=nullptr;  //断开两段子链表
            ListNode *l1=sortList(dummy.next);
            ListNode *l2=sortList(right_begin);
            return mergeTwoLists(l1,l2);
        }
    private:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {  
            ListNode dummy(-1);  
            ListNode *head1=l1,*head2=l2,*tail=&dummy;  
            while(head1!=nullptr && head2!=nullptr)  
            {  
                if(head1->val<head2->val) {tail->next=head1;head1=head1->next;}  
                else                      {tail->next=head2;head2=head2->next;}  
                tail=tail->next;  
            }  
            if(head1==nullptr)   tail->next=head2;  
            if(head2==nullptr)   tail->next=head1;  
        return dummy.next;  
        }  
    };
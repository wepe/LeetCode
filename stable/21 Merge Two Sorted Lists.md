##1、题目

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

##2、wepon的解法
###2.1 解析
将两个已排序的链表L1和L2 merge sort。

-  新建一个结点dummy，初始时tail指向dummy；head1、head2分别指向L1、L2的头结点
-  每次循环都将tail指向head1、head2中val较小者，更新tail、head1/head2
-  跳出循环后的处理


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
            if(head2==nullptr)   tail->next=head1;  /*两句可以合并为 tail->next=head1==nullptr?head2:head1; */
        return dummy.next;
        }
    };

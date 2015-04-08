##1、题目

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity。

##2、wepon的解法
###2.1 解析

复用 [21.Merge Two Sorted Lists]() 这道题所写的函数mergeTwoLists()。

两种方法

- 一种是逐步地merge两个链表，形成新的链表，再将新的链表跟另一个链表merge，时间复杂度是O(n(n1+n2+n3....)) n是链表个数。【因为merge L1和L2花费O(L1+L2)，形成新的链表的长度为n1+n2，merge该新链表与L3花费O((n1+n2)+n3).....所以总的是O((n1+n2)+((n1+n2)+n3)+.......)】

- 另外一种是用归并排序的思想，时间复杂度是O(logn(n1+n2+n3+......)),因为是两两merge，递归树有logn层，每一层的代价都为O(n1+n2+n3+......)。

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
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            
           /*归并排序*/
           int n=lists.size();
           if(n==0) return nullptr;
           if(n==1)  return lists[0];
           vector<ListNode *> list_left;
           vector<ListNode *> list_right;
    	   auto iter=lists.begin();
    	   for(;iter<lists.begin()+n/2;iter++)
    		   list_left.push_back(*iter);
    	   for(;iter!=lists.end();iter++)
    		   list_right.push_back(*iter);
    		   
           ListNode *l1=mergeKLists(list_left);
           ListNode *l2=mergeKLists(list_right);
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
            if(head2==nullptr)   tail->next=head1;  /*两句可以合并为 tail->next=head1==nullptr?head2:head1; */
        return dummy.next;
        }
    };
##1、题目

Sort a linked list using insertion sort.

##2、wepon的解法
###2.1 解析

**用插入排序的方法，排序单链表。**

细节实现题，需要注意的是不要让已排序链表的尾部出现“环”，每一次循环过后，已排序链表尾部都应该指向null。有一些算法没考虑周全就会出现环的情况，是因为把当前节点插入到已排序链表中时，没有断开当前节点与它前驱节点的连接，造成尾部环。下面代码所示的算法可以避免环的出现。

###2.2 代码

**C++**

    /*
    1 插入排序，从左到右遍历所有节点。但是因为是单链表，所以每次从头结点往后比较
    2 每一轮开始时，p更新为已排序链表的首节点，即dummy.next，并且随着比较的进行更新p。pre_p代表p的前一个节点
    3 当满足cur->val小于p->val时，将cur节点插入到pre_p与p之间
    */
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
        ListNode *insertionSortList(ListNode *head) {
            if(head==nullptr)  return head;
            ListNode dummy(INT_MIN);
           // dummy.next=head;
            ListNode *cur=head;
            while(cur!=nullptr)
            {   
                ListNode *pos=findinsertpos(&dummy,cur);   //cur插在pos后面
                
                ListNode *cur_next=cur->next;
                cur->next=pos->next;
                pos->next=cur;
                cur=cur_next;
            }
            return dummy.next;
        }
    private:
         ListNode *findinsertpos(ListNode *head,ListNode *cur)
         {   
             ListNode *pos=nullptr; 
             for(ListNode *p=head;p!=nullptr&&p->val<=cur->val;pos=p,p=p->next)
               ;
              return pos;     
         }
    };


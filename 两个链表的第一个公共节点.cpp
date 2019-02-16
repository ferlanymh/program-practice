/*输入两个链表，找出它们的第一个公共结点。


思路：
1.算出两个链表的长度,让长的链表先走,直到两个链表长度相等.
   再让两个链表同时走,首次遇到相等的结点就是我们要的第一个公共节点.
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        
        int len1 = 0;
        int len2 = 0;
        while (p1)
        {
            p1 = p1->next;
            len1++;
        }
        while (p2)
        {
            p2 = p2->next;
            len2++;
        }
        
        p1 = pHead1;
        p2 = pHead2;
        
        if (len1 > len2)
        {
            int sub = len1 - len2;
            while (sub--)
            {
                p1 = p1->next;
            }
        }
        else
        {
            int sub = len2 - len1;
            while (sub--)
            {
                p2 = p2->next;
            }
        }
        
        while (p1 && p2)
        {
            if (p1 == p2)
                break;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};


//2.用栈,
//将两个链表的结点分别存入两个栈..如果两个链表有公共部分,那么他们的栈顶值应该相等,等遇到不等的值时,最后一个相等的值就是我们要的首个公共结点.
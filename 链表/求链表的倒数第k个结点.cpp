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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL)
            return NULL;
        ListNode* first = pListHead;
        ListNode* second = pListHead;
        
        while (--k)//让second先往前走n步
        {
            if (second->next)
                second = second->next;
            else
                return NULL;//链表不具备k个结点
        }
        
        while (second->next)//再让second和first同时向后走，second到达链表末尾时,first就是倒数第k个
        {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};
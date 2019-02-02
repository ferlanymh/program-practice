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
    ListNode* Merge(ListNode* a, ListNode* b)
    {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        
        
        ListNode* newhead = nullptr;
        ListNode* tail = newhead;
        
        if (a->val < b->val)
        {
            newhead = a;
            a = a->next;
        }
        else
        {
            newhead = b;
            b = b->next;
        }
        
        tail = newhead;
        
        while (a && b)
        {
            if (a->val < b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        
        if (a)
            tail->next = a;
        else
            tail->next = b;
        
        return newhead;
        
        
        
    }
};
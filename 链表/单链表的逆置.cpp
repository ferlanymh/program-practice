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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr)//空
            return nullptr;
        if (pHead->next == nullptr)//1个结点
            return pHead;
        if (pHead->next->next == nullptr)//2个结点
        {
            ListNode* a = pHead->next;
            ListNode* b = a->next;
            b->next = a;
            a->next = pHead;
            pHead->next = nullptr;
            pHead = b;
            return pHead;
        }
        
        //三个结点及以上
        ListNode* a = pHead;
        ListNode* b = a->next;
        ListNode* c = b->next;
        
        while (c->next)//当c不为最后一个结点的时候
        {
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        
        c->next = b;
        b->next = a;
        pHead->next = nullptr;
        pHead = c;
        return pHead;
        
        
        
    }
};



//做法二 ，用栈存结点，再依次出结点
//用栈更好
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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead ==nullptr || pHead->next ==nullptr)
        {
            return pHead;
        }
        stack<ListNode*> s;
        ListNode* cur = pHead;
        while (cur->next)//挨个入栈，留最后一个结点
        {
            s.push(cur);
            cur = cur->next;
        }
        pHead = cur;//最后一个作头部
         
        while (!s.empty())//依次取出结点链在最后
        {
            cur->next = s.top();
            cur = cur->next;
            s.pop();
        }
        cur->next = nullptr;
        return pHead;
    }
};

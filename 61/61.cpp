struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* p = head;
        //遍历链表
        while (p->next != nullptr) {
            n++;
            p = p->next;
        }
        int mv = (n - k) % n;
        if (mv == 0) {
            return head;
        }
        p->next = head;
        while (mv--) {
            p = p->next;
        }
        ListNode* pl = p->next;
        p->next = nullptr;
        return pl;
    }
};

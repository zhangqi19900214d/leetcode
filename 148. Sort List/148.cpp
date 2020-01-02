/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *midNode(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *p = head;
        ListNode *q = head;// ->next->next;

        while (q != nullptr && q->next != nullptr && q->next->next != nullptr)
        {
            p = p->next;
            q = q->next->next;
        }

        return p;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode *head = nullptr;

        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        
        auto h = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                h->next = l1;
                l1 = l1->next;
            }
            else
            {
                h->next = l2;
                l2 = l2->next;
            }

            h = h->next;
        }

        if (l1 != nullptr)
        {
            h->next = l1;
        }
        if (l2 != nullptr)
        {
            h->next = l2;
        }

        return head;
    }

    ListNode *sortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        else
        {
            ListNode *mid = this->midNode(head);

            auto right = this->sortList(mid->next);
            mid->next = nullptr;
            auto left = this->sortList(head);

            return this->merge(left, right);
        }
    }

    void print(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    auto sol = new Solution();
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);

    sol->print(head);
    head = sol->sortList(head);
    sol->print(head);
}
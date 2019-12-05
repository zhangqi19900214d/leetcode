#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode *bigger = nullptr;
		ListNode *smaller = nullptr;

		ListNode *p = head;

		if (p->val < x)
		{
			smaller = p;
		}
		else
		{
			bigger = p;
		}

		p = p->next;

		while (p != nullptr)
		{

		}
		return NULL;
	}

	void print(ListNode *head)
	{
		ListNode *p = head;
		while (p != nullptr)
		{
			cout << p->val << " ";
			p = p->next;
		}
	}
};


int main()
{
	auto sol = new Solution();
	ListNode *head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);
	
	sol->print(head);

	auto ret = sol->partition(head, 3);
	sol->print(ret);
}
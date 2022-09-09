#include <stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL, * tail = NULL;
	while (cur)
	{
		if (cur->val != val)
		{
			if (tail == NULL)
			{
				newhead = tail = cur;
			}
			else
			{
				tail->next = cur;
				tail=tail->next;
			}
			cur = cur->next;
		}
		else
		{
			struct ListNode* del = cur;
			cur = cur->next;
			free(del);
		}
	}
	return newhead;
}
int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n1);
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n2);
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n3);
	struct ListNode* n4= (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n4);
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n5);
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n6);
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(n7);
	n1->next = n2;
    n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next =NULL;

	n1->val = 1;
	n2->val = 2;
	n3->val = 6;
	n4->val = 3;
	n5->val = 4;
	n6->val = 5;
	n7->val = 6;
	struct ListNode* head = removeElements(n1, 6);
	return 0;
}
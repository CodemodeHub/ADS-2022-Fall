class Solution
{
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr, * cur = head;
		while (cur != nullptr) {
			ListNode* nextt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nextt;
		}
		return prev;
	}
};
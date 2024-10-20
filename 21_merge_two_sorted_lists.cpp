/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
		ListNode* merged_list;

        if (!list1 && list2) return list2;
        else if (list1 && !list2) return list1;
        else if (!list1 && !list2) return nullptr;

        if (list1->val < list2->val)
        {
			merged_list = new ListNode(list1->val);
			list1 = list1->next;
        }
		else 
		{
			merged_list = new ListNode(list2->val);
			list2 = list2->next;
		}
		head = merged_list;

		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				merged_list->next = new ListNode(list1->val);
				merged_list = merged_list->next;
				list1 = list1->next;
			}						
			else
			{
				merged_list->next = new ListNode(list2->val);
				merged_list = merged_list->next;
				list2 = list2->next;
			}						
		}

		if (list1)
		{
			while (list1)
			{
				merged_list->next = new ListNode(list1->val);
				merged_list = merged_list->next;
				list1 = list1->next;
			}
		}
		else
		{
			while (list2)
			{
				merged_list->next = new ListNode(list2->val);
				merged_list = merged_list->next;
				list2 = list2->next;
			}
		}

        return head;
    }
};
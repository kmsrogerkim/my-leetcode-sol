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
		// Solution 2 
		// Runtime: 0ms, 100%
		// Memory: 19.80MB, 55.72% 
        ListNode* head;
		ListNode* merged_list;

        if (!list1 && list2) return list2;
        else if (list1 && !list2) return list1;
        else if (!list1 && !list2) return nullptr;

        if (list1->val < list2->val)
        {
			merged_list = list1;
			list1 = list1->next;
        }
		else 
		{
			merged_list = list2;
			list2 = list2->next;
		}
		head = merged_list;

		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				merged_list->next = list1;
				list1 = list1->next;
				merged_list = merged_list->next;
				merged_list->next = nullptr;
			}						
			else
			{
				merged_list->next = list2;
				list2 = list2->next;
				merged_list = merged_list->next;
				merged_list->next = nullptr;
			}						
		}

		if (list1)
		{
			while (list1)
			{
				merged_list->next = list1;
				list1 = list1->next;
				merged_list = merged_list->next;
				merged_list->next = nullptr;
			}
		}
		else
		{
			while (list2)
			{
				merged_list->next = list2;
				list2 = list2->next;
				merged_list = merged_list->next;
				merged_list->next = nullptr;
			}
		}

        return head;
    }
};
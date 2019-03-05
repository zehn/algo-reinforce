/**
 * Problem: Add Two Numbers
 *
 * Description: You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add
 * the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *   Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *   Output: 7 -> 0 -> 8
 *   Explanation: 342 + 465 = 807
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list_ret = nullptr;
        ListNode* list_tmp = nullptr;
        int carry = 0;
        
        while ((l1 || l2) || carry != 0) {
            int x = 0, y = 0;
            if (l1) x = l1->val;
            if (l2) y = l2->val;
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            ListNode* __node = new ListNode(sum);
            if (!__node) return nullptr;
            if (!list_tmp) {
                list_new = __node;
            } else {
                list_tmp->next = __node;
            }
            list_tmp = __node;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return list_ret;
    }
};

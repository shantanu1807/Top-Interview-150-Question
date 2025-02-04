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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        int total = 0, carry = 0;

        while (l1 || l2 || carry) {
            total = carry;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            int num = total % 10;
            carry = total / 10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }

        ListNode* result = res->next;
        delete res;
        return result;         
    }
};


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode();
//         ListNode* temp = dummy;
//         int carry = 0;
        
//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int val1 = (l1 != nullptr) ? l1->val : 0;
//             int val2 = (l2 != nullptr) ? l2->val : 0;
            
//             int sum = val1 + val2 + carry;
//             carry = sum / 10;
//             temp->next = new ListNode(sum % 10);
//             temp = temp->next;
            
//             if (l1 != nullptr) l1 = l1->next;
//             if (l2 != nullptr) l2 = l2->next;
//         }
        
//         return dummy->next;
//     }
// };
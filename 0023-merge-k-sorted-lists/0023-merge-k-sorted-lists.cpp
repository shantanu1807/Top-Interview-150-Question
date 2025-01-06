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
    ListNode*MergeTwoLists(ListNode*l1, ListNode*l2){
        if(!l1)return l2;
        if(!l2)return l1;
        if(l1->val <= l2->val){
            l1->next = MergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
             l2->next = MergeTwoLists(l2->next, l1);
            return l2;
        }
        return NULL;
    }
      ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if(start == end)
            return lists[start];
        
        if(start > end)
            return NULL;
        
        int mid = start + (end-start)/2;
        
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);
        
        return MergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0){
            return NULL;
        }
        return partitionAndMerge(0, n-1, lists);
    }
};

// Algorithm :
// Divide: Split the ( k ) lists into pairs and recursively merge them.
// Conquer: Merge two sorted lists at each step using a helper function.
// Repeat the process until only one merged list remains.

// Steps in Code :
// Use a helper function to merge two sorted linked lists.
// Implement a recursive function that divides the list of linked lists into two halves until the base case is reached (a single list or empty list).
// Merge the two halves recursively.
// Return the final merged list.
// Complexity :
// Time Complexity: O(N log k)
// ( N ): Total number of nodes across all lists.
// ( log k ): Number of levels in the divide-and-conquer recursion tree.
// Space Complexity: O(log k) due to recursive function calls.
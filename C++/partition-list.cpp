// Time:  O(n)
// Space: O(1)

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy_smaller = new ListNode(INT_MIN);
        ListNode *dummy_larger = new ListNode(INT_MIN);
        ListNode *smaller = dummy_smaller;
        ListNode *larger = dummy_larger;
        
        while (head) {
            if (head->val < x) {
                smaller->next = head;
                smaller = smaller->next;
            } else {
                larger->next = head;
                larger = larger->next;
            }
            head = head->next;
        }
        smaller->next = dummy_larger->next;
        larger->next = nullptr;
        
        return dummy_smaller->next;
    }
};




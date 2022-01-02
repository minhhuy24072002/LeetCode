/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) return false;
        ListNode *fast = head -> next;
        ListNode *slow = head;
        
        while (slow != fast) {
            if (fast == nullptr || fast -> next == nullptr) return false;
            
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return true;
    }
};
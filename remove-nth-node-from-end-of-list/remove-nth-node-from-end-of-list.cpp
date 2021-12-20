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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = 0, target;
        ListNode* currNode = head;
        ListNode* prevNode = nullptr;
        
        while (currNode != nullptr) {
            listSize++;
            currNode = currNode -> next;
        }
        
        currNode = head;
        target = listSize - n + 1;
        
        while (currNode != nullptr) {
            target--;
            
            if (target == 0) {
                if (prevNode) {
                    prevNode -> next = currNode -> next;
                } else head = head -> next;
                break;
            }
            
            prevNode = currNode;
            currNode = currNode -> next;
            
        }
        return head;
    }
};
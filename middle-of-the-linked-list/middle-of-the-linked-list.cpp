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
    ListNode* middleNode(ListNode* head) {
        ListNode* A=head;
        ListNode* B=head;
        while (B!=NULL)
        {
            B=B->next;
            if (B==NULL)
            {
                return(A);
            }
            A=A->next;
            B=B->next;
        }
        return(A);
    }
};
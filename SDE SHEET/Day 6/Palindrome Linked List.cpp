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
    bool isPalindrome(ListNode* head) {
        //finding the middle node
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reversing the linked list
        ListNode* temp = slow->next;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        slow ->next = prev;
        slow = slow->next;
        //check
        ListNode* dummy = new ListNode();
        dummy->next = head;
        dummy = dummy->next;
        while(slow){
            if(dummy->val != slow->val) return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};


class Solution {
private:
int getLength(ListNode* head){
    int length =0;
    ListNode* temp = head;
    while(temp){
        temp = temp->next;
        ++length;
    }
    return length;
}
ListNode* solve(ListNode*  &head,int k,int length){
     if(head == NULL || head->next == NULL || k == 1|| length < k) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int cnt =0;
        while(curr != NULL && cnt < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
            ++cnt;
        }
        if(next !=  NULL){
            head->next = solve(next,k,length-k);
        }
        return prev;
 }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = getLength(head);
        return solve(head,k,length);
    }
};

///space more 
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
        ListNode* temp = new ListNode();
        ListNode* newHead = temp;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        while(list1){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while(list2){
            temp->next = list2;
            list2=list2->next;
            temp = temp->next;
        }
        return newHead->next;
    }
};
//in place
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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val >= list2->val) swap(list1,list2);
        ListNode* newHead = list1;
        while(list1 && list2){
            ListNode* prev;
            while(list1 && list1->val <= list2->val){
                prev = list1;
                list1 = list1->next;
            }
            prev->next = list2;
            swap(list1,list2);
        }
        return newHead;
        
    }
};

//+++++++++++++++++++++HASH MAP++++++++++++++++++++++++++++++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        Node* temp = head;
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        Node* t = head;
        while(t){
            Node* node = mp[t];
            node->next = (t->next != NULL)?mp[t->next]:NULL;
            node->random = (t->random != NULL) ? mp[t->random]:NULL;
            t = t->next;
        }
        return mp[head];
    }
};

//++++++++++++++++++ second approach in O(1) space +++++++++++++++++++++++++++++

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp ->next = node;
            temp= temp->next->next;
        }
        Node* t = head;
        while(t){
            if(t->random != NULL){
                t->next->random = t->random->next;
            }
            t = t->next->next;
        }
        Node* dummy = new Node(0);
        Node* ans = dummy;
        Node* s = head;
        Node* fast;
        while(s){
            fast = s->next->next;
            dummy->next = s->next;
            s->next = fast;
            dummy= dummy->next;
            s= fast;
        }
        return ans->next;
    }
};

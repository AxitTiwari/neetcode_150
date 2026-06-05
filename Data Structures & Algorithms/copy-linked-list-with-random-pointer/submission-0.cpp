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

        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* cur = head;
        Node* new_head = new Node(cur->val);
        Node* new_tail = new_head;

        mp[new_tail] = cur->random;

        cur = cur->next;
        while (cur) {

            Node* new_node = new Node(cur->val);

            new_tail->next = new_node;
            new_tail = new_tail->next;

            mp[new_tail] = cur->random;

            cur = cur->next;
        }

        unordered_map<Node*, Node*> copied;
        new_tail = new_head;
        cur = head;
        while (new_tail) {
            copied[cur] = new_tail;
            cur = cur->next;
            new_tail = new_tail->next;
        }

        new_tail = new_head;
        while (new_tail) {

            new_tail->random = copied[mp[new_tail]];
            new_tail = new_tail->next;
        }
        return new_head;
    }
};

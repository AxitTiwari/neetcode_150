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
    bool hasCycle(ListNode* head) {
        
        unordered_map<ListNode*, ListNode*> mp;
        while (head) {

            if (mp.count(head)) {
                return true;
            }

            mp[head] = head->next;
            head = head->next;
        }
        return false;
    }
};

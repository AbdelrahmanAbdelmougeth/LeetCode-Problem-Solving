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
        /*
        unordered_set<ListNode*> pointer_add;
        int count = 0;
        for(ListNode* curr=head; curr!=nullptr; curr=curr->next, count++){
            if(pointer_add.find(curr) != pointer_add.end())
                return true;
            pointer_add.insert(curr);
        }
        return -1;
        */
        
        unordered_set<ListNode*> visited;
    ListNode* curr = head;
    while (curr != nullptr) {
        if (visited.count(curr)) {
            // Cycle detected
            return true;
        }
        visited.insert(curr);
        curr = curr->next;
    }
    // No cycle found
    return false;
    }
};
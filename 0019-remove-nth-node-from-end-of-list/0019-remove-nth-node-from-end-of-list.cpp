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
        ListNode* curr = head;
        int no_of_nodes = 1;
        while(curr->next != nullptr){
            curr = curr->next;
            no_of_nodes++;
        }
            
        int nth_node_from_start = no_of_nodes - n;
        int counter = 1; curr = head;
        //cout<<n<<" "<<no_of_nodes<<" "<<nth_node_from_start<<" "<<endl;
        
        ListNode* to_delete;
        if(nth_node_from_start == 0){
            to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }
        
        while(counter != nth_node_from_start){
            curr = curr->next;
            counter++;
        }
        
        to_delete = curr->next;
        curr->next = curr->next->next;
        delete to_delete;
        
        return head;
        
        /*
        ListNode* delayed_ptr = head;
        ListNode* fast_ptr = head;
        
        int number_of_nodes = 1;
        ListNode* curr = head;
        
        while(curr->next != nullptr){
            curr = curr->next;
            number_of_nodes++;
        }
        
        cout<<number_of_nodes<<curr->val;
        
        int i = number_of_nodes - n - 1;
        
        if(number_of_nodes == 1 && n == 1){
            ListNode* curr2 = head;
            head = nullptr;
            delete curr2;
            return head;
        }
        
        if(number_of_nodes == 2 && n == 2){
            ListNode* curr2 = head;
            head = curr2->next;
            delete curr2;
            return head;
        }
        
        ListNode* curr2 = head;
        
        while(i != 0){
            curr2 = curr2->next;
            i--;
        }
        
        ListNode* to_pointed_at = curr2->next->next;
        ListNode* to_delete = curr2->next;
        
        curr2->next = to_pointed_at;
        delete to_delete;
        
        return head;
        */
        
    }
};
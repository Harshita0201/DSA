//Given the head of a singly linked list, return the middle node of the linked list.

//If there are two middle nodes, return the second middle node.

//Input: head = [1,2,3,4,5]
//Output: [3,4,5]
//Explanation: The middle node of the list is node 3.

//Input: head = [1,2,3,4,5,6]
//Output: [4,5,6]
//Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

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
    int length(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int len=length(head);
        int mid=len/2 +1;
        
        int cnt=1;
        while(cnt!=mid){
            head=head->next;
            cnt++;
        }
        return head;
        
    }
};

//aproach 2: optimised o(n/2) solution
//  ListNode* middleNode(ListNode* head) {
//         //if 1 node
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         // if 2 nodes
//         if(head->next->next==NULL){
//             return head->next; //second node
//         }
        
//         ListNode *slow= head;
//         ListNode *fast=head->next;
//         while(fast!=NULL){
//             fast=fast->next;//1 hop for fast
//             if(fast!=NULL){
//                 fast=fast->next; //2 hop for fast
//             }
//             slow=slow->next; //1 hop for slow
            
//         }
//         return slow;
        
//     }

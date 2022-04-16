//Given the head of a singly linked list, reverse the list, and return the reversed list.
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
			return head;
		}
		
		ListNode *prev=NULL;
		ListNode *curr=head;
		ListNode *forward=NULL;
		
		while(curr!=NULL){
			forward=curr->next;
			curr->next=prev;
			prev=curr;
			curr=forward;
		}
		
		return prev;
    }
};



//recursive approach 1

// class Solution {
// public:
//     void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
//         //base case
//         //when curr reached the end of list
//         if(curr==NULL){
//             head=prev;
//             return;
//         }
        
//         ListNode *forward=curr->next;
//         reverse(head, forward, curr);
//         curr->next=prev;
//     }
//     ListNode* reverseList(ListNode* head) {
//         //rercursive
//         ListNode *prev=NULL;
//         ListNode *curr=head;
//         reverse(head, curr, prev);
//         return head;
        
        
//     }
// };


//recursive appraoch 2
// class Solution {
// public:

    
//     ListNode* reverse(ListNode *head){ //reverse 2
//         //base case
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
        
//         ListNode *c_head= reverse(head->next);
//         head->next->next=head;
//         head->next=NULL;
//         return c_head;
            
//     }
//     ListNode* reverseList(ListNode* head) {
        
//         return reverse(head);
      
//     }
// };
	

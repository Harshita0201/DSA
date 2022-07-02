//https://leetcode.com/problems/copy-list-with-random-pointer/


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
        //1. make copy nodes and link them together side by side
        Node *iter=head;
        Node *fwd=head;
        
        while(iter!=NULL){
            fwd=iter->next;
            Node *copy =new Node(iter->val); //make copy
            
            //link side by side
            iter->next=copy;
            copy->next=fwd;
            
            //move ahead
            iter=fwd;
        }
        
        //2. copy/ assign random pointers
        iter=head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random = iter->random->next;
            }
            iter=iter->next->next; //move forward
        }
        
        //3. seperate the copy linked list and original linked list
        iter=head;
        Node *pseudohead= new Node(0);
        Node *copy=pseudohead;
        
        while(iter!=NULL){
            fwd=iter->next->next;
            //extrtact copy
            copy->next=iter->next; 
            
            //delink
            iter->next=fwd;
            
            //move ahead
            copy=copy->next;
            iter=fwd;
        }
        return pseudohead->next; //copy linked list
    } //TC: O(N) SC:O(1)
};

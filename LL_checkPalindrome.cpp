// N = 3
// value[] = {1,2,1}
// Output: 1
// Explanation: The given linked list is
// 1 2 1 , which is a palindrome and
// Hence, the output is 1.

//palindrome - reads same from front and back

//approach 1-> 

// #include<vector>
// class Solution{
//   private:
  
//   bool isPalindrome_arr(vector<int> v){
//       int s=0;
//       int e=v.size()-1;
      
//       while(s<=e){
//           if(v[s]!=v[e]){
//               return false;
//           }
//           s++;
//           e--;
//       }
//       return true;
//   }    
  
//   public:
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         //Your code here
//         vector<int> v;
//         Node * temp=head;
//         while(temp!=NULL){
//             v.push_back(temp->data);
//             temp=temp->next;
//         }
//         return isPalindrome_arr(v);
//     }
// };

//approach 2

class Solution{
  public:
    Node *reverse(Node * head){
        Node *curr=head;
        Node *prev=NULL;
        Node *next=NULL;
        
        while(curr!=NULL){
            next=curr->next; //save link
            curr->next=prev; //change link
            //move ahead
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    
    Node* getMid(Node *head){
        Node* s=head;
        Node *f=head->next;
        while(f!=NULL && f->next!=NULL){
            f=f->next->next;
            s=s->next;
        }
        return s;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL && head->next==NULL){ //0 or 1 element
            return true;
        }
        
        //1.get mid
        Node* mid= getMid(head);
        //2. reverse after mid
        Node *temp=mid->next;
        mid->next=reverse(temp);
        
        //3.compare both halves
        Node *h1=head;
        Node *h2=mid->next;
        
        while(h2!=NULL){
            if(h1->data != h2->data){
                return false;
            }//else true
            //move pointers ahead
            h1=h1->next;
            h2=h2->next;
            
        }
        
        //reverse back //repeat 2 //optional
        temp=mid->next;
        mid->next=reverse(temp);
        
        return true;
        
    }
};

// Input:
// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL
// Output: 15


//TC->O(n+m)  SC->O(n)
// int intersectPoint(Node* head1, Node* head2)
// {
//     // Your Code Here
//     set<Node *> s;
//     Node *temp1=head1;
//     Node *temp2=head2;
    
//     while(temp1){
//         s.insert(temp1);
//         temp1=temp1->next;
//     }
//     while(temp2){
//         if(s.find(temp2)==s.end()){//not found
//             temp2=temp2->next;
//         }else{//found intersection/match
//             return temp2->data;
//         }
//     }
//     return -1; //not y shaped
// }



//Approach 2: O(n+m) time O(1) space
//No. of nodes in first + distance of head1 to intersection = no. of nodes in second + distance of head2 to intersection
    // Your Code Here
    Node *x=head1;
    Node *y=head2;
    while(x!=y){
        if(x==NULL){ 
            x=head2;
        }else{
        x=x->next;
        }
        
        if(y==NULL){
            y=head1;
        }else{
        y=y->next;
        }
        
    }
    return x->data;

}

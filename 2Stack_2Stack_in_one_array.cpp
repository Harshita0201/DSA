//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{ 
        if(top2 - top1 > 1 ) { //check at least 1 element space  present
            top1 //move top index to next pos, left to right insertion
            arr[top1] = x; //insert
        } 
       
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{ 
     if(top2 - top1 > 1 ) {  //check  at least 1 element space  present
            top2--; //move top index to next pos, right to left insertion
            arr[top2] = x; //insert
    } 

}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if( top1 >= 0) { //chekc if at least 1 element present
            int ans = arr[top1]; //return popped element 
            top1--;
            return ans;
        }
    else{
            return -1;
    }
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    	if( top2 < size) {//chekc if at least 1 element present
            int ans = arr[top2]; //return popped element 
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }

}


class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)//col corresponding to index  a is 1, ie a knows b
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i); //push all elements/ persons
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){ // a knows b, a is not celebrity
                s.push(b); //check for b
            }
            else //b knows a , b is not celebrity
            {
                s.push(a);  //check for a
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {//index that traverses all cols corresponding to row @ans index
            if(M[ans][i] == 0)
                zeroCount++;
        }
        //the person knows no one ,therfore all there should be 0's in it's rows
        //all zeroes
        if(zeroCount != n) //less 0's
            return -1; //no ans
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) { //index that traverses all the rows corresponding to col @ index ans
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        //if all 1's except the diagonal, i.e everyone knows the person
        if(oneCount != n-1) //less 1's 
            return -1; //no ans
        
        return ans;
        
    }
};

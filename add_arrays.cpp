// You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, 
// where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.
//                  1 <-carry
//eg : arr1[]-> 1 2 3 4
//     arr2[]->       6
//     sum->    1 2 4 0


vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;
    while(s<e){
        swap(v[s++],v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    int i=n-1;
    int j=m-1;
    int carry=0;
    vector<int> ans;
    while(i>=0 && j>=0){
        int v1=a[i];
        int v2=b[j];
        int sum=v1+v2+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    
    //case 1: when arrays are of the form 1 2 3 4
    //                                          6
    
    while(i>=0){
        int sum=a[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        
    }
    
    //case 2: when arrays are of the form       6 
    //                                    1 2 3 4
    
    while(j>=0){
        int sum=b[j]+carry;
        carry=sum/10;
        int val=sum%10; //or sum=sum%10;
        ans.push_back(val);
        
        j--;
    }
    
    //Case 3: when array is of the form 9 9 9
    //									9 9 9 i.e carry
    
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    
    
    return reverse(ans);
}

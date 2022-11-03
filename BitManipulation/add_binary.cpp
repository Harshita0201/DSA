class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        string ans;
      
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry+=a[i]-'0';  //extract numeric value
                i--; //move to next place
            }
            if(j>=0){
                carry+=b[j]-'0';
                j--; //move to next place
            }
            
            ans+=(carry%2 + '0'); //convert tostring value
            carry=carry/2; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

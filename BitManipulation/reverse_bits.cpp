//Reverse bits of a given 32 bits unsigned integer.
// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
// so return 964176192 which its binary representation is 00111001011110000010100101000000.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        int i=32;
        while(i--){
            ans=ans<<1;//left shift by 1 space or add 0 to end to accomodate new bit ahead
            ans=ans|(n&1);//extract last bit add to ans
            n=n>>1; // update bits
        }
        return ans;
    }
};

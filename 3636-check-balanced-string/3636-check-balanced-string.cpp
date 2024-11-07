// Note => 1 The stoi function should not be used directly on a character. Instead, you should convert the character to an integer by subtracting the character '0'.
//   2.  The stoi function is meant for strings, not single characters. 
 
 
 class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int even=0;
        int odd=0;
        for(int i=0; i<n; i++){
            int digit = num[i]-'0'; // convert character to integer
            if(i%2==0){
                even+= digit;
            }
            else{
                odd+= digit;
            }
            
        }
        cout<<even;
        if(even==odd){
            return true;
        }
        return false;
    }
};
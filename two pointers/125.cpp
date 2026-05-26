class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.length() - 1;
        
        while (lo < hi) {
            // Skip non-alphanumeric characters from the left
            while (lo < hi && !isalnum(s[lo])) {
                lo++;
            }
            // Skip non-alphanumeric characters from the right
            while (lo < hi && !isalnum(s[hi])) {
                hi--;
            }
            
            // Compare characters by converting them to lowercase
            if (tolower(s[lo]) != tolower(s[hi])) {
                return false;
            }
            
            lo++;
            hi--;
        }
        
        return true;
    }
};
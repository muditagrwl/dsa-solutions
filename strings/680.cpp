class Solution {
public:
    // Helper function to check if a substring is a perfect palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                // We found a mismatch! Try deleting s[lo] OR deleting s[hi]
                return isPalindrome(s, lo + 1, hi) || isPalindrome(s, lo, hi - 1);
            }
            lo++;
            hi--;
        }
        
        // If we made it through without a mismatch, it's already a perfect palindrome
        return true;
    }
};
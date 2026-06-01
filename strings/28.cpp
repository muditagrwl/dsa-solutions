class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        // Edge case: If needle is larger than haystack, it can't exist inside it
        if (m > n) return -1;
        
        // Loop through haystack up to the point where needle can still fit
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            
            // Check if the characters match starting from index i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            
            // If we successfully matched the entire length of the needle
            if (j == m) {
                return i;
            }
        }
        
        // If we loop through the entire haystack without a match
        return -1;
    }
};
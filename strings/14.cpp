class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Safe check: if the array is empty, return empty string
        if (strs.empty()) return "";
        
        // Step 1: Sort the strings alphabetically
        sort(strs.begin(), strs.end());
        
        // Step 2: Compare the first and the last string
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string ans = "";
        
        // Loop through the characters as long as they match
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                break; // Stop at the first mismatch
            }
            ans += first[i];
        }
        
        return ans;
    }
};

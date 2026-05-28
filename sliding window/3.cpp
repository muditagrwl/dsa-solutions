class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0;
        unordered_map <char, int> count;
        for(int r = 0; r<n; r++)
        {
            count[s[r]]++;
            while(count[s[r]]>1)
            {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: If numRows is 1 or greater than/equal to the string length, 
        // the zigzag pattern doesn't change the string layout at all.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a list of strings representing each row
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;

        // Step through each character in the string
        for (char c : s) {
            rows[curRow] += c;
            
            // Turn around if we hit the top or bottom boundary
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down depending on the direction
            curRow += goingDown ? 1 : -1;
        }

        // Combine all rows into one final string
        string ans = "";
        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};
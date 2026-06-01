class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long ans = 0; // Use 'long' to safely track and handle 32-bit integer overflow

        // 1. Skip all leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for an optional '+' or '-' sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read valid digits until a non-digit character is encountered
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            
            // 4. Handle 32-bit signed integer boundaries dynamically
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;
            
            i++;
        }

        return ans * sign;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add digit from string a if available
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // Add digit from string b if available
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // The bit to append is always sum % 2 (either '0' or '1')
            res += to_string(sum % 2);

            // Calculate the new carry
            carry = sum / 2;
        }

        // Since we added digits from right-to-left, the result string is backwards.
        // Reverse it to get the correct order.
        reverse(res.begin(), res.end());
        
        return res;
    }
};
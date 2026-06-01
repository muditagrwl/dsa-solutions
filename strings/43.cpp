class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1 == "0" || nums2 == "0") return "0";
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result(n+m, 0);
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                int mul = (nums1[i]-'0')*(nums2[j]-'0');
                int p1 = i+j;
                int p2 = i+j+1;
                int sum = mul + result[p2];
                result[p1] += sum/10;
                result[p2] = sum%10;
            }
        }
        string ans = "";
        for(int num : result)
        {
            if(!(ans.empty() && num == 0))
            {
                ans+=to_string(num);
            }
        }
        return ans;
    }
};
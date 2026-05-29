class Solution {
public:
    string removeDuplicateLetters(string st) {
       int n = st.size();
       vector<int> count(26, 0);
       vector<bool> instack(26, false);
       stack<char> s;
       for(char c : st)
       {
        count[c-'a']++;
       }
       for(char c : st)
       {
        count[c-'a']--;
        if(instack[c-'a']) continue;
        while(!s.empty() && s.top()>c && count[s.top()-'a']>0)
        {
            instack[s.top()-'a'] = false;
            s.pop();
        }
        s.push(c);
        instack[c-'a'] = true;
    
    }
    string res = "";
    while(!s.empty())
    {
        res+=s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;}
};
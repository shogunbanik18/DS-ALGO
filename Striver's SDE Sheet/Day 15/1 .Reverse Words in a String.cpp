class Solution {
public:

// using stack data structure
string reverseWords(string s)
{
    int n = s.size();
    stack<string>st;
    string ans = "";
    string temp = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            temp.push_back(s[i]);
        }
        else if (temp != "")
        {
            st.push(temp);
            temp = "";
        }
    }
    if (temp != "")
    {
        st.push(temp);
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        if (!st.empty())
        {
            ans += ' ';
        }
    }
    return ans;
}
    
   // Using 2 pointer appraoch 
   string reverseWords(string s)
    {
        int n = s.size();
        vector<string>v;
        string a = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                a += s[i];
            }
            else
            {
                if (a.size() > 0)
                {
                    v.push_back(a);
                }
                a.clear();
            }
        }
        if (a.size() > 0)
        {
            v.push_back(a);
        }
        a.clear();

        for (int i = v.size() - 1; i > 0; i--)
        {
            a += v[i];
            a += ' ';
        }
        a += v[0];
        return a;
    }

};

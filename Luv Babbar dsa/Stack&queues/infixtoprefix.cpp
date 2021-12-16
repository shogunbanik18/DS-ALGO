#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }

    else if (c == '*' or c == '/')
    {
        return 2;
    }

    else if (c == '+' or c == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

string infixtoprefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    stack<char> st;
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z'))
        {
            res = res + s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() and st.top() != '(')
            {
                res = res + st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() and prec(st.top()) > prec(s[i]))
            {
                res = res + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res = res + st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixtoprefix(s) << endl;
    return 0;
}

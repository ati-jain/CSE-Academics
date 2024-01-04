#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    unordered_map<char, int> p;
    p.insert({'/', 1});
    p.insert({'*', 1});
    p.insert({'%', 1});
    p.insert({'+', 0});
    p.insert({'-', 0});

    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
            cout << s[i] << " ";
        else if (st.empty() || st.top() == '(') 
            st.push(s[i]);
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                cout << st.top() << " ";
                st.pop();
            }
            st.pop();
        }
        else if (p[s[i]] > p[st.top()])
            st.push(s[i]);
        else if (p[s[i]] == p[st.top()])
        {
            cout << st.top() << " ";
            st.pop();
            st.push(s[i]);
        }
        else
        {
            cout << st.top() << " ";
            st.pop();
            i--;
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
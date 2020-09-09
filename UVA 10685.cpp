#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, i, ans, sz[5001], p[5001];
string s1, s2, s[5001];
int find_parent(int a)
{
    return (p[a] == a) ? a : p[a] = find_parent(p[a]);
}

void Union(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if(a != b)
    {
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b]; sz[b] = 0;
        ans = max(ans, sz[a]);
    }
}

int main ()
{
    while(cin >> n >> m, n + m)
    {
        map < string, int > mp; ans = 1;
        for(i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
        for(i = 1; i <= n; i++)
        {
            cin >> s[i];
            mp[s[i]] = i;
        }
        while(m--)
        {
            cin >> s1 >> s2;
            u = mp[s1], v = mp[s2];
            Union(u, v);
        }
        cout << ans << endl;
    }
}

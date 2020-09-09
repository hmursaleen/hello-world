#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, k, i, ans, p[30001], sz[30001];

int find_parent(int x)
{
    return (p[x] == x) ? x : p[x] = find_parent(p[x]);
}

void Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return;
    if(x == 0 or y == 0)
    {
        if(y == 0) swap(x, y);
        p[y] = 0;
        ans += sz[y];
    }
    else
    {
        p[y] = x;
        sz[x] += sz[y];
    }
}

int main ()
{
    while(cin >> n >> m, n + m)
    {
        for(i = 0; i < n; i++) p[i] = i, sz[i] = 1; ans = 1;
        while(m--)
        {
            cin >> k >> a;
            while(--k)
            {
                cin >> b;
                Union(a, b);
            }
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m, u, v, i, kase, timer, low[101], tin[101];
bool vis[101], mark[101];
vector < int > adj[101]; vector < string > ans;
string s1, s2, s[101];
void dfs(int v, int p = 0)
{
    vis[v] = true; tin[v] = low[v] = ++timer;
    int child = 0;
    for(auto to : adj[v])
    {
        if(to == p) continue;
        if(vis[to]) low[v] = min(low[v], tin[to]);
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(tin[v] <= low[to] and p != 0) mark[v] = true;
            child++;
        }
    }
    if(child > 1 and p == 0) mark[v] = true;
}

int main ()
{
    while(cin >> n and n)
    {
        map < string, int > mp;
        for(i = 1; i <= n; i++)
        {
            cin >> s[i];
            mp[s[i]] = i;
        }
        cin >> m;
        while(m--)
        {
            cin >> s1 >> s2;
            u = mp[s1], v = mp[s2];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(i = 1; i <= n; i++) if(!vis[i]) dfs(i);
        for(i = 1; i <= n; i++) if(mark[i]) ans.pb(s[i]);
        sort(ans.begin(), ans.end());
        if(kase) printf("\n");
        printf("City map #%d: %d camera(s) found\n", ++kase, ans.size());
        for(auto it : ans) cout << it << endl;
        ans.clear(); timer = 0;
        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = mark[i] = false;
            tin[i] = low[i] = 0;
        }
    }
}

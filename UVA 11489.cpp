#include <bits/stdc++.h>
using namespace std;
int t, kase, i, in, sum, ans, len, cnt[10]; string s;
int main ()
{
    cin >> t;
    while(t--)
    {
        sum = ans = 0; for(i = 1; i <= 9; i++) cnt[i] = 0;
        cin >> s; len = s.size();
        for(i = 0; i < len; i++)
        {
            in = s[i] - '0';
            sum += in;
            cnt[in]++;
        }
        while(len)
        {
            if(len == 1) len--;
            else if(sum % 3 == 0)
            {
                if(cnt[3]) sum -= 3, cnt[3]--;
                else if(cnt[6]) sum -= 6, cnt[6]--;
                else if(cnt[9]) sum -= 9, cnt[9]--;
                else break;
                len--;
            }
            else if(sum % 3 == 1)
            {
                if(cnt[1]) sum--, cnt[1]--;
                else if(cnt[4]) sum -= 4, cnt[4]--;
                else if(cnt[7]) sum -= 7, cnt[7]--;
                else break;
                len--;
            }
            else if(sum % 3 == 2)
            {
                if(cnt[2]) sum -= 2, cnt[2]--;
                else if(cnt[5]) sum -= 5, cnt[5]--;
                else if(cnt[8]) sum -= 8, cnt[8]--;
                else break;
                len--;
            }
            ans++;
        }
        printf("Case %d: %c\n", ++kase, (ans & 1) ? 'S' : 'T');
    }
}

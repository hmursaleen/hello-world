#include <bits/stdc++.h>
using namespace std;
long long n, cnt;
int main ()
{
    while(cin >> n)
    {
        while(n > 1)
        {
            if(++cnt % 2 == 1) n = (n + 8) / 9;
            else n = (n + 1) / 2;
        }
        cout << ((cnt & 1) ? "Stan wins." : "Ollie wins.") << endl; cnt = 0;
    }
}

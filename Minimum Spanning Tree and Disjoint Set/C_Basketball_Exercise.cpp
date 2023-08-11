#include <bits/stdc++.h>
#define ld long double
#define gcd(a, b) __gcd(a, b)
#define ll long long
#define vll vector<ll>
#define vin vector<int>
#define vr(v) v.begin(), v.end()
#define rvr(x) x.rbegin(), x.rend()
#define fr(i, x, y) for (int i = x; i < y; i++)
#define putin(P)     \
    for (int &p : P) \
        cin >> p;
#define putll(X)           \
    for (long long &x : X) \
        cin >> x;
#define srt(v) sort(v.begin(), v.end());
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Akash cout.tie(NULL);

using namespace std;

ll f(ll ind1, vll h1, vll h2, int prev)
{

    if (prev == 0)
    {
        ll pick1 = h1[ind1] + f(ind1 + 1, h1, h2, 0);
        ll notPick1 = f(ind1 + 1, h1, h2, 1);
    }
    else
    {
        ll pick2 = h2[ind1] + f(ind1 + 1, h1, h2, 1);
        ll notPick2 = f(ind1 + 1, h1, h2, 0);
    }
}

void solve()
{

    ll n;
    cin >> n;
    vll h1(n), h2(n);
    putll(h1);
    putll(h2);

    cout << f(0, h1, h2, 0);
}

int main()
{
    Code By Akash
            cout
        << setprecision(10);

    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }

    return 0;
}
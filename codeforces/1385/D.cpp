/**
 *  Hi, I'm Arpan.
 *
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
#define inv(v)         \
    for (auto &it : v) \
        cin >> it;
#define MOD 1000000007
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define fi first
#define se second
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());

ll modPower(ll num,ll r) {
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

ll nCr(ll n, ll r) {
    ll res = 1;
    if (r > n - r) {
        r = n - r;
    }
    for(int i=0;i<r;i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

/*******************************************/

ll foo(char ch, int l, int r, string &s) {
  if (l == r) {
    if(s[l] ==ch) return 0;
    else return 1;
  }
  ll sizeq = r - l + 1;
  ll c = 0;
  for (int i = l; i < l + sizeq / 2; i++) {
    if (s[i] != ch) c++;
  }
  ll ans = c + foo(ch + 1, l + sizeq / 2, r, s);
  c = 0;
  for (int i = l + sizeq / 2; i <= r; i++) {
    if (s[i] != ch) c++;
  }
  ans = min(ans, c + foo(ch + 1, l, l + sizeq / 2 - 1, s));

  return ans;
}

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << foo('a', 0, n - 1, s) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
	cin >> t;

    while (t--)
        solve();
    return 0;
}



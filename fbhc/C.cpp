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

void solve()
{
	int n;
	cin >> n;
	vector<pair<ll,ll>> tree(n);
	for(int i=0;i<n;i++){
		cin >> tree[i].first >> tree[i].second;
	}
	sort(tree.begin(),tree.end());
	ll mx = 0;
	map<ll,ll> mp,mp1;

	for(int i=0;i<n;i++){
		mp[tree[i].fi+tree[i].se] = max(mp[tree[i].fi+tree[i].se],mp[tree[i].fi]+tree[i].se);
	}

	for(int i=n-1;i>=0;i--){
		mp1[tree[i].fi-tree[i].se] = max(mp1[tree[i].fi-tree[i].se],mp1[tree[i].fi]+tree[i].se);
	}

	for(auto x: mp) {
		mx = max(mx,x.second+mp1[x.first]);
	}

	for(auto x: mp1){
		mx  = max(mx,x.second+mp[x.first]);
	}

	cout << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
 freopen("timber_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   #endif
    int t;
    cin >> t;
    for(int t1 = 1;t1<=t;t1++){
		cout << "Case #" << t1 <<": ";
		solve();
    }
    return 0;
}


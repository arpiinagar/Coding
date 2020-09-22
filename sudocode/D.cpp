
// author: arpunagar

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
#define ar array
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define sortv(v) sort(v.begin(),v.end())
#define db(x) cout << (#x) << " is " << (x) << endl;
#define rsortv(v) sort(v.begin(),v.end(), greater<>());

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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	inv(a);
	vector<int> ans;
	for(int i=n-1;i>=0;i--){
		int pos = -1;
		for(int j = n-1;j>i && pos == -1;j--){
			if(a[j] < a[i]){
				pos = j;
			}
		}
		if(pos != -1)
		ans.pb(pos-i-1);
		else ans.pb(-1);
	}
	reverse(ans.begin(),ans.end());
	for(auto &x : ans) cout << x << " ";
	cout << endl;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int t = 1;

        while (t--)
            solve();
        return 0;
}





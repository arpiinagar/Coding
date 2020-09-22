
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

const int N = 1e5+1;
vector<int> adj[N];
vector<int> ans;
vector<bool> vis(N,false);
bool ans1 = true;
set<int> s;
void dfs(int i){
	if(!vis[i]){
		vis[i] = 1;
		s.insert(i);
		for(auto x: adj[i]) {
			dfs(x);
		}
		ans.push_back(i);
		s.erase(s.find(i));
	}
	else{
		if(s.find(i) != s.end()){
			ans1 = false;
		}
	}
}

void solve(){
	int n,e;
	cin >> n >> e;
	for(int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	set<int> s;
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	if(!ans1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	reverse(ans.begin(),ans.end());
	for(auto x: ans) cout << x << " ";
	cout << endl;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
		solve();
        return 0;
}





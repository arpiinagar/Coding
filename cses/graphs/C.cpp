#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MX = 2e5+1;
vector<int> adj[MX];
vector<bool> vis(MX,false);

void dfs(int i){
	if(vis[i]) return;
	vis[i] = true;
	for(auto u : adj[i]) dfs(u);
}

int main(){
	int n,e;
	cin >> n >> e;
	for(int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}

	ll c = 0;
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		else{
			ans.emplace_back(i);
			c++;
			dfs(i);
		}
	}

	if(c == 1){
		cout << 0 << endl;
	}
	else{
		cout << c -1 << endl;
		for(int i=0;i<ans.size()-1;i++){
			cout << ans[i]+1 << " " << ans[i+1]+1 << endl;
		}
	}
	cout << endl;

}

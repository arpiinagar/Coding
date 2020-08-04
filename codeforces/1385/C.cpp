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
//
void solve()
{
	int n;
	cin >> n;
	vi arr(n);
	inv(arr);
	vi b;
	b = arr;
	sortv(b);
	if(b == arr){
		cout << "0" << endl;
		return;
	}
	rsortv(b);
	if(b == arr){
		cout << "0" << endl;
		return;
	}
	if(n == 1){
		cout << "0" << endl;
		return;
	}
	int ok = 0;
	int dec,inc = 1;
	dec = 0;
	int mx = arr[n-1];
	int i;
	//1 3 1 4 5 3 2
	for(i=n-2;i>=0 && ok == 0;i--){
		if(arr[i] >= mx && dec == 0){
			mx = arr[i];
			inc = 1;
		}
		else if(arr[i] < mx && inc == 1){
			dec = 1;
			mx = arr[i];
		}
		else if(arr[i] > mx && dec == 1){
			ok = i+1;
		}
		//cout << arr[i] << " " << mx << endl;
	}
	if(ok == 0){
		cout << "0" << endl;
		return;
	}
	cout << i+2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
	cin >> t;

    while (t--)
        solve();
    return 0;
}



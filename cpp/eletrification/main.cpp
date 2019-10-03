#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
 
bool debug = 0;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl
 
const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 200100
 
int n, k;
ll a[N];
 
int main () {
 
	int t;
 
	cin >> t;
	while(t--) {
		scanf("%d %d", &n, &k);
		FOR(i,0,n) scanf("%lld", &a[i]);
		k++;
		
		int res = 2000000000, id;
		FOR(i,0,n-k+1) {
			ll x = (a[i+k-1] - a[i]);
			prin(x);
			if(res > (x+1)/2) {
				res = (x+1)/2;
				id = (x+1)/2 + a[i];
			}
		}
		
		cout << id << endl;
	}
 
 
	return 0;
 
}
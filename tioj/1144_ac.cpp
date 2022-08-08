#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 5;
const int M = 1000 + 5;
const int INF = 1<<30;

int arr[M], D[N][N], dp[N][N][2];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m; cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>D[i][j];
			dp[i][j][0]=dp[i][j][1]=INF;
		}
	}
	for(m=0;cin>>arr[m];m++);
	dp[2][3][0]=dp[3][2][0]=D[1][arr[0]];
	dp[3][1][0]=dp[1][3][0]=D[2][arr[0]];
	dp[1][2][0]=dp[2][1][0]=D[3][arr[0]];
	int pos=0;
	for(int k=0;k<m-1;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j][pos^1] = min(dp[i][j][pos^1], dp[i][j][pos]+D[arr[k]][arr[k+1]]);
				dp[i][arr[k]][pos^1] = min(dp[i][arr[k]][pos^1], dp[i][j][pos]+D[j][arr[k+1]]);
				dp[arr[k]][j][pos^1] = min(dp[arr[k]][j][pos^1], dp[i][j][pos]+D[i][arr[k+1]]);
				dp[i][j][pos]=INF;
			}
		}
		pos^=1;
	}
	int ans = INF;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		ans = min(ans, dp[i][j][pos]);
	cout<<ans<<'\n';
	return 0;
}

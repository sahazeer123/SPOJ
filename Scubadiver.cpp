#include <iostream>
#include <climits>
#define MAX 100000000
using namespace std;
int main()
{
	int no_test;
	cin >> no_test;
	for(int test = 0;test < no_test;++test)
	{
		int t,a;
		cin >> t >> a;
		int n;
		cin >> n;
		int oxygen[n];
		int nitrogen[n];
		int weight[n];
		for(int i = 0;i < n;++i)
			cin >> oxygen[i] >> nitrogen[i] >> weight[i];
		int dp[n][t+1][a+1];
		for(int i = 0;i < n;++i)
		{
			for(int j = 0;j <= t;++j)
			{
				for(int k = 0;k <= a;++k)
				{
					dp[i][j][k] = MAX;
					if(j == 0 && k == 0)
						dp[i][j][k] = 0;
					if(i == 0 && !(j == 0 && k == 0))
					{
						if(j <= oxygen[i] && k <= nitrogen[i])
							dp[0][j][k] = weight[0];
					}
					else
					{
						dp[i][j][k] = dp[i-1][j][k];
						if(oxygen[i] >= j && nitrogen[i] >= k)
							dp[i][j][k] = min(dp[i][j][k],weight[i]);
						else
						    dp[i][j][k] = min(dp[i][j][k],dp[i-1][max(0,j-oxygen[i])][max(0,k-nitrogen[i])]+weight[i]);
					}
				}
			}
		}
		cout << dp[n-1][t][a] << "\n";
	}	
	return 0;
}

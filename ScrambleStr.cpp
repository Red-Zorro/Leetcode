#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	//invariant: the length of two input strings are the same
    bool isScramble(string s1, string s2) {
		int len = s1.size();
        if(len==0)
			return true;
		if(len==1)
			return s1[0]==s2[0];
		vector<vector<vector<bool> > > dp(len, vector<vector<bool> >(len, vector<bool>(len, false)));
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				dp[0][i][j]=s1[i]==s2[j];
			}
		}
		for (int k = 2; k <= len; k++) {
			for(int i = len-k; i>=0;i--){
				for (int j = len-k; j>=0; j--) {
					for(int m=1; m<k&&!dp[k-1][i][j]; m++){
						dp[k-1][i][j]=(dp[m-1][i][j]&&dp[k-m-1][i+m][j+m])||(dp[m-1][i][j+k-m]&&dp[k-m-1][i+m][j]);
					}
				}
			}
		}
		return dp[len-1][0][0];
    }
};

int main(void)
{
    Solution sol;
	cout<<(sol.isScramble("great","rgtae")?"true":"false")<<endl;
    return 0;
}

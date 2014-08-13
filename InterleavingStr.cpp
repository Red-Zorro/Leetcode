#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if(s1.size()+s2.size()!=s3.size())
			return false;
        vector<vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1,false));
		dp[0][0]=true;
		for (int i = 1; i < s1.size()+1; i++) {
			dp[i][0]=dp[i-1][0] && s1[i-1]==s3[i-1];
		}
		for (int i = 1; i < s2.size()+1; i++) {
			dp[0][i]=dp[0][i-1] && s2[i-1]==s3[i-1];
		}
		for(int i=1; i<=s1.size(); i++){
			for (int j=1; j<=s2.size(); j++) {
				dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])
					||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
			}
		}
		return dp[s1.size()][s2.size()];
    }
};

int main(void)
{
    string s1="aabcc";
	string s2="dbbca";
	Solution sol;
	cout<<(sol.isInterleave(s1,s2,"aadbbcbcac")?"true":"false")<<endl;
	cout<<(sol.isInterleave(s1,s2,"aadbbbaccc")?"true":"false")<<endl;
    return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        vector<int> dp;
		int maxArea=0;
		for (int i = 0; i < matrix[0].size(); i++) {
			dp.push_back(matrix[0][i]-'0');
		}
		dp.push_back(0);
		for(int i=0; i<matrix.size(); i++){
			for(int j=1; j<dp.size();j++){
				int len = dp[j-1];
				for(int k=j-1;k>=0;k--){
					if(dp[k]>dp[j]){
						len=min(len,dp[k]);
						maxArea=max(maxArea, len*(j-k));
					}
					else
						break;
				}
			}
			if(i<matrix.size()-1){
				for(int j=0; j<matrix[0].size();j++){
					dp[j]=matrix[i+1][j]=='0'?0:dp[j]+1;
				}					
			}
		}
		return maxArea;
    }
};

int main(void)
{
    char arr[4][4]={{'1','0','0','1'},
					{'1','1','1','1'},
					{'1','1','1','1'},
					{'1','1','0','1'}};
	vector<vector<char> > v;
	for(int i=0; i<4; i++){
		v.push_back(vector<char>(arr[i],arr[i]+4));
	}
	Solution sol;
	cout<<sol.maximalRectangle(v)<<endl;
    return 0;
}

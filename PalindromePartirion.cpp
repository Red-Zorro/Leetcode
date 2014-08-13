#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
private:
	bool checkPalindrome(const string &str, int npos, int len){
		int mid=npos+len/2;
		if((len & 1)==1){
			for (int i=1; i <= len/2; i++) {
				if(str[mid-i]!=str[mid+i])
					return false;
			}
		}
		else{
			for(int i=0;i<len/2;i++){
				if(str[mid+i]!=str[mid-1-i])
					return false;
			}
		}
		return true;
	}
public:
    vector<vector<string> > partition(string s) {
		vector<vector<string> > v;
		vector<vector<int> > seq(s.size()+1, vector<int>());
		seq[0].push_back(-1);
		for(int i=1; i<=s.size(); i++){
			for(int j=0; j<i; j++){
				if(seq[j].size()>0&&checkPalindrome(s,j,i-j))
					seq[i].push_back(j);
			}
		}
		queue<pair<vector<string>, int> > q;
		for(int j=0; j<seq[s.size()].size();j++)
			q.push(make_pair(
					   vector<string>(1,s.substr(seq[s.size()][j],s.size()-seq[s.size()][j])),
					   seq[s.size()][j]));
		while(!q.empty()){
			pair<vector<string>, int> tmp=q.front();
			q.pop();
			if(seq[tmp.second][0]==-1){
				v.push_back(tmp.first);
			}
			else{
				for(int i=0;i<seq[tmp.second].size();i++){
					tmp.first.push_back(s.substr(seq[tmp.second][i],tmp.second-seq[tmp.second][i]));
					q.push(make_pair(tmp.first, seq[tmp.second][i]));
					tmp.first.pop_back();
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			reverse(v[i].begin(), v[i].end());
		}
		
		return v;
    }

	int minCut(string s) {
        vector<int> seq(s.size()+1);
		vector<vector<bool> > flag(s.size(), vector<bool>(s.size(),false));
		seq[0]=-1;
		for(int i=1; i<=s.size(); i++){
			seq[i]=i;
			for(int j=0; j<i; j++){
				if(s[j]==s[i-1]&&(i-j<3||flag[j+1][i-2])){
					flag[j][i-1]=true;
					seq[i]=min(seq[i],seq[j]+1);
				}
			}
		}
		return seq[s.size()];
    }
};

int main(int argc, char *argv[])
{
	if(argc!=2){
		cout<<"No Parameters"<<endl;
		return -1;
	}
    Solution sol;
	vector<vector<string> > v = sol.partition(string(argv[1]));
	for (int i = 0; i < v.size(); i++) {
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<sol.minCut(string(argv[1]))<<endl;
    return 0;
}

//DP
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    bool wordBreakI(string s, unordered_set<string> &dict) {
        if(s.size()==0)
			return true;
		if(dict.empty())
			return false;
		vector<bool> flag(s.size()+1, false);
		flag[0]=true;
		for(int i=1;i<=s.size();i++){
			for (int j = 0; j < i && !flag[i]; j++) {
				flag[i] = flag[j] && dict.find(s.substr(j,i-j))!=dict.end();
			}
		}
		return flag[s.size()];
    }

	vector<string> wordBreakII(string s, unordered_set<string> &dict) {
        vector<string> v;
		if(s.size()==0||dict.empty())
			return v;
		vector<vector<int> > seq(s.size()+1, vector<int>());
		seq[0].push_back(-1);
		for(int i=1;i<=s.size();i++){
			for (int j = 0; j < i; j++) {
				if(seq[j].size()>0&&dict.find(s.substr(j,i-j))!=dict.end())
					seq[i].push_back(j);
			}
		}
		queue<pair<string, int> > q;
		for(int j=0; j<seq[s.size()].size();j++)
			q.push(make_pair(s.substr(seq[s.size()][j],s.size()-seq[s.size()][j]),seq[s.size()][j]));
		while(!q.empty()){
			pair<string, int> tmp=q.front();
			q.pop();
			if(seq[tmp.second][0]==-1){
				v.push_back(tmp.first);
			}
			else{
				for(int i=0;i<seq[tmp.second].size();i++){
					string stmp=s.substr(seq[tmp.second][i],tmp.second-seq[tmp.second][i])+" "+tmp.first;
					q.push(make_pair(stmp, seq[tmp.second][i]));
				}
			}
		}
		return v;
    }
};

int main(void)
{
    string test[5] = {"cat", "cats", "and", "sand", "dog"};
	unordered_set<string> dict;
	for (int i = 0; i < 5; i++) {
		dict.insert(test[i]);
	}
	Solution sol;
	// test case for word break I
	cout<<(sol.wordBreakI("catsanddog", dict)==true?"true":"false")<<" true"<<endl;
	cout<<(sol.wordBreakI("catnddog", dict)==true?"true":"false")<<" false"<<endl;	
	vector<string> v=sol.wordBreakII("catsanddog", dict);
	// test case for word break II
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<endl;
	}
    return 0;
}



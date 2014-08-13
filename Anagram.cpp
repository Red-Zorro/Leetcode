#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> rlt;
		if(strs.size()<1)
			return rlt;
		unordered_map<string, int> set;
		for(int i=0; i<strs.size(); i++){
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if(set.find(tmp)==set.end()){
				set.insert(make_pair(tmp, i));
			}
			else{
				if(set[tmp]>=0){
					rlt.push_back(strs[set[tmp]]);
					set[tmp]=-1;
				}
				rlt.push_back(strs[i]);
			}
		}
		return rlt;
    }
};

int main(void)
{
    string arr[5]={"tea","and","ate","eat","den"};
	vector<string> v(arr,arr+5);
	Solution sol;
	vector<string> rlt = sol.anagrams(v);
	for(int i=0;i<rlt.size();i++){
		cout<<rlt[i]<<" ";
	}
	cout<<endl;
	return 0;
}

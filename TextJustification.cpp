#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> set;
		if(words.size()==0||words[0].size()>L)
			return set;
		int start=0, cnt=0;
		for(int end=0; end<words.size(); end++){
			if(cnt+end+(int)words[end].size()-start>L){
				if(end-start>1){
					int gap = (L - cnt)/(end-start-1);
					int mod = (L - cnt)%(end-start-1);
					string tmp="";
					for(int i=start; i<end-1; i++){
						tmp+=words[i]+string(gap, ' ');
						if(i-start<mod)
							tmp.push_back(' ');
					}
					tmp+=words[end-1];
					set.push_back(tmp);
				}
				else{
					set.push_back(words[start]+string(L-words[start].size(),' '));
				}
				start=end;
				cnt=words[end].size();
				if(cnt>L)
					return vector<string>();
			}
			else
				cnt+=words[end].size();
		}
		cout<<set.size()<<endl;
		string tmp="";
		for(int i=start; i<words.size(); i++){
			tmp+=words[i];
			if(i<words.size()-1)
				tmp.push_back(' ');
		}
		if(L+start-cnt-(int)words.size()+1>0){
			tmp+=string(L+start-cnt-words.size()+1, ' ');
		}
		set.push_back(tmp);
		return set;
    }
};

int main(void)
{
    string tmp[9]={"This","is","an","example","of","text","justification.","another","test"};
	vector<string> v(tmp, tmp+9);
	Solution sol;
	vector<string> rlt=sol.fullJustify(v,16);
	for (int end = 0; end < rlt.size(); end++) {
		cout<<rlt[end]<<"||"<<endl;
	}
	v=vector<string>(1,"a");
	rlt=sol.fullJustify(v,2);
	for (int end = 0; end < rlt.size(); end++) {
		cout<<rlt[end]<<"||"<<endl;
	}
	return 0;
}

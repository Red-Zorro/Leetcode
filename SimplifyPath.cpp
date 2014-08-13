#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		string str;
		if(path.size()==0)
			return str;
		vector<string> v;
		string tmp="";
		int i, cnt=0;
		for (i = 0; i <= path.size(); i++) {
			if(i==path.size()||path[i]=='/'){
				if(tmp.size()==2&&tmp[0]=='.'&&tmp[1]=='.'){
					if(cnt>0)
					cnt--;
				}
				else if(tmp.size()==1&&tmp[0]=='.');
				else if(tmp.size()>0&&cnt==v.size()){
					v.push_back(tmp);
					cnt++;
				}
				else if(tmp.size()>0&&cnt>=0&&cnt<v.size())
					v[cnt++]=tmp;
				tmp.clear();
			}
			else{
				tmp.push_back(path[i]);
			}
		}
		if(cnt>0){
			for (i = 0; i < cnt; i++) {
				str.push_back('/');
				str += v[i];
			}
		}
		else
			str.push_back('/');
		return str;
    }
};

int main(void)
{
	const int N=8;
    string testCase[N][2]={
		{"/","/"},
		{"/home/","/home"},
		{"/a/./b/../../c/","/c"},
		{"/home//foo/","/home/foo"},
		{"/../","/"},
		{"/.hidden/","/.hidden"},
		{"/...","/..."},
		{"/home/../../..","/"}
	};
	Solution sol;
	for (int i = 0; i < N; i++) {
		cout<<"Case "<<i+1<<" "<<sol.simplifyPath(testCase[i][0])<<"=="<<testCase[i][1]<<endl;
	}
    return 0;
}

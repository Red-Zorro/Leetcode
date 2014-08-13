#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	bool isValid(string &str, int left, int len){
		if(str[left]=='0'&&len>1)
			return false;
		int sum=0;
		for(int i=left;i<left+len;i++){
			sum=sum*10+str[i]-'0';
		}
		return sum<256;
	}
	
	void DFS(vector<string> &set, string &str, string &tar, int num, int pt){
		if(str.size()-pt>12-3*num)
			return;
		if(num==4&&pt==str.size()){
			set.push_back(tar);
			return;
		}
		if(num>0)
			tar.push_back('.');
		for(int i = 1; i < 4; i++){
			if(isValid(str, pt, i)){
				for(int j=0; j<i; j++)
					tar.push_back(str[pt+j]);
				DFS(set, str, tar, num+1, pt+i);
				for(int j=0; j<i; j++)
					tar.pop_back();
			}
		}
		if(num>0)
			tar.pop_back();
	}
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> v;
		if(s.size()<4||s.size()>12)
			return v;
		string tmp;
		DFS(v, s, tmp, 0, 0);
		return v;
    }
};

void print(string s){
	Solution sol;
	vector<string> v = sol.restoreIpAddresses(s);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<endl;
	}
}

int main(void)
{
	const int N=4;
	string set[N]={"255255255255", "0000","112112112","103574606193"};
	for(int i=0; i<N; i++){
		cout<<"case "<<i+1<<" :"<<endl;
		print(set[i]);
	}
    return 0;
}

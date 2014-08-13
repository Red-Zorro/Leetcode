#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
		int map[256]={0}, cur[256]={0};
		for(int i=0; i<T.size();i++)
			map[T[i]]++;
		int start=0, cnt=0, len=S.size()+1, begin;
		for(int end=0; end<S.size(); end++){
			if(map[S[end]]==0)
				continue;
			if(cur[S[end]]<map[S[end]])
				cnt++;
			cur[S[end]]++;
			if(cnt==T.size()){
				while(start<=end&&(map[S[start]]==0||map[S[start]]<cur[S[start]])){
					if(map[S[start]]>0)
						cur[S[start]]--;
					start++;
				}
				int tmp=end-start+1;
				if(len>tmp&&start<=end){
					len = tmp;
					begin = start;
				}
				cur[S[start]]--;
				start++;
				cnt--;
			}
		}
		return len>S.size()?"":S.substr(begin, len);
    }
};

int main(void)
{
    Solution sol;
	cout<<sol.minWindow("ADOBECODEBANC","ABC")<<endl;
    return 0;
}


#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> words, cur;
        int wordNum = L.size();
        int wordLen = L[0].size();
        vector<int> v;
        for(int k = 0;k<wordNum;k++){
			if(words.find(L[k])==words.end())
				words.insert(make_pair(L[k],1));
			else
				words[L[k]]++;
		}
        for(int i = 0; i <= (int)S.size()-wordLen*wordNum; i++)
        {
			cur.clear();
			int j=0;
			while(j<wordNum)
			{
				string word = S.substr(i+j*wordLen,wordLen);
				if(words.find(word) == words.end())
					break;
				cur[word]++;
				if(words[word]<cur[word])
					break;
				j++;
			}
			if(j == wordNum)
				v.push_back(i);
        }
        return v;
    }
};

void printResult(vector<string> & v, string s){
	Solution sol;
	vector<int> set = sol.findSubstring(s, v);
	for (int i = 0; i < set.size(); i++) {
		cout<<set[i]<<" ";
	}
}

int main(void)
{
	vector<string> v;
	string str1[2] = {"foo", "bar"};
	v = vector<string>(str1, str1+2);
	printResult(v, "barfoothefoobarman");
	cout<<" ans: 0 9"<<endl;

	string str2[5]={"fooo","barr","wing","ding","wing"};
	v = vector<string>(str2, str2+5);
	printResult(v,"lingmindraboofooowingdingbarrwingmonkeypoundcake");
	cout<<" ans: 13"<<endl;

	string str3[2]={"a","a"};
	v = vector<string>(str3, str3+2);
	printResult(v,"a");
	cout<<" ans: "<<endl;
	
	string str4[2]={"a","a"};
	v = vector<string>(str4, str4+2);
	printResult(v,"aaa");
	cout<<" ans: 0 1"<<endl;
	
 	string str5[2]={"a","b"};
	v = vector<string>(str5, str5+2);
	printResult(v,"aaa");
	cout<<" ans: "<<endl;

 	string str6[4]={"ab","ba","ab","ba"};
	v = vector<string>(str6, str6+4);
	printResult(v,"abaababbaba");
	cout<<" ans: 1 3"<<endl;
    return 0;
}

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int i=0, j=0;
		int star = -1;
		int tmp = -1;
		while(s[i]!='\0'){
			if(s[i]==p[j]||p[j]=='?'){
				i++, j++;
			}
			else if(p[j]=='*'){
				star = j;
				tmp = i;
				j++;
			}
			else if(star!=-1){
				j = star+1;
				i = ++tmp;
			}
			else
				return false;
		}
		while(p[j]=='*')
			j++;
		return p[j]=='\0';
    }
};

void judge(const char *s, const char *p){
	Solution sol;
	cout<<(sol.isMatch(s, p)?"true":"false")<<endl;
}

int main(void)
{
    judge("aa","a");
	cout<<"false"<<endl<<endl;
	
    judge("aa","aa");
	cout<<"true"<<endl<<endl;
	
    judge("aaa","aa");
	cout<<"false"<<endl<<endl;
	
    judge("aa","*");
	cout<<"true"<<endl<<endl;
	
	judge("aa","a*");
	cout<<"true"<<endl<<endl;

	judge("aa","*a");
	cout<<"true"<<endl<<endl;
	
	judge("aa","?*");
	cout<<"true"<<endl<<endl;
	
	judge("aab","c*a*b");
	cout<<"false"<<endl<<endl;

	judge("b","*a*");
	cout<<"false"<<endl<<endl;

	judge("","*");
	cout<<"true"<<endl<<endl;

	judge("b","*?*?");
	cout<<"false"<<endl<<endl;

	judge("hi","*?");
	cout<<"true"<<endl<<endl;
    return 0;
}

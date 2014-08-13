#include <iostream>

using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p){
		if(s==NULL || p==NULL)
			return false;
		if(*p=='\0')
			return *s == '\0';
		if(*(p+1)=='*'){
			while ((*s != '\0'&&*p == '.') || *s==*p){
				if(isMatch(s, p+2))
					return true;
				s++;
			}
			// * match zero times
			return isMatch(s, p + 2);
		}
		else if ((*s != '\0' && *p == '.') || *s == *p){
			return isMatch(s + 1, p + 1);
		}
		return false;
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
	
    judge("aa",".a");
	cout<<"true"<<endl<<endl;
	
	judge("aa","a*");
	cout<<"true"<<endl<<endl;

	judge("aa",".*");
	cout<<"true"<<endl<<endl;
	
	judge("ab",".*");
	cout<<"true"<<endl<<endl;
	
	judge("aab","c*a*b");
	cout<<"true"<<endl<<endl;

    return 0;
}

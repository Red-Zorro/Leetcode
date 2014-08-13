#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
		long long tmp=0;
        while(*str==' ')
			str++;
		if(!*str)
			return 0;
		int sign = 1;
		if(*str=='-'||*str=='+'){
			if(*str=='-')
				sign *= -1;
			str++;
		}
		while(*str>='0'&&*str<='9'){
			tmp=tmp*10+*str-'0';
			if(tmp*sign>=INT_MAX)
				return INT_MAX;
			else if(tmp*sign<=INT_MIN)
				return INT_MIN;
			str++;
		}
		return (int)tmp*sign;
    }
};

int main(int argc, char *argv[])
{
    if(argc!=2){
		cout<<"No Parameters"<<endl;
		return -1;
	}
	Solution sol;
	cout<<sol.atoi(argv[1])<<" "<<atoi(argv[1])<<endl;
	return 0;
}

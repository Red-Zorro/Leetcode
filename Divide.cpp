#include "Timer.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = (divisor>0&&dividend>0)||(divisor<0&&dividend<0)?1:-1;
		long long absDividend = abs((long long)dividend);
		long long absDivisor = abs((long long)divisor);
		if(absDividend<absDivisor)
			return 0;
		if(absDividend==absDivisor)
			return sign;
		int cnt, rlt=0;
		long long sum;
		while(absDividend>=absDivisor){
			cnt=1; sum=absDivisor;
			while(sum+sum<=absDividend){
				sum+=sum;
				cnt+=cnt;
			}
			absDividend-=sum;
			rlt+=cnt;
		}
		return rlt*sign;
	}														   
};

int main(void)
{
    Solution sol;
	Timer timer;
	timer.begin();
	cout<<sol.divide(4,2)<<" 2"<<endl;
	cout<<setiosflags(ios::fixed)<<timer.count()<<endl;
	timer.begin();
	cout<<sol.divide(2147483647,2)<<" 1073741823"<<endl;
	cout<<setiosflags(ios::fixed)<<timer.count()<<endl;
	timer.begin();
	cout<<sol.divide(-4,2)<<" -2"<<endl;
	cout<<setiosflags(ios::fixed)<<timer.count()<<endl;
	timer.begin();
	cout<<sol.divide(-4,-2)<<" 2"<<endl;
	cout<<setiosflags(ios::fixed)<<timer.count()<<endl;
	timer.begin();
	cout<<sol.divide(5,1)<<" 5"<<endl;
	cout<<setiosflags(ios::fixed)<<timer.count()<<endl;
    return 0;
}


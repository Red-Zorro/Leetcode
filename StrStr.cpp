//KMP Algorithm
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
private:
	int *buildNext(char *p){
		int m = strlen(p), j=0;
		int *N = new int[m];
		int t = N[0] = -1;
		while(j<m-1){
			if(t<0||p[j] == p[t])
				N[++j] = ++t;
			else
				t = N[t];
		}
		return N;
	}
public:
    char *strStr(char *haystack, char *needle) {
        int* next = buildNext(needle);
		int n = (int) strlen(haystack), i=0;
		int m = (int) strlen(needle), j=0;
		while(i<n && j<m){
			if(j<0 || haystack[i]==needle[j]){
				i++;
				j++;
			}
			else
				j = next[j];
		}
		if(j<m)
			return NULL;
		delete[] next;
		return haystack+i-j;
    }
};

void printStr(char *s){
	char *tmp = s;
	while(tmp!=NULL && *tmp){
		cout<<*tmp;
		tmp++;
	}
	cout<<endl;
}

int main(void)
{
	Solution sol;
	char *t = "Hello worworld!";
	char *p = "world";
	printStr(sol.strStr(t, p));
    return 0;
}

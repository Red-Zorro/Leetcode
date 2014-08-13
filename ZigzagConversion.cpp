#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
        if (s.size() <= nRows || nRows <= 1)
			return s;
        string str;
        // the first row
        for (int i = 0; i < s.size(); i += (nRows - 1) * 2) {
            str.push_back(s[i]);
        }
        
        for (int i = 1; i < nRows - 1; i++) {
            for (int j = i; j < s.size(); j+= (nRows - 1) * 2) {
                str.push_back(s[j]);
                if (j + (nRows - i - 1) * 2 < s.size()) {
                    str.push_back(s[j + (nRows - i - 1) * 2]);
                }
            }
        }
        // the last row
        for (int i = nRows - 1; i < s.size(); i += (nRows - 1) * 2) {
            str.push_back(s[i]);
        }
        return str;
    }
};

int main(void)
{
    Solution sol;
	cout<<sol.convert("PAYPALISHIRING",3)<<endl;
	cout<<"PAHNAPLSIIGYIR"<<endl;
    return 0;
}

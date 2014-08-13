#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		if(ratings.size()==0)
			return 0;
		int total = 1;    /// Total candies
		int len = 0;  /// Continuous descending length of rate
		int nPreCanCnt = 1; /// Previous child's candy count
		int beforeDenc = nPreCanCnt;
        for(auto i = ratings.begin()+1; i!= ratings.end(); i++)
        {
            if(*i < *(i-1))
            {
                len++;
                total += len + (beforeDenc <= len?1:0);
                nPreCanCnt = 1;    //This step is important,
				//it ensures that once we leave the decending sequence,
				//candy number start from 1
            }
            else
            {
                int curCanCnt = (*i > *(i-1))?nPreCanCnt + 1:1;
                total += curCanCnt;
                nPreCanCnt = curCanCnt;
                len = 0;    //reset length of decending sequence
                beforeDenc = curCanCnt;
            }
        }
		return total;
    }
};

int main(void)
{
    int arr[]={1,4,3,2,1};
	vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<sol.candy(v)<<endl;
    return 0;
}


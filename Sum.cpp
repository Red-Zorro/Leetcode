#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > v;
		if(num.size()<3)
		return v;
        sort(num.begin(),num.end());
        for(int i=0; i<num.size()-2;i++){
    		if(i > 0 && num[i]==num[i-1])
				continue;
			int j,k;
			j=i+1;
			k=num.size()-1;
			while(j<k){
				if(j>i+1&&num[j]==num[j-1]){ 
					j++;
					continue;
				}
				if(k<num.size()-1&& num[k]==num[k+1]){
					k--;
					continue;
				}
				int sum = num[i] + num[j] + num[k];
				if(sum>0)
					k--;
				else if(sum<0)
					j++;
				else{
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);
					v.push_back(tmp);
					j++;
				}
			}
		}
		return v;            
    }

	int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3)
		return 0;
        sort(num.begin(),num.end());
		int rlt=num[0]+num[1]+num[2];
        for(int i=0; i<num.size()-2;i++){
    		if(i > 0 && num[i]==num[i-1])
				continue;
			int j,k,sum;
			j=i+1;
			k=num.size()-1;
			while(j<k){
				if(j>i+1&&num[j]==num[j-1]){ 
					j++;
					continue;
				}
				if(k<num.size()-1&& num[k]==num[k+1]){
					k--;
					continue;
				}
				sum = num[i] + num[j] + num[k];
				if(abs(rlt-target)>abs(sum-target))
					rlt=sum;
				if(sum>target)
					k--;
				else if(sum<target)
					j++;
				else{
					rlt=target;
					break;
				}
			}
		}
		return rlt;
    }

	vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > v;
		if(num.size()<4)
		return v;
        sort(num.begin(),num.end());
		int rlt=num[0]+num[1]+num[2]+num[3];
		for(int m=0; m<num.size()-3;m++){
			if(m > 0 && num[m]==num[m-1])
				continue;
			for(int i=m+1; i<num.size()-2;i++){
				if(i > m+1 && num[i]==num[i-1])
				continue;
				int j,k;
				j=i+1;
				k=num.size()-1;
				while(j<k){
					if(j>i+1&&num[j]==num[j-1]){ 
						j++;
						continue;
					}
					if(k<num.size()-1&& num[k]==num[k+1]){
						k--;
						continue;
					}
					int sum = num[m]+num[i] + num[j] + num[k];
					if(sum>target)
						k--;
					else if(sum<target)
						j++;
					else{
						vector<int> tmp;
						tmp.push_back(num[m]);
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[k]);
						v.push_back(tmp);
						j++;
					}
				}
			}
		}
		return v;
    }
};

int main(void)
{
	Solution sol;
	vector<int> tmpVector;
	vector<vector<int> > v;
	clock_t start, end;
    // int tmp[]={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	// vector<int> arr(tmp, tmp+sizeof(tmp)/sizeof(int));
	// start=clock();
	// v = sol.threeSum(arr);
	// end=clock();
	// for (int i = 0; i < v.size(); i++) {
	// 	for (int j = 0; j < v[i].size(); j++)
	// 		cout<<v[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<(float)(end-start)/CLOCKS_PER_SEC<<endl;
	// int tmp2[]={-1,2,1,-4};//-4 -1 1 2
	// tmpVector=vector<int>(tmp2, tmp2+sizeof(tmp2)/sizeof(int));
	// cout<<sol.threeSumClosest(tmpVector,1)<<" 2"<<endl;

	// int tmp3[]={1,1,1,0};//0 1 1 1
	// tmpVector=vector<int>(tmp3, tmp3+sizeof(tmp3)/sizeof(int));
	// cout<<sol.threeSumClosest(tmpVector,100)<<" 3"<<endl;

	int tmp4[]={1,0,-1,0,-2,2};
	tmpVector=vector<int>(tmp4, tmp4+sizeof(tmp4)/sizeof(int));
	start=clock();
	v = sol.fourSum(tmpVector, 0);
	end=clock();
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;

	int tmp5[]={1,1,1,1,1,1,1,1,1,1,1,-3};
	tmpVector=vector<int>(tmp5, tmp5+sizeof(tmp5)/sizeof(int));
	start=clock();
	v = sol.fourSum(tmpVector, 0);
	end=clock();
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	
	int tmp6[]={0,0,0,0};
	tmpVector=vector<int>(tmp6, tmp6+sizeof(tmp6)/sizeof(int));
	v = sol.fourSum(tmpVector, 0);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}

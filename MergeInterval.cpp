#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		if(intervals.size()==0)
			return intervals;
		int i=0;
		sort(intervals.begin(),intervals.end());
        while(i<intervals.size()-1){
			if(intervals[i+1].start<=intervals[i].end){
				intervals[i].end=max(intervals[i+1].end, intervals[i].end);
				intervals.erase(intervals.begin()+i+1);
			}
			else
				i++;
			// for (int k = 0; k < intervals.size(); k++) {
			// 	cout<<"("<<intervals[k].start<<","<<intervals[k].end<<") ";
			// }
			// cout<<endl;
		}
		return intervals;
    }
};

void test(int *arr, int size){
	static int index=0;
	vector<Interval> v;
	for (int i=0; i < size; i++) {
		v.push_back(Interval(arr[2*i],arr[2*i+1]));
	}
	Solution sol;
	v=sol.merge(v);
	cout<<"case "<<++index<<endl;
	for (int i = 0; i < v.size(); i++) {
		cout<<"("<<v[i].start<<","<<v[i].end<<") ";
	}
	cout<<endl;
}

int main(void)
{
	int arr1[6][2]={{1,2},{3,5},{4,9},{6,7},{8,10},{12,16}};
	test((int *)arr1, 6);
	int arr2[3][2]={{1,2},{3,6},{10,12}};
	test((int *)arr2, 3);
	int arr3[3][2]={{1,3},{3,6},{10,12}};
	test((int *)arr3, 3);
	int arr4[3][2]={{1,13},{3,6},{10,12}};
	test((int *)arr4, 3);
	int arr5[5][2]={{1,4},{0,4}};
	test((int *)arr5, 2);
    return 0;
}

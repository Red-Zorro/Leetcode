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

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> v;
		if(intervals.size()==0){
			v.push_back(newInterval);
			return v;
		}
		if(newInterval.end<intervals[0].start){
			v.push_back(newInterval);
			v.insert(v.begin()+1,intervals.begin(),intervals.end());
			return v;
		}
		if(newInterval.start>intervals[intervals.size()-1].end){
			v.insert(v.begin(), intervals.begin(),intervals.end());
			v.push_back(newInterval);
			return v;
		}
		bool flag = false;
		for(int i=0;i<intervals.size();i++){
			if(((newInterval.start>=intervals[i].start
				 &&newInterval.start<=intervals[i].end)||
				(newInterval.end>=intervals[i].start
				 &&newInterval.end<=intervals[i].end)||
				(newInterval.end>=intervals[i].end
				 &&newInterval.start<=intervals[i].start))&&!flag){
				flag = true;
				newInterval.start=min(intervals[i].start, newInterval.start);
				newInterval.end=max(intervals[i].end, newInterval.end);
			}
		    else if(flag && newInterval.end>=intervals[i].start){
				newInterval.end=max(newInterval.end, intervals[i].end);
			}
			else{
				if(flag||(newInterval.end<intervals[i].start&&newInterval.start>intervals[i-1].end)){
					v.push_back(newInterval);
					flag=false;
				}
				v.push_back(intervals[i]);
			}
		}
		if(flag){
			v.push_back(newInterval);
		}
		return v;
    }
};
void test(int *arr, int size){
	static int index=0;
	vector<Interval> v;
	int i=0;
	for (; i < size; i++) {
		v.push_back(Interval(arr[2*i],arr[2*i+1]));
	}
	Solution sol;
	v=sol.insert(v, Interval(arr[2*i],arr[2*i+1]));
	cout<<"case "<<++index<<endl;
	for (i = 0; i < v.size(); i++) {
		cout<<"("<<v[i].start<<","<<v[i].end<<") ";
	}
	cout<<endl;
}

int main(void)
{
	int arr1[6][2]={{1,2},{3,5},{6,7},{8,10},{12,16},{4,9}};
	test((int *)arr1, 5);
	int arr2[3][2]={{1,3},{6,9},{2,5}};
	test((int *)arr2, 2);
	int arr3[3][2]={{3,6},{10,12},{1,2}};
	test((int *)arr3, 2);
	int arr4[3][2]={{3,6},{10,12},{1,3}};
	test((int *)arr4, 2);
	int arr5[3][2]={{3,6},{10,12},{1,13}};
	test((int *)arr5, 2);
	int arr6[3][2]={{3,6},{10,12},{7,8}};
	test((int *)arr6, 2);
    return 0;
}

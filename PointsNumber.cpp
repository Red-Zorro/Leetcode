#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		unordered_map<float, int> cntSet;
		int maxNum=0;
		for(int i=0; i<points.size(); i++){
			int duplicate=1;
			cntSet.clear();
			cntSet[INT_MIN]=0;
			for(int j=0; j<points.size();j++){
			    if(i==j)
			    continue;
			    if(points[i].x==points[j].x&&points[i].y==points[j].y){
			        duplicate++;
			        continue;
			    }
				float k=points[i].x==points[j].x?INT_MAX:(float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
			    cntSet[k]++;
			}
			for(auto it=cntSet.begin(); it != cntSet.end(); it++){
				if(it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
			}
		}
		return maxNum;
    }
};

int main(void)
{
    cout<<"test"<<endl;
    return 0;
}

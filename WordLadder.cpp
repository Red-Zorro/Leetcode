#include <string>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

#include <ctime>
class Timer{
private:
	clock_t start;
public:
	double count(){
		clock_t end = clock();
		return (double)(end-start)/CLOCKS_PER_SEC;
	};
	void begin(){
		start = clock();
	};
};

//adjacent lists
class Solution {
private:
	vector<vector<string> > result;	
	void  GeneratePath(unordered_map<string, vector<string> > &prevMap, vector<string>& path, const string& word)
    {
		if (prevMap[word].size() == 0)
        {
            vector<string> curPath = path;
			curPath.push_back(word);
            reverse(curPath.begin(), curPath.end());
            result.push_back(curPath);
            return;
        }
        path.push_back(word);
        for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
            GeneratePath(prevMap, path, *iter);
        path.pop_back();
    }
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> map;
		map.insert(make_pair(start,1));
		for(auto iter = dict.begin(); iter != dict.end(); iter++){
			map.insert(make_pair(*iter,0));
		}
		map.insert(make_pair(end,0));
		queue<string> q;
		q.push(start);
		int len = start.size();
		while(!q.empty()){
			string tmp = q.front();
			q.pop();
			if(tmp == end)
				break;
			int tmpCnt = map[tmp];
			for(int i=0; i<len; i++){
				for(int j=0; j<26; j++){
					tmp[i]++;
					if(tmp[i]>'z')
						tmp[i]-=26;
					auto iter = map.find(tmp);
					if(iter !=map.end() && iter->second == 0){
						iter->second = tmpCnt+1;
						q.push(tmp);
					}
				}
			}
		}
		return map[end];
    }

	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		result.clear();
		dict.insert(end);
        unordered_map<string, vector<string> > prevMap;
        for(auto iter = dict.begin(); iter != dict.end(); ++iter)
            prevMap[*iter] = vector<string>();
        vector<unordered_set<string> > candidates(2);
        int current = 0;
        int previous = 1;
        candidates[current].insert(start);
        while(true)
        {
            current = !current;
            previous = !previous;
            for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
                dict.erase(*iter);
            candidates[current].clear();            
            for(auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
            {
                for(size_t pos = 0; pos < iter->size(); ++pos)
                {
                    string word = *iter;
                    for(int i = 'a'; i <= 'z'; ++i)
                    {
                        if(word[pos] == i)
							continue;
                        word[pos] = i;
                        if(dict.find(word) !=dict.end())
                        {
                            prevMap[word].push_back(*iter);
                            candidates[current].insert(word);
                        }
                    }
                }
            }
            if (candidates[current].size() == 0)
                return result;
            if (candidates[current].find(end) != candidates[current].end())
				break;
        }
        vector<string> path;
        GeneratePath(prevMap, path, end);
        return result;
    }
};

int main(void)
{
	Timer timer;
    string start = "hit";
	string end = "cog";
	string set[5]={"hot","dot","dog","lot","log"};
	unordered_set<string> dict;
	for(int i=0; i<5; i++){
		dict.insert(set[i]);
	}
	timer.begin();
	Solution sol;
	cout<<sol.ladderLength(start, end, dict)<<endl;
	vector<vector<string> > v = sol.findLadders(start, end, dict);
	for (int i=0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<timer.count()<<endl;
	timer.begin();
	start = "a";
	end = "c";
	string set2[3]={"a", "b", "c"};
	dict.clear();
	for(int i=0; i<3; i++){
		dict.insert(set2[i]);
	}
	v = sol.findLadders(start, end, dict);
	for (int i=0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<timer.count()<<endl;
	timer.begin();

	start = "red";
	end = "tax";
	string set3[8]={"ted","tex","red","tax","tad","den","rex","pee"};
	dict.clear();
	for(int i=0; i<8; i++){
		dict.insert(set3[i]);
	}
	v = sol.findLadders(start, end, dict);
	for (int i=0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<timer.count()<<endl;
	return 0;
}

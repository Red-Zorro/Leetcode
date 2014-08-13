//DFS algorithm

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
private:
	bool DFS(vector<vector<char> > &board, const string &word, int index, int loc[]){
		if(index==word.size())
			return true;
		for (int i = 0; i < 4; i++) {
			loc[0]+=mov[i][0];
			loc[1]+=mov[i][1]; 
			if(loc[0]>=0&&loc[0]<board.size()&&loc[1]<board[0].size()&&loc[1]>=0&&board[loc[0]][loc[1]]==word[index]){
				char tmp=board[loc[0]][loc[1]];
				char & pt = board[loc[0]][loc[1]];
				pt=0;
				bool flag=DFS(board, word, index+1, loc);
				pt=tmp;
				if(flag)
					return true;
			}
			loc[0]-=mov[i][0];
			loc[1]-=mov[i][1];
		}
		return false;
	}
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size()==0)
			return false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if(board[i][j]==word[0]){
					int loc[2]={i,j};
					char tmp=board[i][j];
					board[i][j]=0;
					bool flag=DFS(board, word, 1, loc);
					board[i][j]=tmp;					
					if(flag)
						return true;
				}
			}
		}
		return false;
    }
};

int main(void)
{
    char test[][4]={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	vector<vector<char> > board;
	for (int i = 0; i < 3; i++) {
		vector<char> tmp;
		for (int j = 0; j < 4; j++) {
			tmp.push_back(test[i][j]);
		}
		board.push_back(tmp);
	}
	Solution sol;
	cout<<(sol.exist(board,"ABCCED")==true?"true":"false")<<"  true"<<endl;
	cout<<(sol.exist(board,"SFCS")==true?"true":"false")<<"  true"<<endl;
	cout<<(sol.exist(board,"SEE")==true?"true":"false")<<"   true"<<endl;
	cout<<(sol.exist(board,"ABCB")==true?"true":"false")<<"   false"<<endl;
    return 0;
}

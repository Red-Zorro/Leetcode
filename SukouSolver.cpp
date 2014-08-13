#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	bool isValid(vector<vector<char> > &board, int x, int y) {
		for(int i = 0; i < 9; i++){
			if(i != x && board[i][y] == board[x][y])
				return false;
		}

		for(int j = 0; j < 9; j++){
			if(j != y && board[x][j] == board[x][y])
				return false;
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j< 3; j++){
				if((x/3*3+i!=x ||y/3*3+j!=y) && board[x/3*3+i][y/3*3+j] == board[x][y])
					return false;
			}
		}
		return true;
    }
	bool DFS(vector<vector<char> > &board)
	{
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] == '.')
				{
					for(int k = 1; k <= 9; k++)
					{
						board[i][j] = '0' + k;
						if(isValid(board,i,j) && DFS(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		return true;
	}
public:
    void solveSudoku(vector<vector<char> > &board) {
        DFS(board);
    }
};

int main(void)
{
	char arr[9][10]={"53..7....",
					"6..195...",
					".98....6.",
					"8...6...3",
					"4..8.3..1",
					"7...2...6",
					".6....28.",
					"...419..5",
					"....8..79"};
	vector<vector<char> > board;
	for (int i = 0; i < 9; i++) {
		board.push_back(vector<char>(arr[i],arr[i]+9));
	}

	Solution sol;
	sol.solveSudoku(board);
	for (int i = 0; i < 9; i++) {
		for(int j=0; j<9; j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}



/*
 * Date:2021-05-21 16:54
 * filename:051_n-queens.cpp
 *
 */

class Solution {
public:
		vector<string> generateBoard(vector<int>& queens, int n) {
			auto board = vector<string>();
			for (int i = 0; i < n; i++) {
				string row = string(n, '.');
				row[queens[i]] = 'Q';
				board.push_back(row);
			}
			return board;
		}
		
		void backtrack(vector<vector<string>>& solutions, vector<int>& queens, int n, int row, unordered_set<int>& columns, unordered_set<int>& diagoals1, unordered_set<int>& diagoals2) {
			if(row == n) {
				vector<string> board = generateBoard(queens, n);
				solutions.push_back(board);
			} else {
				for (int i = 0; i < n;i++) {
					if (columns.find(i) != columns.end()) {
						continue;
					}
					int diagonal1 = row - i;
					if (diagoals1.find(diagonal1) != diagoals1.end()) {
						continue;
					}
					int diagonal2 = row + i;
					if (diagoals2.find(diagonal2) != diagoals2.end()) {
						continue;
					}
					queens[row] = i;
					columns.insert(i);
					diagoals1.insert(diagonal1);
					diagoals2.insert(diagonal2);
					backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
					queens[row] = -1;
					columns.erase(i);
					diagonals1.erase(diagonal1);
					diagonals2.erase(diagonal2);
				}
			}
		}

    vector<vector<string>> solveNQueens(int n) {
			auto solutions = vector<vector<string> >();
			auto queens = vector<int>(n, -1);
			auto colums = unordered_set<int>();
			auto diagonals1 = unordered_set<int>();
			auto diagonals2 = unordered_set<int>();
			backtrack(solutions, queens, n, 0, colums, diagoals1, diagoals2);
			return solutions;
    }
};

/*
 * Date:2021-05-31 19:53
 * Solution_2 bits
 *
 */

class Solution_2 {
public:
    vector<vector<string>> solveNQueens(int n) {
			if (n < 1) return {};
			count = 0;
			DFS(n,0,0,0,0);
			return n;
    }
		int DFS(int n, int row, int cols, int pie, int na) {
			if (row >= n) {
				count++;
				return count;
			}
			int bits = (~(cols | pie | na)) & ((1 << n) - 1);//获取当前所有的空位

			while(bits > 0) {
				int p = bits & (-bits);//取到最低位的1
				DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1);
				bits = bits & (bits - 1);	//去掉最低位的1
			}
		}

private:
    int count = 0;
};

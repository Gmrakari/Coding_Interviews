

/*
 * Date:2021-11-16 20:50
 * filename:684_redundant-connection.cpp
 *
 */

class Solution {
private:
	int n = 1005;
	int father[1005];

	//初始化
	void init() {
		for (int i = 0; i < n;++i) {
			father[i] = i;
		}
	}

	//并查集里寻根过程
	int find(int u) {
		return u == father[u] ? u : father[u] = find(father[u]);
	}

	//将v->u 这条边加入并查集
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) 
			return ;
		father[v] = u;
	}

	//判断u 和 v 是否找到同一个根
	bool same(int u, int v) {
		 u = find(u);
		 v = find(v);
		 return u == v;
	}
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
			init();
			for (int i = 0;i < edges.size();++i) {
				if (same(edges[i][0], edges[i][1]))
					return edges[i];
			}
			return {};
    }
};

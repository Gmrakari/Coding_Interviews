#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL) { }

};

class Solution
{
private:
	string SerializeCore(TreeNode* root)
	{
		if(root == nullptr)
		{
			return "#!";
		}

		string str;
		str += to_string(root->val) + '!';
		str += SerializeCore(root->left);
		str += SerializeCore(root->right);
		return str;
	}

	TreeNode* DeserializeCore(char*& str)
	{
		if(*str == '#')
		{
			str++;
			return nullptr;
		}

		int num = 0;
		while(*str != '!')
		{
			num = num * 10 + (*str) - '0';
			str++;
		}

		TreeNode *node = new TreeNode(num);
		node->left = DeserializeCore(++str);
		node->right = DeserializeCore(++str);

		return node;
	}
public:
	char* Serialize(TreeNode* root)
	{
		string str = SerializeCore(root);
		char *chs = new char[str.size()];
		for(int i = 0; i < str.size();++i)
		{
			chs[i] = str[i];
		}
		return chs;
	}

	TreeNode* Deserialize(char* str)
	{
		return DeserializeCore(str);
	}
};

int main()
{
    TreeNode tree[7];

    tree[0].val = 8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];


    tree[1].val = 6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];


    tree[2].val = 10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];


    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 9;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 11;
    tree[6].left = NULL;
    tree[6].right = NULL;


    Solution solu;
    cout << solu.Serialize(tree) << endl;
    cout << solu.Serialize(solu.Deserialize(solu.Serialize(tree))) << endl;	
}

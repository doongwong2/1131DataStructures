#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct node {
	int value;
	node* left;
	node* right;

	node(int value) : value(value), left(nullptr), right(nullptr){}
};

node* insert(node* root, int value)
{
	if (nullptr == root)
	{
		return new node(value);
	}

	if (value < root->value)
	{
		root->left = insert(root->left, value);
	}

	else if (value > root->value)
	{
		root->right = insert(root->right, value);
	}

	return root;
}

node* buildTree(const vector<int>& input)
{
	node* root = nullptr;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != -1) root = insert(root, input[i]);
	}

	return root;
}


void preorder(node* root, vector<int>& result)
{
	if (root == nullptr) return;
	result.push_back(root->value);
	preorder(root->left, result);
	preorder(root->right, result);
}

void inorder(node* root, vector<int>& result)
{
	if (root == nullptr) return;
	inorder(root->left, result);
	result.push_back(root->value);
	inorder(root->right, result);
}

void postorder(node* root, vector<int>& result)
{
	if (nullptr == root) return;
	postorder(root->left, result);
	postorder(root->right, result);
	result.push_back(root->value);
}

int findKey(const vector<int>& traversal, int key)
{
	for (int i = 0; i < traversal.size(); i++)
	{
		if (traversal[i] == key)
			return traversal[i - 1];
	}

	return -1;
}

int main()
{
	string treeIn;
	getline(cin, treeIn);
	int key;
	cin >> key;

	vector<int> treeValues;
	size_t pos = 0;
	while ((pos = treeIn.find(' ')) != string::npos)
	{
		treeValues.push_back(stoi(treeIn.substr(0, pos)));
		treeIn.erase(0, pos + 1);
	}
	treeValues.push_back(stoi(treeIn)); // push the final value found in string.

	node* root = buildTree(treeValues);

	vector<int> preRes, inRes, postRes;
	preorder(root, preRes);
	inorder(root, inRes);
	postorder(root, postRes);

	cout << findKey(inRes,key) << " " << findKey(preRes,key) << " " << findKey(postRes,key);


	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int value;
	Node* leftNode;
	Node* rightNode;

	Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr) {}
};

#pragma region 트리 순회하는 방식

class Tree
{
public:
	void preOrder(Node* root)  // 재귀 방식
	{
		if (root == nullptr)   // 재귀 탈출 조건
			return;
		
		cout << root->value << " ";  // N
		preOrder(root->leftNode);
		preOrder(root->rightNode);
	}
	void inOrder(Node* root)
	{
		if (root == nullptr) return;
		
		inOrder(root->leftNode);
		cout << root->value << " "; 
		inOrder(root->rightNode);

	}
	void postOrder(Node* root)
	{
		if (root == nullptr) return;
		
		postOrder(root->leftNode);
		postOrder(root->rightNode);
		cout << root->value << " ";
	}

};

#pragma endregion

#pragma region 노드 직접 연결

void NodeConnect()
{
	Node* root = new Node(4);                 
	root->leftNode = new Node(2);             
	root->leftNode->leftNode = new Node(9);             
	root->leftNode->rightNode = new Node(7);  
	root->rightNode = new Node(6);            
	root->rightNode->leftNode = new Node(1);  

	cout << "\n트리를 전위 순회로 출력" << endl;
	Tree tree;
	tree.preOrder(root);

	cout << "\n트리를 중위 순회로 출력" << endl;
	tree.inOrder(root);

	cout << "\n트리를 후위 순회로 출력" << endl;
	tree.postOrder(root);
}

#pragma endregion

#pragma region BST구현

class BST
{
private:
	Node* root;

	Node* insert(Node* node, int value)
	{
		if (node == nullptr)
		{
			return new Node(value);
		}

		if (node->value > value)
		{
			node->leftNode = insert(node->leftNode, value);
		}
		else if (node->value < value)
		{
			node->rightNode = insert(node->rightNode, value);
		}

		return node;
	}

	void inOrder(Node* node)
	{
		if (node == nullptr) return;

		inOrder(node->leftNode);
		cout << node->value << " ";
		inOrder(node->rightNode);
	}

public:
	BST()
	{
		root = nullptr;
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	void inOrder()
	{
		inOrder(root);	
		cout << endl;
	}
};
	

#pragma endregion

int main()
{
	//NodeConnect();

	cout << "\n이진 검색 트리 데이터 입력 예시" << endl;

	BST bst;
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	bst.inOrder();
	bst.insert(9);
	bst.insert(7);
	bst.insert(1);
	bst.inOrder();

}
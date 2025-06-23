
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

#pragma region Ʈ�� ��ȸ�ϴ� ���

class Tree
{
public:
	void preOrder(Node* root)  // ��� ���
	{
		if (root == nullptr)   // ��� Ż�� ����
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

#pragma region ��� ���� ����

void NodeConnect()
{
	Node* root = new Node(4);                 
	root->leftNode = new Node(2);             
	root->leftNode->leftNode = new Node(9);             
	root->leftNode->rightNode = new Node(7);  
	root->rightNode = new Node(6);            
	root->rightNode->leftNode = new Node(1);  

	cout << "\nƮ���� ���� ��ȸ�� ���" << endl;
	Tree tree;
	tree.preOrder(root);

	cout << "\nƮ���� ���� ��ȸ�� ���" << endl;
	tree.inOrder(root);

	cout << "\nƮ���� ���� ��ȸ�� ���" << endl;
	tree.postOrder(root);
}

#pragma endregion

#pragma region BST����

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

	Node* findMin(Node* node)
	{
		if (node == nullptr || node->leftNode == nullptr)
		{
			return node;
		}

		return findMin(node->leftNode);
	}

	Node* findMax(Node* node)
	{
		if (node == nullptr || node->rightNode== nullptr)
		{
			return node;
		}

		return findMax(node->rightNode);
	}

	Node* deleteNode(Node* node, int target)
	{
		if (node == nullptr)  return nullptr;

		if (node->value > target)
		{
			node->leftNode = deleteNode(node->leftNode, target);
		}
		else if (node->value < target)
		{
			node->rightNode = deleteNode(node->rightNode, target);
		}
		else
		{
			//if (node->leftNode == nullptr && node->rightNode == nullptr);
			//if (node->leftNode == nullptr);
			//if (node->rightNode == nullptr);

			if (node->leftNode == nullptr || node->rightNode == nullptr)
			{
				Node* temp = node->leftNode != nullptr ? node->leftNode : node->rightNode;

				if (temp == nullptr) // �ڽ��� ���� ���
				{
					temp = node;
					node = nullptr;
					delete temp;
				}
				else
				{
					Node* nodeToDelete = node;
					node = temp;
					delete nodeToDelete;
				}
			}
			else // �ڽ��� ���� ���
			{
				//Node* temp =  findMin(node->rightNode);
				//node->value = temp->value;
				//node->rightNode = deleteNode(node->rightNode, temp->value);

				Node* temp = findMax(node->leftNode);
				node->value = temp->value;
				node->leftNode = deleteNode(node->leftNode, temp->value);
			}
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

	void DeleteNode(int value)
	{
		root = deleteNode(root, value);
	}

	void ReturnRoot()
	{
		cout << "��Ʈ�� ����� �� : " << root->value << endl;
	}
};
	

#pragma endregion

int main()
{
	//NodeConnect();

	cout << "\n���� �˻� Ʈ�� ������ �Է� ����" << endl;

	BST bst;
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	//bst.inOrder();
	bst.insert(9);
	bst.insert(7);
	bst.insert(1);
	bst.insert(5);
	bst.insert(8);
	bst.inOrder();

	cout << "\n������ ���� �� ��� ����" << endl;
	bst.DeleteNode(6);
	bst.inOrder();

}

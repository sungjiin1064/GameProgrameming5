
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void PriorityQueue()
{
	std::priority_queue<int> pq;
}

class MinHeap 
{

};

class MaxHeap
{
private:
	struct Node
	{
		int value;
		Node* leftNode;
		Node* rightNode;
		Node* parentNode;

		Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr), parentNode(nullptr) {}
	};

	Node* root;
	int size;

	void heapifyup(Node* node)
	{
		while (node->parentNode != nullptr && node->value > node->parentNode->value)
		{
			std::swap(node->value, node->parentNode->value);
			node = node->parentNode;
		}
	}

	Node* findLastNode()
	{
		if (!root) return nullptr;

		std::queue<Node*> q;
		q.push(root);
		Node* lastNode = nullptr;

		while (!q.empty())
		{
			lastNode = q.front();
			q.pop();
			if (lastNode->leftNode)
			{
				q.push(lastNode->leftNode);
			}
			if (lastNode->rightNode)
			{
				q.push(lastNode->rightNode);
			}
		}
		
		return lastNode;

	}

	void heapifydown(Node* node)
	{
		while (node)
		{
			Node* largest = node;

			if (node->leftNode && node->leftNode->value > largest->value)
			{
				largest = node->leftNode;
			}
			if (node->rightNode && node->rightNode->value > largest->value)
			{
				largest = node->rightNode;
			}

			if (largest == node) break;

			std::swap(node->value, largest->value);
			node = largest;
			
		}
	}

	void deleteNode(Node* node)
	{
		if (!node) return;

		deleteNode(node->leftNode);
		deleteNode(node->rightNode);
		delete node;

		
	}

public:
	MaxHeap() : root(nullptr), size(0) {}

	void insert(int value)
	{
		Node* newNode = new Node(value);

		if (!root) // 데이터가 0개일 경우, 새로 들어온 데이터가 루트가 된다.
		{
			root = newNode;
			size = 1;
			return;
		}

		std::queue<Node*> q; //FIFO
		q.push(root);

		while (!q.empty()) // 데이터가 있을때
		{
			Node* currrentNode = q.front();
			q.pop();

			if (!currrentNode->leftNode) // 왼쪽에 데이터가 없으면 왼쪽에 데이터를 넣어라
			{
				currrentNode->leftNode = newNode;  // 현제 노드의 왼쪽 자식에 새로운 데이터를 넣었다.
				newNode->parentNode = currrentNode; // 자식의 부모를 설정해준다.
				break;
			}

			if (!currrentNode->rightNode)
			{
				currrentNode->rightNode = newNode;
				newNode->parentNode = currrentNode;
				break;
			}

			q.push(currrentNode->leftNode);
			q.push(currrentNode->rightNode);
		}

		size++;
		heapifyup(newNode);

	}

	int extractMax()
	{
		if (!root) return -1;  ////////

		int MaxValue = root->value;

		if (size == 1)
		{
			delete root;
			root = nullptr;
			size = 0;
			return MaxValue;
		}

		Node* lastNode = findLastNode();

		if (!lastNode) return -2;   /////////////////

		root->value = lastNode->value;

		if (lastNode->parentNode)
		{
			if (lastNode->parentNode->leftNode == lastNode)
			{
				lastNode->parentNode->leftNode = nullptr;
			}
			else
			{
				lastNode->parentNode->rightNode = nullptr;
			}
		}

		delete lastNode;
		size--;
		heapifydown(root);

		return MaxValue;
	}

	std::vector<int> toArray()
	{
		std::vector<int> result;

		if (!root) return result;

		std::queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();
			result.push_back(node->value);
			if (node->leftNode)
			{
				q.push(node->leftNode);
			}
			if (node->rightNode)
			{
				q.push(node->rightNode);
			}

			
		}

		return result;
	}
};

int main()
{
	MaxHeap mHeap;

	cout << "가장 큰 수를 찾는 Heap 데이터 입력" << endl;

	mHeap.insert(7);
	mHeap.insert(3);
	mHeap.insert(5);
	mHeap.insert(11);

	cout << "Heap자료구조의 트리 저장 순서대로 출력하는 예제" << endl;
	std::vector<int> tempV =  mHeap.toArray();

	for (auto& data : tempV)
	{
		cout << data << " ";
	}
	cout << endl;

	cout << "가장 큰 수를 반환하고 다사시 Heap 정렬 하는 예제" << endl;
	int maxValue = mHeap.extractMax();
	int k = 2;
	int kthValue;

	for (int i = 0; i < k-1; i++)      ///////////////////////////
	{
		kthValue = mHeap.extractMax();
		
	}

	cout << "k번째로 큰 수는 : " << kthValue <<endl;

}
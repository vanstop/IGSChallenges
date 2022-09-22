#include <iostream>
#include <list>

using namespace std;

struct Node {
	int value;
	struct Node* next;
};

Node* Merge(Node** lists, int listsSize);
Node* Merge(Node* ListA, Node* ListB);
Node* CreateNode(int value = 0);
Node* Push(Node* list, int value);
Node* Append(Node* headNode, Node* tailNode);
Node* CreateNode(int* values, int listSize);
void PrintList(Node* list);
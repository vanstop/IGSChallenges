#include "LinkedListMerger.h"

int main() 
{
	Node** linkedLists;
	linkedLists = (Node**)malloc(3 * sizeof *linkedLists);
	
	linkedLists[0] = CreateNode(new int[] { 1, 3, 8 }, 3);
	linkedLists[1] = CreateNode(new int[] { 1, 3, 6 }, 3);
	linkedLists[2] = CreateNode(new int[] { 8, 9 }, 2);

	PrintList(Merge(linkedLists, 3));

	return 0;
}

Node* Merge(Node** Lists, int listSize)
{
	Node* mergedList = nullptr;

	for (int i = 0; i < listSize; i++)
	{
		mergedList = Merge(mergedList, Lists[i]);
	}

	return mergedList;
}

Node* Merge(Node* headNodeA, Node* headNodeB)
{
	Node* mergedList = nullptr;

	while (headNodeA != nullptr || headNodeB != nullptr)
	{
		if (headNodeA == nullptr)
		{
			mergedList = Append(mergedList, headNodeB);
			break;
		}
		else if(headNodeB == nullptr)
		{
			mergedList = Append(mergedList, headNodeA);
			break;
		}

		if (headNodeA->value <= headNodeB->value)
		{
			mergedList = Push(mergedList, headNodeA->value);
			headNodeA = headNodeA->next;
		}
		else
		{
			mergedList = Push(mergedList, headNodeB->value);
			headNodeB = headNodeB->next;
		}
	}

	return mergedList;
}

Node* CreateNode(int value) 
{
	Node* currentNode;
	currentNode = (Node*)malloc(sizeof(struct Node));
	currentNode->value = value;
	currentNode->next = nullptr;
    return currentNode;
}

Node* Push(Node* headNode, int value)
{
	Node* newNode = CreateNode(value);

	if (headNode == NULL)
	{
		headNode = newNode;
	}
	else
	{
		Node* lastNode = headNode;
		while (lastNode->next != nullptr)
		{
			lastNode = lastNode->next;
		}

		lastNode->next = newNode;
	}

	return headNode;
}

Node* Append(Node* headNode, Node* tailNode)
{
	if (headNode == NULL && tailNode == NULL)
	{
		return CreateNode();
	}
	if (headNode == NULL && tailNode != NULL)
	{
		return tailNode;
	}
	else if (tailNode == NULL && headNode != NULL)
	{
		return headNode;
	}

	Node* lastNode = headNode;
	while (lastNode->next != nullptr)
	{
		lastNode = lastNode->next;
	}

	lastNode->next = tailNode;

	return headNode;
}

Node* CreateNode(int* values, int listSize)
{
	Node* headNode = CreateNode(values[0]);

	Node* currentNode = headNode;

	for (int i = 1; i < listSize; i++)
	{
		currentNode->next = CreateNode(values[i]);

		currentNode = currentNode->next;
	}

	return headNode;
}

void PrintList(Node* list)
{
	cout << "[";
	while (list != nullptr)
	{
		cout << list->value << ", ";
		list = list->next;
	}
	cout << "], ";
}
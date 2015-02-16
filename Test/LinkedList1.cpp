
/*
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{




	return 0;
}
*/


//Linked List

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Node
{
	Node *next;
	int number;

	public:
		Node(Node *newNextNode, int num) : next(newNextNode), number(num) {};
		~Node() { delete next; }
		
		int getNumber();
		void setNext(Node *newNextNode) { next = newNextNode; }
		Node *getNext() { return next; }

};

int Node::getNumber()
{
	return number;
}


class LinkedList
{
	Node *list;

	public:
		LinkedList(int num)
		{
			list = new Node(nullptr, num);
		}
		~LinkedList()
		{
			delete list;
		}

		void addNode(int num);
		void printList();
};

void LinkedList::addNode(int num)
{
	Node *temp = list;

	while(temp->getNext() != nullptr)
	{
		temp = temp->getNext();
	}

	temp->setNext( new Node(nullptr, num) );
	
}

void LinkedList::printList()
{

	char *str = new char[1];
	str[0] = '\0';
	//itoa(list->getNumber(), str, 10);
	
	Node *temp = list;
	
	while( temp->getNext() != nullptr )
	{
		char *c = new char[2];
		itoa( temp->getNumber(), c, 10 );
		
		char *tmp = new char[strlen(str) + strlen(c) + 1];
		tmp[0] = '\0';
		
		strcat(tmp, str);
		strcat(tmp, c);
		
		delete [] str;
		str = new char[strlen(tmp) + 1];
		str = tmp;
		
		delete [] c;
		
		temp = temp->getNext();
	}
	
	char *c = new char[2];
	itoa(temp->getNumber(), c, 10);

	char *tmp = new char[strlen(c) + strlen(str) + 1];
	tmp[0] = '\0';

	strcat(tmp, str);
	strcat(tmp, c);

	delete [] str;
	str = new char[strlen(tmp) + 1];
	str = tmp;
	
	printf(str);
	
	delete [] c;
	delete [] str;
}

/*
int main()
{

	LinkedList *list = new LinkedList(1);

	list->addNode(2);
	list->addNode(3);
	list->addNode(4);

	list->printList();
	

	cin.get();

	delete list;
	return 0;
}
*/
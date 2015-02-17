#include "StdAfx.h"
#include "LinkedList.h"



template<class T>
LinkedList<T>::LinkedList(T data)
{
	head = new Node<T>(data);
	tail = NULL;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *curr = head;
	while(head != tail)
	{
		curr = head;
		head = head->next;
		delete curr;
	}

	delete tail;
}

template<class T>
LinkedList<T> &LinkedList<T>::insertToTail(T val)
{
	if(tail == NULL)
	{
		tail = new Node<T>(val);
		head->next = tail;
	}
	else
	{
		tail->next = new Node<T>(val);
		tail = tail->next;
	}

	return *this;
}

template<class T>
LinkedList<T> &LinkedList<T>::insertToHead(T val)
{
	Node<T> *temp = new Node<T>(val);
	temp->next = head;
	head = temp;

	return *this;
}

template<class T>
void LinkedList<T>::toString()
{

	Node<T> *temp = head;

	printf("\nHEAD --> ");
	while(temp->next)
	{
		std::cout << temp->data << " --> ";
		temp = temp->next;
	}
	std::cout << temp->data << " --> TAIL\n";

}

template<class T>
void LinkedList<T>::reverse(std::string str)
{
	std::cout << str << "\n";
	int first = 0, last = str.length() - 1;
	
	while(first != last)
	{
		char temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		
		first++; last--;
	}

	std::cout << str << "\n";

}

template<class T>
void LinkedList<T>::sort(int a)
{


}

int main()
{

	LinkedList<int> list(5);
	list.insertToTail(4).insertToTail(2).insertToTail(1);
	list.insertToHead(9).insertToHead(10).insertToHead(11);

	list.toString();
	error

	list.reverse("fuck your mom");

	int a[] = {1, 3, 4 , 9, 2, 5, 6, 7, 10};

	std::cin.get();
	
	return 0;
}
#pragma once

#include <iostream>
#include <string>

template<class T>
class LinkedList
{
	private:
		template<class U>
		class Node
		{
			public:
				U data;
				Node *next;
				Node(U &d) : data(d), next(NULL) {std::cout << data << std::endl;}
				Node(const Node &node, U d) : next(node), data(d) {std::cout << data << std::endl;}
		};
		Node<T> *head, *tail;
	public:
		LinkedList(T data);
		~LinkedList();
		LinkedList<T> &insertToTail(T val);
		LinkedList<T> &insertToHead(T val);
		void toString();
		void reverse(std::string str);
		void sort(int a);
};


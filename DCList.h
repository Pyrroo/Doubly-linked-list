#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class DCList
{
private: 
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
	Node<T>* CurrentNodeByIndex;

public:

	int count = 0;

	DCList() = default;
	~DCList()
	{
		Node<T>* Current_Node;
		Current_Node = Head;
		while (Current_Node != Tail)
		{
			Current_Node = Current_Node->NextNode;
			delete Current_Node->PrevNode;
		}
		Head = nullptr;
		Tail = nullptr;
	}

	T& operator[](int index)
	{
		if (index <= count) 
		{
			if (index >= count / 2) 
			{
				Node<T>* Current_Node;
				Current_Node = Tail;
				for (int i = 0; i < count-index-1; i++)
				{
					Current_Node = Current_Node->PrevNode;
				}
				CurrentNodeByIndex = Current_Node;
				return Current_Node->value;
			}
			else 
			{
				Node<T>* Current_Node;
				Current_Node = Head;
				for (int i = 0; i < index; i++)
				{
					Current_Node = Current_Node->NextNode;
				}
				CurrentNodeByIndex = Current_Node;
				return Current_Node->value;
			}
		}
		else
		{
			std::cout << "IndexError" << '\n';
			CurrentNodeByIndex = nullptr;
		}
	}
	void operator=(T value)
	{
		CurrentNodeByIndex->value = value;
		CurrentNodeByIndex = nullptr;
	}
	void operator+(T value)
	{
		CurrentNodeByIndex->value += value;
		CurrentNodeByIndex = nullptr;
	}
	void operator-(T value)
	{
		CurrentNodeByIndex->value -= value;
		CurrentNodeByIndex = nullptr;
	}
	void operator*(T value)
	{
		CurrentNodeByIndex->value *= value;
		CurrentNodeByIndex = nullptr;
	}
	void operator/(T value)
	{
		CurrentNodeByIndex->value /= value;
		CurrentNodeByIndex = nullptr;
	}
	void operator++()
	{
		CurrentNodeByIndex->value++;
		CurrentNodeByIndex = nullptr;
	}
	void operator--()
	{
		CurrentNodeByIndex->value--;
		CurrentNodeByIndex = nullptr;
	}

	void Append(T value)
	{
		Node<T>* NewNode = new Node<T>(value);
		if (!Head)
		{			
			Head = Tail = NewNode;
			Head->NextNode = NewNode;
			Tail->PrevNode = NewNode;
			count++;
		}
		else
		{			
			NewNode->PrevNode = Tail;
			Tail->NextNode = NewNode;
			Tail = NewNode;
			count++;
		}
	}
	void AppendByIndex(T value, int index) 
	{
		if (index <= count)
		{
			if (index >= count / 2)
			{
				Node<T>* Current_Node;
				Current_Node = Tail;
				for (int i = 0; i < count - index - 1; i++)
				{
					Current_Node = Current_Node->PrevNode;
				}

				Node<T>* NewNode = new Node<T>(value);

				NewNode->PrevNode = Current_Node->PrevNode;
				Current_Node->PrevNode->NextNode = NewNode;
				NewNode->NextNode = Current_Node;
				Current_Node->PrevNode = NewNode;

				count++;
				
			}
			else
			{
				Node<T>* Current_Node;
				Current_Node = Head;
				for (int i = 0; i < index; i++)
				{
					Current_Node = Current_Node->NextNode;
				}
				Node<T>* NewNode = new Node<T>(value);

				NewNode->PrevNode = Current_Node->PrevNode;
				Current_Node->PrevNode->NextNode = NewNode;
				NewNode->NextNode = Current_Node;
				Current_Node->PrevNode = NewNode;

				count++;
				
			}
		}
		else
		{
			std::cout << "IndexError" << '\n';
			CurrentNodeByIndex = nullptr;
		}
	}
	void CoutHead() { std::cout << Head->value << '\n'; }
	void CoutTail() { std::cout << Tail->value << '\n'; }
	void CoutList()
	{
		Node<T>* Current_Node;
		Current_Node = Head;
		while (Current_Node != Tail)
		{
			std::cout << Current_Node->value << ' ';
			Current_Node = Current_Node->NextNode;
		}
		std::cout << Current_Node->value << ' ';
		std::cout << '\n';
	}
};

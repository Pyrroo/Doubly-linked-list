#pragma once
template <typename T>
class Node
{
public:
	T value;
	Node* NextNode = nullptr;
	Node* PrevNode = nullptr;

	Node(T val) : value(val) {}
};

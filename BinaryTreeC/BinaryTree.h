#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using std::vector;

template <typename T>
class BinaryTree
{
public:
	template <typename T>
	class TreeNode
	{
	public:
		TreeNode() = default;
		TreeNode(T value)
			: _value(value) 
		{}
		TreeNode(TreeNode* right, TreeNode* left, T value)
			: _right(right), _left(left), _value(value) 
		{}
		TreeNode(const TreeNode& other) = delete;
		TreeNode& operator=(const TreeNode& other) = delete;
		TreeNode(TreeNode&& other) = delete;
		TreeNode& operator=(TreeNode&& other) = delete;
		~TreeNode() = default;	
	public:
		TreeNode<T>* _right = nullptr;
		TreeNode<T>* _left = nullptr;
		T _value;
	};
	BinaryTree();
	BinaryTree(const vector<T>& arrayOfValues);
	BinaryTree(const BinaryTree& other);
	BinaryTree(BinaryTree&& other) noexcept;
	BinaryTree operator=(const BinaryTree& other) = delete;
	BinaryTree operator=(BinaryTree&& other) = delete;
	void Insert(const T& value);
	void InsertRecursive(const T& value, TreeNode<T>* pointer);
	bool Empty() const;
	void Remove(const T& value);
	void Delete(const T& value, TreeNode<T>*& pointer);
	bool SearchElement(const T& value, TreeNode<T>* pointer);
	bool Contains(const T& value);
	void LrootRTravel(vector<T>& result, TreeNode<T>* pointer);
	vector<T> RoundLrootR();
	void RrootLTravel(vector<T>& result, TreeNode<T>* pointer);
	vector<T> RoundRrootL();
	T Minimum(TreeNode<T>* pointer);
	void OutputTree(TreeNode<T>* pointer, int h = 0) const;
	void Output() const;
	void FreeTree(TreeNode<T>* pointer);
	void TreeToVector(TreeNode<T>* pointer, vector<T>& result) const;
	~BinaryTree();

public:
	TreeNode<T>* _root = nullptr;
};

template<typename T>
BinaryTree<T>::BinaryTree()
{}

template<typename T>
BinaryTree<T>::BinaryTree(const vector<T>& arrayOfValues)
{
	int size = arrayOfValues.size();
	for (int i = 0; i < size; ++i) {
		Insert(arrayOfValues[i]);
	}
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other)
{
	vector<T> vecToCreate{};
	other.TreeToVector(other._root, vecToCreate);
	int size = vecToCreate.size();
	for (int i = size - 1; i > -1; --i) 
	{
		Insert(vecToCreate[i]);
	}
}

template<typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept
{
	_root = other._root;
	other._root = nullptr;
}

template<typename T>
void BinaryTree<T>::Insert(const T& value)
{
	if (this->Empty()) {
		_root = new TreeNode<T>(value);
	}
	else {
		BinaryTree<T>::InsertRecursive(value, _root);
	}
}

template<typename T>
void BinaryTree<T>::InsertRecursive(const T& value, TreeNode<T>* current)
{
	/*TreeNode<T>* temp = value < current->_value ? current->_left : current->_right;
	if (temp) {
		InsertRecursive(value, temp);
	}
	else {
		temp = new TreeNode<T>(value);
	}*/
	if (value < current->_value) {
		if (current->_left) {
			InsertRecursive(value, current->_left);
		}
		else {
			current->_left = new TreeNode<T>(value);
		}
	}
	else {
		if (current->_right) {
			InsertRecursive(value, current->_right);
		}
		else {
			current->_right = new TreeNode<T>(value);
		}
	}
}

template<typename T>
bool BinaryTree<T>::Empty() const
{
	return _root == nullptr;
}

template<typename T>
void BinaryTree<T>::Remove(const T& value)
{
	Delete(value, _root);
}

template<typename T>
void BinaryTree<T>::Delete(const T& value, TreeNode<T>*& current)
{
	if (!current) {
		return;
	}
	if (value < current->_value) {
		Delete(value, current->_left);
	}
	else if (value > current->_value) {
		Delete(value, current->_right);
	}
	else if (current->_left && current->_right) {
		current->_value = Minimum(current->_right);
		Delete(current->_value, current->_right);
	}
	else {
		if (current->_left) {
			auto del = current;
			current = current->_left;
			delete del;
			Delete(current->_value, current->_left);
		}
		else if (current->_right) {
			auto del = current;
			current= current->_right;
			delete del;
			Delete(current->_value, current->_right);
		}
		else {
			delete current;
		}
	}
}

template<typename T>
bool BinaryTree<T>::SearchElement(const T& value, TreeNode<T>* pointer)
{
	if (value == pointer->_value) {
		return true;
	}

	if (value > pointer->_value) {
		if (pointer->_right) {
			return SearchElement(value, pointer->_right);
		}
		else {
			return false;
		}
	}
	else {
		if (pointer->_left) {
			return SearchElement(value, pointer->_left);
		}
		else {
			return false;
		}
	}

	return false;
}

template<typename T>
bool BinaryTree<T>::Contains(const T& value)
{
	if (this->Empty())
		return false;
	return SearchElement(value, _root);
}

template<typename T>
void BinaryTree<T>::LrootRTravel(vector<T>& result, TreeNode<T>* pointer)
{
	if (pointer) {
		LrootRTravel(result, pointer->_left);
		result.push_back(pointer->_value);
		LrootRTravel(result, pointer->_right);
	}
}


template<typename T>
vector<T> BinaryTree<T>::RoundLrootR()
{
	vector<T> result;
	LrootRTravel(result, _root);
	return result;
}

template<typename T>
void BinaryTree<T>::RrootLTravel(vector<T>& result, TreeNode<T>* pointer)
{
	if (pointer) {
		RrootLTravel(result, pointer->_right);
		result.push_back(pointer->_value);
		RrootLTravel(result, pointer->_left);
	}
}

template<typename T>
vector<T> BinaryTree<T>::RoundRrootL()
{
	vector<T> result;
	RrootLTravel(result, _root);
	return result;
}

template<typename T>
T BinaryTree<T>::Minimum(TreeNode<T>* pointer)
{
	if (!pointer->_left)
		return pointer->_value;
	return Minimum(pointer->_left);
}

template<typename T>
void BinaryTree<T>::OutputTree(TreeNode<T>* current, int level) const
{
	if (current)
	{
		OutputTree(current->_right, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "   ";
		std::cout << current->_value << std::endl;
		OutputTree(current->_left, level + 1);
	}
}

template<typename T>
void BinaryTree<T>::Output() const
{
	OutputTree(_root);
	std::cout << "--------------------------------------------\n";
}

template<typename T>
void BinaryTree<T>::FreeTree(TreeNode<T>* pointer)
{
	if (!pointer)
		return;
	if (pointer->_left)
		FreeTree(pointer->_left);
	if (pointer->_right)
		FreeTree(pointer->_right);
	delete pointer;
}

template<typename T>
void BinaryTree<T>::TreeToVector(TreeNode<T>* pointer, vector<T>& result) const
{
	if (!this->Empty()) {
		if (pointer->_left)
			TreeToVector(pointer->_left, result);
		if (pointer->_right)
			TreeToVector(pointer->_right, result);
		result.push_back(pointer->_value);
	}
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	FreeTree(_root);
}


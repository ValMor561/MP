#include "pch.h"
#include "AVL.cpp"

TEST(Insert, Test)
{
	AVLTree<int> tree;
	AVLTree<int> tree1;
	int a[10] = { 10, 20, 30, 40, 50, 25, 45, 30, 40, 50 };
	for (int i = 0; i < 10; ++i)
	{
		tree.insert(a[i]);
		tree.Output();
		std::cout << "\n=======================\n";
	}
}

TEST(Remove, Test)
{
	AVLTree<int> tree;
	for (int i = 0; i < 10; ++i)
		tree.insert(i*10);
	tree.insert(31);
	tree.insert(32);
	tree.Output();
	std::cout << "\n=======================\n"; 
	tree.remove(60);
	tree.Output();
	std::cout << "\n=======================\n"; 
	tree.remove(2);
	tree.Output();
	std::cout << "\n=======================\n"; 
	tree.remove(1);
	tree.Output();
	std::cout << "\n=======================\n"; 
	tree.remove(4);
	tree.Output();
	std::cout << "\n=======================\n"; 
	tree.remove(7);
	tree.Output();
	std::cout << "\n=======================\n"; 
	tree.remove(500);
	tree.Output();
}

TEST(Remove, TestMin)
{
	AVLTree<int> tree;
	for (int i = 0; i < 10; ++i)
		tree.insert(i);
	tree.insert(9);
	tree.Output();
	std::cout << "\n=======================\n";
	tree.remove(7);
}
TEST(Contains, Test)
{
	AVLTree<int> tree;
	for (int i = 0; i < 10; ++i)
		tree.insert(i);
	EXPECT_TRUE(tree.contains(7));
	EXPECT_FALSE(tree.contains(17));
}


TEST(Remove, GraphtVisTest)
{
	AVLTree<int> tree;
	for (int i = 0; i < 10; ++i)
		tree.insert(i * 10);
	//tree.MakeDot();
	tree.remove(0);
	tree.MakeDot();
}
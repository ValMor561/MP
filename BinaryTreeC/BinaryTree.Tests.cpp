#include "pch.h"
#include "../Task1/BinaryTree.h"

TEST(BinaryTreeTests, construct)
{
	BinaryTree<int> k;
	ASSERT_TRUE(k.Empty());
}

TEST(BinaryTreeTests, construct_with_params)
{
	vector<int> values{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	BinaryTree<int> k(values);
	int size = values.size();
	for (int i = 0; i < size; ++i)
	{
		ASSERT_TRUE(k.Contains(values[i]));
	}
}

TEST(BinaryTreeTests, construct_copy)
{
	vector<int> values{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	BinaryTree<int> a(values);
	BinaryTree<int> b(a);
	int size = values.size();
	for (int i = 0; i < size; ++i)
	{
		ASSERT_TRUE(b.Contains(values[i]));
	}
}

TEST(BinaryTreeTests, construct_movement)
{
	vector<int> values{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	BinaryTree<int> a(values);
	BinaryTree<int> b(std::move(a));
	int size = values.size();
	for (int i = 0; i < size; ++i)
	{
		ASSERT_TRUE(b.Contains(values[i]));
	}
}
TEST(BinaryTreeTests, output)
{
	vector<int> values{ 8, 3, 11, 9, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values);
	k.Output();
}

TEST(BinaryTreeTests, delete_two_descendants)
{
	vector<int> values{ 8, 3, 11, 9, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values);
	k.Remove(8);
	k.Output();
}

TEST(BinaryTreeTests, delete_root_without_left_descendants)
{
	vector<int> values{ 8, 10, 14, 13 };
	BinaryTree<int> k(values);
	k.Output();
	k.Remove(8);
	k.Output();
}
TEST(BinaryTreeTests, delete_root_without_right_descendants)
{
	vector<int> values{ 20, 8, 10, 14, 13 };
	BinaryTree<int> k(values);
	k.Output();
	k.Remove(20);
	k.Output();
}

TEST(BinaryTreeTests, delete_one_descendants)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	k.Output();
	k.Remove(8);
	k.Output();
}

TEST(BinaryTreeTests, delete_no_descendants)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	k.Remove(13);
	k.Output();
}

TEST(BinaryTreeTests, delete_not_node)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	k.Remove(20);
	k.Output();
}

TEST(BinaryTreeTests, contains)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	ASSERT_TRUE(k.Contains(13));
}

TEST(BinaryTreeTests, no_contains)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	ASSERT_FALSE(k.Contains(21));
}

TEST(BinaryTreeTests, right_round)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	k.Output();
	vector<int> result = k.RoundRrootL();
	vector<int> example{ 14, 13, 10, 8, 7, 6, 4, 3, 1 };
	ASSERT_EQ(result, example);
}

TEST(BinaryTreeTests, left_round)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 9, 14, 12, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	vector<int> result = k.RoundLrootR();
	vector<int> example{ 1, 3, 4, 6, 7, 8, 9, 10, 12, 13, 14 };
	ASSERT_EQ(result, example);
}

TEST(BinaryTreeTests, tree_to_vector)
{
	vector<int> values_1{ 8, 3, 10, 1, 6, 9, 14, 12, 4, 7, 13 };
	BinaryTree<int> k(values_1);
	vector<int> result;
	k.TreeToVector(k._root, result);
	k.Output();
	ASSERT_EQ(result.size(), values_1.size());
	std::reverse(result.begin(), result.end());
	BinaryTree<int> l(result);
	l.Output();
}
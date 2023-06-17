using Xunit;
using BinaryTree;
using System;
using System.Collections;
using System.Collections.Generic;

namespace BinaryTreeTests
{
    public class UnitTest1
    {
        [Fact]
        public void Insert()
        {
            BinaryTree<int> tree = new BinaryTree<int>();
            tree.Insert(3);
            tree.Insert(2);
            tree.Insert(4);
            tree.Insert(1);
            List<int> answer = new List<int> { 3, 2, 1, 4 };
            List<int> test = tree.ToVector();
            Assert.Equal(test, answer);
        }

        [Fact]
        public void Remove1()
        {
            int[] ints = { 6, 8, 3, 1, 4, 7, 9 };
            BinaryTree<int> tree = new BinaryTree<int>(ints);
            List<int> answer = new List<int> { 6, 3, 4, 8, 7, 9 };
            tree.Remove(1);
            List<int> test = tree.ToVector();
            Assert.Equal(test, answer);
        }

        [Fact]
        public void Remove2()
        {
            int[] ints = { 6, 8, 3, 1, 4, 7};
            BinaryTree<int> tree = new BinaryTree<int>(ints);
            List<int> answer = new List<int> { 6, 3, 1, 4, 7 };
            tree.Remove(8);
            List<int> test = tree.ToVector();
            Assert.Equal(test, answer);
        }

        [Fact]
        public void Remove3()
        {
            int[] ints = { 6, 8, 3, 1, 4, 7, 9 };
            BinaryTree<int> tree = new BinaryTree<int>(ints);
            List<int> answer = new List<int> { 7, 3, 1, 4, 8, 9 };
            tree.Remove(6);
            List<int> test = tree.ToVector();
            Assert.Equal(test, answer);
        }

        [Fact]
        public void IEnumerator()
        {
            int[] ints = { 6, 8, 3, 1, 4, 7, 9 };
            BinaryTree<int> tree = new BinaryTree<int>(ints);
            List<int> answer = new List<int> { 1, 3, 4, 6, 7, 8, 9 };
            List<int> test = new List<int>();
            foreach (var value in tree)
                test.Add(value);
            Assert.Equal(test, answer);
        }
        [Fact]
        public void Contains()
        {
            int[] ints = { 6, 8, 3, 1, 4, 7, 9 };
            BinaryTree<int> tree1 = new BinaryTree<int>(ints);
            BinaryTree<int> tree2 = new BinaryTree<int>(tree1);
            Assert.True(tree1.Contains(4));
            Assert.False(tree2.Contains(5));
        }

        [Fact]
        public void Empty()
        {
            BinaryTree<int> tree = new BinaryTree<int>();
            Assert.True(tree.Empty());
            tree.Insert(5);
            Assert.False(tree.Empty());
        }
    }
}

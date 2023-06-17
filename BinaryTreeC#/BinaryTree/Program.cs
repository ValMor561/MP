#nullable enable
using System;
using System.Collections;
using System.Collections.Generic;

namespace BinaryTree
{
    public class BinaryTree<T> : IEnumerable<T> where T : IComparable<T>
    {
        internal class TreeNode
        {
            public T _value;
            public TreeNode? _left;
            public TreeNode? _right;

            public TreeNode(in T value)
            {
                _value = value;
                _right = null;
                _left = null;
            }
            public TreeNode? ShowNext(in T value)
            {
                return (_value.CompareTo(value) > 0) ? _left : _right;
            }
            public bool IsEmpty()
            {
                return !(_left == null && _right == null);
            }
            public void NoteNodes(ref List<T> vector)
            {
                vector.Add(_value);
                if (_left != null)
                    _left.NoteNodes(ref vector);
                if (_right != null)
                    _right.NoteNodes(ref vector);
            }
            public void NoteNodesL(ref List<T> vector)
            {
                if (this == null)
                    return;
                if (_left != null)
                    _left.NoteNodesL(ref vector);
                vector.Add(_value);
                if (_right != null)
                    _right.NoteNodesL(ref vector);
            }
        };
        TreeNode? _root;

        public BinaryTree()
        {
            _root = null;
        }

        public BinaryTree(T[] arr)
        {
            _root = null;
            for (int i = 0; i < arr.Length; ++i)
                Insert(arr[i]);
        }

        public BinaryTree(in BinaryTree<T> tree)
        {
            _root = null;
            List<T> temp = tree.ToVector();
            foreach (T value in temp)
                Insert(value);
        }

        public bool Empty()
        {
            return _root == null;
        }

        public void Insert(in T value)
        {
            if (_root == null)
            {
                _root = new TreeNode(value);
                return;
            }
            TreeNode temp = ShowLast(value);
            if (value.CompareTo(temp._value) < 0)
            {
                temp._left = new TreeNode(value);
            }
            else
            {
                temp._right = new TreeNode(value);
            }
        }

        public bool Contains(in T value)
        {
            return _root != null && (value.CompareTo(_root._value) == 0 || Find(value) != null);
        }

        public void Remove(in T value)
        {
            Delete(value, ref _root);
        }

        void Delete(in T value, ref TreeNode? pointer)
        {
            if (pointer == null)
            {
                return;
            }
            if (value.CompareTo(pointer._value) < 0)
            {
                Delete(value, ref pointer._left);
            }
            else if (value.CompareTo(pointer._value) > 0)
            {
                Delete(value, ref pointer._right);
            }
            else if (pointer._left != null && pointer._right != null)
            {
                pointer._value = Minimum(pointer._right);
                Delete(pointer._value, ref pointer._right);
            }
            else
            {
                if (pointer._left != null)
                {
                    pointer = pointer._left;
                }
                else if (pointer._right != null)
                {

                    pointer = pointer._right;
                }
                else
                {
                    pointer = null;
                }
            }
        }

        T Minimum(TreeNode pointer)
        {
            if (pointer._left == null)
                return pointer._value;
            return Minimum(pointer._left);
        }

        public List<T> ToVector()
        {
            List<T> result = new List<T>();
            if (_root == null)
                return result;
            _root.NoteNodes(ref result);
            return result;
        }

        TreeNode ShowLast(in T value)
        {
            TreeNode? temp = _root;
            TreeNode? result = null;
            while (temp != null)
            {
                result = temp;
                temp = temp.ShowNext(value);
            }
            return result;
        }

        TreeNode? Find(in T value)
        {
            if (_root == null)
                return null;
            TreeNode? temp = _root;
            while (temp != null)
            {
                if (value.CompareTo(temp._value) == 0)
                    return temp;
                temp = temp.ShowNext(value);
            }
            return null;
        }

        public IEnumerator<T> GetEnumerator()
        {
            return new BinaryTreeEnumerator(_root);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        internal class BinaryTreeEnumerator : IEnumerator<T>
        {
            public List<T> _list;
            public int _pos = -1;
            public BinaryTreeEnumerator(TreeNode root)
            {
                _list = new List<T>();
                root.NoteNodesL(ref _list);
            }

            public T Current
            {
                get
                {
                    if (_pos < 0 || _pos > _list.Count)
                        throw new InvalidOperationException();
                    return _list[_pos];
                }
            }

            object IEnumerator.Current
            {
                get
                {
                    return Current;
                }
            }

            public bool MoveNext()
            {
                if (_pos < _list.Count - 1)
                {
                    ++_pos;
                    return true;
                }
                else
                    return false;
            }

            public void Reset()
            {
                _pos = -1;
            }

            public void Dispose() { }
        };
    };
    public class Program
    {
        public static void Main()
        {
        }
    }
}
#include "pch.h"
#include <string>
using std::string;

template <typename T>
class AVLTree
{
    struct Node
    {
        T _value;
        int _height;
        Node* _left;
        Node* _right;
        Node(const T& value) { _value = value; _left = _right = 0; _height = 1; }
    };
    void make_dot(std::string& out, Node* p, int n)
    {
        if (!p)
        {
            out += ";";
            return;
        }
        out += std::to_string(p->_value);
        if (p->_left)
        {
            out += "->";
        }
        make_dot(out, p->_left, n + 1);
        out += std::to_string(p->_value);
        if (p->_right)
        {
            out += "->";
        }
        make_dot(out, p->_right, n + 1);
    }

    int get_height(Node* p) const
    {
        return p ? p->_height : 0;
    }

    int get_balance(Node* p) const
    {
        return get_height(p->_right) - get_height(p->_left);
    }

    void fix_height(Node* p)
    {
        int x = get_height(p->_left);
        int y = get_height(p->_right);
        p->_height = (x > y ? x : y) + 1;
    }

    Node* rotate_right(Node* p)
    {
        Node* q = p->_left;
        p->_left = q->_right;
        q->_right = p;
        fix_height(p);
        fix_height(q);
        return q;
    }

    Node* rotate_left(Node* q)
    {
        Node* p = q->_right;
        q->_right = p->_left;
        p->_left = q;
        fix_height(q);
        fix_height(p);
        return p;
    }

    Node* set_balance(Node* p)
    {
        fix_height(p);
        if (get_balance(p) == 2)
        {
            if (get_balance(p->_right) < 0)
                p->_right = rotate_right(p->_right);
            return rotate_left(p);
        }

        if (get_balance(p) == -2)
        {
            if (get_balance(p->_left) > 0)
                p->_left = rotate_left(p->_left);
            return rotate_right(p);
        }
        return p;
    }

    Node* insert_node(Node* p, const T& value)
    {
        if (!p)
            return new Node(value);
        if (value < p->_value)
            p->_left = insert_node(p->_left, value);
        else
            p->_right = insert_node(p->_right, value);
        return set_balance(p);
    }

    Node* find_min(Node* p) const
    {
        return p->_left ? find_min(p->_left) : p;
    }

    Node* remove_min(Node* p)
    {
        if (!p->_left)
            return p->_right;
        p->_left = remove_min(p->_left);
        return set_balance(p);
    }

    Node* remove_node(Node* p, const T& value)
    {
        if (!p)
            return 0;
        if (value < p->_value)
            p->_left = remove_node(p->_left, value);
        else if (value > p->_value)
            p->_right = remove_node(p->_right, value);
        else
        {
            Node* l = p->_left;
            Node* r = p->_right;
            delete p;
            if (!r)
                return l;
            Node* min = find_min(r);
            min->_right = remove_min(r);
            min->_left = l;
            return set_balance(min);
        }
        return set_balance(p);
    }

    void output(string& out, Node* p, int n) const
    {
        if (!p)
            return;
        output(out, p->_right, n + 1);
        for (int i = 0; i < n; ++i)
            out += "   ";
        out += std::to_string(p->_value) + "\n";
        output(out, p->_left, n + 1);
    }

    bool find_node(Node* p, const T& value, bool isHere) const
    {
        if (!p)
            return isHere || 0;
        isHere = find_node(p->_right, value, isHere);
        isHere = find_node(p->_left, value, isHere);
        return p->_value == value || isHere;
    }

    void clear(Node* p)
    {
        if (!p)
            return;
        clear(p->_left);
        clear(p->_right);
        delete p;
    }

    Node* _root;
public:
    AVLTree(const T& value)
    {
        _root = new Node(value);
    }

    AVLTree()
    {
        _root = nullptr;
    }

    ~AVLTree()
    {
        clear(_root);
    }

    void insert(const T& value)
    {
        _root = insert_node(_root, value);
    }

    void remove(const T& value)
    {
        _root = remove_node(_root, value);
    }

    void MakeDot()
    {
        std::ofstream out;          
        out.open("graph.txt");
        string strOut = "digraph G {";
        make_dot(strOut, _root, 0);
        strOut += "}";
        if (out.is_open())
        {
            out << strOut << std::endl;
        }
        out.close();
    }
    void Output() const
    {
        string strOut;
        output(strOut, _root, 0);
        std::cout << strOut;
    }

    bool contains(const T& value) const
    {
        return find_node(_root, value, 0);
    }
};

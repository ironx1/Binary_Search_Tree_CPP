#include <iostream>
using namespace std;

class binarySearchTree
{
private:
    struct node
    {
        node *left;
        int data;
        node *right;
    };
    node *root;
    node *createNode(int val)
    {
        node *n = new node;
        n->left = nullptr;
        n->data = val;
        n->right = nullptr;
        return n;
    }
    void InsertPrivate(node *n, int val)
    {
        if (root == nullptr)
        {
            root = createNode(val);
            return;
        }
        if (val < n->data)
        {
            node *iter = n;
            if (iter->left == nullptr)
            {
                iter->left = createNode(val);
                return;
            }
            InsertPrivate(iter->left, val);
            return;
        }
        if (val > n->data)
        {
            node *iter = n;
            if (iter->right == nullptr)
            {
                iter->right = createNode(val);
                return;
            }
            InsertPrivate(iter->right, val);
            return;
        }
        else
        {
            return;
        }
    }
    void printInorderPrivate(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        printInorderPrivate(n->left);
        cout << n->data << " ";
        printInorderPrivate(n->right);
    }
    void printPreorderPrivate(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        cout << n->data << " ";
        printPreorderPrivate(n->left);
        printPreorderPrivate(n->right);
    }
    void printPostorderPrivate(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        printPostorderPrivate(n->left);
        printPostorderPrivate(n->right);
        cout << n->data << " ";
    }
    int findMinPrivate(node *n)
    {
        if (n == nullptr)
        {
            return -1;
        }
        node *iter = n;
        while (iter->left != nullptr)
        {
            iter = iter->left;
        }
        return iter->data;
    }
    int findMaxPrivate(node *n)
    {
        if (n == nullptr)
        {
            return -1;
        }
        node *iter = n;
        while (iter->right != nullptr)
        {
            iter = iter->right;
        }
        return iter->data;
    }
    bool searchPrivate(node *n, int val)
    {
        if (n == nullptr)
        {
            return false;
        }
        if (n->data == val)
        {
            return true;
        }
        if (val < n->data)
        {
            searchPrivate(n->left, val);
        }
        else if (val > n->data)
        {
            searchPrivate(n->right, val);
        }
        else
        {
            return false;
        }
    }

public:
    binarySearchTree()
    {
        root = nullptr;
    }
    void Insert(int val)
    {
        InsertPrivate(root, val);
    }
    void printInorder()
    {
        printInorderPrivate(root);
        cout << endl;
    }
    void printPreorder()
    {
        printPreorderPrivate(root);
        cout << endl;
    }
    void printPostorder()
    {
        printPostorderPrivate(root);
        cout << endl;
    }
    int findMin()
    {
        return findMinPrivate(root);
    }
    int findMax()
    {
        return findMaxPrivate(root);
    }
    bool Search(int val)
    {
        searchPrivate(root, val);
    }
};

int main()
{
    binarySearchTree myBst;
    cout << "####################\n"
            "# BinarySearchTree #\n"
            "#      ironx1      #\n"
            "####################\n";
    bool _bool = true;
    while (_bool)
    {
        int selection;
        int data;
        cout << "1.\tInsert to Tree\n2.\tTraverse in Tree\n3.\tFind Min and Max Value\n4.\tSearch in Tree\n5.\tExit\nSelect: ";
        cin >> selection;
        switch (selection)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> data;
            myBst.Insert(data);
            break;
        case 2:
            cout << "Inorder traversal: ";
            myBst.printInorder();
            cout << "Preorder traversal: ";
            myBst.printPreorder();
            cout << "Postorder traversal: ";
            myBst.printPostorder();
            break;
        case 3:
            cout << "Min Value: " << myBst.findMin() << endl;
            cout << "Max Value: " << myBst.findMax() << endl;
            break;
        case 4:
        {
            string yesNoQuestion;
            cout << "Enter the Value to Search: ";
            cin >> data;
            bool val = myBst.Search(data);
            if (val == 1)
            {
                cout << "Available" << endl;
            }
            else if (val == 0)
            {
                cout << "Not Available" << endl;
            error:
                cout << "Do you want to insert"
                     << " " << data << " to tree?(y/n): ";
                cin >> yesNoQuestion;
                if (yesNoQuestion == "y")
                {
                    myBst.Insert(data);
                    cout << data << " "
                         << "Inserted to Tree" << endl;
                }
                else if (yesNoQuestion == "n")
                {
                    continue;
                }
                else
                {
                    goto error;
                }
            }
            break;
        }
        case 5:
            _bool = false;
            break;
        default:
            cout << "Error occured" << endl;
            break;
        }
    }
    return 0;
}
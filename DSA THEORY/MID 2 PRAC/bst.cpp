#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int n)
    {
        left = right = NULL;
        data = n;
    }
};

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

bool search(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

node *getinordersuccessor(node *root) // left most node in right subtree
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *delete_node(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > key)
    {
        root->left = delete_node(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = delete_node(root->right, key);
    }
    else
    {
        // 0 and 1 children case
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // 2 children case
        else
        {
            node *Is = getinordersuccessor(root->right);
            root->data = Is->data;
            root->right = delete_node(root->right, Is->data);
        }
    }
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if (leftheight > rightheight)
    {
        return leftheight + 1;
    }
    else
    {
        return rightheight + 1;
    }
}

int height_of_node(node *root, int key)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return height(root);
    }
    else if (root->data < key)
    {
        return height_of_node(root->right, key);
    }
    else
    {
        return height_of_node(root->left, key);
    }
}

int findmin(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int findmax(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int count_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftcount = count_nodes(root->left);
    int rightcount = count_nodes(root->right);
    return leftcount + rightcount + 1;
}

int sum_of_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftcount = sum_of_nodes(root->left);
    int rightcount = sum_of_nodes(root->right);
    return leftcount + rightcount + root->data;
}

void print_leaves(node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    print_leaves(root->left);
    print_leaves(root->right);
}

void print_internal_nodes(node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL || root->right != NULL)
    {
        cout << root->data << " ";
    }
    print_internal_nodes(root->left);
    print_internal_nodes(root->right);
}

int count_leaves(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

int count_internal_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    return count_internal_nodes(root->left) + count_internal_nodes(root->right) + 1;
}

int main()
{
    node *root = NULL;

    int arr[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i = 0; i < 7; i++)
    {
        root = insert(root, arr[i]);
    }

    postOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    cout << search(root, 5) << endl;

    root = delete_node(root, 3);
    inOrder(root);
    cout << endl;

    cout << "Min : " << findmin(root) << endl;
    cout << "Max : " << findmax(root) << endl;
    cout << "Height : " << height(root) << endl;
    cout << "Count : " << count_nodes(root) << endl;
    cout << "Height Of Node 5 : " << height_of_node(root, 5) << endl;
    cout << "Sum Of Nodes : " << sum_of_nodes(root) << endl;
    cout << "Leaves Count : " << count_leaves(root) << endl;
    print_leaves(root);
    cout << endl ;
    cout << "Internal Nodes : " << count_internal_nodes(root) << endl ;
    print_internal_nodes(root);

    return 0;
}
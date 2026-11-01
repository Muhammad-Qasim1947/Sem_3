#include <iostream>
#include <string>
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

class queue
{
public:
    node *arr[100];
    int front, rear;
    int cap;

    queue()
    {
        front = -1;
        rear = -1;
        cap = 100;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % cap == front;
    }

    void enqueue(node *n)
    {
        if (isFull())
        {
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % cap;
        }

        arr[rear] = n;
    }

    node *dequeue()
    {
        if (isEmpty())
        {
            return NULL;
        }

        node *temp = arr[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }
        return temp;
    }
};

static int idx = -1;
node *build_tree(int preorder[])
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    node *root = new node(preorder[idx]);

    root->left = build_tree(preorder);
    root->right = build_tree(preorder);
    return root;
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

void levelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue q;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        node *curr = q.dequeue();

        cout << curr->data;

        if (curr->left != NULL)
        {
            q.enqueue(curr->left);
        }
        if (curr->right != NULL)
        {
            q.enqueue(curr->right);
        }
    }
    cout << endl;
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

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftcount = count(root->left);
    int rightcount = count(root->right);
    return leftcount + rightcount + 1;
}

int sumofnodes(node *root){
    if (root == NULL)
    {
        return 0;
    }

    int leftsum = sumofnodes(root->left);
    int rightsum = sumofnodes(root->right);
    return leftsum + rightsum + root->data ;
}

int main()
{
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    node *root = build_tree(preorder);
    cout << root->data << endl;
    cout << endl;

    preOrder(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;

    cout << "HEIGHT : " << height(root) << endl;
    cout << "COUNT : " << count(root) << endl;
    cout << "SUM OF NODES : " << sumofnodes(root) << endl ;
}
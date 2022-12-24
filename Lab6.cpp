#include <iostream>
#include <queue>

struct Node
{
    int value;
    Node *left,*right;
};

void addElement(Node* &root, int newValue)
{
    if (!root)
    {
        root = new Node;
        root->value = newValue;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if(root->value > newValue)
        addElement(root->right, newValue);
    else    
        addElement(root->left, newValue);
}

void printTree(Node* root)
{
    if (root)
    {
        printTree(root->left); 
        printTree(root->right);
        std::cout << "Node value:" << root->value << std::endl;
    }
}

void printByLevels(Node* root)
{
    std::queue<Node*> queueOfLeaves((std::deque<Node*>(50)));
    queueOfLeaves.push(root);
    while(queueOfLeaves.size() > 1)
        {
            Node* leaf = queueOfLeaves.pop();
            std::cout << "Node value:" << leaf->value << std::endl;
            if(leaf->left)
                queueOfLeaves.push(leaf->left);
            if(leaf->right)
                queueOfLeaves.push(leaf->right);
        }
    return;
}

int countElementInTree(Node* root, int element)
{
    if(!root)  
    {
        return 0;
    }
    if (root->value == element)
    {
        return 1 + countElementInTree(root->left, element) + countElementInTree(root->right, element);
    }    
    else if (root->value > element)
    {
        return countElementInTree(root->left, element);
    }
    else
    {
        return countElementInTree(root->right, element);
    }
}

int main()
{
    Node* root = nullptr;
    addElement(root, 5);
    addElement(root, 2);
    addElement(root, 7);
    addElement(root, 3);
    addElement(root, 10);
    printByLevels(root);
    printTree (root);
    std::cout << "Count of element " << 5 << " in tree: " << countElementInTree(root, 5) << std::endl;
    return 0;
}

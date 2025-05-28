//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}

// } Driver Code Ends
// Node structure  used in the program

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *merge(Node *root1, Node *root2)
    {
        Node *head = new Node(-1), *temp = head;
        while (root1 && root2)
        {
            if (root1->data < root2->data)
            {
                temp->bottom = root1;
                root1 = root1->bottom;
            }
            else
            {
                temp->bottom = root2;
                root2 = root2->bottom;
            }
            temp = temp->bottom;
        }
        if (root1)
            temp->bottom = root1;
        if (root2)
            temp->bottom = root2;
        return head->bottom;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        Node *head = new Node(-1);
        while (root)
        {
            Node *temp = root;
            head = merge(head, temp);
            root = root->next;
        }
        return head->bottom;
    }
};

class Solution
{
public:
    Node *merge(Node *l1, Node *l2)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        Node *mergedNode = merge(l2, l2->next);
        Node *head = new Node(-1);
        Node *temp = head;
        while (l1 && l2)
        {
            if (l1->data <= l2->data)
            {
                temp->bottom = l1;
                l1 = l1->bottom;
            }
            else
            {
                temp->bottom = l2;
                l2 = l2->bottom;
            }
            temp = temp->bottom;
        }
        if (!l1)
        {
            temp->bottom = l2;
        }
        if (!l2)
        {
            temp->bottom = l1;
        }
        return head->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root)
    {
        // Your code here
        if (!root)
            return root;
        if (!root->next)
        {
            return root;
        }
        Node *newHead = merge(root, root->next);
        return newHead;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++)
        {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL)
            {
                head = temp;
                pre = temp;
            }
            else
            {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++)
            {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends
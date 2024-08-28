#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/design-linked-list/

class MyLinkedList {
public:
    struct Node {
        int val;
        Node *next;
        Node(int x) {
            this->val = x;
            this->next = NULL;
        }
    };
    Node* head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(!head or index > size || index < 0) return -1;
        Node *temp = head;
        while(temp and index > 0) {
            temp = temp->next;
            index--;
        }
        if(index  == 0 && temp != NULL) return temp->val;
        return -1;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        size++;
        if(!head) {
            head = new Node(val);
            return;
        }
        Node *temp = head;
        while(temp and temp->next) temp = temp->next;
        temp->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size or index < 0) return;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        size++;
        index--;
        Node *temp = head;
        while(temp and index > 0) {
            temp = temp->next;
            index--;
        }
        Node *nxtNode = temp->next;
        temp->next = new Node(val);
        temp = temp->next;
        temp->next = nxtNode; 
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 or index >= size) return;
        size--;
        if(index == 0) {
            head = head->next;
            return;
        }
        Node *temp = head;
        index--;
        while(temp->next and index > 0) {
            temp = temp->next;
            index--;
        }
        if(index == 0)
        temp->next = temp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    
    return 0;
}
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    ~Node()
    {
        int value = data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Delete the " << value << endl;
    }
};
// pahle insert karne kaliye
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
// end pe insert karne kaliye
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
// jis position pe caho t us position pe insert karne kaliye
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // agar position first hua
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // agar position end pe hua
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    // agar position bitch me koibi hua
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
// linkedlist print karne ka function
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // pahle me one node banaliya.
    Node *node1 = new Node(3);
    // head & tail ko node1 se connect kardiya.
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtTail(tail, 4);
    print(head);
    insertAtPosition(tail, head, 1, 1);
    print(head);
    insertAtPosition(tail, head, 5, 5);
    print(head);
    deleteNode(head, 5);
    print(head);
    cout << "Length " << getLength(head);
}
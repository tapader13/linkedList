#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
    ~Node()
    {
        int value = data;
        while (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Delete the " << value << endl;
    }
};
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *insertNode = new Node(d);
    insertNode->next = temp->next;
    temp->next->prev = insertNode;
    temp->next = insertNode;
    insertNode->prev = temp;
}
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    int count = 1;
    Node *prev = NULL;
    Node *curr = head;
    while (count < position)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}
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
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 5);
    print(head);
    insertAtTail(head, tail, 7);
    print(head);
    insertAtPosition(head, tail, 2, 6);
    print(head);
    insertAtPosition(head, tail, 1, 4);
    print(head);
    insertAtPosition(head, tail, 5, 8);
    print(head);
    deleteNode(head, 2);
    print(head);
}
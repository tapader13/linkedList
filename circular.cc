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
        while (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Delete the " << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = tail;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = curr->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "node is empty" << endl;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 0, 1);
    print(tail);
    // insertNode(tail, 1, 3);
    // print(tail);
    // insertNode(tail, 3, 2);
    // print(tail);
    deleteNode(tail, 1);
    print(tail);
}
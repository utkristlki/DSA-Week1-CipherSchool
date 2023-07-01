#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

Node<int>* reverse(Node<int>* head)
{
    Node<int>* curr = head;
    Node<int>* prev = NULL;
    Node<int>* forward = NULL;

    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void insertAtTail(Node<int>*&head, Node<int> *&tail, int num)
{
    Node<int> *newNode = new Node<int>(num);
    if(head == NULL) 
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.
    Node<int>* head1 = reverse(first);
    Node<int>* head2 = reverse(second);
    int carry = 0;
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while(head1!=NULL && head2!=NULL)
    {
        int sum = head1->data + head2->data + carry;
        if(sum>=10)
        {
            int rem = sum%10;
            carry = 1;
            insertAtTail(head, tail, rem);
        }
        else
        {
            insertAtTail(head,tail, sum);
            carry = 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1!=NULL)
    {
        int sum = head1->data + carry;
        if(sum>=10)
        {
            int rem = sum%10;
            carry = 1;
            insertAtTail(head, tail, rem);
        }
        else
        {
            insertAtTail(head, tail, sum);
            carry = 0;
        }
        head1 = head1->next;
    }
     while(head2!=NULL)
    {
        int sum = head2->data + carry;
        if(sum>=10)
        {
            int rem = sum%10;
            carry = 1;
            insertAtTail(head, tail, rem);
        }
        else
        {
            insertAtTail(head, tail, sum);
            carry = 0;
        }
        head2 = head2->next;
    }
    if(carry == 1)
    {
        insertAtTail(head, tail, 1);
    }
    Node<int> *ans = reverse(head);
    return ans;
}

int main()
{

    return 0;
}
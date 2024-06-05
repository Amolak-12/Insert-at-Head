#include <iostream>
using namespace std;


// Making Node for making Linked List
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node() {
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
};

// Function for adding a node right at the head or to the the left of head
void insertAtHead(Node *&head, Node *&tail, int data) {
  // Checking if LL is empty or not
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // Step 1 : Create a node
  Node *newNode = new Node(data);
  // Step 2 : Initialize new node's next with head
  newNode->next = head;
  // Step 3 : Initialize head's prev with newNode
  head->prev = newNode;
  // Step 4 : Change head and make it at the newNode
  head = newNode;
}

// Function for printing the whole of Linked List
void print(Node *&head) {
  Node *temp = head;
  cout << "Printing the Linked List : " << endl;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

int main() {
  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  first->next = second;
  second->prev = first;
  second->next = third;
  third->prev = second;

  //Printing normal Linked List
  print(first);

  //Inserting at head
  insertAtHead(first, third, 100);
  //Printing modified Linked List
  print(first);
}
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // data part
    Node* next;     // pointer to next node
};

// Class for Linked List
class LinkedList {
private:
    Node* head;     // pointer to first node

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Function to insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Function to delete a node with given value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head node is to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << endl;
            return;
        }

        // Otherwise, search for the node to delete
        Node* current = head;
        while (current->next != NULL && current->next->data != value)
            current = current->next;

        if (current->next == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Deleted " << value << endl;
    }

    // Function to display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    //Example Usage
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.deleteNode(20);
    list.display();

    list.deleteNode(100); // not in list
    list.display();

    return 0;
}

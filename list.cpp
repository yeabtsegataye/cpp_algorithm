#include <iostream>
using namespace std;

//////////

struct node {
    int data;
    node* nxt;
};

typedef node* pnode;

pnode head, p;

void createList(pnode* head) {
    *head = nullptr;
    cout << "List created.\n";
}

bool isEmpty(pnode head) {
    return (head == nullptr);
}

pnode getNode() {
    return new node;
}

void freeNode(pnode p) {
    delete p;
}

////////////////
void insertFirst(pnode* head, pnode p) {
    if (*head == nullptr) {
        *head = p;
        p->nxt = nullptr;
    } else {
        p->nxt = *head;
        *head = p;
    }
    cout << "Inserted " << p->data << " at the beginning.\n";
}
///////////////
void insertMiddle(pnode* head, pnode p, pnode previous) {
    if (previous == nullptr)
        insertFirst(&(*head), p);
    else {
        p->nxt = previous->nxt;
        previous->nxt = p;
    }
    cout << "Inserted " << p->data << " in the middle.\n";
}
/////////////////
void insertLast(pnode* head, pnode p) {
    if (*head == nullptr)
        insertFirst(&(*head), p);
    else {
        pnode last = *head;
        while (last->nxt != nullptr) {
            last = last->nxt;
        }
        last->nxt = p;
        p->nxt = nullptr;
    }
    cout << "Inserted " << p->data << " at the end.\n";
}
////////////////
void deleteFirst(pnode* head) {
    if (isEmpty(*head))
        cout << "The list is empty\n";
    else {
        p = *head;
        *head = p->nxt;
        cout << "Deleted " << p->data << " from the beginning.\n";
        freeNode(p);
    }
}
//////////////////
void deleteMiddle(pnode* head, pnode p, pnode previous) {
    if (previous == nullptr)
        deleteFirst(&(*head));
    else {
        previous->nxt = p->nxt;
        cout << "Deleted " << p->data << " from the middle.\n";
        freeNode(p);
    }
}
////////////////
void deleteLast(pnode* head) {
    if (isEmpty(*head))
        cout << "The list is empty.\n";
    else {
        pnode last = *head;
        pnode temp = nullptr;
        while (last->nxt != nullptr) {
            temp = last;
            last = last->nxt;
        }
        if (temp != nullptr)
            temp->nxt = nullptr;
        cout << "Deleted " << last->data << " from the end.\n";
        freeNode(last);
    }
}
//////////////////
void displayList(pnode head) {
    if (isEmpty(head)) {
        cout << "List is empty.\n";
    } else {
        pnode current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->nxt;
        }
        cout << endl;
    }
}
//////////////////
int main() {
    createList(&head);

    int n;

    do { 
        cout << "1. Insert list at\n";
        cout << "2. Delete list at\n";
        cout << "3. Display\n";
        cout << "4. Go back\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1 ) {
            int x;
            cout << "1. First\n";
            cout << "2. Middle\n";
            cout << "3. Last\n";
            cout << "4. Go back\n";
            cout << "Enter your choice: ";
            cin >> x;

            if (x == 1) {
                p = getNode();
                cout << "Enter the data: ";
                cin >> p->data;
                insertFirst(&head, p);
            } else if (x == 2) {
                int val;
                cout << "Enter the value after which to insert: ";
                cin >> val;
                p = getNode();
                cout << "Enter the data: ";
                cin >> p->data;
                pnode previous = head;
                while (previous != nullptr && previous->data != val) {
                    previous = previous->nxt;
                }
                insertMiddle(&head, p, previous);
            } else if (x == 3) {
                p = getNode();
                cout << "Enter the data: ";
                cin >> p->data;
                insertLast(&head, p);
            } else if (x == 4) {
                continue; // Go back to the menu
            } else {
                cout << "Invalid choice for increment/decrement." << endl;
            }
        }
        ////////////////
        if (choice == 2) {
            int x;
            cout << "1. First\n";
            cout << "2. Middle\n";
            cout << "3. Last\n";
            cout << "4. Go back\n";
            cout << "Enter your choice: ";
            cin >> x;

            if (x == 1) {
                deleteFirst(&head);
            } else if (x == 2) {
                int val;
                cout << "Enter the value to delete: ";
                cin >> val;
                pnode current = head;
                pnode previous = nullptr;
                while (current != nullptr && current->data != val) {
                    previous = current;
                    current = current->nxt;
                }
                deleteMiddle(&head, current, previous);
            } else if (x == 3) {
                deleteLast(&head);
            } else if (x == 4) {
                continue; // Go back to the menu
            } else {
                cout << "Invalid choice for increment/decrement." << endl;
            }
        }
        ////////////////
        if (choice == 3) {
            displayList(head);
        }
        if (choice == 4) {
            continue;
        }
        if (choice == 5) {
            cout << "Exiting..." << endl;
            break; // Exit the program
        }
    } while (n != 5);

    return 0;
}

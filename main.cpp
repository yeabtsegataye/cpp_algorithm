#include <iostream>

using namespace std;

struct node {
    int data;
    node* nxt;
};

typedef node* pnode;

pnode head, p;

// Function prototypes
void createList(pnode* head);
bool isEmpty(pnode head);
pnode getNode();
void freeNode(pnode p);
void insertFirst(pnode* head, pnode p);
void insertMiddle(pnode* head, pnode p, pnode previous);
void insertLast(pnode* head, pnode p);
void deleteFirst(pnode* head);
void deleteMiddle(pnode* head, pnode p, pnode previous);
void deleteLast(pnode* head);
void displayList(pnode head);

int main() {
    createList(&head);
    int ch;
    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert in the middle\n";
        cout << "3. Insert at the end\n";
        cout << "4. Delete from the beginning\n";
        cout << "5. Delete from the middle\n";
        cout << "6. Delete from the end\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                p = getNode();
                cout << "Enter the value to insert at the beginning: ";
                cin >> p->data;
                insertFirst(&head, p);
                break;
            case 2:
                p = getNode();
                cout << "Enter the value to insert in the middle: ";
                cin >> p->data;
                insertMiddle(&head, p, nullptr);
                break;
            case 3:
                p = getNode();
                cout << "Enter the value to insert at the end: ";
                cin >> p->data;
                insertLast(&head, p);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteMiddle(&head, p, nullptr);
                break;
            case 6:
                deleteLast(&head);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (ch != 8);

    return 0;
}

// Function definitions

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

void insertMiddle(pnode* head, pnode p, pnode previous) {
    if (previous == nullptr)
        insertFirst(&(*head), p);
    else {
        p->nxt = previous->nxt;
        previous->nxt = p;
    }
    cout << "Inserted " << p->data << " in the middle.\n";
}

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

void deleteMiddle(pnode* head, pnode p, pnode previous) {
    if (previous == nullptr)
        deleteFirst(&(*head));
    else {
        previous->nxt = p->nxt;
        cout << "Deleted " << p->data << " from the middle.\n";
        freeNode(p);
    }
}

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
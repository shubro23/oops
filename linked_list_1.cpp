#include<iostream>
using namespace std;

struct Listnode {
    int data;
    Listnode* next;
};

int listlength(Listnode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void InsertInLinkedList(Listnode** head, int data, int position) {
    int k = 1;
    Listnode *p, *q, *newnode;
    newnode = new Listnode();

    if (newnode == NULL) {
        cout << "Memory error" << endl;
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    p = *head;

    if (position == 1) {
        newnode->next = *head;
        *head = newnode;
    } else {
        while ((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }

        if (k != position) {
            cout << "Position out of bounds" << endl;
            delete newnode;
            return;
        }

        q->next = newnode;
        newnode->next = p;
    }
}

void deletenode(Listnode** head, int position) {
    int k = 1;
    Listnode *p, *q;

    if (*head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    p = *head;

    if (position == 1) {
        *head = (*head)->next;
        delete p;
        return;
    }

    while ((p != NULL) && (k < position)) {
        k++;
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Position not found" << endl;
    } else {
        q->next = p->next;
        delete p;
    }
}

void printList(Listnode* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Listnode* head = NULL;

    InsertInLinkedList(&head, 10, 1);
    InsertInLinkedList(&head, 20, 2);
    InsertInLinkedList(&head, 30, 3);
    InsertInLinkedList(&head, 15, 2);
    printList(head);

    cout << "Length: " << listlength(head) << endl;

    deletenode(&head, 2);
    printList(head);

    return 0;
}
#include <iostream>

using namespace std;


struct tovar {
    int id;
    int price;
    tovar *next;
};


void addFirst(tovar *&head, int id, int price) {
    tovar *newtovar = new tovar;
    newtovar->id = id;
    newtovar->price = price;
    newtovar->next = head;
    head = newtovar;
}


void addBefore(tovar *&head, int idkey, int id, int price) {
    tovar *newtovar = new tovar;
    newtovar->id = id;
    newtovar->price = price;

    if (head == NULL) {
        cout << "This list is empty\n";
        return;
    }

    tovar *tmp = head;
    while (tmp->next != NULL && tmp->next->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->next->id == idkey) {
        newtovar->next = tmp->next;
        tmp->next = newtovar;
    } else cout << "No elements with provided id in list\n";
}


void addAfter(tovar *&head, int idkey, int id, int price) {
    tovar *newtovar = new tovar;
    newtovar->id = id;
    newtovar->price = price;

    if (head == NULL) {
        cout << "This list is empty\n";
        return;
    }

    tovar *tmp = head;
    while (tmp->next != NULL && tmp->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->id == idkey) {
        newtovar->next = tmp->next;
        tmp->next = newtovar;
    } else cout << "No elements with provided id in list\n";
}


void delFromList(tovar *&head, int idkey) {
    if (head == NULL) {
        cout << "This list is empty\n";
    }
    tovar *tmp = head;


    if (tmp->id == idkey) {
        head = tmp->next;
        return;
    }

    while (tmp->next != NULL && tmp->next->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->next->id == idkey) {
        tmp->next = tmp->next->next;
    } else cout << "No elements with provided id in list\n";
}


void printList(tovar *&head) {
    if (head == NULL) {
        cout << "This list is empty\n";
    }
    tovar *tmp = head;
    while (tmp != NULL) {
        cout << "Tovar id: " << tmp->id << endl;
        tmp = tmp->next;
    }
}

int main() {
    tovar *head = NULL;

    int id1 = 1;
    int price1 = 11;

    int id2 = 2;
    int price2 = 22;

    int id3 = 3;
    int price3 = 33;

    int id4 = 4;
    int price4 = 44;


    addAfter(head, id1, id1, price1);
    cout << "--------------------------\n";
    addFirst(head, id1, price1);
    addAfter(head, 0, 4, price3);
    printList(head);
    cout << "--------------------------\n";
    addAfter(head, id1, id2, price2);
    printList(head);
    cout << "--------------------------\n";
    addAfter(head, id1, id3, price3);
    printList(head);
    cout << "--------------------------\n";
    addAfter(head, 0, 4, price3);
    printList(head);
    cout << "--------------------------\n";
    addBefore(head, id3, id4, price4);
    printList(head);
    cout << "--------------------------\n";
    delFromList(head, id1);
    printList(head);
    cout << "--------------------------\n";
    delFromList(head, id2);
    printList(head);
    return 0;
}

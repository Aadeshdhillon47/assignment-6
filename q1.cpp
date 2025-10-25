#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node* createNode(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = n->prev = NULL;
    return n;
}

void insertEnd(Node* &head, int x) {
    Node* n = createNode(x);
    if (!head) {
        head = n;
        head->next = head->prev = head;
        return;
    }
    Node* last = head->prev;
    last->next = n;
    n->prev = last;
    n->next = head;
    head->prev = n;
}

void deleteNode(Node* &head, int x) {
    if (!head) return;
    Node* temp = head;
    do {
        if (temp->data == x) {
            if (temp->next == temp) { head = NULL; delete temp; return; }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            delete temp; return;
        }
        temp = temp->next;
    } while (temp != head);
}

bool search(Node* head, int x) {
    if (!head) return false;
    Node* t = head;
    do {
        if (t->data == x) return true;
        t = t->next;
    } while (t != head);
    return false;
}

void display(Node* head) {
    if (!head) return;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    int ch, val;
    do {
        cout << "1.Insert 2.Delete 3.Search 4.Display 5.Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> val; insertEnd(head, val); }
        else if (ch == 2) { cin >> val; deleteNode(head, val); }
        else if (ch == 3) { cin >> val; cout << (search(head, val) ? "Found\n" : "Not Found\n"); }
        else if (ch == 4) display(head);
    } while (ch != 5);
}

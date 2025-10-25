#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head){
    if(!head) return;
    Node* t = head;
    do{
        cout << t->data << " ";
        t = t->next;
    }while(t != head);
    cout << head->data;
}

Node* create(int a[], int n){
    Node* head = NULL;
    Node* last = NULL;
    for(int i=0;i<n;i++){
        Node* nNode = new Node{a[i], NULL};
        if(!head){ head = nNode; head->next = head; last = head; }
        else{
            nNode->next = head;
            last->next = nNode;
            last = nNode;
        }
    }
    return head;
}

int main(){
    int a[5] = {20,100,40,80,60};
    Node* head = create(a,5);
    display(head);
}

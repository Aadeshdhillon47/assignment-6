#include <iostream>
using namespace std;

struct DNode{
    int data;
    DNode *next, *prev;
};
struct CNode{
    int data;
    CNode* next;
};

int sizeDLL(DNode* head){
    int c=0;
    while(head){ c++; head=head->next; }
    return c;
}
int sizeCLL(CNode* head){
    if(!head) return 0;
    int c=0;
    CNode* t = head;
    do{ c++; t=t->next; }while(t!=head);
    return c;
}

int main(){
    DNode *d1 = new DNode{1,NULL,NULL};
    d1->next = new DNode{2,NULL,d1};
    cout << "Size of DLL: " << sizeDLL(d1) << endl;

    CNode *c1 = new CNode{1,NULL};
    CNode *c2 = new CNode{2,NULL};
    c1->next = c2; c2->next = c1;
    cout << "Size of CLL: " << sizeCLL(c1);
}

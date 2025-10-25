#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *next,*prev;
};

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* tail=head;
    while(tail->next) tail=tail->next;
    while(head && tail && head!=tail && tail->next!=head){
        if(head->data!=tail->data) return false;
        head=head->next;
        tail=tail->prev;
    }
    return true;
}

int main(){
    Node* a = new Node{'r',NULL,NULL};
    a->next=new Node{'a',NULL,a};
    a->next->next=new Node{'r',NULL,a->next};
    cout << (isPalindrome(a) ? "True" : "False");
}

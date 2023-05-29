#include<iostream>
#include<vector>

class Node{
    public:
    int data;
    Node* next;

    Node(int tmpdata){
        data = tmpdata;
    }
};

void printList(Node* head){

    while(head!=nullptr){
        std::cout<<head->data<<" ";
        head=head->next;
    }
    std::cout<<std::endl;
}

Node* reverseList(Node* head){

    Node* current = head;
    Node* prev = nullptr;

    while(current!=nullptr){
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main(){

    std::vector<int> V;
    
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = nullptr;
    printList(a);
    Node* revHead = reverseList(a);

    printList(revHead);

}
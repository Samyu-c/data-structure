

#include <iostream>
using namespace std;

class node 
{
public:
    int data;
    node* next;

public:
    node(int d1, node* n1) {
        data = d1;
        next = n1;
    }

    node(int d1) {
        data = d1;
        next = nullptr;
    }
};

node* push(node*& top, int val) 
{
    node* newnode = new node(val, top);
    top = newnode;
    cout << "element pushed" << endl;
    return top;
}

node* pop(node* top) {
    if (top == NULL) {
        cout << "stack empty" << endl;
        return NULL;
    }
    node* temp = top;
    cout << "element popped is :" << temp->data << endl;
    top = temp->next;
    delete temp;
    return top;
}

void display(node* top) {
    if (top == NULL) {
        return;
    }
    node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* top = NULL;
    int op;
    char a = 'y';

    while (a == 'y') {
        cout << "1.push\n2.pop\n3.display\n";
        cout << "enter option: ";
        cin >> op;

        switch (op) {
            case 1: {
                int val;
                cout << "enter value: ";
                cin >> val;
                top = push(top, val);
                break;
            }
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            default:
                cout << "Invalid option" << endl;
        }

        cout << "do you want to continue (y/n): ";
        cin >> a;
        cout << endl;
    }
}
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* back;
    node* next;

    node(int d1) {
        data = d1;
        back = next = nullptr;
    }
    node(int d1, node* b1, node* n1) {
        data = d1;
        back = b1;
        next = n1;
    }
};


node* create(node* head) {
    int val;
    node* temp = head;
    while (true) {
        cout << "Enter value (-1 to stop): ";
        cin >> val;
        if (val == -1) break;
        node* newnode = new node(val, temp, nullptr);
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}


node* insertbeg(node* head) {
    int val;
    cout << "Enter value: ";
    cin >> val;
    node* newhead = new node(val, nullptr, head);
    if (head != nullptr) head->back = newhead;
    return newhead;
}


node* insertend(node* head) {
    node* temp = head;
    int val;
    cout << "Enter element: ";
    cin >> val;
    while (temp->next != nullptr) temp = temp->next;
    node* newtail = new node(val, temp, nullptr);
    temp->next = newtail;
    return head;
}

// insertion at position k
node* insertk(node* head, int k) {
    int val;
    cout << "Enter value: ";
    cin >> val;
    node* temp = head;
    int c = 1;
    while (temp != nullptr) {
        if (c == k - 1) {
            node* y = new node(val, temp, temp->next);
            if (temp->next != nullptr) temp->next->back = y;
            temp->next = y;
            return head;
        }
        temp = temp->next;
        c++;
    }
    cout << "Not a valid position\n";
    return head;
}

node* deletehead(node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}


node* deletend(node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->back->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}


node* deletek(node* head, int k) {
    if (head == nullptr) return nullptr;
    int c = 1;
    node* temp = head;
    while (temp != nullptr) {
        if (c == k) break;
        temp = temp->next;
        c++;
    }
    if (temp == nullptr) {
        cout << "Not a valid position\n";
        return head;
    }
    node* prev = temp->back;
    node* front = temp->next;

    if (prev == nullptr && front == nullptr) { 
        delete temp;
        return nullptr;
    }
    else if (prev == nullptr) { 
        return deletehead(head);
    }
    else if (front == nullptr) { 
        return deletend(head);
    }
    else {
        prev->next = front;
        front->back = prev;
        delete temp;
        return head;
    }
}

// display DLL
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// search element
void search(node* head) {
    node* temp = head;
    int s;
    cout << "Enter element to search: ";
    cin >> s;
    while (temp != nullptr) {
        if (temp->data == s) {
            cout << "Element FOUND!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "NOT FOUND\n";
}

int main() {
    int hd;
    cout << "Enter first element: ";
    cin >> hd;
    node* head = new node(hd);

    bool a = true;
    int op;

    while (a) {
        cout << "\n1. Create\n2. Insertion\n3. Deletion\n4. Search\n0. Exit\n";
        cout << "Enter option: ";
        cin >> op;
        switch (op) {
        case 1:
            head = create(head);
            display(head);
            break;

        case 2: {
            int op1;
            cout << "1. Insert at beginning\n2. Insert at end\n3. Insert at position\n0. Exit\n";
            cout << "Enter option: ";
            cin >> op1;
            if (op1 == 1) head = insertbeg(head);
            else if (op1 == 2) head = insertend(head);
            else if (op1 == 3) {
                int k;
                cout << "Enter position: ";
                cin >> k;
                head = insertk(head, k);
            }
            display(head);
            break;
        }

        case 3: {
            int op2;
            cout << "1. Delete head\n2. Delete tail\n3. Delete at position\n";
            cout << "Enter option: ";
            cin >> op2;
            if (op2 == 1) head = deletehead(head);
            else if (op2 == 2) head = deletend(head);
            else if (op2 == 3) {
                int k;
                cout << "Enter position: ";
                cin >> k;
                head = deletek(head, k);
            }
            display(head);
            break;
        }

        case 4:
            search(head);
            break;

        case 0:
            a = false;
            break;

        default:
            cout << "Invalid option!\n";
        }
    }
    return 0;
}

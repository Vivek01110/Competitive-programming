#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
         this -> val = val;
         this -> next = NULL;
        }
};

void insert_node(Node*&head, int val){
    Node* temp = new Node(val);

    temp -> next = head;
    head = temp;
}

Node* separateEvenOdd(Node* head) {
    if (!head || !head->next) return head;

    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    Node* temp = head;

    while (temp) {
        int val = temp->val;
        if (!val&1) {
            if (evenStart == NULL) {
                evenStart = temp;
                evenEnd = evenStart;
            } else {
                evenEnd->next = temp;
                evenEnd = evenEnd->next;
            }
        } else {
            if (oddStart == NULL) {
                oddStart = temp;
                oddEnd = oddStart;
            } else {
                oddEnd->next = temp;
                oddEnd = oddEnd->next;
            }
        }
        temp = temp->next;
    }

    if (!evenStart || !oddStart) return head;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Node* head = NULL;

        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            insert_node(head , val);
        }
        Node* newhead = separateEvenOdd(head);
        printList(newhead);
    }
   
}
/*
1
6
2 3 1 5 7 8

*/
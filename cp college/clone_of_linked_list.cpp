#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};


Node* cloneLinkedList(Node* head) {
    if (!head) return NULL;

    unordered_map<Node*, Node*> nodeMap;
    
   
    Node* temp = head;
    while (temp) {
        nodeMap[temp] = new Node(temp->data);
        temp = temp->next;
    }

   
    temp = head;
    while (temp) {
        nodeMap[temp]->next = nodeMap[temp->next];  // Assign next pointer
        nodeMap[temp]->random = nodeMap[temp->random];  // Assign random pointer
        temp = temp->next;
    }

    return nodeMap[head];  
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Data: " << temp->data;
        if (temp->random) 
            cout << ", Random: " << temp->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}


Node* createLinkedList(int n) {
    if (n == 0) return nullptr;

    vector< Node*> nodeMap;
    Node *head = NULL, *tail = NULL;

   
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        
        if (!head) head = newNode;
        else tail->next = newNode;

        tail = newNode;
        nodeMap[i] = newNode;  // Store reference to the node for random pointers
    }

    // Step 2: Read random pointer indices
    for (int i = 0; i < n; i++) {
        int randIndex;
        cin >> randIndex;
        if (randIndex != -1) {
            nodeMap[i]->random = nodeMap[randIndex];
        }
    }

    return head;
}


int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n;
        cin >> n;  

        Node* head = createLinkedList(n);
      
        // printList(head);

        Node* clonedHead = cloneLinkedList(head);
        // cout << "Cloned List:\n";
        // printList(clonedHead);
    }

    return 0;
}

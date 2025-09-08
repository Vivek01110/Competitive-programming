#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }

    int val;
    Node* next;
    

};

Node *insert_Node(Node*&head , int val){
    Node*temp = new Node(val);
    if(head == NULL){
        head = temp;
        
    }
    else{
        temp -> next = head;
        head = temp; 
    }

    return temp;    
}

bool hascycle(Node* head){
    if(head == NULL)
        return false;
    
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast){
            return true;
        }
    }

    return false;
     
}


int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin>> n;

        int index; // (index start from  1)
        cin>> index;
        

        Node* head = NULL;
       

        Node* cycleNode = NULL;
        Node* temp = NULL;
        
        for(int i = n - 1; i >= 0; i--){
            int val;
            cin>> val;

            temp =  insert_Node(head ,  val);

          if(index == i + 1){
            cycleNode = temp;
          }

        }

        if(temp){
            temp -> next = cycleNode;
        }
        
        if(hascycle(head)){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
        
        
    }
}
// if index == -1 it means there is no cycle
/*
7
4
3
12 30 40 55
4
2
12 30 40 55
5
-1
50 60 70 80 90
2
1
20 30
1
-1
40
1
1
50
0
-1
*/

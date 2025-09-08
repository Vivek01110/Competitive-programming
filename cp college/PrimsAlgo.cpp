#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    int weight;
    Node*next;

    Node(int data, int weight) {
        this->data = data;
        this->weight = weight;
        this->next = nullptr;
        }

};

void add_edge(vector<Node*>& adj, int u, int v, int weight) {
    Node* newNode = new Node(v, weight);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = new Node(u, weight);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void prims_algorithm(vector<Node*>& adj, int V) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
    
        int src = 0;
        pq.push({0, src});
        key[src] = 0;
    
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
    
            inMST[u] = true;
            Node* node = adj[u];
            
           while(node != nullptr){
                int v = node->data;
                int weight = node->weight;
    
                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
                node = node -> next;
            }
        }
    
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " \n";
        }
    }
    
    int main() {
        int T;
        cin >> T;
    
        while (T--) {
            int V, E;
            cin >> V >> E;
            vector<Node*> adj(V, nullptr);
    
            for (int i = 0; i < E; ++i) {
                int u, v, weight;
                cin >> u >> v >> weight;
                add_edge(adj, u, v, weight);
            }
    
            prims_algorithm(adj, V);
        }
    
        return 0;
    }







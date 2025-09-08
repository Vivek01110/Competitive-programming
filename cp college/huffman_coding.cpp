#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


struct Node {
    char ch;              
    int freq;              
    Node* left;           
    Node* right;   

    Node(char c, int f) {
        this-> ch = c;
        this -> freq = f;
        this -> left = NULL;
        this -> right = NULL;
    }

    
    bool operator>(Node& other) {
        return freq > other.freq;
    }
};


Node* buildHuffmanTree(unordered_map<char, int>& freqMap) {
    
    priority_queue<Node*, vector<Node*>, greater<Node*>> minHeap;

   
    for (auto& itr : freqMap) {
        minHeap.push(new Node(itr.first, itr.second));
    }

   
    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode  = new Node('\0', left->freq + right->freq);
        newNode ->left = left;
        newNode ->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top(); 
}


void generateHuffmanCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

   
    if (root->ch != '\0') {
        huffmanCodes[root->ch] = code;
    }

    
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}


string encode(const string& input, const unordered_map<char, string>& huffmanCodes) {
    string encodedStr;
    for (char c : input) {
        encodedStr += huffmanCodes.at(c);
    }
    return encodedStr;
}





unordered_map<char, int> buildFrequencyMap(const string& input) {
    unordered_map<char, int> freqMap;
    for (char c : input) {
        freqMap[c]++;
    }
    return freqMap;
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
       
        string input;
        cin >> input;

       
        unordered_map<char, int> freqMap = buildFrequencyMap(input);

       
        Node* root = buildHuffmanTree(freqMap);

        
        unordered_map<char, string> huffmanCodes;
        generateHuffmanCodes(root, "", huffmanCodes);

       
        string encodedStr = encode(input, huffmanCodes);

        
       
       
        cout << "Original String: " << input << endl;
        cout << "Encoded String: " << encodedStr << endl;
       
    }

    return 0;
}


// 1
// abbc

// struct{
// char[]/string
// int freq;
// node* left , node* right;
// char code [50]
// }

// use arrray of pointer insetead for input for read data 

// huffmantree()
// huffmancode()
// displaycode()

// leaf => 


// use of union in place of strucy


// struct {
//     // int flag;
        // bool status = 0 for leaf and 1 nonleaf
    
        // divide into leaf and nonleaf make structure
        
        // union{
            
            // struct { left }
            // struct { right }
    
        // }

// }
#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <vector>
#include <list> // ddl
#include <forward_list> // sll
#include <iterator> // pointer
#include <stack> // pointer
#include <fstream> // fstream
#include <queue> // queue
#include <set> // set
#include <map> // map
using namespace std;



class AdjacentList {
private:
	// create nodes and edges
	int nodes, edges;
	// initiating big vector called graph to carry small victors of type int
	vector <vector<int>> graph;

public:

	void createList() {
		int node1, node2; // start and end of every edge
		cout << "Add number of Nodes: \n";
		cin >> nodes;
		cout << "\nAdd number of Edges: \n";
		cin >> edges;

		// resize graph (the big vector) on the size of nodes (small vectors) only + 1 as index 0 can not be used
		graph.resize(nodes + 1);

		// loop from 1 as index 0 is always empty, loop on the number of existing edges (relation between nodes) only
		for (int i = 1; i <= edges; i++) {
			cout << "\nEnter start and end of the Edge " << i << ": ";
			cin >> node1 >> node2;
			// since it's undirected so we add every node to each other vector not only one way
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		};

	}

	// (root, unreachable node, the big array, visited array)
	void DFS(int currentNode, int searchNode, vector <vector<int>> graph, bool visited[]) {
		visited[currentNode] = true; // save node as visited
		if (currentNode == searchNode) return; // if we found the search return
		cout << currentNode << " -> "; // print the current node
		// then loooping over the elements in every node
		for (int i = 0; i < graph[currentNode].size(); i++) {
			int child = graph[currentNode][i]; // let's call child to the element in node in graph 
			if (!visited[child]) {
				// if child is still not visited then invoke DFS
				// which will mark as visited, check if it's the one we search for if not print it, then
				// move to the other node elements then move to the next node untill it finish all the graph 
				DFS(child, searchNode, graph, visited);
			}
		}

	}

		void BFS(int currentNode, int searchNode, vector <vector<int>> graph, bool visited[]) {
		visited[currentNode] = true; // save node as visited
		if (currentNode == searchNode) return; // if we found the search return
		queue <int> q;
		q.push(currentNode);
			while (!q.empty()) {
			currentNode = q.front();
			cout << q.front() << " -> "; // print the current node
			// then loooping over the elements in every node
			for (int i = 0; i < graph[currentNode].size(); i++) {
				int child = graph[currentNode][i]; // let's call child to the element in node in graph 
				if (!visited[child]) {
					// if child is still not visited then invoke DFS
					// which will mark as visited, check if it's the one we search for if not print it, then
					// move to the other node elements then move to the next node untill it finish all the graph 
					q.push(child);
					visited[child] = true;
				   }
				}
				q.pop();
			}
		}

	void DFSprint() {
		cout << "\n========================\n\n\n";
		cout << "DFS ==>>>\n";
		bool* visited = new bool [nodes + 1] {}; // initiate visited arr with boolean type, and reset it {}
		// Loop through all nodes and perform DFS from each unvisited node
		for (int i = 1; i <= nodes; i++) {
			if (!visited[i]) {
				DFS(i, -1, graph, visited); // Start DFS traversal from node i
			}
		}
	    //DFS(1, -1, graph, visited); // using DFS by adding (root, unreachable node, the big array, visited array)
		cout << endl;		
		delete[]visited; // clearing visited arr after finishing to free memory as we don't need it
		//// DFS ==>>> 1 -> 5 -> 2 -> 6 -> 3 -> 4 ->
	};	


	void BFSprint() {
		bool* visited = new bool [nodes + 1] {}; // initiate visited arr with boolean type, and reset it {}
		cout << "\n\nBFS ==>>>\n";

		BFS(1, -1, graph, visited); // using DFS by adding (root, unreachable node, the big array, visited array)
		cout << endl;
		delete []visited; // clearing visited arr after finishing to free memory as we don't need it
		// BFS ==>>> 1 -> 5 -> 2 -> 4 -> 3 -> 6 ->
	};
};



int main() {

	AdjacentList a;
	a.createList();
	a.DFSprint();
	a.BFSprint();
}










//// Node class
//class Node {
//public:
//	int value;
//	Node* left;
//	Node* right;
//
//	Node() {
//		this->value = value;       // initial value 
//		this->right = nullptr; // initial value null
//		this->left = nullptr;  // initial value null
//
//	}
//	Node(int value, Node* right, Node* left) {
//		this->value = value;
//		this->right = right;
//		this->left = left;
//
//	}
//};
//
//
//// Binary Search Tree class
//class BST {
//private:
//	Node* root; // creating root as an initial Node
//
//public:
//	BST() {
//		this->root = nullptr; // initial root(value, right, left) is null
//	}
//
//	// searching for value
//	bool search(int value) {
//		Node* p = root; // creating a pointer on the root
//		while (p != nullptr) // if there is members in the tree continue
//		{
//			if (p->value == value) return true; // if value is found return TRUE
//			if (value > p->value) { 
//			// if value > pointer value which starts from root, move pointer to the next node
//				p = p->right; 
//			}
//			else {
//			// if value < pointer value, move pointer to the prev node
//				p = p->left;
//			}
//		}
//		// if value is not found return FALSE
//		return false;
//	}
//
//	// adding new value by creating a new Node
//	void insert(int value) {
//		// if value is already exist return it
//		if (search(value)) return; 
//
//		// creating a new Node which has the added value, null for right & left
//		Node* n = new Node(value, nullptr, nullptr); 
//		// if tree is empty, set root to be the new value
//		if (root == nullptr) {
//			root = n;
//			return;
//		}
//		Node* p = root; // creating a pointer on the root 
//
//		while (true) { // detecting where to add the value:
//			// p=50, other nodes [60, 70, 80] value= 72 then p will be = 60 
//			// p=60, other nodes [70, 80] value= 72 then p will be = 70 
//			// p=70, other nodes [80] value= 72 then search will stop here to add the 72. 
//
//			if (value > p->value) {
//			// if value > pointer value, move pointer to the next node
//				if (p->right == nullptr) break; 
//				// break after moving to the next node to re check from the begaining
//				p = p->right; 
//			}
//			else {
//				// if value <>> pointer value, move pointer to the prev node
//				if (p->left == nullptr) break;
//				// break after moving to the prev node to re check from the begaining
//				p = p->left;
//			}
//		}
//
//		// after finding the null we need to add the new value
//		if (value > p->value) {
//		// value = 72, p = 70 then p->right will be = 72
//			p->right = n;
//		}
//		else {
//			// value = 90, p = 70 then p->left will be = 90
//			p->left = n;
//		}
//	}
//
//
//	// pre : me >> left >> right 
//	void preDFS(Node* n) {
//	    if (n == nullptr) return;
//		cout << n->value << " -> ";
//		preDFS(n->left);
//		preDFS(n->right);
//	
//	}
//	
//	
//	// in : left >> me >> right  
//	void inDFS(Node* n) {
//	    if (n == nullptr) return;
//		inDFS(n->left);
//		cout << n->value << " -> ";
//		inDFS(n->right);
//	
//	}
//	
//	
//	
//	// post : left >> right >> me
//	void postDFS(Node* n) {
//	    if (n == nullptr) return;
//		postDFS(n->left);
//		postDFS(n->right);
//	    cout << n->value << " -> ";
//	
//	}
//
//	void print() {
//		cout << "PRE  : ";
//		preDFS(root);		
//		cout << "\nIN   : ";
//		inDFS(root);		
//		cout << "\nPOST : ";
//		postDFS(root);
//	}
//
//
//	void BFS(Node* aho) {
//		queue<Node*> q; // creating a queue
//		q.push(root);  // adding root to the queue
//
//		while (!q.empty()) // if the queue has nodes 
//		{
//		// first print the current root
//		cout << q.front()->value << " -> ";
//
//		// second push the right, left nodes if exist
//		if (q.front()->left != nullptr) {
//				q.push(q.front()->left);
//			}	
//
//		if (q.front()->right != nullptr) {
//				q.push(q.front()->right);
//			}
//		// third pop the current root and repeat until the queue is empty
//			q.pop();
//		}
//	}
//};
//
//void printSet(set<int> s) {
//	set<int> ::iterator it;
//	for (it = s.begin(); it != s.end(); it++) {
//		cout << *it << " -> ";
//	}
//	cout << "\n==========\n";
//}
//
//void printMap(map<int, string> m) {
//	map<int, string> ::iterator it;
//	for (it = m.begin(); it != m.end(); it++) {
//		cout << it->first << " : " << it->second << endl;
//	}
//	cout << "\n==========\n";
//}
//
//int main() {
//	set<int> t;
//
//	t.insert(10);
//	t.insert(40);
//	t.insert(70);
//	t.insert(20);
//
//	printSet(t);
//	
//	
//	map<int, string> m;
//	m.insert(pair<int, string>(1, "Ahmed"));
//	m.insert(pair<int, string>(2, "Medhat"));
//	m[3] = "Ibrahim";
//	m[4] = "Mahmoud";
//	m[3] = "Shehata";
//
//	printMap(m);
//
//}
#include "node.h"
#include <iostream>
#include <unordered_set>
#include <queue>

Node* cloneGraph(Node* node) {
  return nullptr;
}

void printList(Node* node) {
  
  std::unordered_set<int> printed_nodes;
  std::queue<Node*> to_print;
  if (node == nullptr) { return; }
  std::cout << "[";
  while (true) {
   std::cout << "node: " << node->val << " -> "; 
   for (const auto& neighbor: node->neighbors) {
    std::cout << neighbor->val << ",";
    if (printed_nodes.find(neighbor->val) == printed_nodes.end()) to_print.push(neighbor);
   }
   printed_nodes.insert(node->val);
   if (to_print.empty()) break;
   
   node = to_print.front();
   to_print.pop();
  }
  std::cout << "]\n";
}

int main() {
  std::vector<Node*> nodes;
  for (int i = 1; i <= 4; ++i) {
    nodes.emplace_back(new Node(i));
  }
  nodes[0]->neighbors.emplace_back(nodes[1]); nodes[0]->neighbors.emplace_back(nodes[3]);
  nodes[1]->neighbors.emplace_back(nodes[0]); nodes[1]->neighbors.emplace_back(nodes[2]);
  nodes[2]->neighbors.emplace_back(nodes[1]); nodes[2]->neighbors.emplace_back(nodes[3]);
  nodes[3]->neighbors.emplace_back(nodes[0]); nodes[3]->neighbors.emplace_back(nodes[2]);

  printList(nodes[0]);
  
  return 0;
}

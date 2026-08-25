#include "node.h"
#include <iostream>
#include <set>
#include <queue>
#include <map>

Node* cloneGraph(Node* node) {
  return nullptr;
}

void printList(Node* node) {
  
  std::map<int, Node*> to_print; 
  int count = 0;
  if (node == nullptr) { return; }

  to_print[node->val] = node;
  count = node->val;

  std::cout << "[";
  while (to_print.find(count) != to_print.end()) {

   node = to_print[count];
   std::cout << "[";
   size_t neighbor_cnt = 0;
   for (const auto& neighbor: node->neighbors) {
    std::cout << neighbor->val;
    if (neighbor_cnt < node->neighbors.size() - 1) std::cout << ",";
    if (to_print.find(neighbor->val) == to_print.end()) {
      to_print[neighbor->val] = neighbor;
    }
    neighbor_cnt++;
   }
   std::cout << "]";
   count++;
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

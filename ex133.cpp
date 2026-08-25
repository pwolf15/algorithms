#include "node.h"
#include <iostream>
#include <set>
#include <queue>
#include <map>

Node* cloneGraph(Node* node) {
  std::map<int, Node*> to_visit;
  std::map<int, Node*> new_graph;
  int count = 1;
  if (node == nullptr) { return nullptr; }
  
  to_visit[node->val] = node;

  while(to_visit.find(count) != to_visit.end()) {
    
    node = to_visit[count];
    new_graph[count] = new Node(count);

    for (const auto& neighbor: node->neighbors) {
      if (to_visit.find(neighbor->val) == to_visit.end()) {
        to_visit[neighbor->val] = neighbor;
      }
      new_graph[count]->neighbors.emplace_back(neighbor);
    }
    count++;
  }
  return new_graph[1];
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
  
  Node* copy = cloneGraph(nodes[0]);
  printList(copy);

  copy = cloneGraph(nullptr);
  printList(copy);

  Node* single = new Node(1);

  copy = cloneGraph(single);
  printList(copy);
  
  return 0;
}

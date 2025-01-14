#include <iostream>
#include "Graph.cpp"

int main() {
    // Create a graph where edges don't have weights
    Graph<std::string, double, false> g(1, "Graph without weights");

    Node<std::string> nodeA("A", 0);
    Node<std::string> nodeB("B", 1);
    Node<std::string> nodeC("C", 2);

    g.addNode("A");
    g.addNode("B");
    g.addNode("C");

    // Adding edges without weights
    g.addEdge(nodeA, nodeB, 1.0);  // No weight provided
    g.addEdge(nodeB, nodeC, 2.0);

    g.displayGraph();  // Will display without weights

    return 0;
}

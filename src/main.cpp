#include <iostream>
#include "Graph.cpp"

int main() {
    Graph<std::string, int> graph(1, "MyGraph");

    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");

    Node<std::string> nodeA("A", 0);
    Node<std::string> nodeB("B", 1);
    Node<std::string> nodeC("C", 2);
    Node<std::string> nodeD("D", 3);

    graph.addEdge(nodeA, nodeB, 10);
    graph.addEdge(nodeB, nodeC, 20);
    graph.addEdge(nodeC, nodeD, 30);

    graph.displayGraph();

    return 0;
}

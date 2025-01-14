// #include <iostream>
// #include "Graph.cpp"

// int main() {
//     // Create a graph where edges don't have weights
//     Graph<std::string, double, false> g(1, "Graph without weights");
//
//     Node<std::string> nodeA("A", 0);
//     Node<std::string> nodeB("B", 1);
//     Node<std::string> nodeC("C", 2);
//
//     g.addNode("A");
//     g.addNode("B");
//     g.addNode("C");
//
//     // Adding edges without weights
//     g.addEdge(nodeA, nodeB, 1.0);  // No weight provided
//     g.addEdge(nodeB, nodeC, 2.0);
//
//     g.displayGraph();  // Will display without weights
//
//     return 0;
// }


#include <iostream>
#include "Graph.cpp"
#include "GraphRepository.cpp"

int main() {
    // Step 1: Create a graph and add some nodes and edges
    Graph<int, std::string> graph(1, "Test Graph");
    graph.addNode(1);  // Node 1
    graph.addNode(2);  // Node 2
    graph.addNode(3);  // Node 3

    // Add edges between nodes
    Node<int>* node1 = graph.getNodeById(1);
    Node<int>* node2 = graph.getNodeById(2);
    Node<int>* node3 = graph.getNodeById(3);

    if (node1 && node2) {
        graph.addEdge(*node1, *node2, "Edge 1-2");
    }
    if (node2 && node3) {
        graph.addEdge(*node2, *node3, "Edge 2-3");
    }

    // Step 2: Serialize the graph to a file
    GraphRepository<int, std::string> repository;
    const std::string filename = "graph_data.txt";
    repository.serialize(graph, filename);

    // Step 3: Deserialize the graph from the file
    Graph<int, std::string> loadedGraph = repository.deserialize(filename);

    // Step 4: Display the loaded graph to verify deserialization
    loadedGraph.displayGraph();

    return 0;
}

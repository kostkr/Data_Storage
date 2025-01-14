#include "Edge.cpp"
#include <vector>
#include <iostream>
#include <string>

template <typename TNode, typename TEdge>
class Graph {
    const int id;  // Unique id
    std::string name;
    std::vector<Node<TNode>> nodes;
    std::vector<Edge<TNode, TEdge>> edges;

    static int currentNodeId;
    static int currentEdgeId;

public:
    explicit Graph(const int graphId, const std::string& graphName = "default name")
        : id(graphId), name(graphName) {
        std::cout << "Graph '" << this->name << "' (ID: " << this->id << ") created.\n";
    }

    int getId() const {
        return this->id;
    }

    std::string getName() const {
        return this->name;
    }

    void setName(const std::string& newName) {
        this->name = newName;
        std::cout << "Graph name changed to: " << this->name << "\n";
    }

    void addNode(const TNode& data) {
        int nodeId = currentNodeId++;
        Node<TNode> node(data, nodeId);
        nodes.push_back(node);
        std::cout << "Node added: " << node.getData() << " with ID: " << node.getId() << "\n";
    }

    void addEdge(const Node<TNode>& source, const Node<TNode>& destination, const TEdge& metadata) {
        int edgeId = currentEdgeId++;
        Edge<TNode, TEdge> edge(source, destination, metadata, edgeId);
        edges.push_back(edge);
        std::cout << "Edge added: " << edge.getSource().getData() << " -> "
                  << edge.getDestination().getData() << " with ID: " << edge.getId() << "\n";
    }

    void displayGraph() const {
        std::cout << "Graph (ID: " << this->id << ", Name: " << this->name << "):\n";
        for (const auto& node : this->nodes) {
            std::cout << "Node: " << node.getData() << " ID: " << node.getId() << "\n";
        }
        for (const auto& edge : this->edges) {
            std::cout << "Edge: " << edge.getSource().getData() << " -> "
                      << edge.getDestination().getData() << " [" << edge.getMetadata() << "] ID: "
                      << edge.getId() << "\n";
        }
    }
};

template <typename TNode, typename TEdge>
int Graph<TNode, TEdge>::currentNodeId = 0;

template <typename TNode, typename TEdge>
int Graph<TNode, TEdge>::currentEdgeId = 0;

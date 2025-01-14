#include <iostream>
#include <vector>
#include <string>
#include "Edge.cpp"

template <typename TNode, typename TEdge, bool HasWeight = false>
class Graph {
    int id;  // Unique id
    std::string name;
    std::vector<Node<TNode>> nodes;
    std::vector<Edge<TNode, TEdge, HasWeight>> edges;

    static int currentNodeId;
    static int currentEdgeId;

public:
    explicit Graph(int graphId, const std::string& graphName = "default name")
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

    // Add edge with or without weight based on HasWeight
    void addEdge(const Node<TNode>& source, const Node<TNode>& destination, const TEdge& metadata, double weight = 0.0) {
        int edgeId = currentEdgeId++;

        // If HasWeight is true, pass weight to the Edge constructor
        if constexpr (HasWeight) {
            Edge<TNode, TEdge, true> edge(source, destination, metadata, edgeId, weight);
            edges.push_back(edge);
            std::cout << "Edge added: " << edge.getSource().getData() << " -> "
                      << edge.getDestination().getData() << " with metadata: " << edge.getMetadata()
                      << " and weight: " << edge.getWeight() << "\n";
        } else {
            // If HasWeight is false, do not use the weight
            Edge<TNode, TEdge, false> edge(source, destination, metadata, edgeId);
            edges.push_back(edge);
            std::cout << "Edge added: " << edge.getSource().getData() << " -> "
                      << edge.getDestination().getData() << " with metadata: " << edge.getMetadata() << "\n";
        }
    }

    void removeNode(int nodeId) {
        removeEdgesByNodeId(nodeId);

        auto it = std::remove_if(nodes.begin(), nodes.end(), [nodeId](const Node<TNode>& node) {
            return node.getId() == nodeId;
        });
        if (it != nodes.end()) {
            nodes.erase(it, nodes.end());
            std::cout << "Node with ID: " << nodeId << " removed.\n";
        } else {
            std::cout << "Node with ID: " << nodeId << " not found.\n";
        }
    }

    void removeEdgesByNodeId(int nodeId) {
        edges.erase(std::remove_if(edges.begin(), edges.end(), [nodeId](const Edge<TNode, TEdge, HasWeight>& edge) {
            return edge.getSource().getId() == nodeId || edge.getDestination().getId() == nodeId;
        }), edges.end());
        std::cout << "Edges connected to node with ID: " << nodeId << " removed.\n";
    }

    void displayGraph() const {
        std::cout << "Graph (ID: " << this->id << ", Name: " << this->name << "):\n";
        for (const auto& node : this->nodes) {
            std::cout << "Node: " << node.getData() << " ID: " << node.getId() << "\n";
        }
        for (const auto& edge : this->edges) {
            edge.displayEdge();  // Use the display method of Edge class
        }
    }
};

template <typename TNode, typename TEdge, bool HasWeight>
int Graph<TNode, TEdge, HasWeight>::currentNodeId = 0;

template <typename TNode, typename TEdge, bool HasWeight>
int Graph<TNode, TEdge, HasWeight>::currentEdgeId = 0;

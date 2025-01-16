#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Edge.cpp"

template <typename TNode, typename TEdge, bool HasWeight = false>
class Graph {
    int id;  // Unique id
    std::string name;
    std::vector<Node<TNode>> nodes;
    std::vector<Edge<TNode, TEdge, HasWeight>> edges;

    int currentNodeId;
    int currentEdgeId;

public:
    explicit Graph(int graphId, const std::string& graphName = "default name", int currentNodeId = 0, int currentEdgeId = 0)
        : id(graphId), name(graphName), currentNodeId(currentNodeId), currentEdgeId(currentEdgeId) {
        std::cout << "Graph '" << this->name << "' (ID: " << this->id << ") created.\n";
    }

    int getId() const {
        return this->id;
    }

    void setId(int newId) {
        this->id = newId;
    }

    std::string getName() const {
        return this->name;
    }

    const std::vector<Edge<TNode, TEdge, HasWeight>>& getEdges() const {
        return edges;
    }

    const std::vector<Node<TNode>>& getNodes() const {
        return nodes;
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

    void addEdge(const Node<TNode>& source, const Node<TNode>& destination, const TEdge& metadata, double weight = 0.0) {
        int edgeId = currentEdgeId++;

        if constexpr (HasWeight) {
            Edge<TNode, TEdge, true> edge(source, destination, metadata, edgeId, weight);
            edges.push_back(edge);
            std::cout << "Edge added: " << edge.getSource().getData() << " -> "
                      << edge.getDestination().getData() << " with metadata: " << edge.getMetadata()
                      << " and weight: " << edge.getWeight() << "\n";
        } else {
            Edge<TNode, TEdge, false> edge(source, destination, metadata, edgeId);
            edges.push_back(edge);
            std::cout << "Edge added: " << edge.getSource().getData() << " -> "
                      << edge.getDestination().getData() << " with metadata: " << edge.getMetadata() << "\n";
        }
    }

    void addEdgeByNodeId(int sourceNodeId, int targetNodeId, const std::string metadata, double weight = 0.0) {
        Node<TNode>* sourceNode = getNodeById(sourceNodeId);
        Node<TNode>* targetNode = getNodeById(targetNodeId);

        if (sourceNode && targetNode) {
            addEdge(*sourceNode, *targetNode, metadata, weight);
        } else {
            std::cout << "Can't find node by id.\n";
        }
    }

    void removeNode(int nodeId) {
        auto it = std::remove_if(nodes.begin(), nodes.end(), [nodeId](const Node<TNode>& node) {
            return node.getId() == nodeId;
        });
        if (it != nodes.end()) {
            removeEdgesByNodeId(nodeId);
            nodes.erase(it, nodes.end());
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

    void removeEdgeByNodeIds(int sourceId, int targetId) {
        edges.erase(std::remove_if(edges.begin(), edges.end(), [sourceId, targetId](const Edge<TNode, TEdge, HasWeight>& edge) {
            return (edge.getSource().getId() == sourceId && edge.getDestination().getId() == targetId) ||
                   (edge.getSource().getId() == targetId && edge.getDestination().getId() == sourceId);
        }), edges.end());

        std::cout << "Edge(s) between nodes with IDs " << sourceId << " and " << targetId << " removed.\n";
    }


    Node<TNode>* getNodeById(int nodeId) {
        for (auto& node : nodes) {
            if (node.getId() == nodeId) {
                return &node;
            }
        }
        std::cout << "Node with ID: " << nodeId << " not found.\n";
        return nullptr;
    }

    void displayGraph() const {
        std::cout << "Graph (ID: " << this->id << ", Name: " << this->name << "):\n";
        for (const auto& node : this->nodes) {
            node.displayNode();
        }
        for (const auto& edge : this->edges) {
            edge.displayEdge();
        }
    }
};

#include <iostream>
#include <map>
#include <string>
#include "Graph.cpp"

template <typename TNode, typename TEdge>
concept ValidGraph = requires {
    typename Graph<TNode, TEdge>; // Ensure Graph<TNode, TEdge> exists
    { Graph<TNode, TEdge>::addNode(std::declval<TNode>()) } -> std::same_as<void>;
    { Graph<TNode, TEdge>::addEdge(std::declval<Node<TNode>>(), std::declval<Node<TNode>>(), std::declval<TEdge>()) } -> std::same_as<void>;
    { std::declval<Graph<TNode, TEdge>>().removeNode(std::declval<int>()) } -> std::same_as<void>;
    { std::declval<Graph<TNode, TEdge>>().removeEdge(std::declval<int>()) } -> std::same_as<void>;
};

class GraphManager {
    std::map<std::string, std::shared_ptr<Graph<std::string, double> > > graphs;
    std::shared_ptr<Graph<std::string, double> > currentGraph;
    int nextGraphId = 0;  // Unique ID for each graph

public:
    // Create a graph with a unique ID
    void createGraph(const std::string& graphName) {
        auto newGraph = std::make_shared<Graph<std::string, double> >(nextGraphId++, graphName);
        graphs[graphName] = newGraph;
        std::cout << "Graph '" << graphName << "' created with ID: " << newGraph->getId() << "\n";
    }

    // Delete a graph by name
    void deleteGraph(const std::string& graphName) {
        auto it = graphs.find(graphName);
        if (it != graphs.end()) {
            graphs.erase(it);
            std::cout << "Graph '" << graphName << "' deleted.\n";
        } else {
            std::cout << "Graph '" << graphName << "' not found.\n";
        }
    }

    // Switch to another graph by name
    void switchGraph(const std::string& graphName) {
        auto it = graphs.find(graphName);
        if (it != graphs.end()) {
            currentGraph = it->second;
            std::cout << "Switched to graph '" << graphName << "'\n";
        } else {
            std::cout << "Graph '" << graphName << "' not found.\n";
        }
    }

    // Get the current graph
    std::shared_ptr<Graph<std::string, double>> getCurrentGraph() const {
        return currentGraph;
    }

    // Display all graphs
    void displayGraphs() const {
        if (graphs.empty()) {
            std::cout << "No graphs available.\n";
        } else {
            std::cout << "Available graphs:\n";
            for (const auto& pair : graphs) {
                std::cout << "- " << pair.first << " (ID: " << pair.second->getId() << ")\n";
            }
        }
    }
};

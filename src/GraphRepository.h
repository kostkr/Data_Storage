#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Graph.cpp"

template <typename TNode=std::string, typename TEdge=std::string>
class GraphRepository {

public:
    void serialize(const Graph<TNode, TEdge>& graph, const std::string& filename) {
        std::ofstream outFile(filename, std::ios::out);
        if (outFile.is_open()) {
            outFile << graph.getId() << "\n";
            outFile << graph.getName() << "\n";
            const auto& nodes = graph.getNodes();
            outFile << nodes.size() << "\n";
            for (const auto& node : nodes) {
                outFile << node.getId() << " " << node.getData() << "\n";
            }

            const auto& edges = graph.getEdges();
            outFile << edges.size() << "\n";
            for (const auto& edge : edges) {
                outFile << edge.getSource().getId() << " "
                        << edge.getDestination().getId() << " "
                        << edge.getMetadata() << " ";
                if (edge.hasWeight()) {
                    outFile << edge.getWeight() << "\n";
                } else {
                    outFile << "\n";
                }
            }

            std::cout << "Graph serialized to " << filename << "\n";
        } else {
            std::cerr << "Failed to open file for serialization.\n";
        }
    }
};

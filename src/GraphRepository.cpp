#include <fstream>
#include <iostream>
#include <string>
#include "Graph.cpp"

template <typename TNode, typename TEdge>
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

    Graph<TNode, TEdge> deserialize(const std::string& filename) {
        std::ifstream inFile(filename, std::ios::in);
        Graph<TNode, TEdge> graph(0, "");

        if (inFile.is_open()) {
            int graphId;
            std::string graphName;

            inFile >> graphId;
            inFile.ignore();
            std::getline(inFile, graphName);

            graph.setId(graphId);
            graph.setName(graphName);

            size_t nodeCount;
            inFile >> nodeCount;
            inFile.ignore();

            for (size_t i = 0; i < nodeCount; ++i) {
                int nodeId;
                TNode nodeData;
                inFile >> nodeId >> nodeData;
                inFile.ignore();

                graph.addNode(nodeData);
            }

            size_t edgeCount;
            inFile >> edgeCount;
            inFile.ignore();

            for (size_t i = 0; i < edgeCount; ++i) {
                int sourceId, destId;
                TEdge metadata;
                double weight = 0.0;

                inFile >> sourceId >> destId >> metadata;
                if (inFile.peek() != '\n') {
                    inFile >> weight;
                }

                Node<TNode> source = graph.getNodeById(sourceId);
                Node<TNode> destination = graph.getNodeById(destId);
                graph.addEdge(source, destination, metadata, weight);
            }

            std::cout << "Graph deserialized from " << filename << "\n";
        } else {
            std::cerr << "Failed to open file for deserialization.\n";
        }

        return graph;
    }
};

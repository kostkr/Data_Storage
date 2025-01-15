#include "GraphManager.h"
#include <iostream>
#include <stdexcept>
#include "Command.h"

template <typename TEdge>
class AddEdgeCommand : public Command {
    GraphManager& graphManager;
    int sourceId;
    int targetId;
    TEdge metadata;
    double weight;

public:
    AddEdgeCommand(GraphManager& manager,
                   int source,
                   int target,
                   const TEdge& meta,
                   double edgeWeight = 0.0)
        : graphManager(manager), sourceId(source), targetId(target), metadata(meta), weight(edgeWeight) {}

    void execute() noexcept override {
        auto currentGraph = graphManager.getCurrentGraph();
        if (currentGraph) {
            try {
                currentGraph->addEdgeByNodeId(sourceId, targetId, metadata, weight);
                std::cout << "Edge added between nodes with IDs " << sourceId << " and " << targetId
                          << " with metadata: \"" << metadata << "\" and weight: " << weight << ".\n";
            } catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "No current graph available to add the edge.\n";
        }
    }
};

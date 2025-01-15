#include "GraphManager.h"
#include <iostream>
#include <stdexcept>
#include "Command.h"

class RemoveEdgeCommand : public Command {
    GraphManager& graphManager;
    int sourceId;
    int targetId;

public:
    RemoveEdgeCommand(GraphManager& manager, int source, int target)
        : graphManager(manager), sourceId(source), targetId(target) {}

    void execute() noexcept override {
        auto currentGraph = graphManager.getCurrentGraph();
        if (currentGraph) {
            try {
                currentGraph->removeEdgeByNodeIds(sourceId, targetId);
            } catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "No current graph available to delete the edge.\n";
        }
    }
};

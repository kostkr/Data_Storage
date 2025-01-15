#include "GraphManager.h"
#include <iostream>
#include <stdexcept>
#include "Command.h"

class RemoveNodeCommand : public Command {
    GraphManager& graphManager;
    int nodeId;

public:
    RemoveNodeCommand(GraphManager& manager, int node)
        : graphManager(manager), nodeId(node) {}

    void execute() noexcept override {
        auto currentGraph = graphManager.getCurrentGraph();
        if (currentGraph) {
            try {
                currentGraph->removeNode(nodeId);
            } catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "No current graph available to delete the node.\n";
        }
    }
};

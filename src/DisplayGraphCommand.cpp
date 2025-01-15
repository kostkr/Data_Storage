#include "GraphManager.h"
#include <iostream>
#include "Command.h"

class DisplayGraphCommand : public Command {
    GraphManager& graphManager;

public:
    DisplayGraphCommand(GraphManager& manager) : graphManager(manager) {}

    void execute() noexcept override {
        auto currentGraph = graphManager.getCurrentGraph();
        if (currentGraph) {
            currentGraph->displayGraph();
        } else {
            std::cout << "No current graph available to display.\n";
        }
    }
};

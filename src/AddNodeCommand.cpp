#include "Command.h"
#include "GraphManager.h"

class AddNodeCommand : public Command {
    GraphManager& graphManager;
    std::string nodeData;
    int id;

public:
    AddNodeCommand(GraphManager& manager, std::string& data)
        : graphManager(manager), nodeData(data) {}

    void execute() noexcept override {
        auto currentGraph = graphManager.getCurrentGraph();
        if (currentGraph) {
            currentGraph->addNode(nodeData);
            std::cout << "Node with data '" << nodeData << "' added to the graph." << std::endl;
        } else {
            std::cout << "No current graph available to add the node." << std::endl;
        }
    }
};

#include "Command.h"
#include "GraphManager.h"

class InitGraphCommand : public Command {
    GraphManager& graphManager;
    std::string graphName;

public:
    InitGraphCommand(GraphManager& manager, const std::string& name)
        : graphManager(manager), graphName(name) {}

    void execute() noexcept override {
        graphManager.createGraph(graphName);

        graphManager.switchGraph(graphName);

        auto currentGraph = graphManager.getCurrentGraph();

        currentGraph->displayGraph();
    }
};

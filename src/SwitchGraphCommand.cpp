#include "Command.h"
#include "GraphManager.h"

class SwitchGraphCommand : public Command {
    GraphManager& graphManager;
    std::string graphName;

public:
    SwitchGraphCommand(GraphManager& manager, const std::string& name)
        : graphManager(manager), graphName(name) {}

    void execute() noexcept override {
        graphManager.switchGraph(graphName);
    }
};

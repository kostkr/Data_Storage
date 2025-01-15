#include "Command.h"
#include "GraphManager.h"

class DeleteGraphCommand : public Command {
    GraphManager& graphManager;
    std::string graphName;

public:
    DeleteGraphCommand(GraphManager& manager, const std::string& name)
        : graphManager(manager), graphName(name) {}

    void execute() noexcept override {
        graphManager.deleteGraph(graphName);
    }
};

#pragma once
#include "Command.h"
#include "GraphManager.h"

class CreateGraphCommand : public Command {
    GraphManager& graphManager;
    std::string graphName;

public:
    CreateGraphCommand(GraphManager& manager, const std::string& name)
        : graphManager(manager), graphName(name) {}

    void execute() noexcept override {
        graphManager.createGraph(graphName);
    }
};

#pragma once
#include "Command.h"
#include "GraphManager.h"

class DisplayGraphsCommand : public Command {
    GraphManager& graphManager;

public:
    DisplayGraphsCommand(GraphManager& manager)
        : graphManager(manager) {}

    void execute() noexcept override {
        graphManager.displayGraphs();
    }
};

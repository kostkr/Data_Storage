#pragma once
#include "GraphManager.h"
#include "CommandManager.h"
#include "CreateGraphCommand.cpp"
#include "DeleteGraphCommand.cpp"
#include "SwitchGraphCommand.cpp"
#include "DisplayGraphsCommand.cpp"
#include "InitGraphCommand.cpp"
#include "AddNodeCommand.cpp"

class CLI {
    GraphManager& graphManager;
    CommandManager& commandManager;

public:
    CLI(GraphManager& manager, CommandManager& cmdManager)
        : graphManager(manager), commandManager(cmdManager) {}

    void run() {
        commandManager.registerCommand("create_graph", [this]() {
            std::string graphName;
            std::cout << "Enter graph name: ";
            std::cin >> graphName;
            return new CreateGraphCommand(graphManager, graphName);
        });
        commandManager.registerCommand("delete_graph", [this]() {
            std::string graphName;
            std::cout << "Enter graph name: ";
            std::cin >> graphName;
            return new DeleteGraphCommand(graphManager, graphName);
        });
        commandManager.registerCommand("switch_graph", [this]() {
            std::string graphName;
            std::cout << "Enter graph name: ";
            std::cin >> graphName;
            return new SwitchGraphCommand(graphManager, graphName);
        });
        commandManager.registerCommand("display_graphs", [this]() {
            return new DisplayGraphsCommand(graphManager);
        });
        commandManager.registerCommand("init_graph", [this]() {
            std::string graphName;
            std::cout << "Enter graph name: ";
            std::cin >> graphName;
            return new InitGraphCommand(graphManager, graphName);
        });
        commandManager.registerCommand("add_node", [this]() {
            std::string text;
            std::cout << "Enter data: ";
            std::cin.ignore();
            std::getline(std::cin, text);
            return new AddNodeCommand(graphManager, text);
        });

        std::string command;
        while (true) {
            std::cout << "\nEnter command: ";
            std::cin >> command;

            if (command == "exit") {
                break;
            }

            commandManager.executeCommand(command);
        }
    }
};

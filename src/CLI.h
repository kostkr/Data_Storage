#pragma once
#include "GraphManager.h"
#include "CommandManager.h"
#include "CreateGraphCommand.cpp"
#include "DeleteGraphCommand.cpp"
#include "SwitchGraphCommand.cpp"
#include "DisplayGraphsCommand.cpp"
#include "InitGraphCommand.cpp"
#include "AddNodeCommand.cpp"
#include "AddEdgeCommand.cpp"
#include "DisplayGraphCommand.cpp"
#include "RemoveNodeCommand.cpp"
#include "RemoveEdgeCommand.cpp"

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

        commandManager.registerCommand("add_edge", [this]() {
            int sourceId, targetId;
            std::string metadata;
            double weight = 0.0;

            std::cout << "Enter source node ID: ";
            std::cin >> sourceId;
            std::cout << "Enter target node ID: ";
            std::cin >> targetId;
            std::cin.ignore();
            std::cout << "Enter edge metadata: ";
            std::getline(std::cin, metadata);
            std::cout << "Enter edge weight (default 0): ";
            while (true) {
                std::string weightInput;
                std::getline(std::cin, weightInput);

                if (weightInput.empty()) {
                    break;
                }

                try {
                    weight = std::stod(weightInput);
                    break;
                } catch (const std::invalid_argument&) {
                    std::cout << "Invalid input. Please enter a valid number for the edge weight: ";
                } catch (const std::out_of_range&) {
                    std::cout << "Number out of range. Please enter a valid number: ";
                }
            }

            return new AddEdgeCommand<std::string>(graphManager, sourceId, targetId, metadata, weight);
        });

        commandManager.registerCommand("display_graph", [this]() {
            return new  DisplayGraphCommand(graphManager);
        });

        commandManager.registerCommand("remove_node", [this]() {
            int nodeId;
            std::cout << "Enter node ID to remove: ";
            std::cin >> nodeId;
            return new RemoveNodeCommand(graphManager, nodeId);
        });

        commandManager.registerCommand("remove_edge", [this]() {
            int sourceId, targetId;

            std::cout << "Enter source node ID: ";
            std::cin >> sourceId;
            std::cout << "Enter target node ID: ";
            std::cin >> targetId;
            return new RemoveEdgeCommand(graphManager, sourceId, targetId);
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

#include "GraphRepository.h"
#include "GraphManager.h"
#include <iostream>
#include <stdexcept>
#include "Command.h"

template <typename TNode, typename TEdge>
class SerializeGraphCommand : public Command {
    GraphManager& graphManager;
    GraphRepository<TNode, TEdge>& repository;
    std::string filename;

public:
    SerializeGraphCommand(GraphManager& manager,
                          GraphRepository<TNode, TEdge>& repo,
                          const std::string& file)
        : graphManager(manager), repository(repo), filename(file) {}

    void execute() noexcept override {
        auto currentGraph = graphManager.getCurrentGraph();
        if (currentGraph) {
            try {
                repository.serialize(*currentGraph, filename);
                std::cout << "Graph serialized to file: " << filename << "\n";
            } catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "No current graph available to serialize.\n";
        }
    }
};

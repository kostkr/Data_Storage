#include "GraphManager.h"
#include "CommandManager.h"
#include "GraphRepository.h"
#include "CLI.h"

int main() {
    GraphManager graphManager;
    CommandManager commandManager;
    GraphRepository<std::string, std::string> graph_repository;
    CLI cli(graphManager, commandManager, graph_repository);

    cli.run();

    return 0;
}

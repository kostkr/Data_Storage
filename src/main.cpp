#include "GraphManager.h"
#include "CommandManager.h"
#include "CLI.h"

int main() {
    GraphManager graphManager;
    CommandManager commandManager;
    CLI cli(graphManager, commandManager);

    cli.run();

    return 0;
}

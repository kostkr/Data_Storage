#pragma once
#include <map>
#include <functional>
#include <string>
#include <iostream>
#include "Command.h"

class CommandManager {
    std::map<std::string, std::function<Command*()>> commandMap;

public:
    void registerCommand(const std::string& name, std::function<Command*()> command) {
        commandMap[name] = command;
    }

    void executeCommand(const std::string& commandName) {
        if (commandMap.find(commandName) != commandMap.end()) {
            Command* command = commandMap[commandName]();
            command->execute();
            delete command;
        } else {
            std::cout << "Unknown command: " << commandName << std::endl;
        }
    }
};

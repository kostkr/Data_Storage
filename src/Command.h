#pragma once

class Command {
public:
    virtual void execute() noexcept = 0;
    virtual ~Command() = default;
};

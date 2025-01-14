#include "iostream"

template <typename T>
class Node {
    int id;
    T data;

public:
    Node(const T& data, int id) : id(id), data(data) {}

    T getData() const {
        return data;
    }

    int getId() const {
        return id;
    }

    void setData(const T& newData) {
        data = newData;
    }

    bool operator==(const Node& other) const {
        return id == other.id;
    }

    void displayNode() const {
        std::cout << "Node ID: " << id << "  " << data << "\n";
    }
};

#include "Node.cpp"

template <typename TNode, typename TEdge>
class Edge {
    const int id;
    Node<TNode> source;
    Node<TNode> destination;
    TEdge metadata;

public:
    Edge(const Node<TNode>& source, const Node<TNode>& destination, const TEdge& metadata, const int id)
        : id(id), source(source), destination(destination), metadata(metadata) {}

    Node<TNode> getSource() const {
        return source;
    }

    Node<TNode> getDestination() const {
        return destination;
    }

    TEdge getMetadata() const {
        return metadata;
    }

    int getId() const {
        return id;
    }

    bool operator==(const Edge& other) const {
        return id == other.id;
    }
};

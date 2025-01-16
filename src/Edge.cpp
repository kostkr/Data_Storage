#pragma once
#include <iostream>
#include "Node.h"

template <typename TNode, typename TEdge, bool HasWeight = false>
class Edge {
    int id;
    Node<TNode> source;
    Node<TNode> destination;
    TEdge metadata;
    double weight;

public:
    // Constructor without weight (for edges that don't have weight)
    Edge(const Node<TNode>& source, const Node<TNode>& destination, const TEdge& metadata, int id)
        : id(id), source(source), destination(destination), metadata(metadata), weight() {
        static_assert(!HasWeight, "Edge with weight requires a weight parameter.");
    }

    // Constructor with weight (for edges that have weight)
    Edge(const Node<TNode>& source, const Node<TNode>& destination, const TEdge& metadata, int id, double weight)
        : id(id), source(source), destination(destination), metadata(metadata), weight(weight) {
        static_assert(HasWeight, "Edge without weight should not have weight constructor.");
    }

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

    bool hasWeight() const {
        return HasWeight;
    }

    // Only available if HasWeight is true
    double getWeight() const {
        return HasWeight ? weight : 0.0;
    }

    bool operator==(const Edge& other) const {
        return id == other.id;
    }

    void displayEdge() const {
        std::cout << "Edge ID: " << id << " from Node " << source.getData() << " to Node "
                  << destination.getData() << " with metadata: " << metadata;
        if constexpr (HasWeight) {
            std::cout << " and weight: " << weight;
        }
        std::cout << std::endl;
    }
};

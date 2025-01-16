#include <gtest/gtest.h>
#include "Node.h"
#include "Edge.cpp"
#include "Graph.cpp"

TEST(GraphTest, CreateGraph) {
    Graph<std::string, std::string, false> graph(1, "Test Graph");

    EXPECT_EQ(graph.getId(), 1);
    EXPECT_EQ(graph.getName(), "Test Graph");
    EXPECT_TRUE(graph.getNodes().empty());
    EXPECT_TRUE(graph.getEdges().empty());
}

TEST(GraphTest, AddNode) {
    Graph<std::string, std::string, false> graph(1, "Test Graph");

    graph.addNode("Node 1");

    EXPECT_EQ(graph.getNodes().size(), 1);
    EXPECT_EQ(graph.getNodes()[0].getData(), "Node 1");
    EXPECT_EQ(graph.getNodes()[0].getId(), 0);
}

TEST(GraphTest, AddEdgeWithoutWeight) {
    Graph<std::string, std::string, false> graph(1, "Test Graph");

    graph.addNode("Node 1");
    graph.addNode("Node 2");

    Node<std::string> node1 = graph.getNodes()[0];
    Node<std::string> node2 = graph.getNodes()[1];

    graph.addEdge(node1, node2, "Edge Metadata");

    EXPECT_EQ(graph.getEdges().size(), 1);
    EXPECT_EQ(graph.getEdges()[0].getMetadata(), "Edge Metadata");
    EXPECT_EQ(graph.getEdges()[0].getSource().getData(), "Node 1");
    EXPECT_EQ(graph.getEdges()[0].getDestination().getData(), "Node 2");
    EXPECT_FALSE(graph.getEdges()[0].hasWeight());
}

TEST(GraphTest, AddEdgeWithWeight) {
    Graph<std::string, std::string, true> graph(1, "Test Graph");

    graph.addNode("Node 1");
    graph.addNode("Node 2");

    Node<std::string> node1 = graph.getNodes()[0];
    Node<std::string> node2 = graph.getNodes()[1];

    graph.addEdge(node1, node2, "Edge Metadata", 10.0);

    EXPECT_EQ(graph.getEdges().size(), 1);
    EXPECT_EQ(graph.getEdges()[0].getMetadata(), "Edge Metadata");
    EXPECT_EQ(graph.getEdges()[0].getSource().getData(), "Node 1");
    EXPECT_EQ(graph.getEdges()[0].getDestination().getData(), "Node 2");
    EXPECT_TRUE(graph.getEdges()[0].hasWeight());
    EXPECT_EQ(graph.getEdges()[0].getWeight(), 10.0);
}

TEST(GraphTest, RemoveEdgeByNodeIds) {
    Graph<std::string, std::string, false> graph(1, "Test Graph");

    graph.addNode("Node 1");
    graph.addNode("Node 2");
    graph.addNode("Node 3");

    Node<std::string> node1 = graph.getNodes()[0];
    Node<std::string> node2 = graph.getNodes()[1];
    Node<std::string> node3 = graph.getNodes()[2];

    graph.addEdge(node1, node2, "Edge 1");
    graph.addEdge(node2, node3, "Edge 2");

    graph.removeEdgeByNodeIds(0, 1);

    EXPECT_EQ(graph.getEdges().size(), 1);
}

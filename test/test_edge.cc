#include <gtest/gtest.h>
#include "Node.h"
#include "Edge.cpp"

TEST(EdgeTest, CreateEdgeWithoutWeight) {
    Node<std::string> node1("Node 1", 1);
    Node<std::string> node2("Node 2", 2);
    std::string metadata = "Edge metadata";
    Edge<std::string, std::string, false> edge(node1, node2, metadata, 100);

    EXPECT_EQ(edge.getId(), 100);
    EXPECT_EQ(edge.getSource().getData(), "Node 1");
    EXPECT_EQ(edge.getDestination().getData(), "Node 2");
    EXPECT_EQ(edge.getMetadata(), "Edge metadata");
    EXPECT_FALSE(edge.hasWeight());
    EXPECT_EQ(edge.getWeight(), 0.0);
}

TEST(EdgeTest, CreateEdgeWithWeight) {
    Node<std::string> node1("Node 1", 1);
    Node<std::string> node2("Node 2", 2);
    std::string metadata = "Edge metadata";
    Edge<std::string, std::string, true> edge(node1, node2, metadata, 100, 5.0);

    EXPECT_EQ(edge.getId(), 100);
    EXPECT_EQ(edge.getSource().getData(), "Node 1");
    EXPECT_EQ(edge.getDestination().getData(), "Node 2");
    EXPECT_EQ(edge.getMetadata(), "Edge metadata");
    EXPECT_TRUE(edge.hasWeight());
    EXPECT_EQ(edge.getWeight(), 5.0);
}

TEST(EdgeTest, EdgeEquality) {
    Node<std::string> node1("Node 1", 1);
    Node<std::string> node2("Node 2", 2);
    std::string metadata = "Edge metadata";
    Edge<std::string, std::string, false> edge1(node1, node2, metadata, 100);
    Edge<std::string, std::string, false> edge2(node1, node2, metadata, 100);

    EXPECT_TRUE(edge1 == edge2);
}

TEST(EdgeTest, EdgeWithDifferentIdShouldNotBeEqual) {
    Node<std::string> node1("Node 1", 1);
    Node<std::string> node2("Node 2", 2);
    std::string metadata = "Edge metadata";
    Edge<std::string, std::string, false> edge1(node1, node2, metadata, 100);
    Edge<std::string, std::string, false> edge2(node1, node2, metadata, 101);

    EXPECT_FALSE(edge1 == edge2);
}

TEST(EdgeTest, DisplayEdgeWithoutWeight) {
    Node<std::string> node1("Node 1", 1);
    Node<std::string> node2("Node 2", 2);
    std::string metadata = "Edge metadata";
    Edge<std::string, std::string, false> edge(node1, node2, metadata, 100);

    testing::internal::CaptureStdout();
    edge.displayEdge();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Edge ID: 100 from Node Node 1 to Node Node 2 with metadata: Edge metadata"), std::string::npos);
    EXPECT_EQ(output.find("and weight:"), std::string::npos);
}

TEST(EdgeTest, DisplayEdgeWithWeight) {
    Node<std::string> node1("Node 1", 1);
    Node<std::string> node2("Node 2", 2);
    std::string metadata = "Edge metadata";
    Edge<std::string, std::string, true> edge(node1, node2, metadata, 100, 5.0);

    testing::internal::CaptureStdout();
    edge.displayEdge();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Edge ID: 100 from Node Node 1 to Node Node 2 with metadata: Edge metadata"), std::string::npos);
    EXPECT_NE(output.find("and weight: 5"), std::string::npos);
}

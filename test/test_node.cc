#include <gtest/gtest.h>
#include "Node.h"

TEST(NodeTest, ConstructorTest) {
    Node<int> node(10, 1);

    EXPECT_EQ(node.getData(), 10);
    EXPECT_EQ(node.getId(), 1);
}

TEST(NodeTest, SetDataTest) {
    Node<int> node(10, 1);
    node.setData(20);

    EXPECT_EQ(node.getData(), 20);
}

TEST(NodeTest, EqualityOperatorTest) {
    Node<int> node1(10, 1);
    Node<int> node2(20, 2);
    Node<int> node3(10, 1);

    EXPECT_FALSE(node1 == node2);
    EXPECT_TRUE(node1 == node3);
}

TEST(NodeTest, DisplayNodeTest) {
    testing::internal::CaptureStdout();
    Node<int> node(10, 1);
    node.displayNode();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Node ID: 1  10\n");
}

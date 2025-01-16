#include <gtest/gtest.h>
#include "GraphManager.h"

TEST(GraphManagerTest, DeleteGraph) {
    GraphManager manager;
    manager.createGraph("Graph 1");
    manager.deleteGraph("Graph 1");

    testing::internal::CaptureStdout();
    manager.displayGraphs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("No graphs available."), std::string::npos);
}

TEST(GraphManagerTest, SwitchGraph) {
    GraphManager manager;
    manager.createGraph("Graph 1");
    manager.createGraph("Graph 2");

    manager.switchGraph("Graph 2");
    auto graph = manager.getCurrentGraph();

    EXPECT_EQ(graph->getName(), "Graph 2");
    EXPECT_EQ(graph->getId(), 1);
}

TEST(GraphManagerTest, SwitchGraphNotFound) {
    GraphManager manager;
    manager.createGraph("Graph 1");

    testing::internal::CaptureStdout();
    manager.switchGraph("Graph 3");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Graph 'Graph 3' not found."), std::string::npos);
}

TEST(GraphManagerTest, DisplayGraphs) {
    GraphManager manager;
    manager.createGraph("Graph 1");
    manager.createGraph("Graph 2");

    testing::internal::CaptureStdout();
    manager.displayGraphs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Graph 1"), std::string::npos);
    EXPECT_NE(output.find("Graph 2"), std::string::npos);
}

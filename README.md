# Data Collector for RAG

## Overview

This project is a Data Collector system built for the RAG (Retrieval-Augmented Generation). It is designed to gather, manage, and process data that can be used for Retrieval-Augmented Generation tasks.
RAG combines information retrieval with large language models to improve the quality and relevance of generated content.
The system uses graph-based structures to represent and manage data, enabling advanced analytics and retrieval capabilities.

## Key Principles

1. Minimalism and Simplicity
   The system follows the minimalism principle by avoiding unnecessary complexity in the hierarchy and structure of the knowledge base. The focus is on keeping things simple, efficient, and straightforward to use. The goal is to prevent over-complication of data relationships and structure, ensuring that the user can easily manage and understand their data without feeling overwhelmed by the system’s design.

2. Adding Metadata and Tags to Notes
   This system provides the ability to attach metadata and tags to pieces of information, such as notes or documents, allowing for a more structured and categorized data storage approach. This feature is useful for enhancing the retrieval process by offering extra context and classification to the data, making it easier to search, organize, and understand the content.

3. Data Storage and Vector Store Creation
   The system supports saving data as files and generating a vector store from the saved files. This means that after collecting and organizing information in the system, you can easily export it as a file (for example, in JSON or CSV format). Additionally, the system can create a vector store from these files, allowing for more efficient and relevant data retrieval in RAG tasks. The vector store provides an efficient structure for querying and augmenting generative models with relevant content.

4. Explicit Relationships Between Information Pieces
   One of the core features of this system is the ability to explicitly define relationships between different pieces of information. Whether it's creating a link between documents, notes, or other data entities, the system allows you to mark and visualize these connections clearly. This functionality is vital for creating a knowledge graph where relationships between entities (nodes) are crucial for data retrieval and context in RAG models.

## Run project

Here's the detailed documentation on how to build and run C++ code using CMake:

### Step 1: Install CMake

1. **On macOS**:

    ```sh
    brew install cmake
    ```

2. **On Ubuntu/Debian**:

    ```sh
    sudo apt update
    sudo apt install cmake
    ```

3. **On Windows**:
   - Download the installer from the official CMake website.
   - Install CMake by following the installer instructions.

### Step 2: Build the Project Using CMake

1. Navigate to the root directory.

2. Run the command to generate build files and build the project:

 ```bash
 cmake -S . -B build && cmake --build build
 ```

### Step 3: Run the Executable

After a successful build, an executable file named `app` will be created in the `build` folder. Run it with the following command:

```bash
./build/data_storage
```

### Full Command to Build and Run

```bash
cmake -S . -B build && cmake --build build && ./build/data_storage
```
### Run tests

```bash
cd build
ctest --output-on-failure
cd ..
```

### Rerun failed tests with all logs

```bash
ctest --rerun-failed --output-on-failure
```

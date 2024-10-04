#include <bits/stdc++.h>
using namespace std;

// Function to perform Depth First Search (DFS) and push nodes onto the stack for topological sorting
void depthFirstSearch(int vertex, const vector<vector<int>>& adjacencyList,
                      vector<bool>& visited, stack<int>& resultStack) {
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Recur for all adjacent vertices
    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            depthFirstSearch(neighbor, adjacencyList, visited, resultStack);
        }
    }

    // Push the current vertex to the result stack
    resultStack.push(vertex);
}

// Function to perform Topological Sort using DFS
void topologicalSort(const vector<vector<int>>& adjacencyList, int vertexCount) {
    stack<int> resultStack; // Stack to store the topological order
    vector<bool> visited(vertexCount, false); // Track visited vertices

    // Perform DFS from each unvisited vertex
    for (int i = 0; i < vertexCount; i++) {
        if (!visited[i]) {
            depthFirstSearch(i, adjacencyList, visited, resultStack);
        }
    }

    // Output the contents of the stack to display the topological order
    cout << "Topological sorting of the graph: ";
    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
    }
}

int main() {
    // Number of vertices in the graph
    int vertexCount = 4;

    // Define the edges of the graph
    vector<vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Construct the graph as an adjacency list
    vector<vector<int>> adjacencyList(vertexCount);
    for (const auto& edge : edges) {
        adjacencyList[edge[0]].push_back(edge[1]);
    }

    // Perform topological sorting on the constructed graph
    topologicalSort(adjacencyList, vertexCount);

    return 0;
}

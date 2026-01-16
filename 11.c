// Floyd-Warshall Algorithm in C

#include <stdio.h>

// defining the number of vertices
#define nV 5

#define INF 999

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], updatedMatrix[nV][nV], i, j, k;

  // Initialize the updated matrix with the original graph
  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Main loop of the Floyd-Warshall algorithm
  for (k = 0; k < nV; k++) {
    // Initialize the updated matrix with the current state
    for (i = 0; i < nV; i++)
      for (j = 0; j < nV; j++)
        updatedMatrix[i][j] = matrix[i][j];

    // Update the distances using the intermediate vertex k
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          updatedMatrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }

    // Replace the original matrix with the updated matrix
    for (i = 0; i < nV; i++)
      for (j = 0; j < nV; j++)
        matrix[i][j] = updatedMatrix[i][j];
      // Print each matrix matrix
  
  printMatrix(matrix);
  printf("\n");
  }

  
}


void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {{0, 3, INF, 5, 2},
             {2, 0, INF, 4, INF},
             {INF, 1, 0, INF, 1},
             {INF, INF, 2, 0, 0},
             {INF, 0, 2, 4, 1}};
  floydWarshall(graph);
}

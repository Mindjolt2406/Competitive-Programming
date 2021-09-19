#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool dfsFindCycle(int curr, vector<vector<int>> &graph, vector<bool> &visited) {
  bool isCycle = false;
  visited[curr] = true;
  
  for (auto child : graph[curr]) {
    if (visited[child])
      isCycle = true;
    else 
      isCycle = isCycle || dfsFindCycle(child, graph, visited);
  }
  
  return isCycle;
}

bool findCycle(vector<vector<int>> &graph, int N) {
  vector<bool> visited(N);
  bool isCycle = false;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      isCycle = dfsFindCycle(i, graph, visited) || isCycle; 
    }
  }
  
  return isCycle;
}

bool isPainting(vector<vector<int>> &mat) {
  int n = mat.size(), m = mat[0].size();
  const int INF = INT_MAX;
  vector<int> minI(n*m, INF), maxI(n*m, -1);
  vector<int> minJ(n*m, INF), maxJ(n*m, -1);
  
  // Assumption colours [1, N*M]
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mat[i][j]--;
      int colour = mat[i][j];
      minI[colour] = min(minI[colour], i);
      minJ[colour] = min(minJ[colour], j);
      maxI[colour] = max(maxI[colour], i);
      maxJ[colour] = max(maxJ[colour], j);
    }
  }
  
  vector<vector<int>> graph(n*m);
  for (int col = 0; col < n*m; col++) {
    if (minI[col] <= maxI[col] && minJ[col] <= maxJ[col]) {
      // Go through submatrix.
      set<int> distinctColours;
      for (int i = minI[col]; i <= maxI[col]; i++) {
         for (int j = minJ[col]; j <= maxJ[col]; j++) {
           distinctColours.insert(mat[i][j]);
         }
      }
      
      for (auto colour : distinctColours) {
        graph[colour].push_back(col); 
        cout << "colour: " << colour << " col: " << col << endl;
      }
    }
  }
  
  return !findCycle(graph, n*m);
}

// To execute C++, please define "int main()"
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];
  
  cout << isPainting(mat) << "\n";
  return 0;
}


/* 
Your previous Plain Text content is preserved below:

You are given a rectangular grid which you want to paint using different colors, but since you are not an experienced painter, you have certain restrictions with your art:
1. On each brush stroke, you'll paint a solid rectangular pattern of a single color on the grid, This will cover up the existing colors in that rectangular area.
2. Once you have used a certain color, you won't use that color again.

You are given a `m x n` matrix `targetGrid`, where `targetGrid[row][col]` is the color in the position (row, col) of the grid.
Return true if it is possible to paint the matrix targetGrid, otherwise, return false.
eg:
1. [
[1,1,1,1],
[1,1,3,3],
[1,1,2,3],
[5,5,3,4],
]
Ans: True
2. [
[1,2,1],
[2,1,2],
[1,1,2],
]
Ans: False

1. [
[1,1,1,1],
[1,1,3,3],
[1,1,2,3],
[5,5,3,4],]

2. [
[1,2,1],
[2,1,2],
[1,1,2],
]

Observations
1. min_i, max_i, min_j, max_j. 
  Get the potential rectangle for a colour. 
  N colours, N! different combinations
  
  1, 5, 2, 3, 4
  1. [
[1,1,1,1],
[1,1,3,3],
[1,1,3,3],
[5,5,3,4],]

  1, 5, 3, 2, 4
  1. [
[1,1,1,1],
[1,1,3,3],
[1,1,2,3],
[5,5,3,4],] 
Brute Force - O(M*N! * M * N)

  1. [
[1,1,1,1],
[1,1,3,3],
[1,1,X,3],
[X,X,3,X],] 

Query - Given a colour, does it form a rectangle with only that colour and X?

While(RemainingColours()) {
  for (auto colour : colours)
    if (checkQuery(colour)) {
      MarkColourAsX();
    }
}

#Remaining - O(N*M)
#Colours - O(N*M)
#CheckQuery - O(N*M)
Total - O(N^3 * M^3)

Approach with Hint

Colour - (Rectangle, #Colour + #X)
3 -> ((1, 2) , (3, 4), 2). 
2 -> (((2, 2) (2, 2), 0). 

3-> ((1, 2) , (3, 4), 1). 


(Colour, Rectangle)
(#Left, Colour)



For every X I make, iterate through colours and increment accordingly. 



#X -> N*M
#Colour -> N*M


1 - (2, 1), (3, 3)
2 - 
3 - 2, 4
4 - 
5 -

1 - 
2 - (1, 1)
3 - (1, 3)
4 - (3, 1), (1, 1)
5 - 

1 2 3 4 5
        4
        3
        2
        1
        

 */
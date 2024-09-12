class DSU {
  public:
    vector<int> parent;
    vector<int> size;

    // Constructor that initializes DSU with `n` elements
    DSU(int n) {
        parent.resize(n);  // Resize the parent vector
        size.resize(n);    // Resize the size vector
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Path compression for finding the parent
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    // Union by size
    void Union(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a == parent_b) return;

        if (size[parent_a] < size[parent_b]) {
            size[parent_b] += size[parent_a];
            parent[parent_a] = parent_b;
        } else if (size[parent_a] > size[parent_b]) {
            size[parent_a] += size[parent_b];
            parent[parent_b] = parent_a;
        } else {
            size[parent_a] += size[parent_b];
            parent[parent_b] = parent_a;
        }
    }
};

class Solution {
  public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalSize = m * n;  // Convert 2D index to 1D index
        DSU dsu(totalSize);

        // Lambda to check if a position is valid
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // Step 1: Union connected components by size for all '1's in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (auto& dir : directions) {
                        int x_ = i + dir[0];
                        int y_ = j + dir[1];

                        if (isValid(x_, y_) && grid[x_][y_] == 1) {
                            // Union 2D indices after converting to 1D index
                            int newIndex = x_ * n + y_;
                            int oldIndex = i * n + j;

                            dsu.Union(oldIndex, newIndex);
                        }
                    }
                }
            }
        }

        int ans = 0;
        // Step 2: Check for each 0 and calculate the max island size after flipping it
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {  // We are considering flipping this 0
                    unordered_set<int> visitedComp;
                    int totalSumForThisZero = 1;  // Start with 1 for this zero itself
                    for (auto& dir : directions) {
                        int x_ = i + dir[0];
                        int y_ = j + dir[1];

                        if (isValid(x_, y_) && grid[x_][y_] == 1) {
                            int index = x_ * n + y_;
                            int root = dsu.find(index);  // Use dsu.find() to get the representative

                            if (!visitedComp.count(root)) {
                                visitedComp.insert(root);
                                totalSumForThisZero += dsu.size[root];  // Add the size of the component
                            }
                        }
                    }
                    ans = max(ans, totalSumForThisZero);
                }
            }
        }

        // If no zero was flipped, the largest island is the entire grid or the existing islands
        for (int i = 0; i < totalSize; i++) {
            ans = max(ans, dsu.size[dsu.find(i)]);
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

class DSU
{
  private:
    vector<int> parent;
    vector<int> size;

  public:
    DSU(int n){
      parent.resize(n);
      size.resize(n);  // Corrected: resize size vector here
      
      for(int i = 0; i < n; i++){
        parent[i] = i;
        size[i] = 1;
      }
    }

    int find(int u){
      if(u == parent[u]) return u;

      return parent[u] = find(parent[u]);  // Path compression
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(size[x_parent] > size[y_parent]){
          parent[y_parent] = x_parent;
          size[x_parent] += size[y_parent]; 
        }else if(size[x_parent] < size[y_parent]){  // Corrected: Added if here
          parent[x_parent] = y_parent;
          size[y_parent] += size[x_parent]; 
        }else{ 
          parent[x_parent] = y_parent;
          size[y_parent] += size[x_parent];
        }
    }
};

int main(){
  DSU dsu(8);
  dsu.Union(0, 2);
  dsu.Union(2, 1);

  cout << dsu.find(2) << endl;  // Should output the representative of the set that includes 2
  
  return 
}

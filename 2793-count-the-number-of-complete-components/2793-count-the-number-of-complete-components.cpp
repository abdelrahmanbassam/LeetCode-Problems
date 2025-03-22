class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 1; i <= n; ++i)
                parent[i] = i;
        }

        int findRoot(int x) {
            if (parent[x] != x)
                parent[x] = findRoot(parent[x]);
            return parent[x];
        }

        bool merge(int x, int y) {
            x = findRoot(x);
            y = findRoot(y);
            if (x == y)
                return false;

            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            return true;
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> edgeCount;
        for (auto& edge : edges) {
            dsu.merge(edge[0], edge[1]);
        }

        vector<int> componentSize(n + 1, 0);
        unordered_map<int, int> componentEdges;

        for (int i = 0; i < n; ++i) {
            int root = dsu.findRoot(i);
            componentSize[root]++;
        }

        for (auto& edge : edges) {
            int root = dsu.findRoot(edge[0]);
            componentEdges[root]++;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dsu.findRoot(i) != i) continue;
            int nodes = componentSize[i];
            int edgesInComponent = componentEdges[i];
            if (edgesInComponent == nodes * (nodes - 1) / 2) {
                ans++;
            }
        }

        return ans;
    }
};
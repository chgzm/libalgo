#include <bits/stdc++.h>

class WarshallFloyd {
public:
    using Matrix = std::vector<std::vector<int>>;

    WarshallFloyd(int V) {
        mat.resize(V);
        for (int i = 0; i < V; ++i) {
            mat[i].resize(V, INT32_MAX);
            mat[i][i] = 0;
        }
    }
    ~WarshallFloyd() = default;

    void add(int s, int t, int d) noexcept {
        this->mat[s][t] = d;
    }

    // return all pairs of shortest path from vertex to vertex  
    // if unreachble from vertex i to j, shortest_path[i][j] is INT32_MAX
    Matrix allPairs() const noexcept {
        Matrix sp = this->mat; // shortest path
        for (size_t k = 0; k < this->mat.size(); ++k) {
            for (size_t i = 0; i < this->mat.size(); ++i) {
                for (size_t j = 0; j < this->mat.size(); ++j) {
                    if (sp[i][k] == INT32_MAX || sp[k][j] == INT32_MAX) {
                        continue;
                    }

                    sp[i][j] = std::min(sp[i][j], sp[i][k] + sp[k][j]);
                }
            }
        }

        return sp;
    }

private:
    Matrix mat; // adjacency matrix  
};

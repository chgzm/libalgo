#include <bits/stdc++.h>

struct Edge {
    int to;
    int cost;
}; 

class Prim {
public:
    using Matrix = std::vector<std::vector<Edge>>;
    using P = std::pair<int, int>;

    Prim(int v) {
        this->mat.resize(v);
    }

    ~Prim() = default;

    void addEdge(int s, int t, int c) noexcept {
        this->mat[s].push_back({t, c});
    }

    // return the sum of weights of edges of the MST (Minimum Spanning Tree) 
    int totalCost() noexcept {
        bool used[this->mat.size()] = {false};

        std::priority_queue<P, std::vector<P>, std::greater<P>> que;
        que.push({0, 0});

        int res = 0; 
        while (que.empty() == false) {
            const P p = que.top(); 
            que.pop();
            if (used[p.second]) {
                continue;
            }

            used[p.second] = true;
            res += p.first;
            for (const Edge& e : this->mat[p.second]) {
                que.push({e.cost, e.to});
            }
        }

        return res;
    }

private:
    Matrix mat;
};

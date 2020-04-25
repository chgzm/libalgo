#include <bits/stdc++.h>
#include "../UnionFind/UnionFind.cpp"

struct Edge {
    int from;
    int to;
    int cost;

    bool operator<(const Edge& r) {
        return this->cost < r.cost;
    }
};

class Kruskal {
public:
    Kruskal(int v) : vnum(v) {
    }

    ~Kruskal() = default;

    void addEdge(int f, int t, int c) noexcept {
        this->edges.push_back({f, t, c});
    }

    int totalCost() const noexcept {
        UnionFind uf(this->vnum);

        std::vector<Edge> es = this->edges;
        std::sort(es.begin(), es.end());

        int res = 0;
        for (int i = 0; i < es.size(); ++i) {
            Edge& e = es[i];
            if (uf.same(e.from, e.to) == false) {
                uf.unite(e.from, e.to);
                res += e.cost;
            }
        }

        return res;
    }

private:
    std::vector<Edge> edges;
    int vnum;
};


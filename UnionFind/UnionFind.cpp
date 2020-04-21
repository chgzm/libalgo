#include <bits/stdc++.h>

class UnionFind {
public:
    UnionFind(int n) {
        this->parent.resize(n);
        this->rank.resize(n);
        this->nsize.resize(n);

        for (int i = 0; i < n; ++i) {
            this->parent[i] = i; // default parent is itself
            this->rank[i] = 0;   // default rank is 0
            this->nsize[i] = 1;  // default size is 1
        }
    }

    ~UnionFind() = default;

    // return the parent of node x
    int find(int x) noexcept {
        if (this->parent[x] == x) {
            return x;
        } else {
            return this->parent[x] = this->find(parent[x]);
        }
    }

    // unite the tree of x and the tree of y
    void unite(int x, int y) noexcept {
        const int xp = this->find(x);
        const int yp = this->find(y);
        if (xp == yp) {
            return;
        }

        // change the parent node of tree whose rank is samller.
        if (this->rank[xp] < this->rank[yp]) {
            this->parent[xp] = yp;
            this->nsize[yp] += this->nsize[xp];
        } else {
            this->parent[yp] = xp;
            this->nsize[xp] += this->nsize[yp];

            if (this->rank[xp] == this->rank[yp]) { 
                ++(this->rank[xp]);
            }
        }
    }

    // return true if x and y belong to the same tree.
    bool same(int x, int y) noexcept {
        return (this->find(x) == this->find(y));
    }

    // return the number of nodes in tree which contains x
    int size(int x) noexcept {
        return this->nsize[this->find(x)];
    }

private:
    std::vector<int> parent; // parent of each node
    std::vector<int> rank;   // depth of each tree
    std::vector<int> nsize;  // number of nodes in each tree
};

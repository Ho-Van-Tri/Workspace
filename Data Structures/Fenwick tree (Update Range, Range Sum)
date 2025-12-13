struct Fenwick {
    vector<int> bit1, bit2;
    int n;

    Fenwick(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        bit1.assign(n+5, 0);
        bit2.assign(n+5, 0);
    }

    void updatePoint(vector<int> &b, int id, int v) {
        while(id <= n) {
            b[id] += v;
            id += (id & -id);
        }
    }

    void updateRange(int l, int r, int v) {
        updatePoint(bit1, l, (n-l+1)*v);
        updatePoint(bit1, r+1, -(n-r)*v);
        updatePoint(bit2, l, v);
        updatePoint(bit2, r+1, -v);
    }

    int getsum(vector<int> &b, int id) {
        int ans = 0;
        while(id > 0) {
            ans += b[id];
            id -= (id & -id);
        }
        return ans;
    }

    int prefixsum(int u) {
        return getsum(bit1, u) - getsum(bit2, u) * (n-u);
    }

    int rangesum(int l, int r) {
        return prefixsum(r) - prefixsum(l-1);
    }
};

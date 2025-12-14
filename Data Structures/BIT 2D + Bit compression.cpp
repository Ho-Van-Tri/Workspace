struct Fenwick {
    vector<vector<int>> bit, pos;
    int n;

    void init(int _n) {
        n = _n;
        bit.assign(n+5, {});
        pos.assign(n+5, {});
	  }

    void fakeadd(int u, int v) {
        for(int i = u; i <= n; i += (i & (-i))) {
            pos[i].pb(v);
        }
    }

    void fakeget(int u, int v) {
        for(int i = u; i > 0; i -= (i & (-i))) {
            pos[i].pb(v);
        }
    }

    void compress() {
        for(int i = 1; i <= n; i++) {
            sort(all(pos[i]));
            pos[i].erase(unique(all(pos[i])), pos[i].end());
            bit[i].assign(sz(pos[i]) + 5, 0);
        }
    }

    void add(int x, int y, int val) {
        for(int i = x; i <= n; i += (i & (-i))) {
            for(int j = lower_bound(all(pos[i]), y) - pos[i].begin() + 1;
            j < sz(bit[i]); j += (j & (-j))) {
                bit[i][j] = max(bit[i][j], val);
            }
        }
    }

    int get(int x, int y) {
        int ans = 0;
        for(int i = x; i > 0; i -= (i & (-i))) {
            for(int j = lower_bound(all(pos[i]), y) - pos[i].begin() + 1;
            j > 0; j -= (j & (-j))) {
                ans = max(ans, bit[i][j]);
            }
        }
        return ans;
    }
};

struct DSU {
    vector<int> par, num;
    vector<pair<int,int>> history;
    DSU(int n) : par(n+5), num(n+5) {
        fill(num.begin(), num.end(), 1);
        iota(par.begin(), par.end(), 0);
    }
 
    int findpar(int u) {
        return (par[u] == u ? u : findpar(par[u]));
    }
 
    bool unite(int u, int v) {
        u = findpar(u);
        v = findpar(v);
        if (u==v) return false;
        if (num[u] > num[v]) swap(u, v);
 
        history.push_back({u, num[u]});
        history.push_back({v, num[v]});
 
        par[u] = v;
        num[v] += num[u];
        return true;
    }
 
    int getime() {
        return sz(history);
    }
 
    void rollback(int time) {
        while(sz(history) > time) {
            auto[u, oldnum] = history.back();
            history.pop_back();
            par[u] = u;
            num[u] = oldnum;
        }
    }
};

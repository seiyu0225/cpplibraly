// https://atcoder.jp/contests/arc089/tasks
template<int VH, int VW> struct Sum2D {
    i64 v[VH][VW];
    void set(int x, int y, i64 c) { v[y][x] = c; }
    void build() {
        rep(y, 0, VH) rep(x, 0, VW) {
            if (0 < y) v[y][x] += v[y - 1][x];
            if (0 < x) v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
        }
    }
    int get(int sx, int sy, int tx, int ty) {
        assert(sx <= tx && sy <= ty);
        i64 rs = v[ty][tx];
        if (0 < sx) rs -= v[ty][sx - 1];
        if (0 < sy) rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
        return rs;
    }
};
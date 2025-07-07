const int MAXN = 100005;

class SegmentTree {
public:
    SegmentTree() : n(0) {}

    void setInitialArray(const int input[], int size) {
        n = size;
        for (int i = 0; i < n; ++i)
            arr[i] = input[i];
        build(1, 0, n - 1);
    }

    void build() {
        build(1, 0, n - 1);
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }

    void updatePoint(int idx, int value) {
        updatePoint(1, 0, n - 1, idx, value);
    }

    void deletePoint(int idx) {
        updatePoint(idx, 0);
    }

    void updateRange(int ul, int ur, int value) {
        updateRange(1, 0, n - 1, ul, ur, value);
    }

    bool insertAtEnd(int value) {
        if (n >= MAXN) return false;
        arr[n++] = value;
        build();
        return true;
    }

    int getSize() const {
        return n;
    }

    int getTreeValue(int node) const {
        return tree[node];
    }

private:
    int tree[4 * MAXN];
    int lazy[4 * MAXN];
    int arr[MAXN];
    int n;

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void updatePoint(int node, int l, int r, int idx, int value) {
        push(node, l, r);
        if (l == r) {
            tree[node] = value;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid)
                updatePoint(2 * node, l, mid, idx, value);
            else
                updatePoint(2 * node + 1, mid + 1, r, idx, value);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateRange(int node, int l, int r, int ul, int ur, int value) {
        push(node, l, r);
        if (ur < l || ul > r) return;
        if (ul <= l && r <= ur) {
            lazy[node] += value;
            push(node, l, r);
        } else {
            int mid = (l + r) / 2;
            updateRange(2 * node, l, mid, ul, ur, value);
            updateRange(2 * node + 1, mid + 1, r, ul, ur, value);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
};

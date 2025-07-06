#include <iostream>
using namespace std;

const int MAXN = 100005;
int tree[4 * MAXN];
int lazy[4 * MAXN];

int n;  

void build(int arr[], int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);
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
    if (qr < l || ql > r)
        return 0;
    if (ql <= l && r <= qr)
        return tree[node];
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

void deletePoint(int node, int l, int r, int idx) {
    updatePoint(node, l, r, idx, 0);
}

void updateRange(int node, int l, int r, int ul, int ur, int value) {
    push(node, l, r);
    if (ur < l || ul > r)
        return;
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

void deleteRange(int node, int l, int r, int ul, int ur) {
    updateRange(node, l, r, ul, ur, -query(1, 0, n - 1, ul, ur));
}

int main() {
    n = 6;
    int arr[MAXN] = {1, 3, 5, 7, 9, 11};

    build(arr, 1, 0, n - 1);

    cout << "Suma de [1, 3]: " << query(1, 0, n - 1, 1, 3) << endl;

    updatePoint(1, 0, n - 1, 1, 10);
    cout << "Suma de [1, 3] tras actualizar arr[1]=10: " << query(1, 0, n - 1, 1, 3) << endl;

    updateRange(1, 0, n - 1, 1, 3, 5);
    cout << "Suma de [1, 3] tras sumar 5: " << query(1, 0, n - 1, 1, 3) << endl;

    deletePoint(1, 0, n - 1, 2);
    cout << "Suma de [1, 3] tras eliminar arr[2]: " << query(1, 0, n - 1, 1, 3) << endl;

    deleteRange(1, 0, n - 1, 1, 3);
    cout << "Suma de [1, 3] tras eliminar rango: " << query(1, 0, n - 1, 1, 3) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

// update: add val at position idx
void update(int i, int idx, int val, int l, int r){
    if(l == r){
        seg[i] += val;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid) update(2*i+1, idx, val, l, mid);
    else update(2*i+2, idx, val, mid+1, r);
    
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

// query sum in range [ql, qr]
int query(int ql, int qr, int l, int r, int i){
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr) return seg[i];
    
    int mid = (l + r) / 2;
    return query(ql, qr, l, mid, 2*i+1) +
           query(ql, qr, mid+1, r, 2*i+2);
}

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<vector<int>> queries(q, vector<int>(3));
    vector<int> vals;

    // input array
    for(int i = 0; i < n; i++){
        cin >> a[i];
        vals.push_back(a[i]);
    }

    // input queries
    for(int i = 0; i < q; i++){
        char ch;
        int x, y;
        cin >> ch >> x >> y;

        if(ch == '?'){
            queries[i] = {0, x, y};
            vals.push_back(x);
            vals.push_back(y);
        }
        else{
            queries[i] = {1, x, y};
            vals.push_back(y);
        }
    }

    // 🔹 coordinate compression
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int sz = vals.size();
    seg.resize(4 * sz, 0);

    // 🔹 build initial tree
    for(int i = 0; i < n; i++){
        int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        update(0, id, 1, 0, sz-1);
    }

    // 🔹 process queries
    for(int i = 0; i < q; i++){
        if(queries[i][0] == 0){ // range query
            int L = lower_bound(vals.begin(), vals.end(), queries[i][1]) - vals.begin();
            int R = upper_bound(vals.begin(), vals.end(), queries[i][2]) - vals.begin() - 1;

            if(L <= R)
                cout << query(L, R, 0, sz-1, 0) << "\n";
            else
                cout << 0 << "\n";
        }
        else{ // update
            int k = queries[i][1] - 1;

            int old_id = lower_bound(vals.begin(), vals.end(), a[k]) - vals.begin();
            update(0, old_id, -1, 0, sz-1);

            a[k] = queries[i][2];

            int new_id = lower_bound(vals.begin(), vals.end(), a[k]) - vals.begin();
            update(0, new_id, 1, 0, sz-1);
        }
    }
}

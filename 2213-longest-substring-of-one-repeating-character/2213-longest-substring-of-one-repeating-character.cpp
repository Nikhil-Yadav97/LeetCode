class Node {
public:
    int maxlen, suflen, prelen;
    char suf, pre;

    Node() {}

    Node(int mx, int sl, int pl, char s, char p) {
        maxlen = mx;
        suflen = sl;
        prelen = pl;
        suf = s;
        pre = p;
    }
};

class Solution {
    vector<Node> segtree;

public:

    Node merge(Node &l, Node &r, int leftlen, int rightlen) {

        Node res;

        // Prefix
        res.pre = l.pre;
        res.prelen = l.prelen;

        if (l.prelen == leftlen && l.pre == r.pre) {
            res.prelen = leftlen + r.prelen;
        }

        // Suffix
        res.suf = r.suf;
        res.suflen = r.suflen;

        if (r.suflen == rightlen && r.suf == l.suf) {
            res.suflen = rightlen + l.suflen;
        }

        // Maximum
        res.maxlen = max(l.maxlen, r.maxlen);

        // Cross boundary
        if (l.suf == r.pre) {
            res.maxlen = max(res.maxlen, l.suflen + r.prelen);
        }

        return res;
    }

    void build(int i, int l, int r, string &s) {

        if (l == r) {
            segtree[i] = Node(1, 1, 1, s[l], s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, s);
        build(2 * i + 2, mid + 1, r, s);

        segtree[i] = merge(
            segtree[2 * i + 1],
            segtree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    void update(int i, int l, int r, int ind, char ch) {

        if (l == r) {
            segtree[i] = Node(1, 1, 1, ch, ch);
            return;
        }

        int mid = l + (r - l) / 2;

        if (ind <= mid) {
            update(2 * i + 1, l, mid, ind, ch);
        } 
        else {
            update(2 * i + 2, mid + 1, r, ind, ch);
        }

        segtree[i] = merge(
            segtree[2 * i + 1],
            segtree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        segtree.resize(4 * n);

        build(0, 0, n - 1, s);

        vector<int> result;

        for (int k = 0; k < queryIndices.size(); k++) {

            int ind = queryIndices[k];
            char ch = queryCharacters[k];

            update(0, 0, n - 1, ind, ch);

            result.push_back(segtree[0].maxlen);
        }

        return result;
    }
};
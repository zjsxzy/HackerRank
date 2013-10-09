/**
 * SegmentTree
 * each Segment : the sorted value of this Segment 
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree{
private:
    struct Node{
        int s, t;
        vector<int> sorted;
    };
public:
    SegmentTree(int bits) { 
        m_nodes.clear();
        m_nodes.resize(3 * (1<<bits));
        Init(0 , 0 , (1<<bits) -  1);
    }
    
    void InsertValue(int value, int pos) {
        Insert(0, value, pos);
    }
    
    int QueryXOR(int x, int s, int t) {
        return Query(0 , x, s, t);
    }

private:
    void Init(int node_id, int s, int t) {
        m_nodes[node_id].s = s;
        m_nodes[node_id].t = t;
        if (s == t) {
            return;
        }
        int mid = (s + t) / 2;
        Init(2 *node_id + 1, s, mid);
        Init(2 *node_id + 2, mid + 1, t);
    }
    
    void Insert(int node_id, int value, int pos) {
        m_nodes[node_id].sorted.push_back(pos);

        if (m_nodes[node_id].s == value && value == m_nodes[node_id].t) {
            return;
        }
        int mid = (m_nodes[node_id].s + m_nodes[node_id].t) / 2;
        if (value <= mid) {
            Insert(2 * node_id + 1, value, pos);
        } else {
            Insert(2 * node_id + 2, value, pos);
        }

    }

    int Query(int node_id, int x, int from, int to) {
        if (m_nodes[node_id].s == m_nodes[node_id].t) {
            return m_nodes[node_id].s;
        }
       
        int value = (m_nodes[node_id].t - m_nodes[node_id].s + 1) / 2;
        if ((x & value) > 0) {
            if (Exist(m_nodes[2 * node_id + 1].sorted, from, to)) {
                return Query(2 * node_id + 1, x, from, to);
            } else {
                return Query(2 * node_id + 2, x, from, to);
            }
        } else {
            if (Exist(m_nodes[2 * node_id + 2].sorted, from, to)) {
                return Query(2 * node_id + 2, x, from, to);
            } else {
                return Query(2 * node_id + 1, x, from, to);
            } 
        }
    } 
    
    bool Exist(const vector<int>& sorted, int from, int to) {
        int len = sorted.size(); 
        if (len == 0) return false;
        if (sorted[0] > to) return false;
        if (sorted[len - 1] < from) return false;
        int key = *lower_bound(sorted.begin(), sorted.end(), from);
        if (key <= to) return true;
        return false;
    }
private:
   vector<Node> m_nodes;
};

int main() {
    int T, n ,q, v;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d%d", &n, &q);
        SegmentTree tree(15);
        for (int i = 0 ; i < n; i++) {
            scanf("%d", &v);
            tree.InsertValue(v, i);
        }

        int x, s, t;
        while (q-- > 0) {
            scanf("%d%d%d", &x, &s, &t);
            printf("%d\n", tree.QueryXOR(x, s - 1, t - 1) ^x);
        }
    }
    return 0;
}

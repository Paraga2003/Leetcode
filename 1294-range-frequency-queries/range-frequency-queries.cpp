class SegmentTree{
private:
    int n;
    vector<unordered_map<int, int>> seg;
    void buildSegmentTree(vector<int>&arr,int i, int left, int right) {
        if (left == right) {
            seg[i][arr[left]] = 1;
            return;
        }

        int mid = (left + right) / 2;

        buildSegmentTree(arr,2 * i + 1, left, mid);
        buildSegmentTree(arr,2 * i + 2, mid + 1, right);

        for (const auto& [val, freq] : seg[2 * i + 1])
            seg[i][val] += freq;

        for (const auto& [val, freq] : seg[2 * i + 2])
            seg[i][val] += freq;
    }

    int query(int i, int l, int r, int ql, int qr, int value) {
        if (qr < l || ql > r)
            return 0;

        if (ql <= l && r <= qr) {
            return seg[i].count(value) ? seg[i][value] : 0;
        }
        int mid = (l + r) / 2;
        return query(2 * i + 1, l, mid, ql, qr, value) +
            query(2 * i + 2, mid + 1, r, ql, qr, value);
    }
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);  
        buildSegmentTree(arr, 0, 0, n - 1);
    }

    int rangeFreq(int left, int right, int value) {
        return query(0, 0, n - 1, left, right, value);
    }
};    
    





class RangeFreqQuery {
private:
    SegmentTree* A;
public:
    RangeFreqQuery(vector<int>& arr) {
        A = new SegmentTree(arr);
        
    }
    
    int query(int left, int right, int value) {
        return A->rangeFreq(left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
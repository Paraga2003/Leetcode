class SegmentTree{
private:
    vector<int> seg;
    int n;

    void buildTree(vector<int>& nums , int i , int l , int r){
        if(l == r){
            seg[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildTree(nums,2*i+1, l , mid);
        buildTree(nums,2*i+2, mid+1 , r);
        seg[i] = seg[2*i+1] + seg[2*i+2];

    }

     void update(int index , int val , int i , int l , int r){
        if(l == r){
            seg[i] = val;
            return;
        }
         int mid = (l+r)/2;
         if(index<=mid){
            update(index,val,2*i+1,l, mid);
         }else{
            update(index,val,2*i+2,mid+1, r);
         }
         seg[i] = seg[2*i+1] + seg[2*i+2];
     }
     int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return seg[i];
        int mid = (l + r) / 2;
        return query(2 * i + 1, l, mid, ql, qr) +
               query(2 * i + 2, mid + 1, r, ql, qr);
    }
    public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int pos, int val) {
        update(pos, val,0, 0, n-1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};



class NumArray {
private:
    SegmentTree* segTree;    
public:
    NumArray(vector<int>& nums) {
        segTree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        segTree->update(index, val);

        
    }
    
    int sumRange(int left, int right) {
        return segTree->query(left, right);
        
    }
    ~NumArray() {
        delete segTree;
    }    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
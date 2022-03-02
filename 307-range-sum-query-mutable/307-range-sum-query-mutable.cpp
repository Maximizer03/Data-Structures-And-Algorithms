struct FenwickTree{
    vector<int>bit;
    int n;
    void init(int _n){
        n=_n;
        bit.resize(n+1,0);
    }
    int pref(int i){
        int sum=0;
        while(i>0){
            sum+= bit[i];
            i= i- (i&(-i));
        }
        return sum;
    }
    int rsum(int l, int r){
        return pref(r)-pref(l-1);
    }
    void update(int i, int x){
        x-=rsum(i,i);
        while(i<=n){
            bit[i]+=x;
            i= i+ (i&(-i));
        }
    }
};
class NumArray {
public:
    FenwickTree f;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        f.init(n+1);
        for(int i=0;i<n;i++){
            f.update(i+1,nums[i]);
        }
    }
    void update(int index, int val) {
        f.update(index+1,val);
    }
    
    int sumRange(int left, int right) {
        return f.rsum(left+1,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
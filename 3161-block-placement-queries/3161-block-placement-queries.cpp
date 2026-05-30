class Solution {
public:
vector<int>seg ; 
vector<bool>ans ; 
int MAX = 50000 ; 
set<int>st ; 
int mx=INT_MIN ;
    void update(int idx , int low , int high ,int pos , int val){
        if(high==low){
            seg[idx] = val ; 
            return ; 
        }
        int mid  = low + (high-low)/2 ;
        if(pos<=mid)update(2*idx+1,low,mid,pos,val) ; 
        else update(2*idx+2,mid+1,high,pos,val) ; 
        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]) ; 
    } 
    int query(int idx , int low , int high , int l , int r ){
        if(l>high || r < low){
            return  0 ; 
        }
        if(low >= l && high <= r) return seg[idx];
        int mid = low + (high-low)/2 ;  
        int left = query(2*idx+1,low , mid , l , r ) ; 
        int right = query(2*idx+2,mid+1,high,l,r) ; 
        return max(left,right) ; 
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        seg.resize(4*MAX) ; 
        st.insert(0) ; 
        for(auto &q:queries){
            if(q[0]==1){
                int curr = q[1]  ; 
                auto it = st.upper_bound(curr) ; 
                int pgI = *prev(it) ; 
                int val = curr-pgI ; 
                update(0,0,MAX,curr,val) ; 
                if(it!=st.end()){
                    int ngI = *it ; 
                    int val = ngI-curr ; 
                    update(0,0,MAX,ngI,val) ; 
                }
                st.insert(curr) ;
            }
            else{
                int crr = q[1] ; 
                int sz = q[2] ; 
                auto it = st.upper_bound(crr) ; 
                int pgI = *prev(it) ; 
                int avaSize = query(0,0,MAX,0,pgI) ; 
                int maxii = max(avaSize,crr-pgI) ; 
                ans.push_back(maxii>=sz) ; 
            } 
        }
        return ans ; 
    }
};

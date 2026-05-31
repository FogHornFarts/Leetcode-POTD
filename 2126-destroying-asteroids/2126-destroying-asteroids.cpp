class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long m=mass;
        for(int i=0;i<n;i++){
            if(m >= asteroids[i]){
                m+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
            return a[1] - a[0] > b[1] - b[0];
        });
        int l = 0, h = 1e9, ans = 0;
        while(l <= h){
            int m = l + (h - l) / 2;
            int e = m;
            bool ok = 1;
            for(auto& t : tasks){
                if(e < t[1]){
                    ok = 0;
                    break;
                }
                e -= t[0];
            }
            if(ok){
                ans = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
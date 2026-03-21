class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long  l=0;
        long long  s=0;
        for(int x: batteries) s+=x;
        long long  h= s/n;
        
        while(l<=h){
            long long mid = l+(h-l)/2;
            long long total =0;

            for(int x: batteries){
                total+=min((long long)x , mid);
            }
            if(total>= mid*n){
                l = mid+1;
            }
            else h = mid-1; 
        }
        return h;

    }
};
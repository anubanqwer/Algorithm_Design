class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int INF = 2e9;
        int n = (int) nums.size();
        //special case
        if( n == 0 ) return 0;
        //
        int Size = 1;
        vector<int> tails( (int) nums.size(), INF );
        tails[0] = nums[0];
        for(int i=1; i < (int) nums.size(); i++){
            int x = nums[i];
            int L = 0; int R = n-1;
            int ans = -1;
            while( L <= R ){
                int mid = L + (R-L)/2;
                if( tails[mid] < x ){
                    ans = mid;
                    L = mid+1;
                    //find the better solution
                }
                else{
                    R = mid-1;
                }
            }
            
            if( ans == -1 ) tails[0] = min( tails[0], x );
            
            Size = max( Size, ans + 2 );
            //update tail
            tails[ ans+1 ] = min( tails[ans+1], x );
            
            //print
            /*
            cout << "x = " << x << "\n"; 
            cout << "Size = " << Size << "\n";
            cout << "ans = " << ans << "\n";
            for(auto &c: tails ) cout << c << " ";
            cout << "\n------------------------------------\n";     
            */
            //
            
        }
        return Size;
    }
};

/O(nlogn)

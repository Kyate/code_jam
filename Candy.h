class Solution {
public:
    int candy(vector<int>& ratings) {
       int i, n, sum;
        n = ratings.size();
        vector<int> candy(n, 1);

        for(i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candy[i] = candy[i - 1] + 1;
            }
        }
        sum = candy[n - 1];
        for(i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]){
                candy[i] = candy[i + 1] + 1;
            }
            sum += candy[i];
        }
        return sum;
    }
};

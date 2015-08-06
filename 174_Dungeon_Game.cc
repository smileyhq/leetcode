class Solution {
public:
	//Note: this is not the same with Minimum/Maximum path sum
	//because the path with Maximum sum doesn't guarantee the minimum initial HP
	
	//DP
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if(m == 0) return 1;
		int n = dungeon[0].size();
		if(n == 0) return 1;
		int dp[n];
		dp[n-1] = max(1 - dungeon[m-1][n-1], 1);
		for(int col = n-2; col >= 0; col--) {
			dp[col] = max(dp[col+1] - dungeon[m-1][col], 1);
		}
		for(int row = m-2; row >= 0; row--) {
			dp[n-1] = max(dp[n-1] - dungeon[row][n-1], 1);
			for(int col = n-2; col >= 0; col--) {
				dp[col] = max(min(dp[col], dp[col+1]) - dungeon[row][col], 1);
			}
		}
		return dp[0];
	}

	//Binary Search
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int N = dungeon.size();
        int M = dungeon[0].size();

        // just pick a simple path through the dungeon to obtain an upperbound
        int lowerbound = 0;
        int upperbound = 1;
        for (int i = 0; i < M; i++) {
            int val = dungeon[0][i];
            if (val < 0) upperbound += (-val);
        }
        for (int i = 0; i < N; i++) {
            int val = dungeon[i][M - 1];
            if (val < 0) upperbound += (-val);
        }

        // A number so small impossible to come back alive from
        static const int64_t dead = numeric_limits<int64_t>::min() / 3;

        // Binary search looking for the smallest starting health which we
        // survive from. Invariant we maintain is lowerbound dies and
        // upperbound survives
        while (lowerbound < upperbound - 1) {
            int mid = (upperbound - lowerbound) / 2 + lowerbound;

            // create a buffer N + 1 and M + 1 size so we have sentinal values
            // padding the first row and column.
            auto cur_health = vector<vector<int64_t> >(N + 1);
            for (int n = 0; n <= N; n++) {
                cur_health[n].resize(M + 1, dead);
            }

            // Seed in our starting health
            cur_health[0][1] = cur_health[1][0] = mid;
            for (int n = 1; n <= N; n++) {
                for (int m = 1; m <= M; m++) {
                    cur_health[n][m] = max(cur_health[n-1][m], cur_health[n][m-1]) + dungeon[n-1][m-1];
                    if (cur_health[n][m] < 1) {
                        // Once we are dead, ensure we stay dead
                        cur_health[n][m] = dead;
                    }
                }
            }

            // If we have positive health at the end we survived!
            if (cur_health[N][M] > 0) {
                upperbound = mid;
            } else {
                lowerbound = mid;
            }
        }
        return upperbound;        
    }
};

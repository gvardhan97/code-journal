class Solution {
public:
    bool canMake(int day, int m, int k, vector<int>& bloomDay) {
        int flowers = 0;
        int bouquets = 0;

        for (int x : bloomDay) {
            if (x <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;  // Flowers are used for this bouquet
                }
            } else {
                // Consecutive flowers break
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;

        // Not enough flowers
        if (totalFlowers > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(mid, m, k, bloomDay)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
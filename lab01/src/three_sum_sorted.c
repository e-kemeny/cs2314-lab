#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    *out_i = i;
                    *out_j = j;
                    *out_k = k;
                    return 1;
                }

                else if (sum < 0) {
                    j++;
                }

                else {
                    k--;
                }
            }
        }

    return 0;
}

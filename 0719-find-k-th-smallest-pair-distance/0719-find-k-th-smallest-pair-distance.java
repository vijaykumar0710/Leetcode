import java.util.*;

public class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        // Find the maximum element in the array
        int maxEl = Arrays.stream(nums).max().getAsInt();
        
        // Initialize a vector (array) to count distances
        int[] vec = new int[maxEl + 1];
        
        // Calculate all pairwise distances and count their occurrences
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = Math.abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }
        
        // Find the k-th smallest distance
        for (int d = 0; d < maxEl + 1; d++) {
            k -= vec[d];
            if (k <= 0) {
                return d;
            }
        }
        
        return -1;
    }
}

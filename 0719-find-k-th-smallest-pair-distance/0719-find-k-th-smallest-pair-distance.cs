using System;

public class Solution {
    public int SmallestDistancePair(int[] nums, int k) {
        int n = nums.Length;
        int maxEl = 0;
        
        // Find the maximum element in the array
        foreach (int num in nums) {
            if (num > maxEl) {
                maxEl = num;
            }
        }
        
        // Initialize an array to count distances
        int[] distanceCount = new int[maxEl + 1];
        
        // Calculate all pairwise distances and count their occurrences
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = Math.Abs(nums[i] - nums[j]);
                distanceCount[d]++;
            }
        }
        
        // Find the k-th smallest distance
        for (int d = 0; d <= maxEl; d++) {
            k -= distanceCount[d];
            if (k <= 0) {
                return d;
            }
        }
        
        return -1;
    }
}

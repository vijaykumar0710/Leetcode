class Solution {
    fun smallestDistancePair(nums: IntArray, k: Int): Int {
        val n = nums.size
        val maxEl = nums.maxOrNull() ?: 0
        
        // Initialize a list to count distances
        val distanceCount = IntArray(maxEl + 1)
        
        // Calculate all pairwise distances and count their occurrences
        for (i in 0 until n) {
            for (j in i + 1 until n) {
                val d = Math.abs(nums[i] - nums[j])
                distanceCount[d]++
            }
        }
        
        // Find the k-th smallest distance
        var k = k
        for (d in 0..maxEl) {
            k -= distanceCount[d]
            if (k <= 0) {
                return d
            }
        }
        
        return -1
    }
}

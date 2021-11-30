

/*
 * Date:2021-11-30 19:49
 * filename:084_largest-rectangle-in-histogram.cpp
 *
 */

class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			vector<int> minLeftIndex(heights.size());
			vector<int> minRightIndex(heights.size());

			int size = heights.size();

			minLeftIndex[0] = -1;

			for (int i = 1; i < size; i++) {
				int t = i - 1;
				while (t >= 0 && heights[t] >= heights[i])
					t = minLeftIndex[t];
				minLeftIndex[i] = t;
			}

			minRightIndex[size - 1] = size;
			for (int i = size - 2; i >= 0; i--) {
				int t = i + 1;
				while(t < size && heights[t] >= heights[i])
					t = minRightIndex[t];
				minRightIndex[i] = t;
			}

			int result = 0;
			for (int i = 0;i < size; i++) {
				int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
				result = max(sum, result);
			}
			return result;
		}
};

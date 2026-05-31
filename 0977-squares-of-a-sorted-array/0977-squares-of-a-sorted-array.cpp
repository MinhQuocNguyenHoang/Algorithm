class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            int lSquare = nums[left] * nums[left];
            int rSquare = nums[right] * nums[right];

            if (lSquare > rSquare) {
                res[pos] = lSquare;
                left++;
            } else {
                res[pos] = rSquare;
                right--;
            }

            pos--;
        }

        return res;
    }
};
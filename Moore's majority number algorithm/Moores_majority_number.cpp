// Moore's majority vote algorithm
// https://en.wikipedia.org/wiki/Boyer–Moore_majority_vote_algorithm
// Assumption: the array is non-empty and the majority element always exist in the array
int majorityElement(vector<int>& nums) {
    int candidate = nums[0], counter = 0;
    for (int n: nums) {
        if (counter == 0) {
            candidate = n;
            counter = 1;
        } else if (candidate == n) {
            counter++;
        } else {
            counter--;
        }
    }
    return candidate;
};
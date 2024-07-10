class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (++freqMap[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};
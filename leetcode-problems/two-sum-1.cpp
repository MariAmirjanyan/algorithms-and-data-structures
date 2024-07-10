class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
       int n = nums.size();
       for(int i = 0; i < n; ++i){
           map[nums[i]] = i;
       }
       for(int i = 0; i < n; ++i){
           int tmp = target - nums[i];
           if(map.contains(tmp) && map[tmp] != i){
                return {i, map[tmp]};
           }
       }
       return {-1, -1};
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int current_range = nums[0];
        int j = 1;
        for (int i = 0; i < nums.size();i++){
            nums[i] += i;
        }
        int ans = 0;
        int next_range = 0;
        if (nums.size() == 1) return 0;
        while (true){
            if (j == nums.size()-1){
                ans++;
                break;
            }
            next_range = max(next_range, nums[j]);
            if (j == current_range){
                //start new range
                current_range = next_range;
                next_range = 0;
                ans++;
            } 
            j++;
        }
        return ans;
    }
};
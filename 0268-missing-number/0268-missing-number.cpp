class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int element_min = 0;
        int element_max = nums.size();    
        bool found = false;
        int result;
        while(element_min != element_max){
            for(int i=0;i<nums.size();i++){
                if(nums[i] == element_min){
                    found = true;
                    break;
                }
            }
            if(!found){
                result = element_min;
                break;
            }
            found = false;
            element_min++;
        }
        return result;
    }
};
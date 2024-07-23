
// SORT 0 1 2
void sortColors(vector<int>& nums) {
    int i= 0,j = 0; //stores 0 
    int k = nums.size() - 1; //stores 2
    while(i <= k){
        if(nums[i] == 0){
            swap(nums[i], nums[j]);
            j++;
            i++;
        }
        else if(nums[i] == 2){
            swap(nums[i], nums[k]);
            k--;
            //Here we can go wrong no i++
        }
        else{
            i++;
        }
    }
}


// Find the Duplicate Number

int findDuplicate(vector<int>& nums) {
    while(nums[0] != nums[nums[0]]){
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}

// Subarray Sums Divisible by K
int subarraysDivByK(vector<int>& nums, int k) {
    int ans = 0;
    vector<int> arr(k, 0);
    arr[0] = 1; //imp
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        int index = sum%k;
        //negative remainder
        if(index < 0) index += k;
        if(arr[index] != 0){
            ans += arr[index];
            arr[index] += 1;
        }
        else{
            arr[index] = 1;
        }
    }
    return ans; 
}

//Moves Zero

void moveZeroes(vector<int>& nums) {
    int j = 0;
    int k = nums.size();
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }   

    for(j; j < k; j++){
        nums[j] = 0;
    }
}
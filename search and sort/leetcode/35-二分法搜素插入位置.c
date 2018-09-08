/*************************************************************************
	> File Name: 35-二分法搜素插入位置.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/ 8 14:23:04 2018
 ************************************************************************/
int searchInsert(int* nums, int numsSize, int target) {
       
        
        int len  = numsSize;
        int low = 0;
        int high = len - 1;
        int mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
    if (target > nums[low]) {
        return low + 1;
    }else{
        return low;
    }
}

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        
        for (int i = 0; i < arr.size(); ++i) {
            int target = arr[i] * 2;
            int left = (target >= 0 ? i + 1 : 0);
            int right = arr.size() - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    return true;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

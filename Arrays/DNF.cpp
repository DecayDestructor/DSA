#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low, high, mid;
        low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 1)
                mid++;
            else if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {0, 1, 0, 2, 1, 2, 0, 1, 0, 2, 1, 0};
    sol->sortColors(nums);
    for (auto it : nums)
    {
        cout << it << " " << endl;
    }
}

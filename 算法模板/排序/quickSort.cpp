#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& nums, int left, int right)
{
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    int temp = nums[left];
    while (left < right) {
        while (right > left && nums[right] > temp) {
            right--;
        }
        if (left < right) {
            nums[left++] = nums[right];
        }
        while (right > left && nums[left] < temp) {
            left++;
        }
        if (left < right) {
            nums[right--] = nums[left];
        }
    }
    nums[left] = temp;
    quicksort(nums, i, left - 1);
    quicksort(nums, right + 1, j);
}

int main()
{
    vector<int> a = { 1, 4, 3, 7, 2 };
    quicksort(a, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << a[i];
    }
    cin.get();
}
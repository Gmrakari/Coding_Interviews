/*
*
** @filename:912Sort an Array
** @date:2022-05-25 09:01:57
*  @author:gmrakari
*
*/

#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> ret = nums;
        quicksort(ret, 0, ret.size());
        return ret;
    }

    int partition(vector<int>& nums, int low, int high) {
        int pv = nums[low];
        while (low < high) {
            while (low < high && pv < nums[high]) {
                high--;
            }
            swap(nums[low], nums[high]);
            while (low <= high && pv > nums[low]) {
                low++;
            }
            swap(nums[low], nums[high]);
        }
        return low;
    }

    void quicksort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pv = partition(nums, low, high);
            quicksort(nums, low, pv - 1);
            quicksort(nums, pv + 1, high);
        }
    }

    vector<int> sortArra_Heap(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> ret = nums;
        heap_sort(ret, ret.size());
        return ret;
    }

/*
* 算法步骤
* 1、创建一个堆Heap[0···n - 1]
* 2、把堆首(最大值)和堆尾交换
* 3、把堆的尺寸缩小1，兵调用shift_down(0)，目的是把新的数组顶端数据调整到相应位置
* 4、重复步骤2，直到堆的尺寸为1
*/

    void MaxHeapify(vector<int>& nums, int start, int end) {
        int son = start;
        int dad = son * 2 + 1;
        while (son <= end) {
            if (son + 1 <= end && nums[son] < nums[son + 1])
                son++;
            if (nums[dad] > nums[son])
                return ;
            else {
                swap(nums[son], nums[dad]);
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }

    int heap_sort(vector<int>& nums, int len) {
        //初始化
        for (int i = len / 2 - 1;i >= 0; i--) {
            MaxHeapify(nums, i, len - 1);
        }

        //最后一个元素和堆顶交换
        for (int i = len - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            MaxHeapify(nums, 0, i - 1);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


void test() {
    cout << "Begin" << endl;
    
    Solution s;
    vector<int> vec{7, 1, 5, 3, 6, 4};
    vector<int> ret = s.sortArray(vec);

    for (auto i : ret) {
        cout << i << " ";
    }

    cout << "\nEnd" << endl;
}

void test_2() {
    cout << "Begin" << endl;

    Solution s;
    vector<int> vec{7, 1, 5, 3, 6, 4};
    vector<int> ret = s.sortArra_Heap(vec);

    for (auto i : ret) {
        cout << i << " ";
    }

    cout << "\nEnd" << endl;
}

int main()
{
    test();
}
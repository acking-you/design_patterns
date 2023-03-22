#pragma once
#include <span>

namespace lab2 {
namespace detail {

class QuickSort
{
public:
   /**
    * 参考链接:https://oi-wiki.org/basic/quick-sort/
    * @param nums
    */
   void sort(std::span<int> nums)
   {
      if (nums.size() < 2) { return; }
      // i：当前操作的元素
      // j：第一个等于 pivot 的元素
      // k：第一个大于 pivot 的元素
      size_t i = 0, j = 0, k = nums.size();
      int    pivot = nums[k / 2];
      // 完成一趟三路快排，将序列分为：
      // 小于 pivot 的元素｜ 等于 pivot 的元素 ｜ 大于 pivot 的元素
      while (i < k)
      {
         if (nums[i] < pivot) std::swap(nums[i++], nums[j++]);
         else if (pivot < nums[i]) std::swap(nums[i], nums[--k]);
         else ++i;
      }
      sort({nums.begin(), j});
      sort({nums.begin() + k, nums.size() - k});
   }
};

class BinarySearch
{
public:
   int search(std::span<int> nums, int item)
   {
      size_t left = 0, right = nums.size(), mid;
      while (left < right)
      {
         mid   = (right - left) / 2;
         int v = nums[mid];
         if (v < item) { left = mid + 1; }
         else { right = mid; }
      }
      if (left == nums.size() || nums[left] != item) return -1;
      return left;
   }
};
}   // namespace detail

class DataOperation
{
public:
   virtual ~DataOperation()                           = default;
   virtual void sort(std::span<int> nums)             = 0;
   virtual int  search(std::span<int> nums, int item) = 0;
};

class Adapter : public DataOperation
{
public:
   ~Adapter() override = default;
   void sort(std::span<int> nums) override { sort_.sort(nums); }
   int  search(std::span<int> nums, int item) override
   {
      return search_.search(nums, item);
   }

private:
   detail::QuickSort    sort_;
   detail::BinarySearch search_;
};

}   // namespace lab2
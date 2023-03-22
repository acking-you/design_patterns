#include <lab2/adapter.h>

#include <iostream>
#include <string>
#include <vector>

using namespace lab2;

void printNums(std::span<int> nums)
{
   for (auto&& n : nums) { std::cout << n << " "; }
   std::cout << "\n";
}

int main()
{
   auto adapter = Adapter();
   int nums[]{32,23,324,3432,2112,234};
   std::cout<<"原数组:\n";
   printNums(nums);
   adapter.sort(nums);
   std::cout<<"排序后:\n";
   printNums(nums);
   int x;
   std::cout<<"请输入你要查找的数\n";
   std::cin>>x;
   int ret = adapter.search(nums,x);
   if(ret == -1){
      std::cout<<"你查找的数不存在\n";
   }else{
      std::cout<<"下标为:"<<ret;
   }
}
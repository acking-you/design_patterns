#pragma once
#include <random>

namespace util {
namespace detail {
struct Rand
{
   Rand(int start, int end) : rd(), gen(rd()), dis(start, end) {}
   int operator()() { return dis(gen); }

private:
   // 使用硬件随机数生成器作为种子
   std::random_device              rd;
   // 使用Mersenne Twister 19937作为随机数引擎
   std::mt19937                    gen;
   // 使用Uniform分布将生成器范围映射到[start,end]
   std::uniform_int_distribution<> dis;
};
}   // namespace detail
template <int start, int end>
int GetRand()
{
   static detail::Rand rand(start, end);
   return rand();
}
}   // namespace util
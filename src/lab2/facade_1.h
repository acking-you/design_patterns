#pragma once

#include <iostream>
#include <string_view>

#include "../util/random.h"

namespace lab2 {
namespace detail {
struct Memory
{
   bool check() { return util::GetRand<0, 100>() >= 50; }
};
struct CPU
{
   bool run() { return util::GetRand<0, 100>() >= 50; }
};
struct HardDisk
{
   bool read() { return util::GetRand<0, 100>() >= 50; }
};

struct OS
{
   bool load() { return util::GetRand<0, 100>() >= 50; }
};

}   // namespace detail
class MainFrame
{
public:
   bool on()
   {
      if (!memory.check())
      {
         failed("内存", "检查");
         return false;
      }
      ok("内存", "检查");
      if (!cpu.run())
      {
         failed("处理器", "运行");
         return false;
      }
      ok("处理器", "运行");
      if (!disk.read())
      {
         failed("硬盘", "读取");
         return false;
      }
      ok("硬盘", "读取");
      if (!os.load())
      {
         failed("操作系统", "载入");
         return false;
      }
      ok("操作系统", "载入");
      ok("计算机", "启动");
      return true;
   }

private:
   static void ok(std::string_view name, std::string_view op)
   {
      std::cout << name << op << "成功\n";
   }
   static void failed(std::string_view name, std::string_view op)
   {
      std::cout << name << op << "失败\n";
   }

   detail::Memory   memory;
   detail::CPU      cpu;
   detail::HardDisk disk;
   detail::OS       os;
};

}   // namespace lab2

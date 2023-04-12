#pragma once
#include <util/autogen.h>

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

namespace lab3 {

class Strategy
{
public:
   AUTO_GEN_TYPE_SHARED_PTR(Strategy)
   virtual void handle(double money) = 0;
};

class ComputerBook : public Strategy
{
public:
   AUTO_GEN_NEW_SHARED_PTR(ComputerBook)
   void handle(double money) override
   {
      std::cout << "正在购买计算机类图书,打折10%\n最终价格为:" << money * 0.9
                << "\n";
      std::cout<<"-----------------\n";
   }
};

class LanguageBook : public Strategy
{
public:
   AUTO_GEN_NEW_SHARED_PTR(LanguageBook)
   void handle(double money) override
   {
      std::cout << "正在购买语言类图书,有2元优惠\n最终价格为:" << money - 2.0
                << "\n";
      std::cout<<"-----------------\n";
   }
};

class NovelBook : public Strategy
{
public:
   AUTO_GEN_NEW_SHARED_PTR(NovelBook)
   void handle(double money) override
   {
      std::cout << "正在购买语言类图书,有10元优惠\n最终价格为:" << money - 10.0
                << "\n";
      std::cout<<"-----------------\n";
   }
};

class Context
{
public:
   using MapType = std::unordered_map<std::string, Strategy::Ptr>;
   MapType::mapped_type &operator[](std::string const &name)
   {
      return strategyMap[name];
   }

private:
   MapType strategyMap;
};

}   // namespace lab3
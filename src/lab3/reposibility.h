#pragma once
#include <fmt/core.h>

#include <memory>

namespace lab3 {
class Handler;
using HandlerPtr = std::shared_ptr<Handler>;

class Handler
{
public:
   virtual ~Handler() = default;
   virtual void       setNext(HandlerPtr const &handler) { next_ = handler; }
   virtual HandlerPtr getNext() { return next_; }
   virtual void       handle(int day) = 0;

private:
   HandlerPtr next_;
};

class Director : public Handler
{
public:
   void handle(int day) override
   {
      // 本身处理
      if (day < 3)
      {
         fmt::print("主任成功审批\n");
         return;
      }
      // 转移职责
      if (auto next = getNext())
      {
         next->handle(day);
         return;
      }
      // 不能处理
      fmt::print("无法处理");
   }
};
class Manager : public Handler
{
public:
   void handle(int day) override
   {
      // 本身处理
      if (day >= 3 && day < 10)
      {
         fmt::print("经理成功审批\n");
         return;
      }
      // 转移职责
      if (auto next = getNext())
      {
         next->handle(day);
         return;
      }
      // 不能处理
      fmt::print("无法处理");
   }
};

class GeneralManager : public Handler
{
public:
   void handle(int day) override
   {
      // 本身处理
      if (day >= 10 && day < 30)
      {
         fmt::print("总经理成功审批\n");
         return;
      }
      // 转移职责
      if (auto next = getNext())
      {
         next->handle(day);
         return;
      }
      // 不能处理
      fmt::print("无法处理");
   }
};
}   // namespace lab3
#pragma once
#include <fmt/core.h>

#include <memory>
#include <vector>

namespace lab3 {
class Observer
{
public:
   using Ptr           = std::shared_ptr<Observer>;
   virtual ~Observer() = default;

   virtual void update(double state) = 0;
};

class Subject
{
public:
   using Ptr          = std::shared_ptr<Subject>;
   virtual ~Subject() = default;
   void attach(Observer::Ptr const& observer) { observers.push_back(observer); }
   void detach(Observer::Ptr const& observer)
   {
      std::erase_if(observers, [&](auto const& ob) { return ob == observer; });
   }
   virtual void notifyAll() = 0;

protected:
   std::vector<Observer::Ptr> observers;
};

class Stock : public Subject
{
public:
   using Ptr         = std::shared_ptr<Stock>;
   ~Stock() override = default;
   static Stock::Ptr    New() { return std::make_shared<Stock>(); }
   [[nodiscard]] double getState() const { return state_; }
   void                 setState(double state)
   {
      state_ = state;
      notifyAll();
   }

   void notifyAll() override
   {
      for (auto&& ob : observers) { ob->update(state_); }
   }

private:
   double state_{};
};

class Stockholder : public Observer
{
public:
   ~Stockholder() override = default;
   static Stockholder::Ptr New() { return std::make_shared<Stockholder>(); }
   Stockholder() { uid = g_uid++; }
   void update(double state) override
   {
      price = state;
      show();
   }
   void show() { fmt::print("uid:{} price:{}\n", uid, price); }

private:
   static int g_uid;
   int        uid;
   double     price{};
};

}   // namespace lab3
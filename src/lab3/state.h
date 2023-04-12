#pragma once
#include <util/autogen.h>

#include <iostream>
#include <memory>

namespace lab3 {

class Context;
using ContextPtr = std::shared_ptr<Context>;

enum HotelState { kAvail, kBooked, kOccupied };

class State
{
public:
   using Ptr                            = std::shared_ptr<State>;
   virtual ~State()                     = default;
   virtual void handle(ContextPtr &ctx) = 0;
};

class Context : public std::enable_shared_from_this<Context>
{
public:
   AUTO_GEN_NEW_SHARED_PTR(Context)

   Context();

   void handle()
   {
      auto self = shared_from_this();
      state_->handle(self);
   }
   void setState(State::Ptr const &state) { state_ = state; }
   int &stateId() { return stateId_; }

private:
   int        stateId_{kAvail};
   State::Ptr state_;
};

class Available : public State
{
public:
   AUTO_GEN_NEW_SHARED_PTR(Available)

   void handle(lab3::ContextPtr &ctx) override;
};

class Booked : public State
{
public:
   AUTO_GEN_NEW_SHARED_PTR(Booked)

   void handle(lab3::ContextPtr &ctx) override;
};

class Occupied : public State
{
public:
   AUTO_GEN_NEW_SHARED_PTR(Occupied)

   void handle(lab3::ContextPtr &ctx) override;
};

}   // namespace lab3
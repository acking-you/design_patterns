#pragma once
#include <iostream>
#include <string>

namespace lab1 {

class ITelevision
{
public:
   virtual ~ITelevision() = default;
   virtual void work()    = 0;

protected:
   std::string brand_;
};

class IRefrigerator
{
public:
   virtual ~IRefrigerator() = default;
   virtual void work()      = 0;

protected:
   std::string brand_;
};

namespace detail {

class TCLTelevision : public ITelevision
{
public:
   ~TCLTelevision() override = default;
   TCLTelevision() { brand_ = "TCLTV"; }
   void work() override { std::cout << brand_ << " is playing!\n"; }
};
class HaierTelevision : public ITelevision
{
public:
   ~HaierTelevision() override = default;
   HaierTelevision() { brand_ = "HaierTV"; }
   void work() override { std::cout << brand_ << " is playing!\n"; }
};

class TCLRefrigerator : public IRefrigerator
{
public:
   ~TCLRefrigerator() override = default;
   TCLRefrigerator() { brand_ = "TCLAir"; }
   void work() override { std::cout << brand_ << " is playing!\n"; }
};

class HaierRefrigerator : public IRefrigerator
{
public:
   ~HaierRefrigerator() override = default;

   HaierRefrigerator() { brand_ = "HaierAir"; }
   void work() override { std::cout << brand_ << " is playing!\n"; }
};

}   // namespace detail

}   // namespace lab1
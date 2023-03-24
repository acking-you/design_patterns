#pragma once
#include <memory>

namespace lab2 {
class CoffeeDecorator;
class Coffee;
using CoffeePtr          = std::shared_ptr<Coffee>;
using CoffeeDecoratorPtr = std::shared_ptr<CoffeeDecorator>;

class Coffee
{
public:
   virtual ~Coffee()      = default;
   virtual double price() = 0;

protected:
   double price_;
};

class CoffeeDecorator : public Coffee

{
public:
   ~CoffeeDecorator() override                        = default;
   virtual CoffeeDecoratorPtr child(CoffeePtr coffee) = 0;

protected:
   CoffeePtr coffee_;
};

class BlueCoffee : public Coffee
{
public:
   BlueCoffee() { price_ = 8; }
   double price() override { return price_; }
};

class NatieCoffee : public Coffee
{
public:
   NatieCoffee() { price_ = 10; }
   double price() override { return price_; }
};

class Milk : public CoffeeDecorator, public std::enable_shared_from_this<Milk>
{
public:
   Milk() { price_ = 2; }
   double price() override
   {
      if (coffee_) { return price_ + coffee_->price(); }
      return price_;
   }
   CoffeeDecoratorPtr child(CoffeePtr coffee) override
   {
      coffee_ = coffee;
      return shared_from_this();
   }
};

class Orange : public CoffeeDecorator, public std::enable_shared_from_this<Orange>
{
public:
   Orange() { price_ = 3; }
   double price() override
   {
      if (coffee_) { return price_ + coffee_->price(); }
      return price_;
   }
   CoffeeDecoratorPtr child(CoffeePtr coffee) override
   {
      coffee_ = coffee;
      return shared_from_this();
   }
};

}   // namespace lab2
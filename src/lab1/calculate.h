#pragma once
#include <iostream>
#include <memory>

namespace lab1 {
class ICalcullate
{
protected:
   float a_{}, b_{};

public:
   virtual ~ICalcullate() = default;
   void         setA(float a) { a_ = a; }
   void         setB(float b) { b_ = b; }
   virtual void process() = 0;
};

namespace detail {
inline void print(double v) { std::cout << "运算结果为：" << v << "\n"; }
class Add : public ICalcullate
{
public:
   Add()           = default;
   ~Add() override = default;
   void process() override { print(a_ + b_); }
};

class Sub : public ICalcullate
{
public:
   ~Sub() override = default;
   void process() override { print(a_ - b_); }
};

class Mul : public ICalcullate
{
public:
   ~Mul() override = default;
   void process() override { print(a_ * b_); }
};

class Div : public ICalcullate
{
public:
   ~Div() override = default;
   void process() override
   {
      if (b_ == 0.0)
      {
         std::cout << "被除数不能为0！\n";
         return;
      }

      print(a_ / b_);
   }
};
}   // namespace detail
}   // namespace lab1

#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace lab2 {
namespace detail {
class Ability
{
public:
   virtual void work() = 0;
};
}   // namespace detail

using AbilityPtr = std::unique_ptr<detail::Ability>;

class Bird
{
public:
   virtual ~Bird()     = default;
   virtual void work() = 0;

protected:
   std::string             name;
   std::vector<AbilityPtr> abilities;
};

using BirdPtr = std::unique_ptr<Bird>;

namespace detail {
// 能力实现
struct CanFly : public Ability
{
   void work() override { std::cout << "能飞行"; }
};
struct NotCanFly : public Ability
{
   void work() override { std::cout << "不能飞行"; }
};
struct NotCanSwim : public Ability
{
   void work() override { std::cout << "不能游泳"; }
};
struct CanSwim : public Ability
{
   void work() override { std::cout << "能游泳"; }
};

// 鸽子实现
class Dove : public Bird
{
public:
   ~Dove() override = default;
   Dove()
   {
      name = "鸽子";
      abilities.push_back(std::make_unique<CanFly>());
      abilities.push_back(std::make_unique<NotCanSwim>());
   }
   void work() override
   {
      std::cout << name << ":\n";
      for (auto&& a : abilities)
      {
         a->work();
         std::cout << " ";
      }
      std::cout << "\n------------------\n";
   }
};

// 老鹰实现
class Eagle : public Bird
{
public:
   ~Eagle() override = default;
   Eagle()
   {
      name = "老鹰";
      abilities.push_back(std::make_unique<CanFly>());
      abilities.push_back(std::make_unique<NotCanSwim>());
   }
   void work() override
   {
      std::cout << name << ":\n";
      for (auto&& a : abilities)
      {
         a->work();
         std::cout << " ";
      }
      std::cout << "\n------------------\n";
   }
};

// 企鹅实现
class Penguin : public Bird
{
public:
   ~Penguin() override = default;
   Penguin()
   {
      name = "企鹅";
      abilities.push_back(std::make_unique<NotCanFly>());
      abilities.push_back(std::make_unique<CanSwim>());
   }
   void work() override
   {
      std::cout << name << ":\n";
      for (auto&& a : abilities)
      {
         a->work();
         std::cout << " ";
      }
      std::cout << "\n------------------\n";
   }
};
}   // namespace detail

// 工厂方法实现
struct Factory
{
   virtual BirdPtr create() = 0;
};

struct DoveFactory : public Factory
{
   BirdPtr create() override { return std::make_unique<detail::Dove>(); }
};

struct EagleFactory : public Factory
{
   BirdPtr create() override { return std::make_unique<detail::Eagle>(); }
};

struct PenguinFactory : public Factory
{
   BirdPtr create() override { return std::make_unique<detail::Penguin>(); }
};
}   // namespace lab2
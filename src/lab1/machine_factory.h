#pragma once
#include <memory>

#include "machine.h"

namespace lab1 {
class FactoryMachine;
using TelevisionPtr   = std::unique_ptr<ITelevision>;
using RefrigeratorPtr = std::unique_ptr<IRefrigerator>;
using FactoryPtr      = std::unique_ptr<FactoryMachine>;

class FactoryMachine
{
public:
   virtual ~FactoryMachine()                    = default;
   virtual TelevisionPtr   createTelevision()   = 0;
   virtual RefrigeratorPtr createRefrigerator() = 0;
};

class HaierFactory : public FactoryMachine
{
public:
   ~HaierFactory() override = default;
   TelevisionPtr createTelevision() override
   {
      return std::make_unique<detail::HaierTelevision>();
   }
   RefrigeratorPtr createRefrigerator() override
   {
      return std::make_unique<detail::HaierRefrigerator>();
   }
};

class TCLFactory : public FactoryMachine
{
public:
   ~TCLFactory() override = default;
   TelevisionPtr createTelevision() override
   {
      return std::make_unique<detail::TCLTelevision>();
   }
   RefrigeratorPtr createRefrigerator() override
   {
      return std::make_unique<detail::TCLRefrigerator>();
   }
};

}   // namespace lab1

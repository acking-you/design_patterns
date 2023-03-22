#pragma once
#include <memory>

#include "calculate.h"

namespace lab1 {
class FactoryCalculate;

using CalculatePtr = std::unique_ptr<ICalcullate>;
using FactoryPtr = std::unique_ptr<FactoryCalculate>;

class FactoryCalculate
{
public:
   virtual ~FactoryCalculate() = default;
   virtual CalculatePtr create() = 0;
};

class AddFactory : public FactoryCalculate
{
public:
   ~AddFactory() override = default;
   CalculatePtr create() override { return std::make_unique<detail::Add>(); }
};

class SubFactory : public FactoryCalculate
{
public:
   ~SubFactory() override = default;
   CalculatePtr create() override { return std::make_unique<detail::Sub>(); }
};

class MulFactory : public FactoryCalculate
{
public:
   ~MulFactory() override = default;
   CalculatePtr create() override { return std::make_unique<detail::Mul>(); }
};

class DivFactory : public FactoryCalculate
{
public:
   ~DivFactory() override = default;
   CalculatePtr create() override { return std::make_unique<detail::Div>(); }
};

}   // namespace lab1
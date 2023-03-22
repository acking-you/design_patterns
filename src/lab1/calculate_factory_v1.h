#pragma once
#include <memory>

#include "calculate.h"

namespace lab1 {

using CalculatePtr = std::unique_ptr<ICalcullate>;

class CalculateFactory
{
public:
   static CalculatePtr GetInstance(std::string op);
};
}   // namespace lab1

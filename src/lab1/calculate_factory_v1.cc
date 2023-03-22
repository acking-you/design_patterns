#include <string>

#include "calculate_factory_v1.h"
using namespace lab1;

CalculatePtr CalculateFactory::GetInstance(std::string op)
{
   if(op.size() != 1){
      return nullptr;
   }
   switch (op.back())
   {
      case '+':
         return std::make_unique<detail::Add>();
      case '-':
         return std::make_unique<detail::Sub>();
      case '*':
         return std::make_unique<detail::Mul>();
      case '/':
         return std::make_unique<detail::Div>();
      default:
         return nullptr;
   }
}




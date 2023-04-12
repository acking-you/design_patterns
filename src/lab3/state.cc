#include "state.h"

using namespace lab3;

void Available::handle(ContextPtr &ctx)
{
   std::cout << "当前处于空闲状态,可以预定和入住\n";
   std::cout << "输入1预定,输入2入住\n";
   std::cin >> ctx->stateId();
   if (std::cin.fail()) { ctx->stateId() = -1; }
   switch (ctx->stateId())
   {
      case kBooked:
         ctx->setState(Booked::New());
         std::cout << "预定成功切换状态到已预定\n";
         break;
      case kOccupied:
         ctx->setState(Occupied::New());
         std::cout << "入住成功切换状态到已入住\n";
         break;
      default: std::cout << "无效输入\n";
   }
}

void Booked::handle(ContextPtr &ctx)
{
   std::cout << "当前处于已预定状态,可以取消预定和入住\n";
   std::cout << "输入0取消预定,输入2入住\n";
   std::cin >> ctx->stateId();
   if (std::cin.fail()) { ctx->stateId() = -1; }
   switch (ctx->stateId())
   {
      case kAvail:
         ctx->setState(Available::New());
         std::cout << "取消预定成功切换状态到空闲\n";
         break;
      case kOccupied:
         ctx->setState(Occupied::New());
         std::cout << "入住成功切换状态到已入住\n";
         break;
      default: std::cout << "无效输入\n";
   }
}

void Occupied::handle(ContextPtr &ctx)
{
   std::cout << "当前处于已入住状态,可以退房\n";
   std::cout << "输入0退房\n";
   std::cin >> ctx->stateId();
   if (std::cin.fail()) { ctx->stateId() = -1; }
   switch (ctx->stateId())
   {
      case kAvail:
         ctx->setState(Available::New());
         std::cout << "退房成功切换状态到空闲\n";
         break;
      default: std::cout << "无效输入\n";
   }
}
Context::Context() { setState(Available::New()); }

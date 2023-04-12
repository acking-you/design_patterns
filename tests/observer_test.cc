#include <lab3/observer.h>
using namespace lab3;

int main()
{
   Stock::Ptr stock = Stock::New();
   fmt::print("------添加订阅者-------\n");
   for (int i = 0; i < 10; i++)
   {
      Observer::Ptr ob1 = Stockholder::New();
      stock->attach(ob1);
   }
   fmt::print("-------初次更新--------\n");
   stock->setState(100);
   fmt::print("--------股票价格变更--------\n");
   stock->setState(101.8);
}
#include <fmt/core.h>
#include <lab2/decorator_1.h>

using namespace lab2;

int main()
{
   auto blueCoffee  = std::make_shared<BlueCoffee>();
   auto natieCoffee = std::make_shared<NatieCoffee>();

   CoffeeDecoratorPtr milk   = std::make_shared<Milk>();
   CoffeeDecoratorPtr orange = std::make_shared<Orange>();

   milk->child(blueCoffee);
   fmt::print("加了牛奶的蓝山咖啡:{}元\n", milk->price());
   orange->child(natieCoffee);
   fmt::print("加了橙汁的拿铁咖啡:{}元\n", orange->price());
   milk->child(orange);
   fmt::print("加了橙汁和牛奶的拿铁咖啡:{}元\n", milk->price());
   milk->child(orange->child(blueCoffee));
   fmt::print("加了橙汁和牛奶的蓝山咖啡:{}元\n", milk->price());
}
#include <lab3/reposibility.h>

#include <iostream>
using namespace lab3;

int main(){
   auto director = std::make_shared<Director>();
   auto manager = std::make_shared<Manager>();
   auto generalManager = std::make_shared<GeneralManager>();
   director->setNext(manager);
   manager->setNext(generalManager);

   fmt::print("请输入需要请假的天数\n");
   int x;
   std::cin>>x;
   director->handle(x);
}
#include <lab1/calculate_factory_v2.h>

#include <string>

using namespace lab1;

int main()
{
   std::string buf;
   std::string x_buf{};
   char*       pos{};
   int         times{};
   while (true)
   {
      std::cout << "--------------------------------------\n";
      std::cout << "第" << ++times << "次计算\n";
   left:
      std::cout << "请输入一个数：\n";
      std::cin >> buf;
      auto leftNum = std::strtof(buf.data(), &pos);
      if (pos != (buf.c_str()+buf.size()))
      {
         std::cout << "请输入数字！\n";
         goto left;
      }

   op:
      std::cout << "请输入+-*/任意字符：\n";
      std::cin >> x_buf;
      if (x_buf == "q") { break; }
      if (x_buf.size() != 1)
      {
         std::cout << "非法的输入，请输入一个字符！\n";
         goto op;
      }
      auto factory = FactoryPtr();
      switch (x_buf.back())
      {
         case '+': factory = std::make_unique<AddFactory>(); break;
         case '-': factory = std::make_unique<SubFactory>(); break;
         case '*': factory = std::make_unique<MulFactory>(); break;
         case '/': factory = std::make_unique<DivFactory>(); break;
         default:
            std::cout << "运算符必须为+-*/任意一种！请重新输入\n";
            goto op;
      }
      auto instance = factory->create();

   right:
      std::cout << "请输入一个数：\n";
      buf.clear();
      std::cin >> buf;
      auto rightNum = std::strtof(buf.data(), &pos);
      if (pos != (buf.c_str()+buf.size()))
      {
         std::cout << "请输入数字！\n";
         goto right;
      }

      instance->setA(leftNum);
      instance->setB(rightNum);
      instance->process();
   }
}

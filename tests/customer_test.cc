#include <fmt/core.h>
#include <lab1/customer.h>

using namespace lab1;

void printCustom(Customer const& customer)
{
   auto addr = customer.getAddr<AddressPtr>();
   fmt::print("客户姓名：{}，年龄：{}，地址：{}，邮编：{}\n",
              customer.getName<std::string>(), customer.getAge<int>(),
              addr->addr_, addr->zipCode_);
}

int main()
{
   Customer customer;
   customer.setName("张三");
   customer.setAge(20);
   auto addr      = std::make_shared<Address>();
   addr->addr_    = "开福区洪山路98号";
   addr->zipCode_ = 414000;
   customer.setAddr(addr);
   fmt::print("原对象：\n");
   printCustom(customer);
   fmt::print("浅克隆：\n");
   auto clone = customer.clone();
   printCustom(clone);
   fmt::print("--------------修改原对象地址和姓名后-----------------\n");
   addr->addr_ = "长沙学院";
   customer.setName("李四");
   fmt::print("原对象：\n");
   printCustom(customer);
   fmt::print("浅克隆：\n");
   printCustom(customer);
   fmt::print("浅克隆和原对象肯定不是同一对象，在C++"
              "里两者都是值对象，而不是所谓引用或指针对象\n");
   fmt::print("浅克隆和原对象中的指针是否值相同？{}\n",
              clone.getAddr<AddressPtr>() == customer.getAddr<AddressPtr>()
                ? "ture"
                : "false");

   fmt::print("--------------原对象和深克隆对象信息-----------------\n");
   fmt::print("原对象：\n");
   printCustom(customer);
   fmt::print("深克隆：\n");
   auto deep = customer.deepClone();
   printCustom(deep);
   fmt::print("--------------修改原对象地址后-----------------\n");
   addr->addr_ = "开福区洪山路98号";
   fmt::print("原对象：\n");
   printCustom(customer);
   fmt::print("深克隆：\n");
   printCustom(deep);
   fmt::print("浅克隆和原对象肯定不是同一对象，在C++"
              "里两者都是值对象，而不是所谓引用或指针对象\n");
   fmt::print("浅克隆和原对象中的指针是否值相同？{}\n",
              deep.getAddr<AddressPtr>() == customer.getAddr<AddressPtr>()
                ? "ture"
                : "false");
}

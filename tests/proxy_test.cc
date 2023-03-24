#include <lab2/proxy.h>

using namespace lab2;

int main()
{
   {
      IOrderUpdatePtr orderUpdate =
        std::make_unique<OrderDAOProxy>(UserVO{"王仁鑫"});
      orderUpdate->update(Order{.id           = 1,
                                .productNum   = 100,
                                .productName  = "修改后的产品名",
                                .customerName = "修改后的顾客名"});
   }

   {
      IOrderUpdatePtr orderUpdate =
        std::make_unique<OrderDAOProxy>(UserVO{"邱凡鸢"});
      orderUpdate->update(Order{.id           = 1,
                                .productNum   = 100,
                                .productName  = "修改后的产品名",
                                .customerName = "修改后的顾客名"});
   }

}
#include <lab3/memento.h>

using namespace lab3;

int main()
{
   Caretaker<User> caretaker;
   User            user;
   user.setState(1);
   user.setUsername("username");
   user.setPassword("23242342342");
   user.setPhone("12324324343");
   caretaker.setMemo(user.createMemento());
   fmt::print("修改前:\n");
   user.show();
   fmt::print("修改后:\n");
   user.setUsername("hhhhh");
   user.show();
   fmt::print("还原后:\n");
   auto memo = caretaker.getMemo(user.getState());
   if (memo)
   {
      fmt::print("还原点存在,成功还原为:\n");
      user.restoreMemento(memo.value());
      user.show();
   }
   else { fmt::print("还原点不存在!\n"); }
}
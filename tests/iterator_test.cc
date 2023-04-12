#include <lab3/iterator.h>
using namespace lab3;

int main()
{
   List<Channel> list;
   list.add({"cctv1"});
   list.add({"cctv2"});
   list.add({"cctv3"});
   list.add({"cctv4"});
   list.add({"cctv5"});
   list.add({"cctv6"});
   list.add({"cctv7"});
   auto showIter = [&]() {
      auto iter = list.iterator();
      while (iter->hasNext())
      {
         auto& item = iter->next();
         item.show();
      }
   };
   // test iterator
   {
      showIter();
   }
   // test remove
   {
      auto iter = list.iterator();
      while (iter->hasNext())
      {
         auto& item = iter->peek();
         // do remove
         if (item.getName() == "cctv1") { iter->remove(); }
         else { iter->next(); }
      }
      std::cout<<"--------------删除后--------\n";
      // show
      showIter();
   }
   // test contains
   {
      std::cout << (list.contains({"cctv2"}) ? "cctv2存在" : "cctv2不存在")
                << "\n";
   }
   // test clear
   {
      list.clear();
      showIter();
   }
}
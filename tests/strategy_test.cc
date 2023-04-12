#include <lab3/strategy.h>
using namespace lab3;

int main(){
   Context ctx;
   ctx["computer"] = ComputerBook::New();
   ctx["language"] = LanguageBook::New();
   ctx["novel"] = NovelBook::New();

   std::cout<<"一本原价100元的计算机类书籍\n";
   auto computer = ctx["computer"];
   if(computer){
      computer->handle(100);
   }
   std::cout<<"一本原价100元的语言类书籍\n";
   auto language = ctx["language"];
   if(language){
      language->handle(100);
   }
   std::cout<<"一本原价100元的小说类书籍\n";
   auto novel = ctx["novel"];
   if(novel){
      novel->handle(100);
   }
}
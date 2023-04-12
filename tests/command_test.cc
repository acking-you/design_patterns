#include <lab3/command.h>
using namespace lab3;

int main(){
   auto create = CommandImpl<Create>::New();
   auto open = CommandImpl<Open>::New();
   auto save = CommandImpl<Save>::New();
   Invoker invoker;
   invoker["create"] = create;
   invoker["open"] = open;
   invoker["save"] = save;

   invoker.execute("create");
   invoker.execute("open");
   invoker.execute("save");
}
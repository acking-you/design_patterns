#include <lab1/machine_factory.h>

using namespace lab1;

int main()
{
   FactoryPtr tclFactory   = std::make_unique<TCLFactory>();
   FactoryPtr haierFactory = std::make_unique<HaierFactory>();

   auto tclRef   = tclFactory->createRefrigerator();
   auto tclTv    = tclFactory->createTelevision();
   auto haierRef = haierFactory->createRefrigerator();
   auto haierTv  = haierFactory->createTelevision();

   tclRef->work();
   tclTv->work();
   haierRef->work();
   haierTv->work();
}
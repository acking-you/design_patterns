#include <lab2/bridge.h>

using namespace lab2;

int main()
{
   DoveFactory    doveFactory;
   EagleFactory   eagleFactory;
   PenguinFactory penguinFactory;
   auto           dove    = doveFactory.create();
   auto           eagle   = eagleFactory.create();
   auto           penguin = penguinFactory.create();
   dove->work();
   eagle->work();
   penguin->work();
}
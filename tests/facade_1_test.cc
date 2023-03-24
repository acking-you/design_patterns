#include <lab2/facade_1.h>
using namespace lab2;

int main()
{
   MainFrame mainFrame;
   while (!mainFrame.on()){
      std::cout<<"---------------------\n";
   }
}
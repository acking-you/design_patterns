#include <lab3/state.h>
using namespace lab3;
#define MAC \
sdfds       \
     dsfdsfdfdsfdsafdf \


int main(){
   auto ctx = Context::New();
   unsigned char x{};
   while(x != 'q'){
      ctx->handle();
      getchar();
      std::cout<<"------输入 'q' 可退出,否则继续------\n";
      x = getchar();
   }
}
#include <lab2/facade_2.h>

using namespace lab2;

int main()
{
   EncryptFile encryptFile(BASE_DIR "/assets/no_encrypt.txt",
                           BASE_DIR "/assets/encrypt.txt");
   encryptFile.encrypt();
}
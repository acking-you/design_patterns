#pragma once
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include "../util/picosha2.h"

namespace lab2 {
class EncryptFile;
namespace detail {
class ReadFile
{
public:
   ReadFile(std::string_view path) : filepath(path) {}
   std::string read()
   {
      std::ifstream ifs(filepath);
      return std::string(std::istreambuf_iterator<char>(ifs),
                         std::istreambuf_iterator<char>());
   }

private:
   std::string filepath;
};

class SaveFile
{
public:
   SaveFile(std::string_view path) : filepath(path) {}
   void save(std::string const& data)
   {
      std::ofstream ofs(filepath);
      ofs << data;
   }

private:
   std::string filepath;
};

class Encrypt
{
public:
   friend class lab2::EncryptFile;
   std::string encrypt()
   {
      std::vector<unsigned char> hash(picosha2::k_digest_size);
      picosha2::hash256(data.begin(), data.end(), hash.begin(), hash.end());
      return picosha2::bytes_to_hex_string(hash.begin(), hash.end());
   }

private:
   std::string data;
};
}   // namespace detail
class EncryptFile
{
public:
   EncryptFile(std::string_view srcPath, std::string_view destPath)
     : reader_(srcPath), save_(destPath)
   {
   }
   void encrypt()
   {
      encrypt_.data = reader_.read();
      save_.save(encrypt_.encrypt());
   }

private:
   detail::ReadFile reader_;
   detail::SaveFile save_;
   detail::Encrypt  encrypt_;
};

}   // namespace lab2
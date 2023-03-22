#pragma once
#include <util/autogen.h>

#include <memory>
#include <string>

namespace lab1 {
struct Address;
using AddressPtr = std::shared_ptr<Address>;

template <typename T>
class IClone
{
public:
   virtual auto clone() -> T     = 0;
   virtual auto deepClone() -> T = 0;
};

struct Address
{
   int         zipCode_;
   std::string addr_;
};



class Customer : public IClone<Customer>
{
public:

   Customer clone() override { return *this; }
   Customer deepClone() override
   {
      Customer ret = *this;
      ret.addr_    = std::make_shared<Address>();
      (*ret.addr_) = *addr_;
      return ret;
   }
   // auto generate getter&setter by macro
   AUTO_GEN_GETTER_SETTER(age_, Age, name_, Name, addr_, Addr)
private:
   int         age_{};
   std::string name_;
   AddressPtr  addr_;
};

}   // namespace lab1
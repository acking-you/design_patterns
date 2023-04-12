#pragma once
#include <fmt/core.h>
#include <util/autogen.h>

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

namespace lab3 {

template <typename T>
struct Memento
{
   using Ptr = std::shared_ptr<T>;

   int state{};
   Ptr backup;
};

template <typename T>
class Caretaker
{
public:
   using MementoType = Memento<T>;

   auto getMemo(int state) -> std::optional<MementoType>
   {
      auto ret = memoMap.find(state);
      if (ret == memoMap.end()) { return {}; }
      return ret->second;
   }

   void setMemo(MementoType&& memo) { memoMap[memo.state] = std::move(memo); }

private:
   std::unordered_map<int, MementoType> memoMap;
};

class User
{
public:
   AUTO_GEN_GETTER_SETTER(state, State, username, Username, password, Password)


   void show()
   {
      fmt::print("state:{} username:{} password:{} phone:{}\n", state, username,
                 password, phone);
   }

   Memento<User> createMemento()
   {
      Memento<User> memo;
      memo.state  = state;
      memo.backup = std::make_shared<User>(*this);
      return std::move(memo);
   };

   void restoreMemento(const Memento<User>& memo)
   {
      state = memo.state;
      *this = *memo.backup;
   }

private:
   int         state;
   std::string username;
   std::string password;
   std::string phone;
};

}   // namespace lab3
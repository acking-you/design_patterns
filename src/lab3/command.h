#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

namespace lab3 {
class Command;
class Receiver;
using CommandPtr  = std::shared_ptr<Command>;
using ReceiverPtr = std::shared_ptr<Receiver>;
class Receiver
{
public:
   virtual void run() = 0;
};
class Command
{
public:
   virtual void execute() = 0;

protected:
   ReceiverPtr receiver_;
};

class Create : public Receiver
{
   void run() override { std::cout << "创建了一个文件\n"; }
};

class Open : public Receiver
{
   void run() override { std::cout << "打开了一个文件\n"; }
};

class Save : public Receiver
{
   void run() override { std::cout << "保存了一个文件\n"; }
};

template <typename T>
class CommandImpl : public Command
{
public:
   CommandImpl() { receiver_ = std::make_shared<T>(); }
   void              execute() override { receiver_->run(); }
   static CommandPtr New() { return std::make_shared<CommandImpl>(); }
};

class Invoker
{
public:
   using map_t = std::unordered_map<std::string, CommandPtr>;
   map_t::mapped_type& operator[](std::string const& key)
   {
      return commands_[key];
   }
   void erase(std::string const& key) { commands_.erase(key); }

   void execute(std::string const& key)
   {
      auto it = commands_.find(key);
      if (it == commands_.end()) { return; }
      it->second->execute();
   }

private:
   map_t commands_;
};

}   // namespace lab3
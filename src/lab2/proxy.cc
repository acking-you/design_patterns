#include "proxy.h"
#include <fmt/format.h>

using namespace ejson;

namespace lab2::detail {
std::array<Order, 3> s_orders{
  Order{.id           = 1,
        .productNum   = 1000,
        .productName  = "小米手机",
        .customerName = "邱凡鸢"},
  Order{.id           = 2,
        .productNum   = 1000,
        .productName  = "特斯拉",
        .customerName = "王仁鑫"},
  Order{.id           = 3,
        .productNum   = 1000,
        .productName  = "ChatGPT激活码",
        .customerName = "王仁鑫"},
};
std::array<User, 2> s_users{
  User{.username = "邱凡鸢", .password = "12345"},
  User{.username = "王仁鑫", .password = "12345"},
};
}   // namespace lab2::detail

void lab2::OrderDAOProxy::update(lab2::Order newOrder)
{
   auto userDao = std::make_unique<UserDAO>();
   auto user    = userDao->queryByName(user_.username);
   auto order   = order_->queryById(newOrder.id);
   if (!user || !order)
   {
      fmt::print("用户或订单不存在,无法对订单进行修改\n");
      return;
   }
   if (order.value().customerName != user_.username)
   {
      fmt::print("该订单不属于该用户,无法对订单进行修改\n");
      return;
   }
   order_->update(newOrder);
}

std::optional<lab2::User> lab2::UserDAO::queryByName(std::string_view name)
{
   std::optional<lab2::User> ret;
   for (auto&& user : detail::s_users)
   {
      if (user.username == name)
      {
         ret = user;
         break;
      }
   }
   return ret;
}

void lab2::OrderDAO::update(lab2::Order newOrder)
{
   for (auto&& order : detail::s_orders)
   {
      if (order.id == newOrder.id)
      {
         fmt::print("更新订单成功:\n原数据:{}\n更改后:{}\n",
                    Parser::ToJSON(order), Parser::ToJSON(newOrder));
         order = newOrder;
         break;
      }
   }
}
std::optional<lab2::Order> lab2::OrderDAO::queryById(int id)
{
   std::optional<lab2::Order> ret;
   for (auto&& order : detail::s_orders)
   {
      if (order.id == id)
      {
         ret = order;
         break;
      }
   }
   return ret;
}

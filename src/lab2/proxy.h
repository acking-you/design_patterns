#pragma once
#include <array>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <ejson/parser.h>

namespace lab2 {
struct Order;
struct User;
namespace detail {
extern std::array<Order, 3> s_orders;
extern std::array<User, 2>  s_users;
}   // namespace detail

struct Order
{
   int         id;
   int         productNum;
   std::string productName;
   std::string customerName;
};

AUTO_GEN_NON_INTRUSIVE(lab2::Order, id, productNum, productName, customerName)

struct IOrderUpdate
{
   virtual ~IOrderUpdate()             = default;
   virtual void update(Order newOrder) = 0;
};
using IOrderUpdatePtr = std::unique_ptr<IOrderUpdate>;

struct IOrder : public IOrderUpdate
{
   ~IOrder() override                             = default;
   virtual std::optional<Order> queryById(int id) = 0;
};
using IOrderPtr = std::unique_ptr<IOrder>;

struct OrderDAO : public IOrder
{
   void                 update(Order newOrder) override;
   std::optional<Order> queryById(int id) override;
};

struct User
{
   std::string username;
   std::string password;
};

struct IUser
{
   virtual std::optional<User> queryByName(std::string_view name) = 0;
};
using IUserPtr = std::unique_ptr<IUser>;

struct UserDAO : public IUser
{
   std::optional<User> queryByName(std::string_view name) override;
};

struct UserVO
{
   std::string username;
};

class OrderDAOProxy : public IOrderUpdate
{
public:
   explicit OrderDAOProxy(UserVO vo)
     : order_(new OrderDAO), user_(std::move(vo))
   {
   }

   void update(Order newOrder) override;

private:
   UserVO    user_;
   IOrderPtr order_;
};

}   // namespace lab2
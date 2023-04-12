#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace lab3 {
namespace detail {
template <typename T>
using iterator = std::vector<T>::iterator;
}

template <typename T>
class Iterator
{
public:
   using Ptr                      = std::unique_ptr<Iterator<T>>;
   virtual ~Iterator()            = default;
   virtual auto hasNext() -> bool = 0;
   virtual auto next() -> T&      = 0;
   virtual auto peek() -> T&      = 0;
   virtual void remove()          = 0;
};

template <typename T>
class Iterable
{
public:
   virtual ~Iterable()                         = default;
   virtual auto iterator() -> Iterator<T>::Ptr = 0;
};

template <typename T>
class Collection
{
public:
   virtual ~Collection()                = default;
   virtual void add(T const& item)      = 0;
   virtual bool remove(int index)       = 0;
   virtual void clear()                 = 0;
   virtual bool contains(T const& item) = 0;
};

template <typename T>
class ListIterator : public Iterator<T>
{
public:
   ListIterator(std::vector<T>& items, detail::iterator<T> iter)
     : items_(items), iter_(iter)
   {
   }
   ~ListIterator() override = default;
   bool hasNext() override { return iter_ != items_.end(); }
   T&   peek() override
   {
      assert(iter_ != items_.end());
      return *iter_;
   }
   T& next() override
   {
      assert(iter_ != items_.end());
      return *(iter_++);
   }

   void remove() override
   {
      assert(iter_ != items_.end());
      iter_ = items_.erase(iter_);
   }

private:
   std::vector<T>&     items_;
   detail::iterator<T> iter_;
};

template <typename T>
class List : public Collection<T>, public Iterable<T>
{
public:
   using IteratorPtr = typename Iterator<T>::Ptr;

   ~List() override = default;
   void add(T const& item) override { items_.push_back(item); }
   bool remove(int index) override
   {
      if (items_.size() <= index) { return false; }
      items_.erase(items_.begin() + index);
      return true;
   }
   void clear() override { items_.clear(); }
   bool contains(T const& item) override
   {
      auto it = std::find_if(items_.begin(), items_.end(),
                             [&](const auto& cmp) { return item == cmp; });
      return it != items_.end();
   }

   typename Iterator<T>::Ptr iterator() override
   {
      return typename Iterator<T>::Ptr(new ListIterator<T>{items_, items_.begin()});
   }

private:
   std::vector<T> items_;
};

class Channel
{
public:
   Channel(std::string name) : name_(std::move(name)) {}
   std::string getName() { return name_; }
   void show() { std::cout << "成功切换到频道:" << name_ << '\n'; }
   bool operator==(Channel const& chan) const { return chan.name_ == name_; }

private:
   std::string name_;
};

}   // namespace lab3
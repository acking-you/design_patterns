#pragma once
#include <memory>
#include <QtWidgets>

namespace lab2 {

class Component
{
public:
   virtual ~Component() = default;
   virtual void show()  = 0;

protected:
   friend class ScrollBar;
   friend class Transparent;
   QWidget *widget_{};
};

class ViewComponent : public Component
{
public:
   ViewComponent() { widget_ = new QWidget(); }
   void show() override { widget_->show(); }
};

class ComponentDecorator : public Component
{
public:
   ~ComponentDecorator() override                      = default;
   virtual ComponentDecorator *child(Component *child) = 0;

protected:
   Component *child_{};
};

class ScrollBar : public ComponentDecorator
{
public:
   ~ScrollBar() override = default;
   ScrollBar() { widget_ = new QWidget(); }

   ComponentDecorator *child(Component *child) override
   {
      child_          = child;
      auto *layout    = new QVBoxLayout;
      auto *scrollbar = new QScrollBar(Qt::Horizontal);
      layout->addWidget(scrollbar);
      layout->addWidget(child->widget_);
      widget_->setWindowOpacity(child->widget_->windowOpacity());
      widget_->setLayout(layout);
      widget_->setGeometry(
        QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, widget_->size(),
                            qApp->desktop()->frameGeometry()));
      return this;
   }

   void show() override { widget_->show(); }
};

class Transparent : public ComponentDecorator
{
public:
   ~Transparent() override = default;
   Transparent() { widget_ = new QWidget(); }

   ComponentDecorator *child(Component *child) override
   {
      child_       = child;
      auto *layout = new QVBoxLayout;
      layout->addWidget(child->widget_);
      widget_->setLayout(layout);
      widget_->setGeometry(
        QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, widget_->size(),
                            qApp->desktop()->frameGeometry()));
      widget_->setWindowOpacity(0.7);
      return this;
   }
   void show() override { widget_->show(); }
};

}   // namespace lab2
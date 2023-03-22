#include <memory>
#include <QMainWindow>
#include <QPushButton>

namespace lab1 {

class SingletonWindow
{
public:
   SingletonWindow() { widget_.setWindowTitle("singleton Widget"); }

   void show() { widget_.show(); }

private:
   QWidget widget_;
};

template <class T>
class Singleton
{
public:
   static T& instance()
   {
      static T instance;
      return instance;
   }
};




class MainWindow
{
public:
   explicit MainWindow(const char* title) : window_(new QMainWindow())
   {
      window_->setWindowTitle(title);
      auto* button = new QPushButton();
      button->setFixedSize({200, 100});
      window_->setFixedSize(550, 500);
      window_->setCentralWidget(button);
      button->setText("显示单例窗口");
      button->clicked();
      QObject::connect(button, &QPushButton::clicked, [&]() {
         Singleton<SingletonWindow>::instance().show();
      });
   }
   void show() { window_->show(); }

private:
   std::unique_ptr<QMainWindow> window_;
};

}   // namespace lab1
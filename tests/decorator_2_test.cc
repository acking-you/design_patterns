#include <lab2/decorator_2.h>
using namespace lab2;

class MainWindow
{
public:
   MainWindow()
   {
      auto* layout = new QHBoxLayout();
      auto* scroll = new QPushButton();
      scroll->setText("显示ScrollBar");
      auto* trans = new QPushButton();
      trans->setText("显示透明窗口");
      auto* sc_tran = new QPushButton();
      sc_tran->setText("显示透明并带有ScrollBar的窗口");
      layout->addWidget(scroll);
      layout->addWidget(trans);
      layout->addWidget(sc_tran);
      widget.setLayout(layout);
      widget.setFixedSize(1000, 800);
      widget.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
                                             widget.size(),
                                             qApp->desktop()->frameGeometry()));
      QObject::connect(scroll, &QPushButton::clicked,
                       [&]() { showScrollBar(); });
      QObject::connect(trans, &QPushButton::clicked,
                       [&]() { showTransparent(); });
      QObject::connect(sc_tran, &QPushButton::clicked,
                       [&]() { showScrollBarTransparent(); });
   }

   static void showScrollBar()
   {
      auto* view   = new ViewComponent();
      auto* scroll = new ScrollBar();
      scroll->child(view);
      scroll->show();
   }

   static void showTransparent()
   {
      auto* view  = new ViewComponent();
      auto* trans = new Transparent();
      trans->child(view);
      trans->show();
   }

   static void showScrollBarTransparent()
   {
      auto* view   = new ViewComponent();
      auto* trans  = new Transparent();
      auto* scroll = new ScrollBar();
      scroll->child(trans->child(view));
      scroll->show();
   }

   void show() { widget.show(); }

private:
   QWidget widget;
};

int main(int argc, char* argv[])
{
   QApplication app(argc, argv);
   MainWindow   w;
   w.show();
   return QApplication::exec();
}

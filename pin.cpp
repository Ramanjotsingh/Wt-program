#include <Wt/WApplication>
#include <Wt/WPen>
#include <Wt/WColor>
#include <Wt/WContainerWidget>
#include <Wt/WPaintedWidget>
#include <Wt/WPaintDevice>
#include <Wt/WBrush>
#include <Wt/WPainter>
#include <Wt/WPushButton>
#include <Wt/WBreak>

using namespace Wt;

class PaintApplication: public WApplication
{
public:

void PaintEvent( Wt::WPaintDevice *paintDevice);
void call();
PaintApplication(const Wt::WEnvironment &env):WApplication(env)
{
setTitle("raman");
WPushButton *b=new WPushButton("ra.",root());

root()->addWidget(new WBreak());
b->clicked().connect(this, &PaintApplication::call);
}
};

void PaintApplication::call() {
PaintEvent(Wt::WPaintDevice *paintDevice);
}

void PaintApplication::PaintEvent(Wt::WPaintDevice *paintDevice)
{
Wt::WPainter painter(paintDevice);
painter.setBrush(Wt::WBrush(Wt::WBrush(Wt::red)));
painter.drawRect(0,0,100,50);
}
PaintApplication::WApplication *createApplication(const WEnvironment& env)
{
return  new PaintApplication(env);
}

int main(int argc,char **argv)
{
return WRun(argc,argv, &createApplication);
}


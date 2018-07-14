#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include "../FindDialog/FindDialog.h"

int main(int argc, char *argv[ ])
{
	QApplication app(argc, argv);

#if 0
	QWidget *window = new QWidget();
	window->setWindowTitle("Enter a Number");

	QSlider *slider = new QSlider( Qt::Horizontal );
	QSpinBox *spinbox = new QSpinBox();
	slider->setRange( 0, 130 );
	spinbox->setRange( 0, 130 );

	QObject::connect( spinbox, SIGNAL( valueChanged( int ) ), slider, SLOT( setValue( int ) ) );
	QObject::connect( slider, SIGNAL( valueChanged( int ) ), spinbox, SLOT( setValue( int ) ) );
	
	spinbox->setValue( 35 );

	QPushButton *pushbutton = new QPushButton("quit");
	QObject::connect( pushbutton, SIGNAL( clicked() ), &app, SLOT( quit() ) );

	QLabel *label = new QLabel( "Hi, jyo" );
	
	QVBoxLayout *layout = new QVBoxLayout;
	QHBoxLayout *layout1 = new QHBoxLayout;	
	layout1->addWidget(label);
	layout1->addWidget(slider);
	layout->addWidget(spinbox);
	layout->addWidget(pushbutton);
	window->setLayout(layout);
	window->setLayout(layout1);

	window->show();
#endif
	FindDialog *xuzhe = new FindDialog();
	xuzhe->show();

	return app.exec();
}

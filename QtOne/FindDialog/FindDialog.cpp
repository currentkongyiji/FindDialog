#include <QtGui>
#include <QHBoxLayout>
#include "FindDialog.h"

FindDialog::FindDialog( QWidget *widget ) : QDialog( widget )
{
	label = new QLabel( tr( "Find &What" ) );
	lineEdit = new QLineEdit;
	label->setBuddy( lineEdit );

	label1 = new QLabel( tr( "Suer to Close the Dialog?" ) );
	yes = new QPushButton( tr( "Yes" ) );
	cannel = new QPushButton( tr( "Cannel" ) );
	
	QHBoxLayout *LandR = new QHBoxLayout;
	LandR->addWidget( yes );
	LandR->addWidget( cannel );

	QVBoxLayout *cannelDialog = new QVBoxLayout;
	cannelDialog->addWidget( label1 );
	cannelDialog->addLayout( LandR );

	QWidget *xuzheDialog = new QWidget;
	xuzheDialog->setLayout( cannelDialog );
	xuzheDialog->setWindowTitle( tr( "Cannel Dialog" ) );
	xuzheDialog->setFixedHeight( xuzheDialog->sizeHint().height() );

	caseCheckBox = new QCheckBox( tr( "Match Case" ) );
	backwardCheckBox = new QCheckBox( tr( "Find Back" ) );

	findButton = new QPushButton( tr( "Find" ) );
	findButton->setDefault( true );
	findButton->setEnabled( false );
	closeButton = new QPushButton( tr( "Close" ) );

	connect( lineEdit, SIGNAL( textChanged( const QString& ) ),
			  this, SLOT( enableFindButton( const QString& ) ) );
	connect( findButton, SIGNAL( clicked() ),
			  this, SLOT( findClicked() ) );
	connect( closeButton, SIGNAL( clicked() ),
			  xuzheDialog, SLOT( show() ) );
	connect( yes, SIGNAL( clicked() ),
		 xuzheDialog, SLOT( close() ) );
	connect( yes, SIGNAL( clicked() ),
		 this, SLOT( close() ) );
	connect( cannel, SIGNAL( clicked() ),
		 xuzheDialog, SLOT( close() ) );

	QHBoxLayout *top = new QHBoxLayout;
	top->addWidget( label );
	top->addWidget( lineEdit );

	QVBoxLayout *left = new QVBoxLayout;
	left->addLayout( top );
	left->addWidget( caseCheckBox );
	left->addWidget( backwardCheckBox );

	QVBoxLayout *right = new QVBoxLayout;
	right->addWidget( findButton );
	right->addWidget( closeButton );
	right->addStretch();
	
	QHBoxLayout *main = new QHBoxLayout;
	main->addLayout( left );
	main->addLayout( right );
	this->setLayout( main );

	this->setWindowTitle( tr( "Find" ) );
	this->setFixedHeight( sizeHint().height() );
}

FindDialog::~FindDialog()
{
	
	delete label;
	delete lineEdit;
	delete caseCheckBox;
	delete backwardCheckBox;
	delete findButton;
	delete closeButton;
	delete yes;
	delete cannel;
}

void FindDialog::findClicked()
{
	QString text = lineEdit->text();

	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : 
							     Qt::CaseInsensitive;

	if( backwardCheckBox->isChecked() )
	{
		emit findNext( text, cs );
	}
	else
	{
		emit findPrevious( text, cs );
	}
}

void FindDialog::enableFindButton( const QString &text )
{
	findButton->setEnabled( !text.isEmpty() );
}



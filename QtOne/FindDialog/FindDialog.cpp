#include <QtGui>
#include <QHBoxLayout>
#include "FindDialog.h"

FindDialog::FindDialog( QWidget *widget ) : QDialog( widget )
{
	label = new QLabel( tr( "Find &What" ) );
	lineEdit = new QLineEdit;
	label->setBuddy( lineEdit );

	caseCheckBox = new QCheckBox( tr( "Match Case" ) );
	backwardCheckBox = new QCheckBox( tr( "Find Back" ) );

	findButton = new QPushButton( tr( "Find" ) );
	closeButton = new QPushButton( tr( "Close" ) );

	connect( lineEdit, SIGNAL( textChanged( const QString& ) ),
			  this, SLOT( enableFindButton( const QString& ) ) );
	connect( findButton, SIGNAL( clicked() ),
			  this, SLOT( findClicked() ) );
	connect( closeButton, SIGNAL( clicked() ),
			  this, SLOT( close() ) );

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



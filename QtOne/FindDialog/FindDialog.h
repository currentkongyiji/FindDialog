#ifndef FINDDIALOG_H_
#define FINDDIALOG_H_

#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class FindDialog : public QDialog
{
	Q_OBJECT
public:
	FindDialog( QWidget* widget = nullptr );
	~FindDialog();
signals:
	void findNext( const QString &str, Qt::CaseSensitivity cs );
	void findPrevious( const QString &str, Qt::CaseSensitivity cs );
private slots:
	void findClicked();
	void enableFindButton( const QString &text );
private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findButton;
	QPushButton *closeButton;
};

#endif




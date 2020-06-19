#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>

#include "solve.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	bool checkValues();

public slots:
	void checkEquathn();
	void solveEquathn();


private:
	Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

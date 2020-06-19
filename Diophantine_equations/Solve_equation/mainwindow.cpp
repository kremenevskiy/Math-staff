#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QRegExp regex("[-]{0,1}[0-9]{1,4}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->aValue->setValidator(validator);
	ui->bValue->setValidator(validator);
	ui->cValue->setValidator(validator);

	connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::checkEquathn);
	connect(ui->solveButton, &QPushButton::clicked, this, &MainWindow::solveEquathn);

	connect(ui->clearButton, &QPushButton::clicked, [&](){
		ui->solvingView->clear();
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::checkEquathn(){
	if(!checkValues()){
		return;
	}

	int a = ui->aValue->text().toInt();
	int b = ui->bValue->text().toInt();
	int c = ui->cValue->text().toInt();

	QString checker = QString::number(a) + "*x +" + QString::number(b) + "*y = " + QString::number(c);
	ui->checkEdit->setText(checker);
}


void MainWindow::solveEquathn(){
	ui->solvingView->clear();
	int a = ui->aValue->text().toInt();
	int b = ui->bValue->text().toInt();
	int c = ui->cValue->text().toInt();

	QString result = Solve::findSolution(a, b , c);
	ui->solvingView->appendPlainText(result);
}


bool MainWindow::checkValues(){
	if(ui->aValue->text().isEmpty() || ui->bValue->text().isEmpty() || ui->cValue->text().isEmpty()){
		QMessageBox::warning(this, "Empty values", "Add values for a, b, c");
		return false;
	}
	else
		return true;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QRegExp regex("[0-9]{1,3}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->NlineEdit->setValidator(validator);

	connect(ui->clearButton, &QPushButton::clicked, [&](){
		ui->additionViewEdit->clear();
		ui->multiplyViewEdit->clear();
	});

	connect(ui->makeButton, &QPushButton::clicked, this, &MainWindow::buildTables);

}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::buildTables(){
	if(ui->NlineEdit->text().isEmpty()){
		QMessageBox::warning(this, "No value for N", "Enter a int num for N");
		return;
	}

	int n = ui->NlineEdit->text().toInt();

	QString addTable = Cayley::buildAddTbl(n);
	QString multyTable = Cayley::buildMultyTbl(n);

	ui->additionViewEdit->appendPlainText(addTable);
	ui->multiplyViewEdit->appendPlainText(multyTable);
}

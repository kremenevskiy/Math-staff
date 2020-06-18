#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QRegExp regex("[-]{0,1}[0-9]{1,8}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->NumberEdit->setValidator(validator);

	connect(ui->decompButton, &QPushButton::clicked, this, &MainWindow::decompose);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::decompose(){
	if(ui->NumberEdit->text().isEmpty()){
		QMessageBox::warning(this, "Empty Number", "Enter a value for the number");
		return;
	}


	llong a = ui->NumberEdit->text().toLongLong();
	QString result = QString::number(a) + " = ";

	if(a < 0){
		result += "-";
		a = -a;
	}

	result += Decompose::decomposeNum(a);

	ui->decompEdit->setText(result);
}


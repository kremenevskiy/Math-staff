#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculate);


	QRegExp regex("[-]{0,1}[0-9]{1,7}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->alineEdit->setValidator(validator);
	ui->blineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::calculate(){
	if(ui->alineEdit->text().isEmpty() || ui->blineEdit->text().isEmpty()){
		QMessageBox::warning(this, "Empty values", "Enter a value for a and b");
	}
	else{
		llong a = ui->alineEdit->text().toLongLong();
		llong b = ui->blineEdit->text().toLongLong();

		QString decomposition = DivRmndr::Decompose(a, b);
		ui->aLabel->setText(QString::number(a) + " = ");
		ui->result->setText(decomposition);
	}
}


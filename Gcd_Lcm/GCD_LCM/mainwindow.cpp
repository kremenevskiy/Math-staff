#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QRegExp regex("[-]{0,1}[0-9]{1,9}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->alineEdit->setValidator(validator);
	ui->blineEdit->setValidator(validator);

	connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::findGCD_LCM);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::findGCD_LCM(){
	if (ui->alineEdit->text().isEmpty() || ui->blineEdit->text().isEmpty()){
		QMessageBox::warning(this, "Empty lines", "Enter values for a and b");
		return;
	}

	llong a = ui->alineEdit->text().toLongLong();
	llong b = ui->blineEdit->text().toLongLong();

	llong gcd = qAbs(Gcd_Lcm::GCD(a, b));
	llong lcm = qAbs(Gcd_Lcm::LCM(a, b));

	ui->GcdEdit->setText(QString::number(gcd));
	ui->LcmEdit->setText(QString::number(lcm));


}


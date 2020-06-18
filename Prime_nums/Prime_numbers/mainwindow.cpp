#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QRegExp regex("[0-9]{1,7}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->NlineEdit->setValidator(validator);

	connect(ui->findNumsButton, &QPushButton::clicked, this, &MainWindow::findPrime);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::findPrime(){
	ui->PrimeNumsText->clear();

	if(ui->NlineEdit->text().isEmpty()){
		QMessageBox::warning(this, "Empty N", "Write value for N");
		return;
	}

	ullong N = ui->NlineEdit->text().toULongLong();

	QVector<char> prime = PrimeNums::findNums(N);

	for(ullong i = 0; i < prime.size(); i++){
		QString primeRow;
		for (int j = 0; j < 5 && i < prime.size(); i++){
			if (prime[i]){
				j++;
				primeRow += QString::number(i) + " ";
			}
		}
		ui->PrimeNumsText->appendPlainText(primeRow + "\n");

	}
}


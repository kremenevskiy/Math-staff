#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QRegExp regex("[a-z]{1,}");
	QRegExpValidator *validator = new QRegExpValidator(regex);
	ui->defaultText->setValidator(validator);
	ui->keyEncr->setValidator(validator);
	ui->code->setValidator(validator);
	ui->keyDecr->setValidator(validator);


	connect(ui->encryptButton, &QPushButton::clicked, this, &MainWindow::encrypt);
	connect(ui->decryptButton, &QPushButton::clicked, this, &MainWindow::decrypt);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::encrypt(){
	if(ui->defaultText->text().isEmpty() || ui->keyEncr->text().isEmpty()){
		QMessageBox::warning(this, "Empty fields", "Fill text and key fields");
		return;
	}

	QString text = ui->defaultText->text();
	QString key = ui->keyEncr->text();

	QString encrypted = Vizhener::encrypt(text, key);
	ui->encrypted->setText(encrypted);
}


void MainWindow::decrypt(){
	if(ui->code->text().isEmpty() || ui->keyDecr->text().isEmpty()){
		QMessageBox::warning(this, "Empty fields", "Fill text and key fields");
		return;
	}

	QString text = ui->code->text();
	QString key = ui->keyDecr->text();

	QString decrypted = Vizhener::decrypt(text, key);
	ui->decrypted->setText(decrypted);
}

#include "ShowAbsTractTableModel.h"
#include "ui_ShowAbsTractTableModel.h"
#include<QHash>

ShowAbsTractTableModel::ShowAbsTractTableModel(QWidget *parent)
	: QWidget(parent),ui(new Ui::ShowAbsTractTableModel)
{
	ui->setupUi(this);
	QHash<QString, double> data;
	data["USD"] = 1.0000;
	data["CNY"] = 0.1628;
	data["GBP"] = 1.5361;
	data["EUR"] = 1.2992;
	data["HKD"] = 0.1289;
	data["Test"] = 0.0;
	theModel = new AbstractTableModel(this);
	theModel->setCurrencyMap(data);
	ui->tableView->setModel(theModel);
}

ShowAbsTractTableModel::~ShowAbsTractTableModel()
{
	delete ui;
}

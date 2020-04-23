#pragma once

#include <QtWidgets/QMainWindow>
#include<QStringListModel>
#include<QSortFilterProxyModel>
#include "ui_SortFilterProxyModel.h"

class SortFilterProxyModel : public QMainWindow
{
	Q_OBJECT

public:
	SortFilterProxyModel(QWidget *parent = Q_NULLPTR);

private:
	void init();

	Ui::SortFilterProxyModelClass ui;
	QStringListModel *sourceModel_;
	QSortFilterProxyModel *proxyModel_;

private slots:
	void on_lineEdit_textChanged(const QString&format);
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SortFilterProxyModel.h"

class SortFilterProxyModel : public QMainWindow
{
	Q_OBJECT

public:
	SortFilterProxyModel(QWidget *parent = Q_NULLPTR);

private:
	Ui::SortFilterProxyModelClass ui;
};

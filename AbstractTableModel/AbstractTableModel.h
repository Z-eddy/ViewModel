#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AbstractTableModel.h"

class AbstractTableModel : public QMainWindow
{
	Q_OBJECT

public:
	AbstractTableModel(QWidget *parent = Q_NULLPTR);

private:
	Ui::AbstractTableModelClass ui;
};

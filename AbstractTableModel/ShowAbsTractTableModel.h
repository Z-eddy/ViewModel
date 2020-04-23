#pragma once

#include <QWidget>
#include "AbstractTableModel.h"
namespace Ui { class ShowAbsTractTableModel; };

class ShowAbsTractTableModel : public QWidget
{
	Q_OBJECT

public:
	ShowAbsTractTableModel(QWidget *parent = Q_NULLPTR);
	~ShowAbsTractTableModel();

private:
	Ui::ShowAbsTractTableModel *ui;
	AbstractTableModel *theModel;
};

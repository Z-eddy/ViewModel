#include "SortFilterProxyModel.h"
#include<QColor>
#include<QRegularExpression>

SortFilterProxyModel::SortFilterProxyModel(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

void SortFilterProxyModel::init()
{
	auto colorNames{ QColor::colorNames() };
	sourceModel_ = new QStringListModel(colorNames,this);
	proxyModel_ = new QSortFilterProxyModel(this);
	proxyModel_->setSourceModel(sourceModel_);
	ui.listView->setModel(proxyModel_);
}

void SortFilterProxyModel::on_lineEdit_textChanged(const QString&format)
{
	QRegularExpression re{ format };
	proxyModel_->setFilterRegularExpression(re);
}

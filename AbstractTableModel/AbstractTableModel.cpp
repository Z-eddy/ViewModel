#include "AbstractTableModel.h"

AbstractTableModel::AbstractTableModel(QObject *parent)
	:QAbstractTableModel(parent)
{
}

AbstractTableModel::~AbstractTableModel()
{
}

void AbstractTableModel::setCurrencyMap(const QHash<QString, double>&data)
{
	this->beginResetModel();//disable����ص�model����,�������ź�modelAboutToBeReset().
	currencyMap = data;
	this->endResetModel();
}

Q_INVOKABLE int AbstractTableModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	return currencyMap.size();
}

Q_INVOKABLE int AbstractTableModel::columnCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	return currencyMap.size();
}

Q_INVOKABLE QVariant AbstractTableModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
	if (!index.isValid()) {
		return QVariant();
	}
	//��������λ��Ϊ����
	if (role==Qt::TextAlignmentRole) {
		return int(Qt::AlignRight | Qt::AlignVCenter);
	}
	else if (role == Qt::DisplayRole) {
		const QString rItem{ currencyAt(index.row()) };
		if (currencyMap.value(rItem) == 0.0) {//������0ʱ,����������Ϊ0
			return QString("####");
		}
		const QString cItem{ currencyAt(index.column()) };
		const double rVal{ currencyMap.value(rItem) };
		const double cVal{ currencyMap.value(cItem) };
		const double val{ rVal / cVal };
		return QString("%1").arg(val, 0, 'f', 4);
	}
	return QVariant();
}

//sectionΪ��ѯ������
Q_INVOKABLE QVariant AbstractTableModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole) {
		return QVariant();
	}
	return currencyAt(section);
}

QString AbstractTableModel::currencyAt(int idx)const
{
	return (currencyMap.cbegin() + idx).key();
}

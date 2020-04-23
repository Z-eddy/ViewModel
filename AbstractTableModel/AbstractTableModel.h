#pragma once

#include<QAbstractTableModel>
#include<QModelIndex>
#include<QVariant>
#include<QHash>
#include<QString>

class AbstractTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	AbstractTableModel(QObject *parent = Q_NULLPTR);
	~AbstractTableModel();

	void setCurrencyMap(const QHash<QString, double>&data);

	//只读重载
	Q_INVOKABLE virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	Q_INVOKABLE virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Q_INVOKABLE virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	//可写重载
	virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
	Q_INVOKABLE virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

	QString currencyAt(int idx)const;


private:
	QHash<QString, double>currencyMap;
};

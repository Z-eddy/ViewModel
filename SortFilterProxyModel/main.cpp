#include "SortFilterProxyModel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SortFilterProxyModel w;
	w.show();
	return a.exec();
}

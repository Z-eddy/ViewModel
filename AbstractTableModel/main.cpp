#include "ShowAbsTractTableModel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ShowAbsTractTableModel w;
	w.show();
	return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QSpinBox>

#include "intarr.h"
#include "simpleintarray.h"
#include "optimisedintarray.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void updateIndex(QSpinBox *indexHolder, QSpinBox *valueHolder, IIntArr &array);
  void updateValue(QSpinBox *indexHolder, QSpinBox *valueHolder, IIntArr &array);

private:
  Ui::MainWindow *ui;

  SimpleIntArray simpleArray;
  OptimisedIntArray optimisedArray;
};

#endif // MAINWINDOW_H

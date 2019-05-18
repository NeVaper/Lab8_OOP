#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Main window setup
  this->setWindowTitle("Lab8");
  this->resize(300, 80);

  // Add tabs for testing two different types of arrays
  auto tabs = new QTabWidget(ui->centralWidget);
  auto simpleArrWidget = new QWidget();
  auto optimisedArrWidget = new QWidget();
  tabs->addTab(simpleArrWidget, "Simple Array");
  tabs->addTab(optimisedArrWidget, "\"Optimised\" Array");
  tabs->setFont(QFont("Calibri", 12));
  tabs->resize(300, 80);

  // Setup tabs with ui elements
    // simple array tab
  auto simpleArrIndexChooser = new QSpinBox(simpleArrWidget);
  simpleArrIndexChooser->setPrefix("Index: ");
  simpleArrIndexChooser->move(10, 10);
  simpleArrIndexChooser->setRange(0, 99999);
  simpleArrIndexChooser->setFont(QFont("Calibri", 14));

  auto simpleArrValueSetter = new QSpinBox(simpleArrWidget);
  simpleArrValueSetter->setPrefix("Value: ");
  simpleArrValueSetter->move(150, 10);
  simpleArrValueSetter->setRange(-99999, 99999);
  simpleArrValueSetter->setFont(QFont("Calibri", 14));

  connect(simpleArrIndexChooser,
      QOverload<int>::of(&QSpinBox::valueChanged),
      [this, simpleArrIndexChooser, simpleArrValueSetter]() {
      this->updateIndex(simpleArrIndexChooser, simpleArrValueSetter, simpleArray);
    });

  connect(simpleArrValueSetter,
      QOverload<int>::of(&QSpinBox::valueChanged),
      [this, simpleArrIndexChooser, simpleArrValueSetter]() {
      this->updateValue(simpleArrIndexChooser, simpleArrValueSetter, simpleArray);
    });

    // the same for optimised array tab
  auto optimisedArrIndexChooser = new QSpinBox(optimisedArrWidget);
  optimisedArrIndexChooser->setPrefix("Index: ");
  optimisedArrIndexChooser->move(10, 10);
  optimisedArrIndexChooser->setRange(0, 99999);
  optimisedArrIndexChooser->setFont(QFont("Calibri", 14));

  auto optimisedArrValueSetter = new QSpinBox(optimisedArrWidget);
  optimisedArrValueSetter->setPrefix("Value: ");
  optimisedArrValueSetter->move(150, 10);
  optimisedArrValueSetter->setRange(-99999, 99999);
  optimisedArrValueSetter->setFont(QFont("Calibri", 14));

  connect(optimisedArrIndexChooser,
      QOverload<int>::of(&QSpinBox::valueChanged),
      [this, optimisedArrIndexChooser, optimisedArrValueSetter]() {
      this->updateIndex(optimisedArrIndexChooser, optimisedArrValueSetter, optimisedArray);
    });

  connect(optimisedArrValueSetter,
      QOverload<int>::of(&QSpinBox::valueChanged),
      [this, optimisedArrIndexChooser, optimisedArrValueSetter]() {
      this->updateValue(optimisedArrIndexChooser, optimisedArrValueSetter, optimisedArray);
    });
}

void MainWindow::updateIndex(QSpinBox *indexHolder, QSpinBox *valueHolder, IIntArr &array) {
  valueHolder->setValue(array.element(indexHolder->value()));
}

void MainWindow::updateValue(QSpinBox *indexHolder, QSpinBox *valueHolder, IIntArr &array) {
  array.setEl(valueHolder->value(), indexHolder->value());
}

MainWindow::~MainWindow() {
  delete ui;
}

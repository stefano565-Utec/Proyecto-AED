#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Segmenttree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buildButton_clicked();
    void on_queryButton_clicked();
    void on_updateButton_clicked();
    void on_deleteButton_clicked();
    void on_updateRangeButton_clicked();

private:
    Ui::MainWindow *ui;
    SegmentTree* segTree = nullptr;
    int size = 0;
    QGraphicsScene* scene;
    void drawTree();
    void drawNode(int node, int l, int r, int x, int y, int dx);
};

#endif // MAINWINDOW_H

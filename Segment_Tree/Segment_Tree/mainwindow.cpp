#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QGraphicsTextItem>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete segTree;
}

void MainWindow::on_buildButton_clicked()
{
    QString input = ui->inputArray->text();
    QStringList nums = input.split(" ", Qt::SkipEmptyParts);
    std::vector<int> arr;

    for (const QString& s : nums) {
        arr.push_back(s.toInt());
    }

    size = arr.size();
    delete segTree;
    segTree = new SegmentTree(size);
    segTree->build(arr);

    ui->result->setText("Árbol construido.");
    drawTree();
}

void MainWindow::on_queryButton_clicked()
{
    if (!segTree) return;
    int l = ui->inputL->value();
    int r = ui->inputR->value();
    int res = segTree->query(l, r);
    ui->result->setText("Suma [" + QString::number(l) + ", " + QString::number(r) + "] = " + QString::number(res));
}

void MainWindow::on_updateButton_clicked()
{
    if (!segTree) return;
    int idx = ui->inputIndex->value();
    int val = ui->inputValue->value();
    segTree->updatePoint(idx, val);
    ui->result->setText("Elemento " + QString::number(idx) + " actualizado a " + QString::number(val));
    drawTree();
}

void MainWindow::on_deleteButton_clicked()
{
    if (!segTree) return;
    int idx = ui->inputIndex->value();
    segTree->deletePoint(idx);
    ui->result->setText("Elemento " + QString::number(idx) + " eliminado");
    drawTree();
}

void MainWindow::on_updateRangeButton_clicked()
{
    if (!segTree) return;
    int l = ui->inputL->value();
    int r = ui->inputR->value();
    int val = ui->inputValue->value();
    segTree->updateRange(l, r, val);
    ui->result->setText("Rango [" + QString::number(l) + ", " + QString::number(r) + "] incrementado en " + QString::number(val));
    drawTree();
}


void MainWindow::drawTree()
{
    if (!segTree || size == 0) return;

    scene->clear();
    drawNode(1, 0, size - 1, 300, 30, 100);
}

void MainWindow::drawNode(int node, int l, int r, int x, int y, int dx)
{
    if (l > r || node >= 4 * size) return;

    int radius = 20;

    // Dibuja el círculo
    scene->addEllipse(x - radius, y - radius, 2 * radius, 2 * radius, QPen(), QBrush(Qt::yellow));

    // Texto con el valor del nodo y el intervalo
    QString label = QString("%1\n[%2,%3]").arg(segTree->query(node, l, r, l, r)).arg(l).arg(r);
    QGraphicsTextItem* t = scene->addText(label);

    // Centrar el texto
    QRectF rect = t->boundingRect();
    t->setPos(x - rect.width() / 2, y - rect.height() / 2);

    if (l == r) return;

    // Posición de hijos
    int mid = (l + r) / 2;
    int childY = y + 60;
    int leftX = x - dx;
    int rightX = x + dx;

    // Líneas a hijos
    scene->addLine(x, y + radius, leftX, childY - radius, QPen(Qt::black));
    scene->addLine(x, y + radius, rightX, childY - radius, QPen(Qt::black));

    drawNode(2 * node, l, mid, leftX, childY, dx / 2);
    drawNode(2 * node + 1, mid + 1, r, rightX, childY, dx / 2);
}


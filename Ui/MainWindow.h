#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpoint.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
#ifdef Q_OS_WIN
    bool mousePressed;
    QPoint prev;
#endif 

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
#ifdef Q_OS_WIN
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
#endif 

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

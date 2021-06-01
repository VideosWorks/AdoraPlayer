#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Base/Namespace.h"
#include "../Chain/Chain.h"

#include <qlist.h>

class Observer;
#ifdef Q_OS_WIN
class WindowMode;
#endif 

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow , public Chain {
    Q_OBJECT

private:
    Ui::MainWindow* ui;

#ifdef Q_OS_WIN
private:
    WindowMode* windowMode;
#endif 

private:
    QList<Observer*> observers;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void request(Request* request);


protected:

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);


private:
    

#ifdef Q_OS_WIN
    void setWindowMode(CurrentWindowMode mode);
#endif 






};
#endif // MAINWINDOW_H

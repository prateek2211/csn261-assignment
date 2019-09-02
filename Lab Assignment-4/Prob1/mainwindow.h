#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trie.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReadCSV(QString filePath);

public slots:
    void OnSearch();

private:
    Ui::MainWindow *ui;
    Trie trie;
};

#endif // MAINWINDOW_H

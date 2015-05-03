#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lexicon.h>
#include <vector>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextCharFormat>
#include <QTextCursor>
#include <wordbreaker.h>
#include <string>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);

  /* void highlightWord (int beg , int end , const QBrush &brush)
   * this method highlight the word starting
   * at position beg and ending at pos end
   * with the color specified by brush
  */
  void highlightWord(int beg , int end ,const QBrush &brush = Qt::yellow);


  const QString getCurrentTextEditWord(QTextCursor &cursor);

  /*
   * bool isValidWord(string word)
   * this method returns true if the word passed to
   * it is a valid word i.e contains only alphanumeric
   * characters and with size larger than 0
  */
  bool isValidWord (string word);

  /* this method returns a vector of all possible
   * corrections to this word */
  vector<string> getCandidates(string word , int ed=EDITDISTANCE);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    
    void on_checkButton_clicked();

    void on_textEdit_cursorPositionChanged();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    Lexicon *lex;
    static const int MAXCANDIDATES = 100;
    static const int EDITDISTANCE = 2;
};

#endif // MAINWINDOW_H

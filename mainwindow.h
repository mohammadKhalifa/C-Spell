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
  void highlightWord(QTextCursor & cursor , const QBrush & brush = Qt::yellow);

  const QString getCurrentTextEditWord(QTextCursor &cursor);

  /* Usage
   * if (isValidWord(word)) ...
   * this method returns true if the word passed to
   * it is a valid word i.e contains only alphanumeric
   * characters and with size larger than 0
  */
  bool isValidWord (string word);

  /* Usage
   * vector<string> vs = getCandidates(word);
   * this method returns a vector of all possible
   * corrections to this word */
  vector<string> getCandidates(string word , int mxEditDistance=MAXEDITDISTANCE);

  /* Usage
   * vector<int> v =  getFirstLetterPositions (text);
   * this method returns a vector of positions of
   * first letter of all sentences in text
   */

  vector<int> getFirstLetterPositions (const string& text);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    
    void on_checkButton_clicked();

    void on_textEdit_cursorPositionChanged();

    void on_actionSave_triggered();

    void on_ignoreButton_clicked();

    void on_replaceButton_clicked();

    void on_caseButton_clicked();

    void on_AddToDicButton_clicked();

    void on_actionReset_triggered();

    void on_actionClear_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    Lexicon *lex;
    WordBreaker *wb;
    static const int MAXCANDIDATES = 25;
    static const int MAXEDITDISTANCE = 2;
};

#endif // MAINWINDOW_H

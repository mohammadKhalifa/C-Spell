#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "edit_distance.h"
#include <QDebug>
// dictionary file name
const string dictFileName = QDir::currentPath().toStdString() + "/full_dict.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lex = new Lexicon(dictFileName);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete lex;
}
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),
                                                    QString(),"");
    if(!fileName.isEmpty()) {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this,tr("Error"),tr("Error Opening File!"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void MainWindow::on_checkButton_clicked()
{
    // get entered text
    string text = ui->textEdit->toPlainText().toStdString();
    //break text to file with a WordBreaker object
    WordBreaker wb(text);
    string word;
    while (wb.hasMoreWords()) {
        word = wb.nextWord();
        int end = wb.getPosition();
        int beg = end - word.size();

        highlightWord(beg,end,Qt::transparent);
        // make sure that area is transparent
        if (!lex->contains(word)) {
            // if word not in dictiontary
            // highlight it with gray
            highlightWord(beg,end);
        }
    }
}

void MainWindow::highlightWord(int beg, int end, const QBrush &brush) {
    QTextCharFormat fmt;
    fmt.setBackground(brush);
    QTextCursor cursor(ui->textEdit->document());
    cursor.setPosition(beg,QTextCursor::MoveAnchor);
    cursor.setPosition(end,QTextCursor::KeepAnchor);
    cursor.setCharFormat(fmt);
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    string word = getCurrentTextEditWord(cursor).toStdString();
    if (isValidWord(word) &&cursor.charFormat().background()==Qt::yellow) {
        ui->listWidget->clear();
        vector<string> candidates = getCandidates(word);
        foreach(string curWord , candidates) {
            QString str = QString::fromStdString(curWord);
            ui->listWidget->addItem(str);
          }

      }

}

const QString MainWindow::getCurrentTextEditWord(QTextCursor & cursor) {

   cursor.movePosition(QTextCursor::StartOfWord,QTextCursor::MoveAnchor);
   cursor.movePosition(QTextCursor::EndOfWord , QTextCursor::KeepAnchor);
   return cursor.selectedText();
}

bool MainWindow::isValidWord(string word) {
  if(word.size()==0) return false;
  for (size_t i=0;i<word.size();i++)
      if (!isalnum(word[i]))
          return false;
  return true;
}


vector<string> MainWindow::getCandidates(string word, int ed) {
  EditDistance e;
  vector<string> cand;
  set<string> words = lex->getWords();
  foreach (string curWord, words) {

      if(e.getEditDistance(word,curWord) <=ed)
        cand.push_back(curWord);
      if(cand.size() >= MAXCANDIDATES)
        break;
    }
  return cand;

}

void MainWindow::on_actionSave_triggered()
{
    QString fileName;
}

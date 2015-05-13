#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "edit_distance.h"
#include <QDebug>
// dictionary file name
const string dictFileName = QDir::currentPath().toStdString() + "/full_dict.txt";
const string orgDictFileName = QDir::currentPath().toStdString() + "/original_dict.txt";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lex = new Lexicon(dictFileName);
    ui->menubar->setNativeMenuBar(false);
    ui->textEdit->setFocus();
}
MainWindow::~MainWindow()
{
    delete ui;
    delete lex;
    delete wb;
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
    // get input text
    string text = ui->textEdit->toPlainText().toStdString();
    //break text to file with a WordBreaker object
    wb = new WordBreaker(text);
    string word;
    while (wb->hasMoreWords()) {
        word = wb->nextWord();
        if(!isValidWord(word))
            continue;
        int end = wb->getPosition();
        int beg = end - word.size();

        QTextCursor cursor(ui->textEdit->document());
        cursor.setPosition(beg,QTextCursor::MoveAnchor);
        cursor.setPosition(end,QTextCursor::KeepAnchor);

        highlightWord(cursor,Qt::transparent);
        // make sure that area is transparent
        if (!lex->contains(word)) {
            // if word not in dictiontary
            // highlight it with yellow
            highlightWord(cursor);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"),QString(),"");
    if(!fileName.isEmpty()) {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this,tr("Error"),tr("Can't Save file!"));
        }
    //    file << ui->textEdit->toPlainText();

    }
}

void MainWindow::on_ignoreButton_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    getCurrentTextEditWord(cursor);
    highlightWord(cursor,Qt::transparent);
    ui->listWidget->clear();
}

void MainWindow::highlightWord(QTextCursor &cursor , const QBrush & brush) {
    QTextCharFormat fmt;
    fmt.setBackground(brush);
    cursor.setCharFormat(fmt);
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    string word = getCurrentTextEditWord(cursor).toStdString();
    if (cursor.charFormat().background()==Qt::yellow) {
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
  //check if it's a name or an abbreviation
  bool allCaps = true;
  for(size_t i =0 ; i<word.size();i++)
      if(islower(word[i]))
          allCaps = false;
  if(allCaps) return false;
  for (size_t i=0;i<word.size();i++)
      if (!isalpha(word[i]))
          return false;
  return true;
}

vector<string> MainWindow::getCandidates(string word, int mxEditDistance) {
  EditDistance ed;
  vector<string> cand;
  set<string> words = lex->getWords();
  for(int e =1 ;e<=mxEditDistance;e++) {
      foreach (string curWord, words) {
          if(ed.getEditDistance(word,curWord) <=e)
            cand.push_back(curWord);
          if(cand.size() >= MAXCANDIDATES)
            return cand;
        }
  }

  return cand;
}
void MainWindow::on_replaceButton_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    getCurrentTextEditWord(cursor);
    QString selectedWord = ui->listWidget->currentItem()->text();
    highlightWord(cursor,Qt::transparent);
    cursor.insertText(selectedWord);
    ui->listWidget->clear();
}

vector<int> MainWindow::getFirstLetterPositions(const string &text) {

    vector<int> ret;
    ret.push_back(0);
    for(size_t i=1;i<text.size()-2;i++)
        if(text[i]=='.')
            for(size_t j=i+1;j<text.size();j++)
                if(text[j]!=' '){
                    ret.push_back(j);
                    break;
                }
    return ret;

}

void MainWindow::on_caseButton_clicked()
{
    string inputText = ui->textEdit->toPlainText().toStdString();
    vector<int> positions = getFirstLetterPositions(inputText);
    QTextCursor cursor = ui->textEdit->textCursor();
    foreach (int pos , positions) {

        cursor.setPosition(pos);
        cursor.setPosition(pos+1,QTextCursor::KeepAnchor);
        char upperCase = toupper(inputText[pos]);
        QString str ; str.push_back(upperCase);
        cursor.insertText(str);

    }
}

void MainWindow::on_AddToDicButton_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    string word = getCurrentTextEditWord(cursor).toStdString();
    highlightWord(cursor,Qt::transparent);
    ui->listWidget->clear();
    lex->addWord(word);
    ofstream out(dictFileName.c_str(),std::ios_base::app);
    out << word <<endl;
    out.close();
}

void MainWindow::on_actionReset_triggered()
{
    ofstream out(dictFileName.c_str());
    ifstream in (orgDictFileName.c_str());
    string word;
    while(in >>word)
        out <<word<<endl;
    in.close();
    out.close();
    QMessageBox::information(this,"Done","Dictionary was reset successfully.");
}

 /****************************************************************************
 **
 ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
 ** Contact: http://www.qt-project.org/legal
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:BSD$
 ** You may use this file under the terms of the BSD license as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
 **     of its contributors may be used to endorse or promote products derived
 **     from this software without specific prior written permission.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 #include <QtGui>

 #include <math.h>

 #include "button.h"
 #include "calculator.h"

 Calculator::Calculator(QWidget *parent)
     : QWidget(parent)
 {

     this->setStyleSheet("QToolTip { border: 1px solid black; background-color: #ffa02f; padding: 1px; border-radius: 3px; opacity: 100; }  QWidget { color: #b1b1b1; background-color: #323232; }  QWidget:item:hover { background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619); color: #000000; }  QWidget:item:selected { background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); }  QMenuBar::item { background: transparent; }  QMenuBar::item:selected { background: transparent; border: 1px solid #ffaa00; }  QMenuBar::item:pressed { background: #444; border: 1px solid #000; background-color: QLinearGradient( x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434/*, stop:0.2 #343434, stop:0.1 #ffaa00*/ ); margin-bottom:-1px; padding-bottom:1px; }  QMenu { border: 1px solid #000; }  QMenu::item { padding: 2px 20px 2px 20px; }  QMenu::item:selected { color: #000000; }  QWidget:disabled { color: #404040; background-color: #323232; }  QAbstractItemView { background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d); }  QWidget:focus { /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/ }  QLineEdit { background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d); padding: 1px; border-style: solid; border: 1px solid #1e1e1e; border-radius: 5; }  QPushButton { color: #b1b1b1; background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646); border-width: 1px; border-color: #1e1e1e; border-style: solid; border-radius: 6; padding: 3px; font-size: 12px; padding-left: 5px; padding-right: 5px; }  QPushButton:pressed { background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525); }  QComboBox { selection-background-color: #ffaa00; background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646); border-style: solid; border: 1px solid #1e1e1e; border-radius: 5; }  QComboBox:hover,QPushButton:hover { border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); }   QComboBox:on { padding-top: 3px; padding-left: 4px; background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525); selection-background-color: #ffaa00; }  QComboBox QAbstractItemView { border: 2px solid darkgray; selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); }  QComboBox::drop-down { subcontrol-origin: padding; subcontrol-position: top right; width: 15px;  border-left-width: 0px; border-left-color: darkgray; border-left-style: solid; /* just a single line */ border-top-right-radius: 3px; /* same radius as the QComboBox */ border-bottom-right-radius: 3px; }  QComboBox::down-arrow { image: url(:/down_arrow.png); }  QGroupBox:focus { border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); }  QTextEdit:focus { border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); }  QScrollBar:horizontal { border: 1px solid #222222; background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848); height: 7px; margin: 0px 16px 0 16px; }  QScrollBar::handle:horizontal { background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f); min-height: 20px; border-radius: 2px; }  QScrollBar::add-line:horizontal { border: 1px solid #1b1b19; border-radius: 2px; background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a); width: 14px; subcontrol-position: right; subcontrol-origin: margin; }  QScrollBar::sub-line:horizontal { border: 1px solid #1b1b19; border-radius: 2px; background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a); width: 14px; subcontrol-position: left; subcontrol-origin: margin; }  QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal { border: 1px solid black; width: 1px; height: 1px; background: white; }  QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal { background: none; }  QScrollBar:vertical { background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848); width: 7px; margin: 16px 0 16px 0; border: 1px solid #222222; }  QScrollBar::handle:vertical { background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f); min-height: 20px; border-radius: 2px; }  QScrollBar::add-line:vertical { border: 1px solid #1b1b19; border-radius: 2px; background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a); height: 14px; subcontrol-position: bottom; subcontrol-origin: margin; }  QScrollBar::sub-line:vertical { border: 1px solid #1b1b19; border-radius: 2px; background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f); height: 14px; subcontrol-position: top; subcontrol-origin: margin; }  QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical { border: 1px solid black; width: 1px; height: 1px; background: white; }   QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: none; }  QTextEdit { background-color: #242424; }  QPlainTextEdit { background-color: #242424; }  QHeaderView::section { background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); color: white; padding-left: 4px; border: 1px solid #6c6c6c; }  QCheckBox:disabled { color: #414141; }  QDockWidget::title { text-align: center; spacing: 3px; /* spacing between items in the tool bar */ background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232); }  QDockWidget::close-button, QDockWidget::float-button { text-align: center; spacing: 1px; /* spacing between items in the tool bar */ background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232); }  QDockWidget::close-button:hover, QDockWidget::float-button:hover { background: #242424; }  QDockWidget::close-button:pressed, QDockWidget::float-button:pressed { padding: 1px -1px -1px 1px; }  QMainWindow::separator { background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434); color: white; padding-left: 4px; border: 1px solid #4c4c4c; spacing: 3px; /* spacing between items in the tool bar */ }  QMainWindow::separator:hover {  background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f); color: white; padding-left: 4px; border: 1px solid #6c6c6c; spacing: 3px; /* spacing between items in the tool bar */ }  QToolBar::handle { spacing: 3px; /* spacing between items in the tool bar */ background: url(:/images/handle.png); }  QMenu::separator { height: 2px; background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434); color: white; padding-left: 4px; margin-left: 10px; margin-right: 5px; }  QProgressBar { border: 2px solid grey; border-radius: 5px; text-align: center; }  QProgressBar::chunk { background-color: #d7801a; width: 2.15px; margin: 0.5px; }  QTabBar::tab { color: #b1b1b1; border: 1px solid #444; border-bottom-style: none; background-color: #323232; padding-left: 10px; padding-right: 10px; padding-top: 3px; padding-bottom: 2px; margin-right: -1px; }  QTabWidget::pane { border: 1px solid #444; top: 1px; }  QTabBar::tab:last { margin-right: 0; /* the last selected tab has nothing to overlap with on the right */ border-top-right-radius: 3px; }  QTabBar::tab:first:!selected { margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */   border-top-left-radius: 3px; }  QTabBar::tab:!selected { color: #b1b1b1; border-bottom-style: solid; margin-top: 3px; background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434); }  QTabBar::tab:selected { border-top-left-radius: 3px; border-top-right-radius: 3px; margin-bottom: 0px; }  QTabBar::tab:!selected:hover { /*border-top: 2px solid #ffaa00; padding-bottom: 3px;*/ border-top-left-radius: 3px; border-top-right-radius: 3px; background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00); }  QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{ color: #b1b1b1; background-color: #323232; border: 1px solid #b1b1b1; border-radius: 6px; }  QRadioButton::indicator:checked { background-color: qradialgradient( cx: 0.5, cy: 0.5, fx: 0.5, fy: 0.5, radius: 1.0, stop: 0.25 #ffaa00, stop: 0.3 #323232 ); }  QCheckBox::indicator{ color: #b1b1b1; background-color: #323232; border: 1px solid #b1b1b1; width: 9px; height: 9px; }  QRadioButton::indicator { border-radius: 6px; }  QRadioButton::indicator:hover, QCheckBox::indicator:hover { border: 1px solid #ffaa00; }  QCheckBox::indicator:checked { image:url(:/images/checkbox.png); }  QCheckBox::indicator:disabled, QRadioButton::indicator:disabled { border: 1px solid #444; }");

     sumInMemory = 0.0;
     sumSoFar = 0.0;
     factorSoFar = 0.0;
     waitingForOperand = true;

     display = new QLineEdit("0");
     display->setReadOnly(true);
     display->setAlignment(Qt::AlignRight);
     display->setMaxLength(15);

     QFont font = display->font();
     font.setPointSize(font.pointSize() + 8);
     display->setFont(font);

     for (int i = 0; i < NumDigitButtons; ++i) {
         digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
     }

     Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
     Button *changeSignButton = createButton(tr("(-)"), SLOT(changeSignClicked()));

     Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
     Button *clearButton = createButton(tr("Clear"), SLOT(clear()));
     Button *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));

     Button *clearMemoryButton = createButton(tr("MC"), SLOT(clearMemory()));
     Button *readMemoryButton = createButton(tr("MR"), SLOT(readMemory()));
     Button *setMemoryButton = createButton(tr("MS"), SLOT(setMemory()));
     Button *addToMemoryButton = createButton(tr("M+"), SLOT(addToMemory()));

     Button *divisionButton = createButton(tr("/"), SLOT(multiplicativeOperatorClicked()));
     Button *timesButton = createButton(tr("x"), SLOT(multiplicativeOperatorClicked()));
     Button *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
     Button *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

     Button *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
     Button *powerButton = createButton(tr("x^2"), SLOT(unaryOperatorClicked()));
     Button *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
     Button *equalButton = createButton(tr("="), SLOT(equalClicked()));

     QGridLayout *mainLayout = new QGridLayout();
 #if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
     mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
 #else
     mainLayout->setSizeConstraint(QLayout::SetFixedSize);
 #endif
     mainLayout->addWidget(display, 0, 0, 1, 6);
     mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
     mainLayout->addWidget(clearButton, 1, 2, 1, 2);
     mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

     mainLayout->addWidget(clearMemoryButton, 2, 0);
     mainLayout->addWidget(readMemoryButton, 3, 0);
     mainLayout->addWidget(setMemoryButton, 4, 0);
     mainLayout->addWidget(addToMemoryButton, 5, 0);

     for (int i = 1; i < NumDigitButtons; ++i) {
         int row = ((9 - i) / 3) + 2;
         int column = ((i - 1) % 3) + 1;
         mainLayout->addWidget(digitButtons[i], row, column);
     }

     mainLayout->addWidget(digitButtons[0], 5, 1);
     mainLayout->addWidget(pointButton, 5, 2);
     mainLayout->addWidget(changeSignButton, 5, 3);

     mainLayout->addWidget(divisionButton, 2, 4);
     mainLayout->addWidget(timesButton, 3, 4);
     mainLayout->addWidget(minusButton, 4, 4);
     mainLayout->addWidget(plusButton, 5, 4);

     mainLayout->addWidget(squareRootButton, 2, 5);
     mainLayout->addWidget(powerButton, 3, 5);
     mainLayout->addWidget(reciprocalButton, 4, 5);
     mainLayout->addWidget(equalButton, 5, 5);
     setLayout(mainLayout);

     setWindowTitle(tr("Calculator"));
 }

 void Calculator::digitClicked()
 {
     Button *clickedButton = qobject_cast<Button *>(sender());
     int digitValue = clickedButton->text().toInt();
     if (display->text() == "0" && digitValue == 0.0)
         return;

     if (waitingForOperand) {
         display->clear();
         waitingForOperand = false;
     }
     display->setText(display->text() + QString::number(digitValue));
 }

 void Calculator::unaryOperatorClicked()
 {
     Button *clickedButton = qobject_cast<Button *>(sender());
     QString clickedOperator = clickedButton->text();
     double operand = display->text().toDouble();
     double result = 0.0;

     if (clickedOperator == tr("Sqrt")) {
         if (operand < 0.0) {
             abortOperation();
             return;
         }
         result = sqrt(operand);
     } else if (clickedOperator == tr("x^2")) {
         result = pow(operand, 2.0);
     } else if (clickedOperator == tr("1/x")) {
         if (operand == 0.0) {
             abortOperation();
             return;
         }
         result = 1.0 / operand;
     }
     display->setText(QString::number(result));
     waitingForOperand = true;
 }

 void Calculator::additiveOperatorClicked()
 {
     Button *clickedButton = qobject_cast<Button *>(sender());
     QString clickedOperator = clickedButton->text();
     double operand = display->text().toDouble();

     if (!pendingMultiplicativeOperator.isEmpty()) {
         if (!calculate(operand, pendingMultiplicativeOperator)) {
             abortOperation();
             return;
         }
         display->setText(QString::number(factorSoFar));
         operand = factorSoFar;
         factorSoFar = 0.0;
         pendingMultiplicativeOperator.clear();
     }

     if (!pendingAdditiveOperator.isEmpty()) {
         if (!calculate(operand, pendingAdditiveOperator)) {
             abortOperation();
             return;
         }
         display->setText(QString::number(sumSoFar));
     } else {
         sumSoFar = operand;
     }

     pendingAdditiveOperator = clickedOperator;
     waitingForOperand = true;
 }

 void Calculator::multiplicativeOperatorClicked()
 {
     Button *clickedButton = qobject_cast<Button *>(sender());
     QString clickedOperator = clickedButton->text();
     double operand = display->text().toDouble();

     if (!pendingMultiplicativeOperator.isEmpty()) {
         if (!calculate(operand, pendingMultiplicativeOperator)) {
             abortOperation();
             return;
         }
         display->setText(QString::number(factorSoFar));
     } else {
         factorSoFar = operand;
     }

     pendingMultiplicativeOperator = clickedOperator;
     waitingForOperand = true;
 }

 void Calculator::equalClicked()
 {
     double operand = display->text().toDouble();

     if (!pendingMultiplicativeOperator.isEmpty()) {
         if (!calculate(operand, pendingMultiplicativeOperator)) {
             abortOperation();
             return;
         }
         operand = factorSoFar;
         factorSoFar = 0.0;
         pendingMultiplicativeOperator.clear();
     }
     if (!pendingAdditiveOperator.isEmpty()) {
         if (!calculate(operand, pendingAdditiveOperator)) {
             abortOperation();
             return;
         }
         pendingAdditiveOperator.clear();
     } else {
         sumSoFar = operand;
     }

     display->setText(QString::number(sumSoFar));
     sumSoFar = 0.0;
     waitingForOperand = true;
 }

 void Calculator::pointClicked()
 {
     if (waitingForOperand)
         display->setText("0");
     if (!display->text().contains("."))
         display->setText(display->text() + tr("."));
     waitingForOperand = false;
 }

 void Calculator::changeSignClicked()
 {
     QString text = display->text();
     double value = text.toDouble();

     if (value > 0.0) {
         text.prepend(tr("-"));
     } else if (value < 0.0) {
         text.remove(0, 1);
     }
     display->setText(text);
 }

 void Calculator::backspaceClicked()
 {
     if (waitingForOperand)
         return;

     QString text = display->text();
     text.chop(1);
     if (text.isEmpty()) {
         text = "0";
         waitingForOperand = true;
     }
     display->setText(text);
 }

 void Calculator::clear()
 {
     if (waitingForOperand)
         return;

     display->setText("0");
     waitingForOperand = true;
 }

 void Calculator::clearAll()
 {
     sumSoFar = 0.0;
     factorSoFar = 0.0;
     pendingAdditiveOperator.clear();
     pendingMultiplicativeOperator.clear();
     display->setText("0");
     waitingForOperand = true;
 }

 void Calculator::clearMemory()
 {
     sumInMemory = 0.0;
 }

 void Calculator::readMemory()
 {
     display->setText(QString::number(sumInMemory));
     waitingForOperand = true;
 }

 void Calculator::setMemory()
 {
     equalClicked();
     sumInMemory = display->text().toDouble();
 }

 void Calculator::addToMemory()
 {
     equalClicked();
     sumInMemory += display->text().toDouble();
 }
 Button *Calculator::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }

 void Calculator::abortOperation()
 {
     clearAll();
     display->setText(tr("####"));
 }

 bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
 {
     if (pendingOperator == tr("+")) {
         sumSoFar += rightOperand;
     } else if (pendingOperator == tr("-")) {
         sumSoFar -= rightOperand;
     } else if (pendingOperator == tr("x")) {
         factorSoFar *= rightOperand;
     } else if (pendingOperator == tr("/")) {
         if (rightOperand == 0.0)
             return false;
         factorSoFar /= rightOperand;
     }
     return true;
 }

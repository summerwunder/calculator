/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *btnJD;
    QRadioButton *btnHD;
    QCheckBox *btnSci;
    QGridLayout *gridLayout;
    QPushButton *btn8;
    QPushButton *btn7;
    QPushButton *btnMinus;
    QPushButton *btnMul;
    QPushButton *btnPi;
    QPushButton *btn4;
    QPushButton *btn2;
    QPushButton *btnE;
    QPushButton *btnDivise;
    QPushButton *btnTan;
    QPushButton *btnPower;
    QPushButton *btn0;
    QPushButton *btnLog;
    QPushButton *btn3;
    QPushButton *btnCos;
    QPushButton *btnRightBracket;
    QPushButton *btn9;
    QPushButton *btnPercent;
    QPushButton *btn1;
    QPushButton *btn6;
    QPushButton *btnPlus;
    QPushButton *btnSqrt;
    QPushButton *btnClearAll;
    QPushButton *btn5;
    QPushButton *btnLeftBracket;
    QPushButton *btnDeciaml;
    QPushButton *btnBack;
    QPushButton *btnClear;
    QPushButton *btnSin;
    QPushButton *btnEqu;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *btnHistory;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(621, 605);
        QFont font;
        font.setPointSize(16);
        Widget->setFont(font);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnJD = new QRadioButton(Widget);
        btnJD->setObjectName(QString::fromUtf8("btnJD"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnJD->sizePolicy().hasHeightForWidth());
        btnJD->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\345\260\217\346\240\207\345\256\213\347\256\200\344\275\223")});
        font1.setPointSize(13);
        font1.setKerning(true);
        btnJD->setFont(font1);

        verticalLayout->addWidget(btnJD);

        btnHD = new QRadioButton(Widget);
        btnHD->setObjectName(QString::fromUtf8("btnHD"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\345\260\217\346\240\207\345\256\213\347\256\200\344\275\223")});
        font2.setPointSize(13);
        btnHD->setFont(font2);

        verticalLayout->addWidget(btnHD);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 2, 1);

        btnSci = new QCheckBox(Widget);
        btnSci->setObjectName(QString::fromUtf8("btnSci"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\345\260\217\346\240\207\345\256\213\347\256\200\344\275\223")});
        font3.setPointSize(14);
        btnSci->setFont(font3);
        btnSci->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btnSci, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn8 = new QPushButton(Widget);
        btn8->setObjectName(QString::fromUtf8("btn8"));

        gridLayout->addWidget(btn8, 2, 3, 1, 1);

        btn7 = new QPushButton(Widget);
        btn7->setObjectName(QString::fromUtf8("btn7"));

        gridLayout->addWidget(btn7, 2, 2, 1, 1);

        btnMinus = new QPushButton(Widget);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 254, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 255, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 127, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 170, 85, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(255, 255, 191, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush9(QColor(240, 240, 240, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        QBrush brush10(QColor(227, 227, 227, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        QBrush brush11(QColor(160, 160, 160, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        QBrush brush12(QColor(105, 105, 105, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush12);
        QBrush brush13(QColor(245, 245, 245, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnMinus->setPalette(palette);

        gridLayout->addWidget(btnMinus, 2, 5, 1, 1);

        btnMul = new QPushButton(Widget);
        btnMul->setObjectName(QString::fromUtf8("btnMul"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(16);
        btnMul->setFont(font4);

        gridLayout->addWidget(btnMul, 4, 5, 1, 1);

        btnPi = new QPushButton(Widget);
        btnPi->setObjectName(QString::fromUtf8("btnPi"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setItalic(false);
        btnPi->setFont(font5);

        gridLayout->addWidget(btnPi, 6, 1, 1, 1);

        btn4 = new QPushButton(Widget);
        btn4->setObjectName(QString::fromUtf8("btn4"));

        gridLayout->addWidget(btn4, 3, 2, 1, 1);

        btn2 = new QPushButton(Widget);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        gridLayout->addWidget(btn2, 4, 3, 1, 1);

        btnE = new QPushButton(Widget);
        btnE->setObjectName(QString::fromUtf8("btnE"));

        gridLayout->addWidget(btnE, 4, 1, 1, 1);

        btnDivise = new QPushButton(Widget);
        btnDivise->setObjectName(QString::fromUtf8("btnDivise"));

        gridLayout->addWidget(btnDivise, 0, 5, 1, 1);

        btnTan = new QPushButton(Widget);
        btnTan->setObjectName(QString::fromUtf8("btnTan"));

        gridLayout->addWidget(btnTan, 2, 0, 1, 1);

        btnPower = new QPushButton(Widget);
        btnPower->setObjectName(QString::fromUtf8("btnPower"));

        gridLayout->addWidget(btnPower, 4, 0, 1, 1);

        btn0 = new QPushButton(Widget);
        btn0->setObjectName(QString::fromUtf8("btn0"));

        gridLayout->addWidget(btn0, 6, 3, 1, 1);

        btnLog = new QPushButton(Widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));

        gridLayout->addWidget(btnLog, 3, 1, 1, 1);

        btn3 = new QPushButton(Widget);
        btn3->setObjectName(QString::fromUtf8("btn3"));

        gridLayout->addWidget(btn3, 4, 4, 1, 1);

        btnCos = new QPushButton(Widget);
        btnCos->setObjectName(QString::fromUtf8("btnCos"));

        gridLayout->addWidget(btnCos, 0, 0, 1, 1);

        btnRightBracket = new QPushButton(Widget);
        btnRightBracket->setObjectName(QString::fromUtf8("btnRightBracket"));

        gridLayout->addWidget(btnRightBracket, 2, 1, 1, 1);

        btn9 = new QPushButton(Widget);
        btn9->setObjectName(QString::fromUtf8("btn9"));

        gridLayout->addWidget(btn9, 2, 4, 1, 1);

        btnPercent = new QPushButton(Widget);
        btnPercent->setObjectName(QString::fromUtf8("btnPercent"));

        gridLayout->addWidget(btnPercent, 6, 2, 1, 1);

        btn1 = new QPushButton(Widget);
        btn1->setObjectName(QString::fromUtf8("btn1"));

        gridLayout->addWidget(btn1, 4, 2, 1, 1);

        btn6 = new QPushButton(Widget);
        btn6->setObjectName(QString::fromUtf8("btn6"));

        gridLayout->addWidget(btn6, 3, 4, 1, 1);

        btnPlus = new QPushButton(Widget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));

        gridLayout->addWidget(btnPlus, 3, 5, 1, 1);

        btnSqrt = new QPushButton(Widget);
        btnSqrt->setObjectName(QString::fromUtf8("btnSqrt"));

        gridLayout->addWidget(btnSqrt, 6, 0, 1, 1);

        btnClearAll = new QPushButton(Widget);
        btnClearAll->setObjectName(QString::fromUtf8("btnClearAll"));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font6.setPointSize(16);
        btnClearAll->setFont(font6);

        gridLayout->addWidget(btnClearAll, 0, 2, 1, 1);

        btn5 = new QPushButton(Widget);
        btn5->setObjectName(QString::fromUtf8("btn5"));

        gridLayout->addWidget(btn5, 3, 3, 1, 1);

        btnLeftBracket = new QPushButton(Widget);
        btnLeftBracket->setObjectName(QString::fromUtf8("btnLeftBracket"));

        gridLayout->addWidget(btnLeftBracket, 0, 1, 1, 1);

        btnDeciaml = new QPushButton(Widget);
        btnDeciaml->setObjectName(QString::fromUtf8("btnDeciaml"));

        gridLayout->addWidget(btnDeciaml, 6, 4, 1, 1);

        btnBack = new QPushButton(Widget);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));

        gridLayout->addWidget(btnBack, 0, 3, 1, 1);

        btnClear = new QPushButton(Widget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setAutoFillBackground(true);
        btnClear->setAutoDefault(false);
        btnClear->setFlat(false);

        gridLayout->addWidget(btnClear, 0, 4, 1, 1);

        btnSin = new QPushButton(Widget);
        btnSin->setObjectName(QString::fromUtf8("btnSin"));

        gridLayout->addWidget(btnSin, 3, 0, 1, 1);

        btnEqu = new QPushButton(Widget);
        btnEqu->setObjectName(QString::fromUtf8("btnEqu"));
        btnEqu->setMouseTracking(false);
        btnEqu->setContextMenuPolicy(Qt::CustomContextMenu);
        btnEqu->setAutoFillBackground(false);
        btnEqu->setAutoDefault(false);
        btnEqu->setFlat(false);

        gridLayout->addWidget(btnEqu, 5, 5, 2, 1);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);


        gridLayout_2->addLayout(horizontalLayout, 1, 2, 1, 1);

        btnHistory = new QPushButton(Widget);
        btnHistory->setObjectName(QString::fromUtf8("btnHistory"));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\345\260\217\346\240\207\345\256\213\347\256\200\344\275\223")});
        font7.setPointSize(12);
        font7.setUnderline(false);
        font7.setStrikeOut(false);
        btnHistory->setFont(font7);
        btnHistory->setCheckable(false);
        btnHistory->setAutoDefault(false);

        gridLayout_2->addWidget(btnHistory, 1, 0, 2, 1);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 3);


        retranslateUi(Widget);

        btnClear->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnJD->setText(QCoreApplication::translate("Widget", "\350\247\222\345\272\246\345\210\266", nullptr));
        btnHD->setText(QCoreApplication::translate("Widget", "\345\274\247\345\272\246\345\210\266", nullptr));
        btnSci->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\345\260\217\346\225\260\344\275\215\346\225\260", nullptr));
        btn8->setText(QCoreApplication::translate("Widget", "8", nullptr));
#if QT_CONFIG(shortcut)
        btn8->setShortcut(QCoreApplication::translate("Widget", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        btn7->setText(QCoreApplication::translate("Widget", "7", nullptr));
#if QT_CONFIG(shortcut)
        btn7->setShortcut(QCoreApplication::translate("Widget", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMinus->setText(QCoreApplication::translate("Widget", "-", nullptr));
#if QT_CONFIG(shortcut)
        btnMinus->setShortcut(QCoreApplication::translate("Widget", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMul->setText(QCoreApplication::translate("Widget", "*", nullptr));
#if QT_CONFIG(shortcut)
        btnMul->setShortcut(QCoreApplication::translate("Widget", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        btnPi->setText(QCoreApplication::translate("Widget", "\316\240", nullptr));
        btn4->setText(QCoreApplication::translate("Widget", "4", nullptr));
#if QT_CONFIG(shortcut)
        btn4->setShortcut(QCoreApplication::translate("Widget", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        btn2->setText(QCoreApplication::translate("Widget", "2", nullptr));
#if QT_CONFIG(shortcut)
        btn2->setShortcut(QCoreApplication::translate("Widget", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        btnE->setText(QCoreApplication::translate("Widget", "e", nullptr));
#if QT_CONFIG(shortcut)
        btnE->setShortcut(QCoreApplication::translate("Widget", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDivise->setText(QCoreApplication::translate("Widget", "/", nullptr));
#if QT_CONFIG(shortcut)
        btnDivise->setShortcut(QCoreApplication::translate("Widget", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        btnTan->setText(QCoreApplication::translate("Widget", "tan", nullptr));
        btnPower->setText(QCoreApplication::translate("Widget", "^", nullptr));
#if QT_CONFIG(shortcut)
        btnPower->setShortcut(QCoreApplication::translate("Widget", "^", nullptr));
#endif // QT_CONFIG(shortcut)
        btn0->setText(QCoreApplication::translate("Widget", "0", nullptr));
#if QT_CONFIG(shortcut)
        btn0->setShortcut(QCoreApplication::translate("Widget", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        btnLog->setText(QCoreApplication::translate("Widget", "ln", nullptr));
        btn3->setText(QCoreApplication::translate("Widget", "3", nullptr));
#if QT_CONFIG(shortcut)
        btn3->setShortcut(QCoreApplication::translate("Widget", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        btnCos->setText(QCoreApplication::translate("Widget", "cos", nullptr));
        btnRightBracket->setText(QCoreApplication::translate("Widget", ")", nullptr));
#if QT_CONFIG(shortcut)
        btnRightBracket->setShortcut(QCoreApplication::translate("Widget", ")", nullptr));
#endif // QT_CONFIG(shortcut)
        btn9->setText(QCoreApplication::translate("Widget", "9", nullptr));
#if QT_CONFIG(shortcut)
        btn9->setShortcut(QCoreApplication::translate("Widget", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        btnPercent->setText(QCoreApplication::translate("Widget", "%", nullptr));
#if QT_CONFIG(shortcut)
        btnPercent->setShortcut(QCoreApplication::translate("Widget", "%", nullptr));
#endif // QT_CONFIG(shortcut)
        btn1->setText(QCoreApplication::translate("Widget", "1", nullptr));
#if QT_CONFIG(shortcut)
        btn1->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        btn6->setText(QCoreApplication::translate("Widget", "6", nullptr));
#if QT_CONFIG(shortcut)
        btn6->setShortcut(QCoreApplication::translate("Widget", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        btnPlus->setText(QCoreApplication::translate("Widget", "+", nullptr));
#if QT_CONFIG(shortcut)
        btnPlus->setShortcut(QCoreApplication::translate("Widget", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSqrt->setText(QCoreApplication::translate("Widget", "sqrt", nullptr));
        btnClearAll->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        btn5->setText(QCoreApplication::translate("Widget", "5", nullptr));
#if QT_CONFIG(shortcut)
        btn5->setShortcut(QCoreApplication::translate("Widget", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        btnLeftBracket->setText(QCoreApplication::translate("Widget", "(", nullptr));
#if QT_CONFIG(shortcut)
        btnLeftBracket->setShortcut(QCoreApplication::translate("Widget", "(", nullptr));
#endif // QT_CONFIG(shortcut)
        btnDeciaml->setText(QCoreApplication::translate("Widget", ".", nullptr));
#if QT_CONFIG(shortcut)
        btnDeciaml->setShortcut(QCoreApplication::translate("Widget", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        btnBack->setText(QCoreApplication::translate("Widget", "<-", nullptr));
#if QT_CONFIG(shortcut)
        btnBack->setShortcut(QCoreApplication::translate("Widget", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        btnClear->setText(QCoreApplication::translate("Widget", "CE", nullptr));
        btnSin->setText(QCoreApplication::translate("Widget", "sin", nullptr));
        btnEqu->setText(QCoreApplication::translate("Widget", "=", nullptr));
#if QT_CONFIG(shortcut)
        btnEqu->setShortcut(QCoreApplication::translate("Widget", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("Widget", "\346\234\200\345\244\247\344\277\235\347\225\231\347\232\204\344\275\215\346\225\260", nullptr));
        btnHistory->setText(QCoreApplication::translate("Widget", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    static bool getIsJD();//获取信息，是否为角度制
private:
    Ui::Widget *ui;
    void OnlyOneInit();//项目初始化
    void paraInit();//参数初始化

    int rowCount; //lineEdit的当前行数
    int bracketNum; //表达式中括号的数目（是否为0）

    bool isZeroClicked;//判断前面的数字是否为0
    bool isOperatorClicked;//判断是否前面的字符是符号
    bool isDotClicked;//判断是否前面的字符是小数点
    bool isLeftBracketClicked;//是否可以输入左括号
    bool isRightBracketClicked;//是否可以输入右括号
    bool isPercentClicked;//是否可以输入百分号
    bool isNumClicked;//是否可以输入数字
    bool isFunClicked;//是否可以输入函数表达式
    bool isSci;//是否使用科学计数法
    static bool isJD;//是否是角度制
private:
    QString getlastRow();//获取最后一行文本信息
    void numClicked();//槽函数表示输入数字
    void dotClicked();//输入小数点
    void operatorClicked();//输入表达式
    void bracketClicked();//输入括号
    void percentClicked();//百分号的输入
    void functionClicked();//函数表达式的输入
    void equClicked();//等式的输入
    void ceClicked();//清空的输入
    void backClicked();//删除的输入
    void setDecClicked();//设置小数
    void writeToFile(QString str,QString ans);//写入历史记录
    void reportError(int index);//报错
};
#endif // WIDGET_H

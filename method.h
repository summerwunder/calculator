#ifndef METHOD_H
#define METHOD_H

//#include <QList>
#include <QStack>
#include <QVector>
class Method
{
public:
    Method();
    void toMid(QString str);//字符串转中缀表达式
    void midTosuffix();//中缀表达式转后缀表达式
    int priority(QString str);//判断运算优先级
    double calulate();//计算
    double getAns(QString str);//整合上述步骤
    bool getPercent();
    int getError();
private:
    QVector<int> *posNegative;
    QVector<QString> *mid;//中缀表达式
    QVector<QString> *suffix;//后缀表达式 存储器
    bool isPercent;//是否结果需要补上百分号
    int errorIndex;//错误标号
};

#endif // METHOD_H

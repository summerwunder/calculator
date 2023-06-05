#include "method.h"
#include <QDebug>
#include <QString>
#include <QChar>
#include <QMessageBox>
#include <QtMath>
#include <QObject>
#include "widget.h"
#include <QtAlgorithms>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865
#define E 2.7182818284590
Method::Method()
{
    //参数初始化
    isPercent=false;
    posNegative=nullptr;
    mid=nullptr;
    suffix=nullptr;
    errorIndex=0;
}
//先将字符串转换为中缀表达式
void Method::toMid(QString str)
{
    int posLeft=-1;//左括号的尾位置
    int posMinus=-1;//减号位置
    posNegative=new QVector<int>();
    mid=new QVector<QString>();
    QString temp="";
    //先查找存不存在负数的情况
    for(int i=0;i<str.size();i++)
    {
        if(str[i].toLatin1()=='(')
        {
            posLeft=i;
        }
        else if(str[i].toLatin1()=='-')
        {
            posMinus=i;
        }
        if(posMinus==posLeft+1)//如果左括号后边第一个字符是减号，那么就是负数
        {
            posNegative->push_back(posMinus);//获取负数的下标
            posLeft=-1;
            posMinus=-1;
        }
    }
    //测试
    //for(QVector<int>::iterator it=posNegative->begin();it!=posNegative->end();it++)
    //{
    //    qDebug()<<*it;
    //}
    //qDebug()<<"------------";
    for(int i=0;i<str.size();i++)
    {
        //截取数字
        if(str[i].isDigit() || str[i].toLatin1() == '.'||str[i].toLatin1()=='e'||str[i].toLatin1()=='Π')
        {
            temp+=str[i];
        } 
        else
        {
            //当遇到不是数字及小数点后就把这个数据获取
            if(!temp.isEmpty())
            {
                mid->push_back(temp);
                temp="";
            }
            if(posNegative->indexOf(i)!=-1)
            {
               //先对负数进行锁定，当遍历的i在之前存储的数组中，就对负数进行截取，把负号和数字放到一起
               if(str[i+1].isDigit()||str[i+1].toLatin1()=='e'||str[i+1].toLatin1()=='Π')
               {
                   for(int j=i+1;j<str.size();j++)
                   {
                       if(str[j]!='.'&&(!str[j].isDigit())&&str[j].toLatin1()!='e'&&str[j].toLatin1()!='Π')
                       {
                           qDebug()<<i<<j;
                           mid->push_back(str.mid(i,j-i));
                           i=j-1;
                           break;
                       }
                   }
               }
               //sin需要截取四个字符，即-sin
               else if(str[i+1].toLatin1()=='s'&&str[i+2].toLatin1()=='i')
               {
                   mid->push_back(str.mid(i,4));
                   i=i+3;
               }
               //-sqrt
               else if(str[i+1].toLatin1()=='s'&&str[i+2].toLatin1()=='q')
               {
                   mid->push_back(str.mid(i,5));
                   i=i+4;
               }
               //-cos
               else if(str[i+1].toLatin1()=='c')
               {
                   mid->push_back(str.mid(i,4));
                   i=i+3;
               }
               //-lg
               else if(str[i+1].toLatin1()=='l')
               {
                   mid->push_back(str.mid(i,3));
                   i=i+2;
               }
               //-tan
               else if(str[i+1].toLatin1()=='t')
               {
                   mid->push_back(str.mid(i,4));
                   i=i+3;
               }
            }
            else if(str[i].toLatin1()=='+'||str[i].toLatin1()=='-'||str[i].toLatin1()=='%'||
                    str[i].toLatin1()=='*'||str[i].toLatin1()=='/'||str[i].toLatin1()=='^')
            {
                mid->push_back(QString(str[i]));
            }
            else if(str[i].toLatin1()=='s'&&str[i+1].toLatin1()=='i')
            {
                mid->push_back(str.mid(i,3));
                i=i+2;
            }
            else if(str[i].toLatin1()=='s'&&str[i+1].toLatin1()=='q')
            {
                mid->push_back(str.mid(i,4));
                i=i+3;
            }
            else if(str[i].toLatin1()=='c')
            {
                mid->push_back(str.mid(i,3));
                i=i+2;
            }
            else if(str[i].toLatin1()=='l')
            {
                mid->push_back(str.mid(i,2));
                i=i+1;
            }
            else if(str[i].toLatin1()=='t')
            {
                mid->push_back(str.mid(i,3));
                i=i+2;
            }
            else
            {
                mid->push_back(QString(str[i]));
            }
        }
        //如果已经遍历到最后一位了但是temp还有数字（字符串以数字结尾）那么就把最后一段数字获取
        if(i==str.size()-1&&(!temp.isEmpty()))
        {
            mid->push_back(temp);
            temp="";
        }
    }
    //测试
    //for(QVector<QString>::iterator it=mid->begin();it!=mid->end();it++)
    //{
    //    qDebug()<<*it;
    //}

}
//使用两个栈，一个符号栈，一个运算栈
//1.数字直接入队列
//2.运算符要与栈顶元素比较
// ①栈为空直接入栈
// ②运算符优先级大于栈顶元素优先级则直接入栈
// （这里一定注意是优先级大于才可入栈，你可以在网上看到各种抄袭版本，都是大于等于，错都很一致，误人子弟）
// ③小于或等于则出栈入列，再与栈顶元素进行比较，直到运算符优先级小于栈顶元素优先级后，操作符再入栈
//3.操作符是 ( 则无条件入栈
//4.操作符为 )，则依次出栈入列，直到匹配到第一个(为止，此操作符直接舍弃，(直接出栈舍弃

//最后将符号栈中剩余元素压入计算栈中，要注意的是，此时需要对计算栈的次序逆序输出才为正确的逆波兰式。
void Method::midTosuffix()
{
    suffix=new QVector<QString>();//创建存储器
    QStack<QString> stackOp;// 创建符号栈
    for(int i=0;i<mid->size();i++)
    {
        QString str=mid->at(i);
        //数字和%直接入存储器
        if((str[0].toLatin1()>='0'&&str[0].toLatin1()<='9')||str=="%"||str=="e"||str=="Π")
        {
            suffix->push_back(str);
        }
        //负数也是
        else if(str.size()>1&&(str[0].toLatin1()=='-'&&(str[1].toLatin1()>='0'&&str[1].toLatin1()<='9')||str[1].toLatin1()=='e'||str[1].toLatin1()=='Π'))
        {
            suffix->push_back(str);
        }
        //左括号直接入栈
        else if(str=="(")
        {
            stackOp.push(str);
        }
        //操作符为 )，则依次出栈入列，直到匹配到第一个(为止，此操作符直接舍弃，(直接出栈舍弃
        else if(str==")")
        {
            while (true)
            {
                if (stackOp.top() == "(")
                {
                    stackOp.pop();
                    break;
                }
                QString strTop=stackOp.top();
                suffix->push_back(strTop);
                stackOp.pop();
            }
        }
        //操作符
        else
        {
            //栈为空直接入栈
            if(stackOp.isEmpty())
            {
                stackOp.push(str);
            }
            //运算符优先级大于栈顶元素优先级则直接入栈
            else if (priority(str) > priority(stackOp.top()))
            {
                stackOp.push(str);
            }
            //小于或等于则出栈入列，再与栈顶元素进行比较，直到运算符优先级小于栈顶元素优先级后，操作符再入栈
            else
            {
               while(true)
               {
                   if(stackOp.isEmpty())
                   {
                       stackOp.push(str);
                       break;
                   }
                   else if(priority(str) > priority(stackOp.top()))
                   {
                       stackOp.push(str);
                       break;
                   }
                   QString strTop=stackOp.top();
                   suffix->push_back(strTop);
                   stackOp.pop();
               }
            }
        }
        //qDebug()<<stackOp.top();
    }
    //最后将符号栈中剩余元素压入计算栈中
    while(!stackOp.isEmpty())
    {
        QString strTop=stackOp.top();
        suffix->push_back(strTop);
        stackOp.pop();
    }
    //测试
//    for(QVector<QString>::iterator it=suffix->begin();it!=suffix->end();it++)
//    {
//        qDebug()<<*it;
//    }
}


double Method::calulate()
{
    QStack<double> numStack;
    double numFirst;
    double numSecond;
    double numTemp;
    for(int i=0;i<suffix->size();i++)
    {
        QString str=suffix->at(i);
        if((str[0].toLatin1()>='0'&&str[0].toLatin1()<='9')||str=="e"||str=="Π")
        {
            if(str=="e")
            {
                numStack.push(E);
                continue;
            }
            else if(str=="Π")
            {
                numStack.push(PI);
                continue;
            }
            numStack.push(str.toDouble());
        }
        else if(str=="-e")
        {
            numStack.push(0-E);
            continue;
        }
        else if(str=="-Π")
        {
            numStack.push(0-PI);
            continue;
        }
        else if(str.size()>1&&(str[0].toLatin1()=='-'&&((str[1].toLatin1()>='0'&&str[1].toLatin1()<='9'))))
        {
            numStack.push(str.toDouble());
        }
        else if(str=="+"||str=="-"||str=="*"||str=="/"||str=="^")
        {
            numFirst=numStack.pop();
            numSecond=numStack.pop();
            if(str=="+") numTemp=numFirst+numSecond;
            else if(str=="-") numTemp=numSecond-numFirst;
            else if(str=="*") numTemp=numSecond*numFirst;
            else if(str=="/")
            {
                if(qAbs(numFirst)<=1e-10)
                {
                    errorIndex=3;
                    return 0.0;
                }
                numTemp=numSecond/numFirst;
            }
            else if(str=="^")
            {
                if(qAbs(numSecond)<=1e-10)
                {
                    errorIndex=4;
                    return 0.0;
                }
                numTemp=pow(numSecond,numFirst);
            }
            if(qAbs(numTemp)<=1e-10)numTemp=0.0;
            numStack.push(numTemp);
        }
        else
        {
            numFirst=numStack.pop();
            if(str=="sin"||str=="-sin")
            {
                if(Widget::getIsJD())
                {
                    numTemp = qSin(numFirst / 180.0 * PI);
                    if(str.size()==4) numTemp=-numTemp;
                }
                else
                {
                    numTemp = qSin(numFirst);
                    if(str.size()==4) numTemp=-numTemp;
                }
            }

            else if(str=="cos"||str=="-cos")
            {
                if(Widget::getIsJD())
                {
                    numTemp = qCos(numFirst/ 180.0 * PI);
                    if(str.size()==4) numTemp=-numTemp;
                }
                else
                {
                    numTemp = qCos(numFirst);
                    if(str.size()==4) numTemp=-numTemp;
                }
            }
            else if(str=="tan"||str=="-tan")
            {
                if(Widget::getIsJD())
                {
                    int num=int(numFirst);
                    if(qAbs(numFirst-num)<=1e-10&&num%90==0)
                    {
                        errorIndex=2;//报错
                        return 0.0;
                    }
                    numTemp = qTan(numFirst / 180.0 * PI);
                    if(str.size()==4) numTemp=-numTemp;
                }
                else
                {
                    numTemp = qTan(numFirst);
                    if(numTemp>1e10||numTemp<-1e10)
                    {
                        errorIndex=2;//报错
                        return 0.0;
                    }
                    if(str.size()==4) numTemp=-numTemp;
                }
            }
            else if(str=="ln"||str=="-ln")
            {
                if(numFirst<=1e-10)
                {
                    this->errorIndex=1;
                    return 0.0;
                }
                numTemp=qLn(numFirst);
                if(str.size()==3) numTemp=-numTemp;
            }
            else if(str=="sqrt"||str=="-sqrt")
            {
                if(numFirst<0)
                {
                    this->errorIndex=5;
                    return 0.0;
                }
                numTemp=qSqrt(numFirst);
                if(str.size()==5) numTemp=-numTemp;
            }

            else if(str=="%")
            {
                //qDebug()<<numStack.size()<<suffix->back();
                if(numStack.size()==0&&suffix->back()=='%'&&suffix->size()!=2)
                {
                    //为了防止11%=1100%这类问题的出现，不能让后缀表达式只有数字和百分号时触发
                    //qDebug()<<suffix->size();
                    numTemp=numFirst*100;//如果百分号是最后一个符号，那么*100并且最后在屏幕上显示%
                    isPercent=true;
                }
                else
                    numTemp=numFirst*0.01;//正常情况都是*0.01
            }
            if(qAbs(numTemp)<=1e-15)numTemp=0.0;//如果得到的结果特别小，默认为0处理
            numStack.push(numTemp);
        }
    }
    return numStack.top();
}
//返回答案
double Method::getAns(QString str)
{
    this->toMid(str);
    this->midTosuffix();
    double ans=this->calulate();
    //对堆区变量进行析构处理
    if(mid!=nullptr)
    {
        delete mid;
        mid=nullptr;
    }
    if(suffix!=nullptr)
    {
        delete suffix;
        suffix=nullptr;
    }
    if(posNegative!=nullptr)
    {
        delete posNegative;
        posNegative=nullptr;
    }
    return ans;
}

bool Method::getPercent()
{
    return isPercent;
}

int Method::getError()
{
    return errorIndex;
}
Method::priority(QString str)
{
    if(str=="+"||str=="-")
        return 1;
    else if(str=="*"||str=="/")
        return 2;
    else if(str=="^")
        return 3;
    else if(str=="sin"||str=="cos"||str=="tan"||str=="sqrt"||
            str=="ln"||str=="-sin"||str=="-cos"||str=="-tan"||str=="-sqrt"||str=="-ln")
        return 4;
    else
        return 0;
}

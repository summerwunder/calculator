#define FILENAME "history.txt"
#include "widget.h"
#include "ui_widget.h"
#include <QTextEdit>
#include <QDebug>
#include "method.h"
#include <QMessageBox>
#include <QFile>
#include <QDesktopServices>
bool Widget::isJD=true;//类内声明，类外定义
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("简易计算器");//设置标题
    this->setWindowIcon(QIcon(":/bj.png"));//设置图标
    OnlyOneInit();
    paraInit();
    //信号与槽函数的连接
    //数字
    connect(ui->btn0,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn1,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn2,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn3,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn4,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn5,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn6,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn7,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn8,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btn9,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btnE,&QPushButton::clicked,this,&Widget::numClicked);
    connect(ui->btnPi,&QPushButton::clicked,this,&Widget::numClicked);
    //小数点
    connect(ui->btnDeciaml,&QPushButton::clicked,this,&Widget::dotClicked);
    //算数表达式
    connect(ui->btnDivise,&QPushButton::clicked,this,&Widget::operatorClicked);
    connect(ui->btnPlus,&QPushButton::clicked,this,&Widget::operatorClicked);
    connect(ui->btnMul,&QPushButton::clicked,this,&Widget::operatorClicked);
    connect(ui->btnMinus,&QPushButton::clicked,this,&Widget::operatorClicked);
    connect(ui->btnPower,&QPushButton::clicked,this,&Widget::operatorClicked);
    //括号
    connect(ui->btnLeftBracket,&QPushButton::clicked,this,&Widget::bracketClicked);
    connect(ui->btnRightBracket,&QPushButton::clicked,this,&Widget::bracketClicked);
    //百分比
    connect(ui->btnPercent,&QPushButton::clicked,this,&Widget::percentClicked);
    //函数表达式
    connect(ui->btnLog,&QPushButton::clicked,this,&Widget::functionClicked);
    connect(ui->btnSin,&QPushButton::clicked,this,&Widget::functionClicked);
    connect(ui->btnCos,&QPushButton::clicked,this,&Widget::functionClicked);
    connect(ui->btnTan,&QPushButton::clicked,this,&Widget::functionClicked);
    connect(ui->btnSqrt,&QPushButton::clicked,this,&Widget::functionClicked);
    //等号
    connect(ui->btnEqu,&QPushButton::clicked,this,&Widget::equClicked);
    //消行
    connect(ui->btnClear,&QPushButton::clicked,this,&Widget::ceClicked);
    //删除
    connect(ui->btnBack,&QPushButton::clicked,this,&Widget::backClicked);
    //清空
    connect(ui->btnClearAll,&QPushButton::clicked,[=](){
        ui->textEdit->clear();
        paraInit();
    });
    //查看历史
    connect(ui->btnHistory,&QPushButton::clicked,[=](){
        if(!QDesktopServices::openUrl(QUrl(FILENAME)))
        {
            QMessageBox::critical(this,"error","File dont exist");//如果还未创建文件，就报错
        }
    });
    //角度制/弧度制
    connect(ui->btnJD,&QRadioButton::clicked,[=](){
        this->isJD=true;
        qDebug()<<"isJD";
    });
    connect(ui->btnHD,&QRadioButton::clicked,[=](){
        this->isJD=false;
        qDebug()<<"isHD";
    });
    //控制精度
    connect(ui->btnSci,&QCheckBox::toggled,[=](){
        if(!ui->btnSci->isChecked())
        {
            ui->label->setText("默认方法输出答案");
        }
        else
        {
            ui->label->setText("保留的小数位数");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::getIsJD()
{
    return isJD;
}

void Widget::OnlyOneInit()
{
    //对textEdit进行初始化
    QFont font;
    //对textEdit中的字体、大小、字宽进行定义
    font.setFamily("Dotum");
    font.setPointSize(20);
    font.setWeight(QFont::DemiBold);
    ui->textEdit->setFont(font);//加入字体
    //ui->textEdit->setText("0");//设置初始文本
    ui->textEdit->setReadOnly(true);//设置只读
    ui->textEdit->setTextInteractionFlags(Qt::NoTextInteraction);//设置文本不可选中
    ui->textEdit->setAlignment(Qt::AlignLeft|Qt::AlignTop);//设置左上对齐
    ui->textEdit->document()->setMaximumBlockCount(1000);//设置最大行数
    //对于spinBox的初始化
    ui->spinBox->setValue(4);//设置默认值
    ui->spinBox->setSingleStep(1);//步长
    ui->spinBox->setRange(0,25);//设置范围
    //单选框
    ui->btnJD->setChecked(true);//默认选中角度制
    ui->btnSci->setChecked(false);//默认未选中
    //设置颜色
    //按钮背景颜色
    ui->btnClear->setStyleSheet("background-color:rgb(255,255,125)");
    ui->btnEqu->setStyleSheet("background-color: rgb(123, 255, 246)");
    //字体颜色
    ui->btnPlus->setStyleSheet("color : rgb(0,70,255)");
    ui->btnMinus->setStyleSheet("color : rgb(0,70,255)");
    ui->btnDivise->setStyleSheet("color : rgb(0,70,255)");
    ui->btnMul->setStyleSheet("color : rgb(0,70,255)");
}

void Widget::paraInit()
{
    isDotClicked=true;
    isOperatorClicked=false;//不可以空输入表达式
    isZeroClicked=false;//不可以重复输入0
    isLeftBracketClicked=true;
    isRightBracketClicked=false;
    isPercentClicked=false;//不可以空输入百分号
    isNumClicked=true;
    isFunClicked=true;
    bracketNum=0;
}

QString Widget::getlastRow()
{
    this->rowCount=ui->textEdit->document()->lineCount();//获取行数
    QString text = ui->textEdit->toPlainText();
    QStringList number_list =text.split("\n");
    return number_list[rowCount-1];
}

void Widget::numClicked()
{
    if(!isNumClicked)return;
    //qDebug()<<rowCount;
    QPushButton* button=dynamic_cast<QPushButton*>(sender());
    //int buttonValue=button->text().toInt();
    //获取最后一行的字符集合
    QString lastRowStr=this->getlastRow();
    if(lastRowStr.right(1)=="Π"||lastRowStr.right(1)=="e")
    {
        QMessageBox::information(this,"tip","特殊字符后面不可以接数字");
        return;
    }
    if(((lastRowStr.right(1)<='9'&&lastRowStr.right(1)>='0')||lastRowStr.right(1)=='.')&&(button->text()=="Π"||button->text()=="e"))
    {
        QMessageBox::information(this,"tip","数字或小数点后面不能紧跟特殊数值");
        return;
    }
    if(button->text()=='0'&&lastRowStr.isEmpty())
    {
        isZeroClicked=false;//不可以重复输入0
    }
    if(!isZeroClicked)//如果不可以重复输入0，就删除尾置0，然后再加数字
    {
        //如果首字符为0，那么就将首字符删除
        if(lastRowStr.right(1)=='0')
        {
            QTextCursor cursor = ui->textEdit->textCursor();
            cursor.deletePreviousChar();
        }
        if(button->text()!='0')isZeroClicked=true;
        else isZeroClicked=false;
    }
    //将光标指向文章尾部，追加字符
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->textEdit->insertPlainText(button->text());
    isOperatorClicked=true;//更新了状态，可以输入表达式
    isRightBracketClicked=true;
    isLeftBracketClicked=false;
    isPercentClicked=true;
    isNumClicked=true;
    isFunClicked=false;//不可以在数字后面接单目函数表达式
}
void Widget::dotClicked()
{
    //获取最后一行的字符集合
    QString lastRowStr=this->getlastRow();
    if(lastRowStr.right(1)>='0'&&lastRowStr.right(1)<='9'&&isDotClicked)//前面的字符只能是数字
    {
        //将光标指向文章尾部，追加字符
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText(".");
        isZeroClicked=true;//可以无限输入0
        isDotClicked=false;//前面有小数点,不可以继续追加小数点
        isLeftBracketClicked=false;
        isRightBracketClicked=false;
        isPercentClicked=false;
        isNumClicked=true;
        isFunClicked=false;//不可以在小数点后面接函数表达式
    }
}

void Widget::operatorClicked()
{
    QPushButton* button=dynamic_cast<QPushButton*>(sender());
    QString lastRowStr=getlastRow();
    if(isOperatorClicked||(button->text()=='-'&&lastRowStr.right(1)=='('))//前面字符不能是表达式
    {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText(button->text());
        //当输入过表达式后，说明此时可以输入小数点（更新了状态)此时不可以输入表达式，必须等到输入数字，此时可以输入0
        isDotClicked=true;
        isOperatorClicked=false;
        isZeroClicked=false;//不可以重复输入0
        isLeftBracketClicked=true;
        isRightBracketClicked=false;
        isPercentClicked=false;
        isNumClicked=true;
        isFunClicked=true;
    }
}

void Widget::bracketClicked()
{
    QPushButton* button=dynamic_cast<QPushButton*>(sender());
    //获取最后一行的字符集合
    QString lastRowStr=this->getlastRow();
    if(button->text()=="(")
    if(isLeftBracketClicked||lastRowStr.isEmpty())
    {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText(button->text());
        //isLeftBracketClicked=false;
        isRightBracketClicked=true;
        isZeroClicked=false;
        isPercentClicked=false;
        isNumClicked=true;
        isFunClicked=true;
        bracketNum++;//计算括号数
    }
    //如果最后一个字符是（，那么不可以输入），避免（）的出现
    if(lastRowStr.right(1)=="(")isRightBracketClicked=false;
    if(button->text()==")")
    {
        if(isRightBracketClicked&&(!lastRowStr.isEmpty()))
        {
            ui->textEdit->moveCursor(QTextCursor::End);
            ui->textEdit->insertPlainText(button->text());
            isOperatorClicked=true;//允许输入表达式
            isLeftBracketClicked=false;//不能在）后紧邻（
            isPercentClicked=true;//可以在右括号后面跟百分号
            isNumClicked=false;//不可以在右括号后面紧跟数字
            isFunClicked=false;
            bracketNum--;//更新未配对括号数
        }
    }
}

void Widget::percentClicked()
{
    //获取最后一行的字符集合
    //QString lastRowStr=this->getlastRow();
    if(isPercentClicked)
    {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText("%");
        isLeftBracketClicked=false;//不可以在百分号后面输入左括号
        isDotClicked=false;//不可以在百分号后面输入小数点
        isPercentClicked=false;//不可以连续输入百分号
        isNumClicked=false;//不可以在百分号后面输入数字
        isFunClicked=false;
    }
}
void Widget::functionClicked()
{
    QPushButton* button=dynamic_cast<QPushButton*>(sender());
    //获取最后一行的字符集合
    //QString lastRowStr=this->getlastRow();
    if(isFunClicked)
    {
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->textEdit->insertPlainText(button->text()+"(");
        bracketNum++;//多了一个左括号
        isOperatorClicked=false;//不可以在函数运算符后紧接双目运算符
        isRightBracketClicked=true;//可以加右括号
        isZeroClicked=false;//不可以重复0
        isPercentClicked=false;//不可以紧接百分号
        isNumClicked=true;//可以接数字
        isFunClicked=true;//可以紧接函数运算符
    }
}

void Widget::equClicked()
{
    if(this->bracketNum!=0)
    {
        QMessageBox::critical(this,"error","左右括号不对等，出现错误");\
        return;
    }
        //获取最后一行的字符集合
    QString lastRowStr=this->getlastRow();
    if((lastRowStr.right(1)<='9'&&lastRowStr.right(1)>='0')
            ||lastRowStr.right(1)==')'||lastRowStr.right(1)=='%'
            ||lastRowStr.right(1).toLatin1()=="e"||lastRowStr.right(1)=="Π")
    {
        Method m;
        QString str;
        double ans=m.getAns(lastRowStr);//获取答案
        int precision=ui->spinBox->value();//获取精度
        qDebug()<<precision<<ans;
        if(m.getError()!=0)
        {
            this->reportError(m.getError());//查看是否报错
            return;
        }
        if(m.getPercent())
        {
            if(ui->btnSci->isChecked())//如果选择了设置小数，那么number使用f
            {
                str=QString("Answer=%1%").arg(QString::number(ans,'f',precision));
                this->writeToFile(lastRowStr,QString::number(ans,'f',precision)+"%");//写入文件
            }
            else//否则就按默认方式输出
            {
                str=QString("Answer=%1%").arg(QString::number(ans));
                this->writeToFile(lastRowStr,QString::number(ans)+"%");
            }
        }
        else
        {
            if(ui->btnSci->isChecked())
            {
                str=QString("Answer=%1").arg(QString::number(ans,'f',precision));
                this->writeToFile(lastRowStr,QString::number(ans,'f',precision));
            }
            else
            {
                str=QString("Answer=%1").arg(QString::number(ans));
                this->writeToFile(lastRowStr,QString::number(ans));
            }
        }
        ui->textEdit->append(str);//显示结果
        ui->textEdit->append("\n");//换行
        this->paraInit();//下次计算需要更新参数状态
        return;
    }
        QMessageBox::critical(this,"error","语法错误");
        return;
}
void Widget::ceClicked()
{
    //获取最后一行的字符集合
    QString lastRowStr=this->getlastRow();
    for(int i=0;i<lastRowStr.size();i++)//遍历，将每个字符全部删除
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.deletePreviousChar();
    }
    paraInit();//更新参数的初始化
}

void Widget::backClicked()
{
    //获取最后一行的字符集合
    QString lastRowStr=this->getlastRow();
    if(lastRowStr.isEmpty()) return;//如果最后一行删的什么都不剩，那么取消这次操作
    if(lastRowStr.right(1)==")") bracketNum++;//如果删除的时右括号，左括号（净）加一个
    else if(lastRowStr.right(1)=="(") bracketNum--;//如果删除的时左括号，左括号（净）减一个
    else if(lastRowStr.right(1)==".")
    {
        isDotClicked=true;//可以输入小数点
        isZeroClicked=false;//不可以重复输入0
    }
    QString str=lastRowStr.right(2);
    if(str=="in"||str=="os"||str=="an")//删除三个字符
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.deletePreviousChar();
        cursor.deletePreviousChar();
        cursor.deletePreviousChar();
    }
    else if(str=="rt")//删除四个字符
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        for(int i=0;i<4;i++)
        {
           cursor.deletePreviousChar();
        }
    }
    else if(str=="ln")//删除两个字符
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.deletePreviousChar();
        cursor.deletePreviousChar();
    }
    else
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.deletePreviousChar();
    }
    lastRowStr=this->getlastRow();
    //根据最后一个字符判断布尔变量的值
    if(lastRowStr.isEmpty())
    {
        paraInit();
    }
    else if((lastRowStr.right(1)>='0'&&lastRowStr.right(1)<='9')
          ||lastRowStr.right(1).toLatin1()=="e"||lastRowStr.right(1)=="Π")
    {
        isOperatorClicked=true;//更新了状态，可以输入表达式
        isRightBracketClicked=true;
        isLeftBracketClicked=false;
        isPercentClicked=true;
        isNumClicked=true;
        isFunClicked=false;//不可以在数字后面接单目函数表达式
    }
    else if(lastRowStr.right(1)=='.')
    {
        isOperatorClicked=false;
        isLeftBracketClicked=false;
        isRightBracketClicked=false;
        isPercentClicked=false;
    }
    else if(lastRowStr.right(1)=='+'||lastRowStr.right(1)=='-'||
            lastRowStr.right(1)=='*'||lastRowStr.right(1)=='/'||
            lastRowStr.right(1)=='^')
    {
        isDotClicked=true;
        isOperatorClicked=false;
        isZeroClicked=false;
        isLeftBracketClicked=true;
        isRightBracketClicked=false;
        isPercentClicked=false;
        isNumClicked=true;
        isFunClicked=true;
    }
    else if(lastRowStr.right(1)=='%')
    {
        isLeftBracketClicked=false;//不可以在百分号后面输入左括号
        isDotClicked=false;//不可以在百分号后面输入小数点
        isPercentClicked=false;//不可以连续输入百分号
        isNumClicked=false;//不可以在百分号后面输入数字
        isFunClicked=false;
    }
    else if(lastRowStr.right(1)==")")
    {
        isOperatorClicked=true;//允许输入表达式
        isLeftBracketClicked=false;//不能在）后紧邻(
        isRightBracketClicked-true;
        isPercentClicked=true;//可以在右括号后面跟百分号
        isNumClicked=false;//不可以在右括号后面紧跟数字
        isFunClicked=false;
    }
    else if(lastRowStr.right(1)=="(")
    {
        isRightBracketClicked=true;
        isZeroClicked=false;
        isPercentClicked=false;
        isNumClicked=true;
        isFunClicked=true;
    }
    else
    {
        isOperatorClicked=false;//不可以在函数运算符后紧接双目运算符
        isRightBracketClicked=false;
        isZeroClicked=false;//不可以重复0
        isPercentClicked=false;//不可以紧接百分号
        isNumClicked=false;
        isFunClicked=false;//可以紧接函数运算符
        isLeftBracketClicked=true;
    }
    if(lastRowStr.isEmpty())
    {
        paraInit();//如果全部删完了，就初始化
    }
}

void Widget::writeToFile(QString str, QString ans)
{
    QFile file(FILENAME);
    if(!file.open(QIODevice::Append))
    {
        QMessageBox::warning(this,"WriteFile","can't open",QMessageBox::Yes);//如果文件不能正常打开，则反馈
    }
    QString strTemp=str+"="+ans;
    QTextStream stream(&file);
    stream<<strTemp<<"\n";
    file.close();
}

void Widget::reportError(int index)
{
    QVector<QString> vError;
    vError.push_back("不可以将负数或者0作为对数函数的真数");//1
    vError.push_back("正切函数的90°角及其倍数角未定义");//2
    vError.push_back("除数不能为0");
    vError.push_back("不能将0作为幂函数的底数");
    vError.push_back("不能对负数取平方根（实数范围内");
    QMessageBox::critical(this,"error",vError[index-1]);//报错
}

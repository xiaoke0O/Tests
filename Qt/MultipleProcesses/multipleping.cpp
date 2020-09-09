#include "multipleping.h"
#include "./ui_multipleping.h"

#include<QProcess>

MultiplePing::MultiplePing(QWidget *parent)
        : QWidget(parent), ui(new Ui::MultiplePing) {
    ui->setupUi(this);

    connect(ui->pushButtonPingBaidu, &QPushButton::clicked, this, &MultiplePing::startPing);
    connect(ui->pushButtonPingSanchor, &QPushButton::clicked, this, &MultiplePing::startPing);
    connect(ui->pushButtonPingBing, &QPushButton::clicked, this, &MultiplePing::startPing);
    connect(ui->pushButtonPingJD, &QPushButton::clicked, this, &MultiplePing::startPing);
}

void MultiplePing::startPing() {
    //!所有按钮的组合
    QList<QPushButton *> buttons = {ui->pushButtonPingBaidu,
                                    ui->pushButtonPingSanchor,
                                    ui->pushButtonPingBing,
                                    ui->pushButtonPingJD};
    //!所有文本窗口的组合
    QList<QTextBrowser *> browsers = {ui->textBrowserBaidu,
                                      ui->textBrowserSanchor,
                                      ui->textBrowserBing,
                                      ui->textBrowserJD};
    //!所有执行参数的组合
    QList<QStringList> args = {{"www.baidu.com"},
                               {"www.sanchor.xyz"},
                               {"cn.bing.com"},
                               {"www.jd.com"}};
    //!组合的形式是为了对应相应的按钮输出窗口与执行参数，方便索引

    //!哪个按钮发送的信号
    auto *button = qobject_cast<QPushButton *>(sender());
    //!这个按钮在按钮组里是第几个
    int index = buttons.indexOf(button);
    //!新建进程
    auto *process = new QProcess;
    //!读取进程的输出什么（输出错误还是标准运行输出）
    process->setReadChannel(QProcess::StandardOutput);
    //!绑定开始信号，当进程开始时，在相应文本窗口显示Start Ping 网址
    connect(process, &QProcess::started, [=]() {
        browsers.at(index)->append(tr("Start Ping %1").arg(args[index][0]));
    });
    //!绑定输出输出信号，实时在对应的文本窗口输出运行输出内容。采用追加模式append
    connect(process, &QProcess::readyReadStandardOutput, [=]() {
        browsers.at(index)->append(process->readAllStandardOutput());
    });
    //!绑定结束信号。并在对应的文本从窗口输出结束信息，包括错误码和退出状态（正常退出还是崩溃退出）
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [=](int exitcode, QProcess::ExitStatus exitStatus) {
                browsers.at(index)->append(tr("线程已结束，返回错误代码为%1").arg(exitcode));
            });
    //!执行ping命令
    process->start("ping", args.at(index));

}

MultiplePing::~MultiplePing() {
    delete ui;
}


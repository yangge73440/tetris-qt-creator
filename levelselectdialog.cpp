#include "levelselectdialog.h"
#include "adventurewindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>

LevelSelectDialog::LevelSelectDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

LevelSelectDialog::~LevelSelectDialog()
{
}

void LevelSelectDialog::setupUI()
{
    // 设置窗口标题和样式
    setWindowTitle("选择关卡");
    setStyleSheet(R"(
        QDialog {
            background-color: rgb(255, 240, 245);
        }
        QPushButton {
            border: 2px solid rgb(255, 85, 127);
            border-radius: 10px;
            background-color: rgb(255, 182, 193);
            font: 700 14pt "Microsoft YaHei UI";
            color: rgb(255, 85, 127);
            padding: 10px;
            min-width: 80px;
            min-height: 60px;
        }
        QPushButton:hover {
            background-color: rgb(255, 85, 127);
            color: white;
        }
        QLabel {
            border: 0;
            font: 700 20pt "Microsoft YaHei UI";
            color: rgb(255, 85, 127);
        }
    )");
    
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    // 创建标题
    labelTitle = new QLabel("🎮 闯关模式 - 选择关卡", this);
    labelTitle->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(labelTitle);
    
    // 创建关卡按钮的网格布局
    QGridLayout *gridLayout = new QGridLayout();
    
    // 创建20个关卡按钮
    for (int i = 0; i < 20; ++i) {
        levelButtons[i] = new QPushButton(QString("第 %1 关").arg(i + 1), this);
        levelButtons[i]->setProperty("level", i + 1);
        connect(levelButtons[i], &QPushButton::clicked, this, &LevelSelectDialog::onLevelButtonClicked);
        gridLayout->addWidget(levelButtons[i], i / 5, i % 5);
    }
    
    mainLayout->addLayout(gridLayout);
    
    // 创建无尽模式按钮
    pbEndless = new QPushButton("♾️ 无尽模式", this);
    pbEndless->setStyleSheet(R"(
        QPushButton {
            border: 3px solid #FFD700;
            border-radius: 15px;
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFD700, stop:1 #FFA500);
            font: 700 16pt "Microsoft YaHei UI";
            color: #8B4513;
            padding: 15px;
            min-height: 70px;
        }
        QPushButton:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFA500, stop:1 #FF8C00);
            color: white;
        }
    )");
    connect(pbEndless, &QPushButton::clicked, this, &LevelSelectDialog::onEndlessClicked);
    mainLayout->addWidget(pbEndless);
    
    // 创建返回按钮
    pbBack = new QPushButton("← 返回主菜单", this);
    connect(pbBack, &QPushButton::clicked, this, &LevelSelectDialog::onBackClicked);
    mainLayout->addWidget(pbBack);
}

void LevelSelectDialog::onLevelButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        int level = button->property("level").toInt();
        emit levelSelected(level);
        accept();
    }
}

void LevelSelectDialog::onEndlessClicked()
{
    emit levelSelected(-1);
    accept();
}

void LevelSelectDialog::onBackClicked()
{
    reject();
}

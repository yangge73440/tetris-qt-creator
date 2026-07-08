#include "hiteffect.h"
#include <QGraphicsDropShadowEffect>

HitEffect::HitEffect(QWidget *parent)
    : QWidget(parent)
    , m_hitLabel(new QLabel(this))
    , m_hitOpacity(new QGraphicsOpacityEffect(this))
    , m_hitAnim(new QSequentialAnimationGroup(this))
    , m_slideInAnim(new QPropertyAnimation(this, "geometry", this))
    , m_scaleAnim(new QPropertyAnimation(this, "geometry", this))
    , m_slideOutAnim(new QPropertyAnimation(this, "geometry", this))
    , m_layout(new QVBoxLayout(this))
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);
    
    m_hitLabel->setAlignment(Qt::AlignCenter);
    m_hitLabel->hide();
    
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(28);
    font.setBold(true);
    m_hitLabel->setFont(font);
    
    m_hitLabel->setGraphicsEffect(m_hitOpacity);
    
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(10);
    shadow->setColor(QColor(0, 0, 0, 150));
    shadow->setOffset(2, 2);
    m_hitLabel->setGraphicsEffect(shadow);
    
    m_layout->addWidget(m_hitLabel);
    m_layout->setContentsMargins(0, 0, 0, 0);
    
    // 初始化动画但不立即开始
    m_slideInAnim->setDuration(300);
    m_slideInAnim->setEasingCurve(QEasingCurve::OutBack);
    
    m_scaleAnim->setDuration(200);
    m_scaleAnim->setEasingCurve(QEasingCurve::OutElastic);
    
    m_slideOutAnim->setDuration(400);
    m_slideOutAnim->setEasingCurve(QEasingCurve::InCubic);
}

void HitEffect::showHit(int hitCount, const QPoint &startPos)
{
    // 如果之前有动画正在运行，先停止并重置
    if (m_hitAnim->state() == QAbstractAnimation::Running) {
        m_hitAnim->stop();
    }
    
    QString text;
    QColor color;
    
    switch(hitCount) {
        case 1:
            text = "1 HIT!";
            color = QColor(255, 200, 50);
            break;
        case 2:
            text = "2 HITS!";
            color = QColor(255, 150, 50);
            break;
        case 3:
            text = "3 HITS!";
            color = QColor(255, 100, 50);
            break;
        default:
            text = QString("%1 HITS!").arg(hitCount);
            color = QColor(255, 50, 50);
            break;
    }
    
    m_hitLabel->setText(text);
    m_hitLabel->setStyleSheet(QString("color: %1;").arg(color.name()));
    m_hitLabel->show();
    
    QRect startRect(startPos.x(), startPos.y(), 200, 60);
    QRect midRect(startPos.x(), startPos.y() - 50, 250, 70);
    QRect endRect(startPos.x() + 50, startPos.y() - 100, 300, 80);
    
    m_slideInAnim->setStartValue(startRect);
    m_slideInAnim->setEndValue(midRect);
    
    m_scaleAnim->setStartValue(midRect);
    m_scaleAnim->setEndValue(endRect);
    
    m_slideOutAnim->setStartValue(endRect);
    m_slideOutAnim->setEndValue(endRect.translated(100, 0));
    
    m_hitAnim->clear();
    m_hitAnim->addAnimation(m_slideInAnim);
    m_hitAnim->addAnimation(m_scaleAnim);
    m_hitAnim->addPause(500);
    m_hitAnim->addAnimation(m_slideOutAnim);
    
    connect(m_hitAnim, &QSequentialAnimationGroup::finished, this, [this]() {
        m_hitLabel->hide();
    });
    
    m_hitAnim->start();
}

void HitEffect::showBubble(const QString &text, const QPoint &pos)
{
    QLabel *bubble = new QLabel(this);
    bubble->setText(text);
    bubble->setAlignment(Qt::AlignCenter);
    bubble->setStyleSheet(
        "color: white; background-color: rgba(255, 85, 127, 0.8); "
        "border-radius: 15px; padding: 10px;"
    );
    
    QFont bubbleFont;
    bubbleFont.setFamily("Microsoft YaHei");
    bubbleFont.setPointSize(16);
    bubbleFont.setBold(true);
    bubble->setFont(bubbleFont);
    
    bubble->move(pos);
    bubble->show();
    
    QPropertyAnimation *floatAnim = new QPropertyAnimation(bubble, "geometry", this);
    QRect startRect(pos.x(), pos.y(), 150, 50);
    QRect endRect(pos.x() - 30, pos.y() - 150, 180, 60);
    floatAnim->setStartValue(startRect);
    floatAnim->setEndValue(endRect);
    floatAnim->setDuration(1500);
    floatAnim->setEasingCurve(QEasingCurve::OutQuad);
    
    QGraphicsOpacityEffect *bubbleOpacity = new QGraphicsOpacityEffect(bubble);
    bubble->setGraphicsEffect(bubbleOpacity);
    QPropertyAnimation *fadeAnim = new QPropertyAnimation(bubbleOpacity, "opacity", this);
    fadeAnim->setStartValue(1.0);
    fadeAnim->setEndValue(0.0);
    fadeAnim->setDuration(1500);
    
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(floatAnim);
    group->addAnimation(fadeAnim);
    
    connect(group, &QParallelAnimationGroup::finished, bubble, [bubble, this]() {
        bubble->hide();
        bubble->deleteLater();
    });
    
    group->start();
}

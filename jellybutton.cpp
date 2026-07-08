#include "jellybutton.h"
#include <QPainter>
#include <QEvent>
#include <QEnterEvent>

JellyButton::JellyButton(QWidget *parent)
    : QPushButton(parent)
{
    setStyleSheet(R"(
        QPushButton {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1, 
                stop:0 #FFFFF0, stop:1 #FFF8DC);
            border: 3px solid #DEB887;
            border-radius: 15px;
            font: 700 16pt "Microsoft YaHei UI";
            color: #8B4513;
            padding: 10px 20px;
            min-height: 60px;
        }
        QPushButton:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1, 
                stop:0 #FFF8DC, stop:1 #FAFAD2);
            color: #654321;
        }
    )");

    m_enterAnimation = new QPropertyAnimation(this, "jellyScale");
    m_enterAnimation->setDuration(500);
    m_enterAnimation->setEasingCurve(QEasingCurve::OutElastic);
    m_enterAnimation->setStartValue(1.0);
    m_enterAnimation->setEndValue(1.15);

    m_leaveAnimation = new QPropertyAnimation(this, "jellyScale");
    m_leaveAnimation->setDuration(400);
    m_leaveAnimation->setEasingCurve(QEasingCurve::OutElastic);
    m_leaveAnimation->setStartValue(1.15);
    m_leaveAnimation->setEndValue(1.0);
}

void JellyButton::setJellyScale(qreal scale)
{
    m_jellyScale = scale;
    update();
}

void JellyButton::enterEvent(QEnterEvent *event)
{
    QPushButton::enterEvent(event);
    m_leaveAnimation->stop();
    m_enterAnimation->start();
}

void JellyButton::leaveEvent(QEvent *event)
{
    QPushButton::leaveEvent(event);
    m_enterAnimation->stop();
    m_leaveAnimation->start();
}

void JellyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    QRect rect = contentsRect();
    QPoint center = rect.center();
    
    painter.save();
    painter.translate(center);
    painter.scale(m_jellyScale, m_jellyScale);
    painter.translate(-center);
    
    QColor startColor = QColor(255, 255, 240);
    QColor endColor = QColor(255, 248, 220);
    
    if (underMouse()) {
        startColor = QColor(255, 248, 220);
        endColor = QColor(250, 250, 210);
    }
    
    QLinearGradient gradient(rect.topLeft(), rect.bottomRight());
    gradient.setColorAt(0, startColor);
    gradient.setColorAt(1, endColor);
    
    painter.setBrush(gradient);
    painter.setPen(QPen(QColor(222, 184, 135), 3));
    painter.drawRoundedRect(rect.adjusted(2, 2, -2, -2), 15, 15);
    
    painter.setPen(underMouse() ? QColor(101, 67, 33) : QColor(139, 69, 19));
    QFont font = this->font();
    font.setBold(true);
    font.setPointSize(16);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, text());
    
    painter.restore();
}
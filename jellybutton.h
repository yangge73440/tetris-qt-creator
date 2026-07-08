#ifndef JELLYBUTTON_H
#define JELLYBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QEnterEvent>

class JellyButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(qreal jellyScale READ jellyScale WRITE setJellyScale)

public:
    explicit JellyButton(QWidget *parent = nullptr);

    qreal jellyScale() const { return m_jellyScale; }
    void setJellyScale(qreal scale);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    qreal m_jellyScale = 1.0;
    QPropertyAnimation *m_enterAnimation = nullptr;
    QPropertyAnimation *m_leaveAnimation = nullptr;
};

#endif // JELLYBUTTON_H
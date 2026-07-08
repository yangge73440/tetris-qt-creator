#ifndef HITEFFECT_H
#define HITEFFECT_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QVBoxLayout>

class HitEffect : public QWidget
{
    Q_OBJECT
public:
    explicit HitEffect(QWidget *parent = nullptr);
    
    void showHit(int hitCount, const QPoint &startPos);
    void showBubble(const QString &text, const QPoint &pos);

private:
    QLabel *m_hitLabel;
    QGraphicsOpacityEffect *m_hitOpacity;
    QSequentialAnimationGroup *m_hitAnim;
    QPropertyAnimation *m_slideInAnim;
    QPropertyAnimation *m_scaleAnim;
    QPropertyAnimation *m_slideOutAnim;
    QVBoxLayout *m_layout;
};

#endif // HITEFFECT_H

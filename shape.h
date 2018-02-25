#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include "configure.h"

class Shape : public QObject
{
    Q_OBJECT
public:
    // 枚举变量，几个图形的选择
    enum ShapeType {None,Point,Line,Rectangle,Ellipse};
    Shape();
    void setScaleFactor(qreal scaleFactor);
    void setMoveable(bool moveable);  // 设置可移动性
    virtual void startDraw(QGraphicsSceneMouseEvent * event) = 0;
    virtual void drawing(QGraphicsSceneMouseEvent * event) = 0;
    virtual void setPenStyle(PenStyle penstyle) = 0;  // 设置实体类型
    virtual void setEntityUnderCursorStyle(PenStyle underCursorStyle) = 0;  // 设置光标下类型
    void setShapeId(int id);  // 设置实体id
    int getShapeId();  // 获取实体id

    void setLayer(QString layer);  // 设置图层
    QString getLayer();  // 获取图层

    void setShapeType(ShapeType shape);  // 设置类型
    ShapeType getShapeType();  // 获取类型

    void setOverFlag(bool overFlag);  // 结束标志

protected:
    qreal scaleFactor;  // 缩放因子
    bool moveable;  // 是否可移动

    int id;  // 编号
    PenStyle penStyle;  // 属性
    PenStyle underCursorStyle;  // 光标下属性
    QString layer;  // 图层名称
    ShapeType shape;  // 类型

    bool overFlag;  // 结束标识

signals:
    void sceneMoveableChanged(bool moveable);  // 场景可移动性信号

public slots:
    virtual void onSceneMoveableChanged(bool moveable) = 0;  //  响应场景可移动性改变

};

#endif // SHAPE_H

#ifndef ANNOTATIONBASE_H
#define ANNOTATIONBASE_H

#include <QQuickItem>

class QSGGeometry;

class AnnotationBase : public QQuickItem
{
    Q_OBJECT
public:
	AnnotationBase(QQuickItem *parent = 0);
protected:
    virtual QSGNode *updatePaintNode(QSGNode* node, UpdatePaintNodeData* data) override;
	QSGGeometry* createGeometry(const QPointF& center);
private slots:
	void handleWindowChanged(QQuickWindow *);
	void handleBeforeRendering();
};

#endif // ANNOTATIONBASE_H

#include "annotationbase.h"

#include <QSGNode>
#include <QSGFlatColorMaterial>
#include <QSGGeometry>

#include <private\qquickitem_p.h>

AnnotationBase::AnnotationBase(QQuickItem *parent)
	: QQuickItem(parent)
{
    setFlag(ItemHasContents);
	connect(this, &QQuickItem::windowChanged, this, &AnnotationBase::handleWindowChanged);
}

void AnnotationBase::handleWindowChanged(QQuickWindow * wnd)
{
    if (wnd)
        connect(wnd, &QQuickWindow::beforeRendering, this, &AnnotationBase::handleBeforeRendering, Qt::DirectConnection);
}

void AnnotationBase::handleBeforeRendering()
{
    QQuickItemPrivate *itemPriv = QQuickItemPrivate::get(this);
    auto extra = (QQuickItemPrivate::ExtraData*)(itemPriv->extra.operator->());
    if (extra && extra->clipNode)
    {
        auto clipNode = extra->clipNode;
        clipNode->setIsRectangular(false);
        auto rect = clipNode->clipRect();

        clipNode->setGeometry(
            createGeometry(
                rect.center()));
		clipNode->setFlag(QSGNode::OwnsGeometry, true);
    }
}

QSGNode *AnnotationBase::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *data)
{
    Q_UNUSED(data)
    delete oldNode;

	auto mat = new QSGFlatColorMaterial();
	mat->setColor(Qt::yellow);

	QSGGeometryNode* node = new QSGGeometryNode();
    node->setFlags(QSGNode::OwnsMaterial | QSGNode::OwnsMaterial);
	node->setMaterial(mat);
	node->setGeometry(
		createGeometry(
			boundingRect().center()));
	node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

    return node;
}

QSGGeometry* AnnotationBase::createGeometry(const QPointF& center)
{
	QSGGeometry* geom = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 3);
	QSGGeometry::Point2D *vertices = geom->vertexDataAsPoint2D();
	geom->setDrawingMode(GL_TRIANGLE_STRIP);
	const float PI = 3.1415927f;
	float angle = PI / 6;
	vertices[0].set(center.x() - 150 * cos(angle), center.y() - 150 * sin(angle));
	vertices[1].set(center.x() + 150 * cos(angle), center.y() - 150 * sin(angle));
	vertices[2].set(center.x(), center.y() + 150);

	return geom;
}

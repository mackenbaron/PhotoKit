/******************************************************************************
	TransformMachine.h: description
	Copyright (C) 2012 Wang Bin <wbsecg1@gmail.com>
	
	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
******************************************************************************/
//code is stolen from qgraphicsitemanimation ^_^

#ifndef PHOTOKIT_TRANSFORMMACHINE_H
#define PHOTOKIT_TRANSFORMMACHINE_H


#include <QtCore/qobject.h>

class QMatrix;
class QPointF;
class QTimeLine;

template <class T1, class T2> struct QPair;

namespace PhotoKit {

class TransformMachinePrivate;
class TransformMachine : public QObject
{
	Q_OBJECT
public:
	TransformMachine(QObject *parent = 0);
	virtual ~TransformMachine();

	QTimeLine *timeLine() const;
	void setTimeLine(QTimeLine *timeLine);

	QPointF posAt(qreal step) const;
	QList<QPair<qreal, QPointF> > posList() const;
	void setPosAt(qreal step, const QPointF &pos);

	QMatrix matrixAt(qreal step) const;
	void setStartMatrix(const QMatrix& m);

	qreal rotationAt(qreal step) const;
	QList<QPair<qreal, qreal> > rotationList() const;
	void setRotationAt(qreal step, qreal angle);

	qreal xTranslationAt(qreal step) const;
	qreal yTranslationAt(qreal step) const;
	QList<QPair<qreal, QPointF> > translationList() const;
	void setTranslationAt(qreal step, qreal dx, qreal dy);

	qreal verticalScaleAt(qreal step) const;
	qreal horizontalScaleAt(qreal step) const;
	QList<QPair<qreal, QPointF> > scaleList() const;
	void setScaleAt(qreal step, qreal sx, qreal sy);

	qreal verticalShearAt(qreal step) const;
	qreal horizontalShearAt(qreal step) const;
	QList<QPair<qreal, QPointF> > shearList() const;
	void setShearAt(qreal step, qreal sh, qreal sv);

	qreal zValueAt(qreal step) const;
	QList<QPair<qreal, qreal> > zValueList() const;
	void setZValueAt(qreal step, qreal value);

	void clear();

Q_SIGNALS:
	void matrixChanged(const QMatrix& matrix);
	void zValueChanged(qreal value);
	void scaleChanged(qreal sx, qreal sy);
	void translationChanged(qreal dx, qreal dy);

public Q_SLOTS:
	void setStep(qreal x);
	void reset();

protected:
	virtual void beforeAnimationStep(qreal step);
	virtual void afterAnimationStep(qreal step);

private:
	Q_DISABLE_COPY(TransformMachine)
	TransformMachinePrivate *d;
};

} //namespace PhotoKit

#endif // PHOTOKIT_TRANSFORMMACHINE_H

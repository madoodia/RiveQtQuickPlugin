// SPDX-FileCopyrightText: 2023 Jeremias Bosch <jeremias.bosch@basyskom.com>
// SPDX-FileCopyrightText: 2023 basysKom GmbH
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include <QPainterPath>
#include <QPen>

#include <rive/renderer.hpp>
#include <rive/math/raw_path.hpp>

#include "datatypes.h"

class SubPath;

class RiveQtPath : public rive::RenderPath
{
public:
    RiveQtPath(const unsigned segmentCount);
    RiveQtPath(const RiveQtPath &other);
    RiveQtPath(rive::RawPath &rawPath, rive::FillRule fillRule, const unsigned segmentCount);

    void rewind() override;
    void moveTo(float x, float y) override { m_path.moveTo(x, y); }
    void lineTo(float x, float y) override { m_path.lineTo(x, y); }
    void cubicTo(float ox, float oy, float ix, float iy, float x, float y) override { m_path.cubicTo(ox, oy, ix, iy, x, y); }
    void close() override { m_path.closeSubpath(); }
    void fillRule(rive::FillRule value) override;
    void addRenderPath(RenderPath *path, const rive::Mat2D &transform) override;

    void setQPainterPath(QPainterPath path);
    QPainterPath toQPainterPath() const { return m_path; }
    QPainterPath toQPainterPaths(const QMatrix4x4 &t);

    void setSegmentCount(const unsigned segmentCount);

    QVector<QVector<QVector2D>> toVertices();
    QVector<QVector<QVector2D>> toVerticesLine(const QPen &pen);

private:
    void generateVertices();
    void generateOutlineVertices();

    QVector<QVector2D> qpainterPathToVector2D(const QPainterPath &path);
    QVector<QVector2D> qpainterPathToOutlineVector2D(const QPainterPath &path);
    QPointF cubicBezier(const QPointF &startPoint, const QPointF &controlPoint1, const QPointF &controlPoint2, const QPointF &endPoint,
                        qreal t);

    QPainterPath m_path;
    std::vector<SubPath> m_subPaths;
    QVector<QVector<QVector2D>> m_pathSegmentsData;
    QVector<QVector<QVector2D>> m_pathSegmentsOutlineData;
    QVector<QVector<QVector2D>> m_pathOutlineData;

    bool m_isClosed { false };
    bool m_pathSegmentDataDirty { false };
    bool m_pathSegmentOutlineDataDirty { false };

    unsigned m_segmentCount { 10 };
};

class SubPath
{
public:
    SubPath(RiveQtPath *path, const QMatrix4x4 &transform);

    RiveQtPath *path() const;
    QMatrix4x4 transform() const;

private:
    RiveQtPath *m_Path;
    QMatrix4x4 m_Transform;
};
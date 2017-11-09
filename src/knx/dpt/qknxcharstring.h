/******************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtKnx module.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
******************************************************************************/

#ifndef QKNXCHARSTRING_H
#define QKNXCHARSTRING_H

#include <QtKnx/qknxdatapointtype.h>
#include <QtKnx/qknxglobal.h>

QT_BEGIN_NAMESPACE

class Q_KNX_EXPORT QKnxCharString : public QKnxFixedSizeDatapointType
{
public:
    QKnxCharString();
    explicit QKnxCharString(QLatin1String string);

    static const constexpr int TypeSize = 0x0e;
    static const constexpr int MainType = 0x10;

    QLatin1String string() const;
    bool setString(QLatin1String string);

    bool isValid() const override;

protected:
    QKnxCharString(int subType, QLatin1String string);
};

class Q_KNX_EXPORT QKnxCharStringASCII : public QKnxCharString
{
public:
    QKnxCharStringASCII();
    explicit QKnxCharStringASCII(QLatin1String string);
};

class Q_KNX_EXPORT QKnxCharString88591 : public QKnxCharString
{
public:
    QKnxCharString88591();
    explicit QKnxCharString88591(QLatin1String string);

    static const constexpr int SubType = 0x01;
};

QT_END_NAMESPACE

#endif
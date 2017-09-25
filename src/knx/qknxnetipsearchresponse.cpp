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

#include "qknxnetipsearchresponse.h"

QT_BEGIN_NAMESPACE

QKnxNetIpSearchResponse::QKnxNetIpSearchResponse(const QKnxNetIpHpai &controlEndpoint,
    const QKnxNetIpDeviceDib &deviceHardware, const QKnxNetIpServiceFamiliesDib &supportedFamilies)
    : QKnxNetIpFrame(QKnxNetIp::ServiceType::SearchResponse)
{
    QKnxNetIpPayload payload;
    payload.setBytes(controlEndpoint.bytes());
    payload.appendBytes(deviceHardware.bytes());
    payload.appendBytes(supportedFamilies.bytes());
    setPayload(payload);
}

QKnxNetIpSearchResponse::QKnxNetIpSearchResponse(const QKnxNetIpFrame &other)
    : QKnxNetIpFrame(other)
{}

QKnxNetIpHpai QKnxNetIpSearchResponse::controlEndpoint() const
{
    return QKnxNetIpHpai::fromBytes(payloadRef(), 0);
}

QKnxNetIpDeviceDib QKnxNetIpSearchResponse::deviceHardware() const
{
    return QKnxNetIpDeviceDib::fromBytes(payloadRef(), 8);
}

QKnxNetIpServiceFamiliesDib QKnxNetIpSearchResponse::supportedFamilies() const
{
    return QKnxNetIpServiceFamiliesDib::fromBytes(payloadRef(), 62);
}

bool QKnxNetIpSearchResponse::isValid() const
{
    return QKnxNetIpFrame::isValid() && size() >= 70
        && code() == QKnxNetIp::ServiceType::SearchResponse;
}

QT_END_NAMESPACE

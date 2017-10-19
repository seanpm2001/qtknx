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

#ifndef QKNXNETIPDISCOVERYAGENT_P_H
#define QKNXNETIPDISCOVERYAGENT_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qtimer.h>
#include <QtKnx/qknxglobal.h>
#include <QtKnx/qknxnetip.h>
#include <QtKnx/qknxnetipsearchrequest.h>
#include <QtKnx/qknxnetipsearchresponse.h>
#include <QtKnx/qknxnetipserverdiscoveryagent.h>
#include <QtNetwork/qhostaddress.h>
#include <QtNetwork/qnetworkdatagram.h>
#include <QtNetwork/qudpsocket.h>

#include <private/qobject_p.h>

QT_BEGIN_NAMESPACE

class Q_KNX_EXPORT QKnxNetIpServerDiscoveryAgentPrivate final : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QKnxNetIpServerDiscoveryAgent)

public:
    QKnxNetIpServerDiscoveryAgentPrivate(const QHostAddress &addr, quint16 prt);
    ~QKnxNetIpServerDiscoveryAgentPrivate() override = default;

    void setupSocket();

    void setupAndStartReceiveTimer();
    void setupAndStartFrequencyTimer();

    void setAndEmitStateChanged(QKnxNetIpServerDiscoveryAgent::State newState);
    void setAndEmitDeviceDiscovered(const QKnxNetIpServerInfo &discoveryInfo);
    void setAndEmitErrorOccurred(QKnxNetIpServerDiscoveryAgent::Error e, const QString &message);

private:
    QUdpSocket *socket { nullptr };
    QTimer *receiveTimer { nullptr };
    QTimer *frequencyTimer { nullptr };

    quint16 port { 0 }, usedPort;
    QHostAddress address { QHostAddress::AnyIPv4 }, usedAddress;

    const quint16 multicastPort { QKnxNetIp::DefaultPort };
    const QHostAddress multicastAddress { QLatin1String(QKnxNetIp::MulticastAddress) };

    quint8 ttl { 60 };
    bool nat { false };
    int frequency { 0 };
    int timeout { QKnxNetIp::Timeout::SearchTimeout };

    QString errorString;
    QVector<QKnxNetIpServerInfo> servers;

    QKnxNetIpServerDiscoveryAgent::Error error { QKnxNetIpServerDiscoveryAgent::Error::None };
    QKnxNetIpServerDiscoveryAgent::State state { QKnxNetIpServerDiscoveryAgent::State::NotRunning };
    QKnxNetIpServerDiscoveryAgent::ResponseType
        type { QKnxNetIpServerDiscoveryAgent::ResponseType::Multicast };
};

QT_END_NAMESPACE

#endif
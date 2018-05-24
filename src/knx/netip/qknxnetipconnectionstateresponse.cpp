/******************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
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

#include "qknxnetipconnectionstateresponse.h"

QT_BEGIN_NAMESPACE

/*!
    \class QKnxNetIpConnectionStateResponseProxy

    \inmodule QtKnx
    \ingroup qtknx-netip

    \brief The QKnxNetIpConnectionStateResponseProxy class provides the means to
    read a KNXnet/IP connection state response from the generic
    \l QKnxNetIpFrame class and to create a connection state response frame
    based on the information.

    A KNXnet/IP client reqularly sends a connection state request frame,
    \l QKnxNetIpConnectionStateRequestProxy, to the KNXnet/IP server's control
    endpoint to check the state of a connection established to the server.
    The server responds immediately with a connection state response frame.

    In most programs, this class will not be used directly. Instead, the
    \l QKnxNetIpTunnel or \l QKnxNetIpDeviceManagement
    class is used to establish a functional connection to a KNXnet/IP server.

    The following code sample illustrates how to read the connection state
    response information sent by a KNXnet/IP server:

    \code
        auto netIpFrame = QKnxNetIpFrame::fromBytes(...);

        const QKnxNetIpConnectionStateResponseProxy connectionStateResponse(netIpFrame);
        if (!connectionStateResponse.isValid())
            return;

        auto chanId = connectionStateResponse.channelId();
        auto status = connectionStateResponse.status();
    \endcode

    \sa builder(), QKnxNetIpConnectionStateRequestProxy, {Qt KNXnet/IP Connection Classes}
*/

/*!
    \fn QKnxNetIpConnectionStateResponseProxy::QKnxNetIpConnectionStateResponseProxy()
    \internal
*/

/*!
    \fn QKnxNetIpConnectionStateResponseProxy::~QKnxNetIpConnectionStateResponseProxy()
    \internal
*/

/*!
    \fn QKnxNetIpConnectionStateResponseProxy::QKnxNetIpConnectionStateResponseProxy(const QKnxNetIpFrame &&)
    \internal
*/

/*!
    Constructs a proxy object to read the connection state response
    information carried by the specified KNXnet/IP frame \a frame.
*/
QKnxNetIpConnectionStateResponseProxy::QKnxNetIpConnectionStateResponseProxy(const QKnxNetIpFrame &frame)
    : m_frame(frame)
{}

/*!
    Returns the ID of the communication channel prepared by the KNXnet/IP
    server.
*/
quint8 QKnxNetIpConnectionStateResponseProxy::channelId() const
{
    return m_frame.constData().value(0);
}

/*!
    Returns the state of the connection channel established to a KNXnet/IP
    server.
*/
QKnxNetIp::Error QKnxNetIpConnectionStateResponseProxy::status() const
{
    return QKnxNetIp::Error(m_frame.constData().value(1));
}

/*!
    Returns \c true if the frame contains initialized values and is in itself
    valid, otherwise returns \c false. A valid KNXnet/IP frame consist of
    at least a valid header and a size in bytes corresponding to the total size
    of the KNXnet/IP frame header.

    \sa QKnxNetIpFrameHeader::totalSize()
*/
bool QKnxNetIpConnectionStateResponseProxy::isValid() const
{
    return m_frame.isValid() && m_frame.size() == 8
        && m_frame.serviceType() == QKnxNetIp::ServiceType::ConnectionStateResponse;
}

/*!
    Returns a builder object to create a KNXnet/IP connection state response
    frame.
*/
QKnxNetIpConnectionStateResponseProxy::Builder QKnxNetIpConnectionStateResponseProxy::builder()
{
    return QKnxNetIpConnectionStateResponseProxy::Builder();
}


/*!
    \class QKnxNetIpConnectionStateResponseProxy::Builder

    \inmodule QtKnx
    \inheaderfile QKnxNetIpConnectionStateResponseProxy

    \brief The QKnxNetIpConnectionStateResponseProxy::Builder class provides the
    means to create a KNXnet/IP connection state response frame.

    A KNXnet/IP connection state response contains the status of a communication
    channel between a KNXnet/IP client and a KNXnet/IP server.

    In most programs, this class will not be used directly. Instead, the
    \l QKnxNetIpTunnel or \l QKnxNetIpDeviceManagement
    class is used to establish a functional connection to a KNXnet/IP server.

    The common way to create a connection state response is:

    \code
        auto netIpFrame = QKnxNetIpConnectionStateResponseProxy::builder()
            .setChannelId(25)
            .setStatus(QKnx::NetIp::Error::None)
            .create();
    \endcode

    If the KNXnet/IP client does not receive the connection state response
    within a timeout, or the status of the received response indicates that
    errors occurred, the client repeats the connection state request three
    times. It then terminates the connection by sending a disconnect request,
    \l QKnxNetIpDisconnectRequestProxy, to the server's control endpoint.
*/

/*!
    Sets the ID of the communication channel to \a channelId and returns a
    reference to the builder.
*/
QKnxNetIpConnectionStateResponseProxy::Builder &
    QKnxNetIpConnectionStateResponseProxy::Builder::setChannelId(quint8 channelId)
{
    m_channelId = channelId;
    return *this;
}

/*!
    Returns the state of the connection channel established to a KNXnet/IP
    server to \a status and returns a reference to the builder.
*/
QKnxNetIpConnectionStateResponseProxy::Builder &
    QKnxNetIpConnectionStateResponseProxy::Builder::setStatus(QKnxNetIp::Error status)
{
    m_status = status;
    return *this;
}

/*!
    Creates and returns a KNXnet/IP connection state response frame.

    \note The returned frame may be invalid depending on the values used during
    setup.

    \sa isValid()
*/
QKnxNetIpFrame QKnxNetIpConnectionStateResponseProxy::Builder::create() const
{
    QKnxByteArray data;
    switch (m_status) {
    case QKnxNetIp::Error::None:
    case QKnxNetIp::Error::ConnectionId:
    case QKnxNetIp::Error::DataConnection:
    case QKnxNetIp::Error::KnxConnection:
        data = { m_channelId, quint8(m_status) };
        break;
    default:
        break;
    };
    return { QKnxNetIp::ServiceType::ConnectionStateResponse, data };
}

QT_END_NAMESPACE

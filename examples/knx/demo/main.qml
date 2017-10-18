/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QmlKnxDemo 1.0

ApplicationWindow {
    id: mainWindow
    visibility: "FullScreen"
    width: 1280
    height: 800
    title: qsTr("KNX Demo")

    QmlKnxDemo {
        id: knxDemo
        onBoardUpdate: {
            console.log("signal onBoardUpdate lightNum: " + lightNum)
            knxBoard.enableBox(lightNum, getLightState(lightNum));
        }
        onColorLedChange: knxBoard.changeColorLeftLed(color)
        onRockerChange:  {
            logo.rotation = (position - 1000) * 360 / 1000;
        }
    }

    header: ToolBar {
        height: mainWindow.height / 12
        width: parent.width
        Layout.fillWidth: true
        background: Image {
            anchors.fill: parent
            source: "images/topBar.png"
        }
        Image {
            id: logo
            antialiasing: true
            anchors.verticalCenter: title.verticalCenter
            width: 45
            height: 33
            source: "images/Qt-logo-medium.png"
        }
        Label {
            id: title
            color: "grey"
            text: qsTr("Qt for automation KNX demo")
            anchors.left: logo.right
            anchors.verticalCenter: parent.verticalCenter
            Layout.maximumWidth: mainWindow.width / 3
        }
        ToolButton {
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            width: logo.width * 0.8
            height: logo.width * 0.8
            contentItem: Image {
                fillMode: Image.PreserveAspectFit
                source: "images/quit_icon.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: Qt.quit();
                }
            }
        }
    }

    KnxBoardLayout {
        id: knxBoard
        anchors.fill: parent
    }
}

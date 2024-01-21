// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import testingQml


ApplicationWindow {
    id: appWindow

    MyType {
        id: myType
        firstName: firstNameId.text
        lastName: lastNameId.text
    }

    visible: true
    title: "Basic layouts"
    property int margin: 11

    Component.onCompleted: {
        width = mainLayout.implicitWidth + 2 * margin
        height = mainLayout.implicitHeight + 2 * margin
    }

    minimumWidth: mainLayout.Layout.minimumWidth + 2 * margin
    minimumHeight: mainLayout.Layout.minimumHeight + 2 * margin



    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: appWindow.margin
        Button {
            text: "set firstName"
            onClicked: firstNameId.text = "shalom"
        }
        GroupBox {
            id: gridBox
            title: "Grid layout"
            Layout.fillWidth: true
            Layout.minimumWidth: gridLayout.Layout.minimumWidth + 30


            GridLayout {
                id: gridLayout
                rows: 3
                flow: GridLayout.TopToBottom
                anchors.fill: parent

                Label { text: "firstName"
                }
                Label { text: "lastName" }
                Label { text: myType.fullName}

                TextField {
                    id: firstNameId

                }
                TextField {
                    id: lastNameId
                }
                TextField {
                    text: myType.fullName
                }

                TextArea {
                    text: "This widget spans over three rows in the GridLayout.\n"
                        + "All items in the GridLayout are implicitly positioned from top to bottom."
                    wrapMode: TextArea.WordWrap
                    Layout.rowSpan: 3
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.minimumHeight: implicitHeight
                    Layout.minimumWidth: 100     // guesstimate, should be size of largest word
                }
            }
        }

    }
}


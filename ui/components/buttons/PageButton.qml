import QtQuick 2.0
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.13

Item {
	id: pageButton;

	property color highlightColor;
	property alias font: label.font;
	property alias text: label.text;
	property alias imageSource: image.source;

	MouseArea {
		id: mouseArea;
		hoverEnabled: true;
		cursorShape: Qt.PointingHandCursor;
		implicitHeight: layout.implicitHeight;
		implicitWidth: layout.implicitWidth;
		anchors.centerIn: parent;

		Rectangle {
			anchors.fill: parent;

			visible: parent.containsMouse;
			color: highlightColor;
			opacity: 0.2;
			radius: 10;
		}

		ColumnLayout {
			id: layout;

			Image {
				id: image;
				sourceSize.height: 100;
				fillMode: Image.PreserveAspectFit;
			}

			Text {
				id: label;
				Layout.alignment: Qt.AlignHCenter;
				font {
					pointSize: 14;
					family: "Roboto Bold";
				}
				text: text;
			}
		}
	}
}

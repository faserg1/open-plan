import QtQuick 2.0
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.13

Item {
	id: pageButton;
	implicitWidth: label.implicitWidth;

	property color highlightColor;
	property alias font: label.font;
	property alias text: label.text;
	property alias imageSource: image.source;

	MouseArea {
		id: mouseArea;
		anchors.fill: parent;
		hoverEnabled: true;
		cursorShape: Qt.PointingHandCursor;

		Rectangle {
			anchors.fill: parent;

			visible: parent.containsMouse;
			color: highlightColor;
		}

		ColumnLayout {
			id: layout;
			anchors.fill: parent;

			Image {
				id: image;
				sourceSize.width: pageButton.implicitWidth;

				fillMode: Image.PreserveAspectFit;
			}

			Text {
				id: label;
				font {
					pointSize: 14;
					family: "Roboto Bold";
				}
				text: text;
			}
		}
	}
}

import QtQuick 2.0
import QtQuick.Layouts 1.13

import "../components/buttons";

Item {
	id: start;
	RowLayout {
		anchors.centerIn: parent;
		PageButton {
			Layout.alignment: Qt.AlignCenter;
			text: "New Project";
			imageSource: "/resources/images/buttons/new-common.svg";
			highlightColor: "#4287f5";

			height: 80;
		}
	}
}

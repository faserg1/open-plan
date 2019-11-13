import QtQuick 2.0
import QtQuick.Layouts 1.13

import "../components/buttons";

Item {
    id: start
    RowLayout {
		anchors.centerIn: parent;
		PageButton {
			text: "New Project";
			imageSource: "/resources/images/buttons/new-common.svg";
			highlightColor: "#d9f2ff";

			height: 80;
		}
    }
}

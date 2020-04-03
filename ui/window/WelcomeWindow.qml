import QtQuick 2.13
import QtQuick.Window 2.13

import "../view/";
import "../components/";

PWindow {
	width: 640;
	height: 480;
	title: qsTr("OpenPlan");
	Start {
		anchors.fill: parent;
	}
}

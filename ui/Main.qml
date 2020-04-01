import QtQuick 2.13
import QtQuick.Window 2.13

import "./view/";
import WindowManager 1.0;

Window {
	id: main_window;
	visible: true;
	width: 640;
	height: 480;
	title: qsTr("OpenPlan");
    Start {
		anchors.fill: parent;
    }
	WindowManagerLink {
		name: "main";
		window: main_window;
	}
}

import QtQuick 2.13;
import QtQuick.Window 2.13;

import WindowManager 1.0;

Window {
	id: window;
	property string name;
	WindowManagerLink {
		id: link;
		name: window.name;
		window: window;
	}
}

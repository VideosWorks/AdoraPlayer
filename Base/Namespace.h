
#ifndef _NAMESPACE_H
#define _NAMESPACE_H

enum class ResizeBehavior {
	Nothing,
	Move,
	ResizeTopRight,
	ResizeTopLeft,
	ResizeBottomRight,
	ResizeBottomLeft,
	ResizeTop,
	ResizeBottom,
	ResizeLeft,
	ResizeRight,
};


enum class CurrentWindowMode {

	Maximized,
	Minimized,
	FullScreen,
	Restored,
};

#endif //_NAMESPACE_H
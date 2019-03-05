#pragma once
#include "Meeting.h"
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;

class MeetingWindow : public Window {

public:
	MeetingWindow(Point xy, int w, int h, const string& title) 
	: Window(xy, w, h,title) 
	{};

};
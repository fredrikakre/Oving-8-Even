#include "Simple_window.h"
#include "Emoji.h"
#include "std_lib_facilities.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

// eyes:

const Point le = { 85, 92 };
const Point re = { 115, 92 };
constexpr int eyer = 6;

// smilingMouth:

const Point mc = { 100, 100 };
const int width = 50;
const int height = 60;
const int start_deg = 200;
const int end_deg = 340;

//rettMunn:

Point sm = { 80, 120 };
Point em = { 120, 120 };

//Mistenksomme øyenbryn:

Point a = { 75, 85 }; //start venstre øyenbryn
Point b = { 95, 85 }; //slutt venstre øyenbryn
Point eyebrowc = { 115, 85 }; //sentrum høyre øyenbryn
int widtheb = 20;
int heighteb = 25;
int startdegeb = 20;
int enddegeb = 160;

//strengt høyre øyenbryn:

Point c = { 105, 85 };
Point d = { 125, 85 };

//Hjerter:
Point c1c = { 80, 90 };
Point c2c = { 90, 90 };
Point c3c = { 110, 90 };
Point c4c = { 120, 90 };
int radiusc1234 = 6;
Point startline1 = { 75, 90 };
Point startline2 = { 95, 90};
Point meetlines12 = { 85, 95 };
Point startline3 = { 105, 90 };
Point startline4 = { 125, 90 };
Point meetlines34 = { 115, 95 };




int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	
	SmilingFace s(tl, emojiRadius, le, re, eyer, mc, width, height, start_deg, end_deg);
	DisgruntledFace dis(tl, emojiRadius, le, re, eyer, sm, em);
	SuspiciousFace sp(tl, emojiRadius, le, re, eyer, sm, em, a, b, eyebrowc, widtheb, heighteb, startdegeb, enddegeb);
	StrictFace sf(tl, emojiRadius, le, re, eyer, sm, em, a, b, c, d);
	HeartEyes he(tl, emojiRadius, le, re, eyer, mc, width, height, start_deg, end_deg, c1c, c2c, c3c, c4c, radiusc1234, startline1, startline2, meetlines12, startline3, startline4, meetlines34);
	Vector_ref<Emoji> vec;
	vec.push_back(s);
	vec.push_back(dis);
	vec.push_back(sp);
	vec.push_back(sf);
	vec.push_back(he);

	for (auto& element : vec) {
		element->attach_to(win);
		win.wait_for_button();
	}

}

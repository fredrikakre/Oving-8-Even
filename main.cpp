// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h"
#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
int main() {
	using namespace Graph_lib;
	Car *car = new Car(4);
	Person *Even = new Person{ "Even","even.tonseth@gmail.com", car};
	Person Even_1{ "Even","even.tonseth@gmail.com", car };
	cout << Even_1;
	string n;
	Meeting m{ 0, 32472384, 363450934, Campus::Trondheim, "Evenness", Even };
	MeetingWindow x{ Point{0,0}, 400, 200, "Tittel" };
	gui_main();
	cin >> n;
}



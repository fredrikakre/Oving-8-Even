#pragma once
#include "Graph.h"
#include "Simple_window.h"
#include "Person.h"
enum class Campus {
	Gjoevik , Trondheim, Aalesund 
};
ostream& operator<<(Campus& c, ostream& os);

class Meeting {
private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	string subject;
	const Person* leader;
	set<const Person*> participants;
	static set<const Meeting*> meetings;
public:
	Meeting(int day, int startTime, int endTime, Campus location, string subject, Person *leader);
	int getDay() const { return day; }
	int getstartTime() const { return startTime; }
	int getendtime() const { return endTime; }
	Campus getlocation() const { return location; } // spør her
	string getSubject() const { return subject; }
	Person getLeader() const { return *leader; }
	set<const Person*> getParticipants() const { return participants; };
	void addParticipant(Person *p);
	vector<string> getParticipantList() const; //Spør her og
	vector<const Person*> findPotentialCoDriving();
	~Meeting() { meetings.erase(meetings.find(this)); };
};


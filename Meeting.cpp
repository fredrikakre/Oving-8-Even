#include "Meeting.h"

ostream& operator<<(ostream& os, const Campus& c){
	map<Campus, string> kart{ {Campus::Gjoevik, "Gjoevik"}, {Campus::Trondheim, "Trondheim"},
	{Campus::Aalesund, "Aalesund" } };
	os << kart[c];
	return os;
}


void Meeting::addParticipant(Person *p) {
	participants.insert(p);
}

set<const Meeting*> Meeting::meetings;


Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader) :
	day{ day }, startTime{ startTime }, endTime{ endTime }, location{ location }, subject{ subject }, leader{ leader }
{	
	meetings.insert(this);
	participants.insert(leader);
}

vector<string> Meeting::getParticipantList() const {
	vector<string> part(participants.size()+1);
	for (auto p : participants) {
		part.push_back(p->getName());
	}
	return part;
}

ostream& operator<<(ostream& os, const Meeting& m){
	os << "Subject: \t" << m.getSubject() << endl;
	os << "Day: " << m.getDay() << "\t Location: ";
	Campus c = m.getlocation();
	os << c;
	os << "\t Start" << m.getstartTime() << "Endtime" <<
		m.getendtime() <<   endl << "---------------" << endl;
	os << "Deltakere:  " << endl;
	vector<string> k = m.getParticipantList();
	for (string n : k) {
		os << n << "\t";
	}	
	os << "Leder:   " << m.getLeader() << endl;
	return os;
}

vector<const Person*> Meeting::findPotentialCoDriving() {
	vector<const Person*> personer;
	for (auto meet : meetings){
		if (meet->getlocation() == location and (startTime > meet->getstartTime() - 3600 or endTime < meet->getendtime() + 3600)) {
			for (auto people : meet->getParticipants()) {
				if (people->hasAvailableSeats()) {
					personer.push_back(people);
				}
			}
		}
	}
	return personer;
}
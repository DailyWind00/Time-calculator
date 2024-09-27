#include "Time.hpp"
#include <sstream>

using namespace std;

int main (int argc, char **argv) {
	cout << "Time calculator by DailyWind" << endl 
			<< "--> Calculate the time you must stay at work to complete the required hours" << endl;
	if (argc < 4 || argc > 5) {
		cerr << "Usage: " << argv[0] << " <HH:MM> <HH:MM> <HH:MM> [required hours]" << endl;
		return 1;
	}

	argc--; argv++;
	Time times[argc];

	for (int i = 0; i < argc; ++i) {
		stringstream ss(argv[i]);
		int hours, minutes;
		char colon;

		if (!(ss >> hours >> colon >> minutes) || colon != ':' || hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
			cerr << "Invalid time format: " << argv[i] << endl;
			return 1;
		}

		times[i] = Time(0, 0, 0, hours, minutes);
	}

	Time requiredHours;
	if (argc == 4)
		requiredHours = times[3];
	else
		requiredHours = Time(0, 0, 0, 7, 0); // 7:00

	Time result = times[2] + (requiredHours - (times[1] - times[0]));

	cout << "You must stay until "
			<< setfill('0') << setw(2) << result.getHour() << ":"
			<< setfill('0') << setw(2) << result.getMinute() << endl;
}
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;
class alarm
{
public:
    tm alarmtime, presenttime, differenceintime;
    time_t now;
    alarm()
    {
        now = time(0);
        presenttime = *localtime(&now);
        alarmtime = presenttime;
        alarmtime.tm_sec = 0;
    }
    void getTime()
    {
        string time;
        cout << "Enter Alarm Time in 24-hour format [HH:MM]: ";
        getline(cin, time);
        int pos = 0, h;
        while ((pos = time.find(':')) != string::npos)
        {
            string token = time.substr(0, pos);
            stringstream convert(token);
            convert >> alarmtime.tm_hour;
            time.erase(0, pos + 1);
        }
        stringstream convert(time);
        convert >> alarmtime.tm_min;
    }
    void timeDifference()
    {
        int sec = difftime(mktime(&alarmtime), now);
        differenceintime.tm_min = sec / 60;
        differenceintime.tm_hour = differenceintime.tm_min / 60;
        differenceintime.tm_min = differenceintime.tm_min % 60;
        differenceintime.tm_sec = sec % 60;
        if (sec < 0)
        {
            differenceintime.tm_hour = 24 + differenceintime.tm_hour - 1;
            differenceintime.tm_min = 0 - differenceintime.tm_min;
            differenceintime.tm_sec = 0 - differenceintime.tm_sec;
        }
    }
    void start_alarm()
    {
        while (true)
        {
            system("cls");
            now = time(0);
            presenttime = *localtime(&now);
            timeDifference();
            cout << "TIME REMAINING:    " << differenceintime.tm_hour << ":" << differenceintime.tm_min << ":" << differenceintime.tm_sec;
            if (differenceintime.tm_hour == 0 && differenceintime.tm_min == 0 && differenceintime.tm_sec == 0)
            {
                cout << endl
                     << "Time Ended" << endl
                     << ">>> Press CTRL+C or Close the window to stop the alarm <<<" << endl;
                break;
            }
        }
    }
};
int main()
{
    alarm a;
    a.getTime();
    a.start_alarm();
    for (int i = 0;; i = i + 50)
        Beep(i, 1000);
    return 0;
}

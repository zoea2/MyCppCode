#include <ctime>
class Time
{
    private:
    int hour;
    int minute;
    int second;
    public:
    Time()
    {
        long long currentTime = time(0);
        second = currentTime % 60;
        currentTime = currentTime / 60;
        minute = currentTime % 60 ;
        currentTime /= 60;
        hour = currentTime / 24;
    }
    Time(int totalSeconds)
    {
        long long currentTime = totalSeconds;
        second = currentTime % 60;
        currentTime = currentTime / 60;
        minute = currentTime % 60 ;
        currentTime /= 60;
        hour = currentTime / 24;
    }
    int getHour()
    {
        return hour;
    }
    int getMinute()
    {
        return minute;
    }
    int getSecond()
    {
        return second;
    }
};

#include <iostream>
#include <stdexcept>

using namespace std;

struct Time 
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) 
    {
        hours = h + (m + s / 60) / 60;
        hours %= 24;
        minutes = (m + s / 60) % 60;
        seconds = s % 60;
    }

    int toSeconds() const 
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time operator+(const Time& other) const 
    {
        int totalSeconds = toSeconds() + other.toSeconds();
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    Time operator-(const Time& other) const 
    {
        int totalSeconds = toSeconds() - other.toSeconds();
        if (totalSeconds < 0) totalSeconds += 24 * 3600;
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    void output() const 
    {
        cout << hours << " h " << minutes << " m " << seconds << " s" << endl;
    }
};

int main() 
{
    int h1, m1, s1, h2, m2, s2;
    cout << "Enter the first time (hh:mm:ss): ";
    cin >> h1 >> m1 >> s1;
    Time time1(h1, m1, s1);

    cout << "Enter the second time (hh:mm:ss): ";
    cin >> h2 >> m2 >> s2;
    Time time2(h2, m2, s2);

    Time sum = time1 + time2;
    Time diff = time1 - time2;
    cout << "Sum of times: ";
    sum.output();
    cout << "Difference of times: ";
    diff.output();
    return 0;
}

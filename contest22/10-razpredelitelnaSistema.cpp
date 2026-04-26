#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_N = 11;
const int HOURS = 24;

struct Ured {
    char name[101];
    double watts;
    int hours;
};

int n;
Ured Uredi[MAX_N];

double produced[HOURS], available[HOURS];
double bestUsedEnergy = 0;

bool canPlace(int index, int startHour) {
    double watts = Uredi[index].watts;
    int hours = Uredi[index].hours;

    for (int h = startHour; h < startHour + hours; h++) if (available[h] + 1e-9 < watts) return false;

    return true;
}

void placeUred(int index, int startHour) {
    double watts = Uredi[index].watts;
    int hours = Uredi[index].hours;

    for (int h = startHour; h < startHour + hours; h++)
    {
        available[h] -= watts;
    }
}

void removeUred(int index, int startHour){
    double watts = Uredi[index].watts;
    int hours = Uredi[index].hours;

    for (int h = startHour; h < startHour + hours; h++){
        available[h] += watts;
    }
}

void solve(int index, double usedEnergy){
    if (index == n){
        if (usedEnergy > bestUsedEnergy) bestUsedEnergy = usedEnergy;
        return;
    }

    solve(index + 1, usedEnergy);

    int duration = Uredi[index].hours;

    for (int startHour = 0; startHour <= HOURS - duration; startHour++)
    {
        if (canPlace(index, startHour))
        {
            placeUred(index, startHour);

            double UredEnergy = Uredi[index].watts * Uredi[index].hours;
            solve(index + 1, usedEnergy + UredEnergy);

            removeUred(index, startHour);
        }
    }
}

int main()
{
    int solarPanels;
    cin >> solarPanels;

    double totalExpectedEnergy = 0;

    for (int i = 0; i < HOURS; i++)
    {
        double predictedEnergy;
        cin >> predictedEnergy;

        double currentEnergy = (predictedEnergy * 0.296 - 5.4048) * solarPanels;

        if (currentEnergy < 0)
        {
            currentEnergy = 0;
        }

        produced[i] = currentEnergy;
        available[i] = currentEnergy;

        totalExpectedEnergy += currentEnergy;
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> Uredi[i].name >> Uredi[i].watts >> Uredi[i].hours;
    }

    solve(0, 0);

    double remainingEnergy = totalExpectedEnergy - bestUsedEnergy;

    cout << fixed << setprecision(2);
    cout << totalExpectedEnergy << endl;
    cout << remainingEnergy << endl;

    return 0;
}
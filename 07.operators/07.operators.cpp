
#include <iostream>
#include <string>
using namespace std;

class Airplane
{
private:
    string model;
    string type;
    int passengers;
    int maxPassengers;

public:
    Airplane(string m, string t, int p, int maxP)
    {
        model = m;
        type = t;
        maxPassengers = maxP > 0 ? maxP : 0;
        passengers = (p >= 0 && p <= maxPassengers) ? p : 0;
    }

    void Show()
    {
        cout << "Model: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "Passengers: " << passengers << endl;
        cout << "Max passengers: " << maxPassengers << endl;
        cout << "------------------------" << endl;
    }

    friend bool operator==(const Airplane& a, const Airplane& b)
    {
        return a.type == b.type;
    }

    friend bool operator>(const Airplane& a, const Airplane& b)
    {
        return a.maxPassengers > b.maxPassengers;
    }

    Airplane& operator++()
    {
        if (passengers < maxPassengers)
        {
            passengers++;
        }
        else
        {
            cout << "Airplane is full!" << endl;
        }
        return *this;
    }

    Airplane& operator--()
    {
        if (passengers > 0)
        {
            passengers--;
        }
        else
        {
            cout << "No passengers!" << endl;
        }
        return *this;
    }

    void operator()(int count)
    {
        if (count < 0)
        {
            cout << "Invalid number!" << endl;
        }
        else if (passengers + count <= maxPassengers)
        {
            passengers += count;
        }
        else
        {
            cout << "Too many passengers!" << endl;
        }
    }
};

int main()
{
    Airplane a1("Boeing 737", "Passenger", 100, 180);
    Airplane a2("Airbus A320", "Passenger", 120, 200);

    a1.Show();
    a2.Show();

    if (a1 == a2)
        cout << "Same airplane types" << endl;
    else
        cout << "Different airplane types" << endl;

    ++a1;
    cout << "\nAfter ++:" << endl;
    a1.Show();

    --a1;
    cout << "\nAfter --:" << endl;
    a1.Show();

    if (a1 > a2)
        cout << "First airplane is bigger" << endl;
    else
        cout << "Second airplane is bigger or equal" << endl;

    a1(15);
    cout << "\nAfter adding 15 passengers:" << endl;
    a1.Show();

    return 0;
}

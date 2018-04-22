#include <iostream>
const int Max = 5;
double * fill_array(double ar[], int limit);
void show_array(const double ar[], double * pn);
void revalue(double r, double ar[], double * pn);

int main()
{
    using namespace std;
    double properties[Max];

    double * psize = fill_array(properties, Max);
    show_array(properties, psize);
    if (*psize > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, psize);
        show_array(properties, psize);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
	return 0;
}

double * fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        ar[i] = temp;
    }
    return &ar[i];
}

void show_array(const double ar[], double * pn)
{
    using namespace std;
    int i = 0;
    for (const double * pi = ar; pi != pn; pi++)
    {
        cout << "Property #" << ++i << ": $";
        cout << *pi << endl;
    }
}

void revalue(double r, double ar[], double * pn)
{
    for (double * pi = ar; pi != pn; pi++)
        (*pi) *= r;
}

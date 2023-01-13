#include <iostream>
#include <fstream>
#include "header.h"
#include <string>
using namespace std;

int main()
{
    const int size = 11;
    string arr[size] = { "<state name=","abbreviation=", "capital=","date=","most-populous-city=",
        "population=","square-miles=","time-zone-1=","time-zone-2=","dst=","/>" };
    string name = "us_states.xml";
    string line = "";

    ifstream file(name);
    if (file.is_open())
    {
        int i = 0;
        string token;

        while (getline(file, line))
        {
            size_t lentoerase = line.find("<state name=");
            line.erase(0, lentoerase);

            size_t marker = 1;
            r.Getİnfo(arr[0], line, token, marker);

            marker = 3;
            r.Getİnfo(arr[1], line, token, marker);
            StateName[i].setStateName(token);
            LarToSmlCities[i].setLarToSmlCities(token);
            StateNameCopy[i].setStateNameC(token);

            r.Getİnfo(arr[2], line, token, marker);
            Abbreviation[i].setAbbreviation(token);
            AbbreviationCopy[i].setAbbreviationC(token);

            r.Getİnfo(arr[3], line, token, marker);
            Capital[i].setCapital(token);

            r.Getİnfo(arr[4], line, token, marker);
            r.YearMonthDay(i, token);

            r.Getİnfo(arr[5], line, token, marker);
            MostPopCity[i].setMostPopCity(token);

            r.Getİnfo(arr[6], line, token, marker);
            Population[i].setPopulation(token);

            r.Getİnfo(arr[7], line, token, marker);
            SquareMiles[i].setSquareMiles(token);

            size_t pos = line.find(arr[8]);
            if (pos != string::npos)
            {
                r.Getİnfo(arr[8], line, token, marker);
                TimeZone1[i].setTimeZone1(token);

                r.Getİnfo(arr[9], line, token, marker);
                TimeZone2[i].setTimeZone2(token);

                r.Getİnfo(arr[10], line, token, marker - 1);
                Dst[i].setDst(token);
            }
            else
            {
                r.Getİnfo(arr[9], line, token, (marker));
                TimeZone1[i].setTimeZone1(token);

                r.Getİnfo(arr[10], line, token, (marker - 1));
                Dst[i].setDst(token);
            }
            i++;
        }
        file.close();
    }
    else
        cout << "unable to open " << endl;

    r.USAinformation();
    r.Daylight();
    r.SortedMostPopCity();
    r.StatesAndAbbreviation();
    r.LargestAndCrowded();
    r.SortedDates();
    return 0;
}

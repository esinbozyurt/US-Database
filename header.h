#include <iostream>
#include <string>

const int n = 54;

class MyClass {

    std::string stateName;
    std::string abbreviation;
    std::string capital;
    std::string mostPopCity;
    std::string population;
    std::string squareMiles;
    std::string timeZone1;
    std::string timeZone2;
    std::string dst;
    std::string year;
    std::string month;
    std::string day;
    std::string stateNameC;
    std::string abbreviationC;
    std::string cities;
    std::string miles;

public:

    void setStateName(std::string stateName) { this->stateName = stateName; }
    std::string getStateName() { return stateName; }

    void setAbbreviation(std::string abbreviation) { this->abbreviation = abbreviation; }
    std::string getAbbreviation() { return abbreviation; }

    void setStateNameC(std::string stateNameC) { this->stateNameC = stateNameC; }
    std::string getStateNameC() { return stateNameC; }

    void setAbbreviationC(std::string abbreviationC) { this->abbreviationC = abbreviationC; }
    std::string getAbbreviationC() { return abbreviationC; }

    void setCapital(std::string capital) { this->capital = capital; }
    std::string getCapital() { return capital; }

    void setMostPopCity(std::string mostPopCity) { this->mostPopCity = mostPopCity; }
    std::string getMostPopCity() { return mostPopCity; }

    void setPopulation(std::string mostPopCity) { this->population = mostPopCity; }
    std::string getPopulation() { return population; }

    void setSquareMiles(std::string squareMiles) { this->squareMiles = squareMiles; }
    std::string getSquareMiles() { return squareMiles; }

    void setTimeZone1(std::string timeZone1) { this->timeZone1 = timeZone1; }
    std::string getTimeZone1() { return timeZone1; }

    void setTimeZone2(std::string timeZone2) { this->timeZone2 = timeZone2; }
    std::string getTimeZone2() { return timeZone2; }

    void setDst(std::string dst) { this->dst = dst; }
    std::string getDst() { return dst; }

    void setYear(std::string year) { this->year = year; }
    std::string getYear() { return year; }

    void setMonth(std::string month) { this->month = month; }
    std::string getMonth() { return month; }

    void setDay(std::string day) { this->day = day; }
    std::string getDay() { return day; }

    void setLarToSmlCities(std::string cities) { this->cities = cities; }
    std::string getLarToSmlCities() { return cities; }

    int string2int(const std::string& s);
    void Get›nfo(std::string str, std::string& line, std::string& token, std::size_t i);
    void USAinformation();
    void StatesAndAbbreviation();
    void LargestAndCrowded();
    void SortedDates();
    int AllArea();
    int AllPopulation();
    void YearMonthDay(int, std::string);
    void SortedMostPopCity();
    void Daylight();
    std::string toLowUp(std::string);
    std::string Months2Str(std::string);


};

MyClass StateName[n];
MyClass Abbreviation[n];
MyClass Capital[n];
MyClass MostPopCity[n];
MyClass Population[n];
MyClass SquareMiles[n];
MyClass TimeZone1[n];
MyClass TimeZone2[n];
MyClass Dst[n];
MyClass Year[n];
MyClass Month[n];
MyClass Day[n];
MyClass StateNameCopy[n];
MyClass LarToSmlCities[n];
MyClass AbbreviationCopy[n];
MyClass r;

template <class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


std::string MyClass::Months2Str(std::string month)
{
    if (month == "01")
        return "January";
    else if (month == "02")
        return "February";
    else if (month == "03")
        return "March";
    else if (month == "04")
        return "April";
    else if (month == "05")
        return "May";
    else if (month == "06")
        return "June";
    else if (month == "07")
        return "July";
    else if (month == "08")
        return "August";
    else if (month == "09")
        return "September";
    else if (month == "10")
        return "October";
    else if (month == "11")
        return "November";
    else
        return "December";
}


std::string MyClass::toLowUp(std::string str)
{
    if ((str[0] >= 'a') && (str[0] <= 'z'))
    {
        str[0] = str[0] - ('a' - 'A');

    }
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i + 1] = str[i + 1] - ('a' - 'A');
            i++;
        }
        else if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] = str[i] + ('a' - 'A');

    }
    return str;

}


void MyClass::Get›nfo(std::string str, std::string& line, std::string& token, std::size_t i)
{
    token = "";
    size_t pos = 0;
    while ((pos = line.find(str)) != std::string::npos)
    {
        token = line.substr(1, pos - i);
        line.erase(0, pos + str.length());
        str.erase(str.end() - 1);
    }
}


void MyClass::YearMonthDay(int i, std::string line)
{
    std::string token = "";
    token = line.substr(0, 4);
    line.erase(0, 5);
    Year[i].setYear(token);

    token = line.substr(0, 2);
    line.erase(0, 3);
    Month[i].setMonth(token);

    token = line.substr(0, 2);
    line.erase(0, 2);
    Day[i].setDay(token);

}


int MyClass::string2int(const std::string& s)
{
    int ans = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans *= 10;
            ans += s[i] - '0';
        }
    }
    return ans;
}

void MyClass::USAinformation()
{
    std::string name;
    std::cout << "Please Enter State Name: ";
    std::getline(std::cin, name);
    for (int i = 2; i < n - 2; i++)
    {
        if (toLowUp(name) == StateName[i].getStateName())
        {
            std::cout << '\n' << "State: " << StateName[i].getStateName() << std::endl;
            std::cout << "Abbreviation: " << Abbreviation[i].getAbbreviation() << std::endl;
            std::cout << "Capital: " << Capital[i].getCapital() << std::endl;
            //std::cout << "Date of admission: "<<Months2Str(string2int(Month[i].getMonth()));
            std::cout << "Date of admission: " << Months2Str(Month[i].getMonth());
            std::cout << " " << Day[i].getDay() << ", " << Year[i].getYear() << std::endl;
            std::cout << "Most populous city: " << MostPopCity[i].getMostPopCity() << std::endl;
            std::cout << "Population: " << Population[i].getPopulation() << std::endl;
            std::cout << "Area: " << SquareMiles[i].getSquareMiles() << std::endl;
            if (TimeZone2[i].getTimeZone2() != "")
            {
                std::cout << "Time zones: " << TimeZone1[i].getTimeZone1();
                std::cout << ", " << TimeZone2[i].getTimeZone2();
            }
            else
                std::cout << "Time zone: " << TimeZone1[i].getTimeZone1();
            std::cout << '\n' << "Dst: " << Dst[i].getDst() << '\n' << std::endl;
        }
    }
}


void MyClass::StatesAndAbbreviation()
{
    for (int i = 0; i < n - 1; i++)

    {
        for (int j = i + 1; j < n; j++)
        {

            if (StateNameCopy[i].getStateNameC() > StateNameCopy[j].getStateNameC())
            {
                swap(StateNameCopy[i], StateNameCopy[j]);
                swap(AbbreviationCopy[i], AbbreviationCopy[j]);
            }
        }
    }
    std::cout << "All states and their abbreviation in alphabetical order;" << std::endl;
    for (int i = 4; i < n; i++)
        std::cout << StateNameCopy[i].getStateNameC() << " " << "(" << AbbreviationCopy[i].getAbbreviationC() << ")" << "\n";
    std::cout << std::endl;
}


void MyClass::LargestAndCrowded()
{
    for (int i = 2; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (string2int(SquareMiles[i].getSquareMiles()) < string2int(SquareMiles[j].getSquareMiles()))
            {
                swap(LarToSmlCities[i], LarToSmlCities[j]);
                swap(SquareMiles[i], SquareMiles[j]);
                swap(Population[i], Population[j]);
            }
        }
    }
    std::cout << "Largest five state; " << std::endl;
    for (int i = 2; i < 7; i++) {
        std::cout << LarToSmlCities[i].getLarToSmlCities() << " Area: " << SquareMiles[i].getSquareMiles() << "\n";
    }

    std::cout << "\n" << "Overall area of the United States of America is " << r.AllArea() << " square miles" << '\n' << std::endl;

    for (int i = 2; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (string2int(Population[i].getPopulation()) < string2int(Population[j].getPopulation()))
            {
                swap(LarToSmlCities[i], LarToSmlCities[j]);
                swap(Population[i], Population[j]);
            }
        }
    }
    std::cout << "Most crowded five state; " << std::endl;
    for (int i = 2; i < 7; i++)
        std::cout << LarToSmlCities[i].getLarToSmlCities() << " Population: " << Population[i].getPopulation() << "\n";

    std::cout << "\n" << "Overall population of the United States of America is " << r.AllPopulation() << " million" << '\n' << std::endl;
}


void MyClass::SortedDates()
{
    for (int s1 = 0; s1 < n - 1; s1++)
    {
        for (int s2 = s1 + 1; s2 < n; s2++)
        {

            if ((Year[s1].getYear()) >= (Year[s2].getYear()))
            {
                swap(StateName[s1], StateName[s2]);
                swap(Year[s1], Year[s2]);
                swap(Month[s1], Month[s2]);
                swap(Day[s1], Day[s2]);

                for (int s3 = 0; s3 < n - 1; s3++)
                {
                    for (int s4 = s3 + 1; s4 < n; s4++)
                    {

                        if ((Month[s3].getMonth()) >= (Month[s4].getMonth()) && (Year[s3].getYear()) >= (Year[s4].getYear()))
                        {
                            swap(StateName[s3], StateName[s4]);
                            swap(Year[s3], Year[s4]);
                            swap(Month[s3], Month[s4]);
                            swap(Day[s3], Day[s4]);

                            for (int s5 = 0; s5 < n - 1; s5++)
                            {
                                for (int s6 = s5 + 1; s6 < n; s6++)
                                {

                                    if ((Month[s5].getMonth()) >= (Month[s6].getMonth()) && (Year[s5].getYear()) >= (Year[s6].getYear()) && (Day[s5].getDay()) >= (Day[s6].getDay()))
                                    {
                                        swap(StateName[s5], StateName[s6]);
                                        swap(Year[s5], Year[s6]);
                                        swap(Month[s5], Month[s6]);
                                        swap(Day[s5], Day[s6]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 4; i < n; i++)
    {
        std::cout << StateName[i].getStateName() << " -> ";
        std::cout << Months2Str(Month[i].getMonth());
        std::cout << " " << Day[i].getDay()
            << ", " << Year[i].getYear() << std::endl;
    }
    std::cout << std::endl;
}


int MyClass::AllArea()
{
    int ans = 0;

    for (int i = 2; i < n - 2; i++)
        ans += string2int(SquareMiles[i].getSquareMiles());
    return ans;
}


int MyClass::AllPopulation()
{
    int ans = 0;

    for (int i = 2; i < n - 2; i++)
        ans += string2int(Population[i].getPopulation());
    return ans;
}


void MyClass::SortedMostPopCity()
{
    std::cout << "Most populous cities in alphabetical order; " << std::endl;
    for (int i = 2; i < n - 1; i++)

    {
        for (int j = i + 1; j < n; j++)
        {
            if (MostPopCity[i].getMostPopCity() > MostPopCity[j].getMostPopCity())
            {
                swap(MostPopCity[i], MostPopCity[j]);
            }
        }
    }
    for (int i = 4; i < n; i++)
        std::cout << MostPopCity[i].getMostPopCity() << "\n";
    std::cout << std::endl;
}


void MyClass::Daylight()
{
    std::cout << "States with daylight saving time in alphabetical order;" << std::endl;
    for (int i = 2; i < n; i++)
    {
        if (Dst[i].getDst() == "Yes")
        {
            std::cout << StateName[i].getStateName() << "\n";
        }
    }

    std::cout << "\n" << "States without daylight saving time in alphabetical order;" << std::endl;

    for (int i = 2; i < n; i++)
    {
        if (Dst[i].getDst() == "No")
        {
            std::cout << StateName[i].getStateName() << "\n";
        }
    }
    std::cout << std::endl;
}



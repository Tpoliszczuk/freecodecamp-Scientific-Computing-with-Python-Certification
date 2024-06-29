#include <iostream>
using namespace std;

class RuralManagement
{
protected:
    int acceptedSchemes;

public:
    int getAcceptedSchemes()
    {
        return acceptedSchemes;
    }

    void setAcceptedSchemes(int noOfSchemes)
    {
        acceptedSchemes = noOfSchemes;
    }

    void calcNoOfSchemes(int noOfSchemes, int noOfSchemesRejected)
    {
        acceptedSchemes = noOfSchemes - noOfSchemesRejected;
    }
};

class RevenueManagement
{
protected:
    double totalRevenue;

public:
    double getTotalRevenue()
    {
        return totalRevenue;
    }

    void setTotalRevenue(double revenue)
    {
        totalRevenue = revenue;
    }

    void calcTotalRevenue(int noOfTerritories, double revenuePerTerritory)
    {
        totalRevenue = noOfTerritories * revenuePerTerritory;
    }
};

class SchemeManagement : public RuralManagement, public RevenueManagement
{
public:
    double allotMoneyPerScheme()
    {
        if (getAcceptedSchemes() != 0)
            return getTotalRevenue() / getAcceptedSchemes();
        else
            return 0;
    }
};

int main()
{
    int territories, schemes, rejected;
    double revenue;

    cout << "Enter number of territories: ";
    cin >> territories;
    cout << "Enter revenue: ";
    cin >> revenue;
    cout << "Enter total number of schemes: ";
    cin >> schemes;
    cout << "Enter number of schemes rejected: ";
    cin >> rejected;

    SchemeManagement sm;

    sm.calcNoOfSchemes(schemes, rejected);
    sm.calcTotalRevenue(territories, revenue);

    double moneyPerScheme = sm.allotMoneyPerScheme();

    cout << "Money allotted per scheme: " << moneyPerScheme << endl;

    return 0;
}

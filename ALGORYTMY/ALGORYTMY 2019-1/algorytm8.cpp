#include <iostream>

using namespace std;

/*std::string test(unsigned &x, unsigned &y, unsigned &id) {
    unsigned xTest, yTest;
    std::string direction = "";
    switch( id ) {
    case 0:
        xTest = 5;
        yTest = 5;
        break;
    case 1:
        xTest = 14;
        yTest = 16;
        break;
    default:
        xTest = 0;
        yTest = 0;
        break;
    }
    if(yTest < y)
        direction = "S";
    else if(yTest > y)
        direction = "N";
    if(xTest < x)
        direction += "W";
    else if(xTest > x)
        direction += "E";
    return direction;
}*/

unsigned int wymiarX, wymiarY, ilosc_pluskiew, zakresX, zakresY;
void rozwiaz(unsigned int x, unsigned int y, unsigned int pluskwy)
{
    while(true)
    {
        string s = test(x, y, pluskwy);
        
        if(s == "")
        {
            cout << x << " " << y << endl;
            break;
        }
        else if(s == "N")
        {
            y=y+zakresY;
        }
        else if(s == "E")
        {
            x=x+zakresX;
        }
        else if(s == "W")
        {
            x=x-zakresX;
        }
        else if(s == "S")
        {
            y=y-zakresY;
        }
        else if(s == "NE")
        {
            y=y+zakresY;
            x=x+zakresX;
        }
        else if(s == "SE")
        {
            y=y-zakresY;
            x=x+zakresX;
        }
        else if(s == "SW")
        {
            y=y-zakresY;
            x=x-zakresX;
        }
        else if(s == "NW")
        {
            y=y+zakresY;
            x=x-zakresX;
        }
        
        if(zakresX>1)
        {
            zakresX=zakresX/2;
        }
        if(zakresY>1)
        {
            zakresY=zakresY/2;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> wymiarX >> wymiarY >> ilosc_pluskiew;
    
    for(unsigned int i=0; i<ilosc_pluskiew; i++)
    {
        zakresX = wymiarX/4;
        zakresY = wymiarY/4;
        rozwiaz(wymiarX/2, wymiarY/2, i);
    }
    
    return 0;
}

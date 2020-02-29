#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int liczbaZestawowDanych;
    cin >> liczbaZestawowDanych;

    for(int i=0; i<liczbaZestawowDanych; i++)
    {
        long int koszt=0;
        int element1, element2;
        long int liczbaProgramow;
        int pierwszaMinuta, kolejneMinuty;

        cin >> liczbaProgramow >> pierwszaMinuta >> kolejneMinuty;

        vector<int> czasPoczatkowy;
        vector<int> czasKoncowy;

        for(long int j=0; j<liczbaProgramow; j++)
        {
            cin >> element1 >> element2;
            czasPoczatkowy.push_back(element1);
            czasKoncowy.push_back(element2);
            koszt = koszt + pierwszaMinuta + kolejneMinuty*(element2-element1);
        }

        sort(czasPoczatkowy.begin(), czasPoczatkowy.end());
        sort(czasKoncowy.begin(), czasKoncowy.end());

        for(int i=czasKoncowy.size()-1; i>=0; i--)
        {
            vector<int>::iterator roznica = upper_bound(czasPoczatkowy.begin(), czasPoczatkowy.end(), czasKoncowy[i]);
            if(roznica == czasPoczatkowy.end())
                continue;


                int pomK = czasKoncowy[i];
                if( ((*roznica-pomK)*kolejneMinuty) < pierwszaMinuta)
                {
                    koszt = koszt - (pierwszaMinuta - ((*roznica-pomK)*kolejneMinuty));
					czasPoczatkowy.erase(roznica);
                }
        }
		cout << koszt << endl;
    }
    return 0;
}
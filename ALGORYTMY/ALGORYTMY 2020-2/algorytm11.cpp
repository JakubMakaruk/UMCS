#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    string dokogonalezy;
    vector<string> drugie;
    Node(string n, string d)
    {
        drugie.push_back(n);
        dokogonalezy = d;
    }
};

long h(string wyraz, int n)
{
    long long temp = 0;
    for(long long i=0; i<wyraz.length(); i++)
    {
        temp = wyraz[i] + 2 * temp;
        temp%=n;
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    long n = 0;
    
    cin >> n;
    cin.ignore();
    
    vector<vector<Node>> zespoly(n);
    vector<vector<Node>> kasety(n);
    
    for(long i=0; i<n; i++)
    {
        string wybor;
        getline(cin, wybor);
        
        if(wybor.length()==1)
        {
            switch(wybor[0])
            {
            case 'd':
            {
                string zespol, kaseta, xd;
                
                getline(cin, zespol);
                getline(cin, kaseta);
                
                int index1 = h(zespol, n);
                int index2 = h(kaseta, n);
                
                Node temp1(kaseta, zespol);
                Node temp2(zespol, kaseta);
                
                zespoly[index1].push_back(temp1);
                kasety[index2].push_back(temp2);
                
                break;
            }
            case 'w':
            {
                string zespol, xd;
                getline(cin, zespol);
                
                long index = h(zespol, n);
                
                if(!zespoly[index].empty())
                {
                    for(vector<Node>::iterator it=zespoly[index].begin(); it!=zespoly[index].end(); it++)
                    {
                        if((*it).dokogonalezy==zespol)
                        {
                            for(vector<string>::iterator it2=(*it).drugie.begin(); it2!=(*it).drugie.end(); it2++)
                                cout << (*it2) << endl;
                        }
                    }
                }
                
                break;
            }
            case 'z':
            {
                string kaseta;
                getline(cin, kaseta);
                
                long index = h(kaseta, n);
                
                if(!kasety[index].empty())
                {
                    for(vector<Node>::iterator it=kasety[index].begin(); it!=kasety[index].end(); it++)
                    {
                        if((*it).dokogonalezy==kaseta)
                        {
                            for(vector<string>::iterator it2=(*it).drugie.begin(); it2!=(*it).drugie.end(); it2++)
                                cout << (*it2) << endl;
                        }
                    }
                }
                
                break;
            }
            }
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int v[1000]={0};

class participant
{
public:
    string nume;
    string prenume;
    vector<int>nr;

    participant(string n, string p,vector<int>num)
    {
        nume=n;
        prenume=p;
        for(int i=0;i<(int)num.size();i++)
            nr.push_back(num[i]);
    }
};

bool sortare( int a, int b)
{
    if(v[a]<v[b])
        return true;
    if(v[a]==v[b])
    {
        if(v[a]==v[b])
        {
            if(a<b)
                return true;
        }
    }
    return false;
}

bool sortare2(participant a, participant b)
{
    if(a.nume<b.nume)
        return true;
    return false;
}
int main()
{

    int min_nr=50;
    int max=0;
    vector<string>cuv;
    vector<participant>p;
    string cuvant;
    string nume,prenume;
    int nr1;
    vector<int>nre;
    vector<int>s;
    vector<int>nr11;
    for(int i=0;i<6;i++)
    {
        cin>>nr1;
        nr11.push_back(nr1);
    }
    char c;
    cin>>c;
    while(getline(cin,cuvant))
    {
        stringstream s(cuvant);
        string nume;
        s>>nume;
        string prenume;
        s>>prenume;
        int nr;
        while(s>>nr)
        {
            nre.push_back(nr);
        }
        p.push_back(participant(nume,prenume,nre));
        nre.clear();

    }
    for(int i=0;i<(int)p.size();i++)
    {
        for(int j=0;j<(int)p[i].nr.size();j++)
        {
            v[p[i].nr[j]]++;
            if((int)v[p[i].nr[j]]>max)
            {
                max=v[p[i].nr[j]];
            }
        }
    }
    for(int i=0;i<(int)p.size();i++)
    {
        for(int j=0;j<(int)p[i].nr.size();j++)
        {
            if(v[p[i].nr[j]]==max)
            {
                if(p[i].nr[j]<min_nr)
                    min_nr=p[i].nr[j];
            }
        }
    }
    cout<<min_nr<<" "<<max<<"\n";
    max=0;
    for(int i=0;i<(int)p.size();i++)
    {
        if((int)p[i].nr.size()>max)
            max=p[i].nr.size();
    }
    if(max%6==0)
    {
        cout<<max/6<<"\n";
    }
    else
    {
        cout<<(max/6)+1<<"\n";
    }
    for(int i=0;i<(int)p.size();i++)
    {
        for(int j=0;j<(int)p[i].nr.size();j++)
        {
            v[p[i].nr[j]]++;
        }
    }
    for(int i=1;i<50;i++)
    {
        s.push_back(i);
    }
    sort(s.begin(),s.end(),sortare);
    for(int i=0;i<(int)s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<"\n";
    max=0;
    for(int i=0;i<(int)p.size();i++)
    {
        int k1=0;
        int ct=0;
        int z=6;
        int x=p[i].nr.size();
        x=x/6;
        for(int j=0;j<x;j++)
        {
            for(int k=k1;k<z;k++)
            {
                for(int l=0;l<(int)nr11.size();l++)
                {
                    if(nr11[l]==p[i].nr[k])
                        ct++;
                }
            }
            k1+=6;
            z+=6;
            if(ct>max)
                max=ct;
            ct=0;
        }
        k1=0;
        z=6;
    }
    cout<<max<<"\n";
    return 0;
}
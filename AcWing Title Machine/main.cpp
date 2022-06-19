#include <bits/stdc++.h>
typedef long long ll;
const ll maxn=55;
using namespace std;

vector<string> ve;

vector<string> one;
vector<string> two;
vector<string> three;
vector<string> four;
vector<string> five;
vector<string> six;
vector<string> seven;
void initve();

void initve()
{
    one.push_back("<p>");
    two.push_back("<ul>");
    two.push_back("<h4>");
    two.push_back("</p>");
    two.push_back("<ol>");
    three.push_back("</li>");
    three.push_back("</ol>");
    three.push_back("</h4>");
    three.push_back("</ul>");
    three.push_back("<pre>");
    four.push_back("<br />");
    four.push_back("<code>");
    four.push_back("</pre>");
    five.push_back("</code>");
    six.push_back("<strong>");
    seven.push_back("</strong>");
}

ll SolveOne(string s)
{
    for(ll i=0;i<one.size();i++)
    {
        if(s==one[i])
            return 2;
    }
    return 0;
}
ll SolveTwo(string s)
{
    for(ll i=0;i<two.size();i++)
    {
        if(s==two[i])
            return 3;
    }
    return 0;
}
ll SolveThree(string s)
{
    for(ll i=0;i<three.size();i++)
    {
        if(s==three[i])
            return 4;
    }
    return 0;
}
ll SolveFour(string s)
{
    for(ll i=0;i<four.size();i++)
    {
        if(s==four[i])
            return 5;
    }
    return 0;
}
ll SolveFive(string s)
{
    for(ll i=0;i<five.size();i++)
    {
        if(s==five[i])
            return 6;
    }
    return 0;
}
ll SolveSix(string s)
{
    for(ll i=0;i<six.size();i++)
    {
        if(s==six[i])
            return 7;
    }
    return 0;
}
ll SolveSeven(string s)
{
    for(ll i=0;i<seven.size();i++)
    {
        if(s==seven[i])
            return 8;
    }
    return 0;
}

int main(){

// <p>
// <li> <h4> <ul> </p>
// </li> </h4> </ul> <pre>
// <br /> <code>

initve();
bool SymFormula;
ll i,j;
string s;
string res;
string cmp;
ll cnt=0;
while(1)
{
system("cls");
ve.clear();
SymFormula=0;
cnt=0;
printf("Enter:\n");
while(getline(cin,s))
{
    cnt++;
    ll n=s.length();

    if(cnt==8)
    {
        res.clear();
        for(i=0;i<n;i++)
        {
            if(s[i]=='.')
                break;
        }
        i++;
        res+="###";
        for(;i<n-21;i++)
            res+=s[i];
        ve.push_back(res);
        res.clear();
    }

    if(cnt<=499) continue;

    if(s=="                    </div>") break;

    if(s=="0")  break;


    res.clear();

    for(i=0;i<n;i++)
        if(s[i]!=' ')   break;
    if(i==n)    continue;
    if(s.substr(i,11)=="<div class=")   continue;

    if(s.substr(0,4)=="<h4>")
        ve.push_back(res);

    ll plu;

    for(;i<n;i++)
    {
        if(s[i]=='$')   SymFormula^=1;
        // ----
        plu=0;
        plu=SolveOne(s.substr(i,3));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        plu=SolveTwo(s.substr(i,4));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        plu=SolveThree(s.substr(i,5));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        plu=SolveFour(s.substr(i,6));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        plu=SolveFive(s.substr(i,7));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        plu=SolveSix(s.substr(i,8));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        plu=SolveSeven(s.substr(i,9));
        if(plu!=0)
        {
            i+=plu;continue;
        }
        // -----

        if(s.substr(i,4)=="&gt;")
        {
            res+=">";i+=3;continue;
        }
        if(s.substr(i,4)=="&lt;")
        {
            res+="<";i+=3;continue;
        }
        if(s.substr(i,5)==" \\lt ")
        {
            res+=" \\lt ";i+=4;continue;
        }
        if(s.substr(i,4)=="\\le")
        {
            res+="\\leq";i+=3;continue;
        }
        if(s.substr(i,8)=="&hellip;")
        {
            if(SymFormula)
                res+="\\cdots ";
            else
                res+="$\\cdots$ ";
            i+=7;continue;

        }
        if(s.substr(i,5)=="src=\"")
        {
            res.clear();
            res+="![](";
            if(s.substr(i+5,4)!="http")
            {
                res+="https://www.acwing.com/";
            }
            for(j=i+5;j<n;j++)
            {
                if(s[j]=='\"')  break;
                res+=s[j];
            }
            res+=")";
            break;
        }

        if(s.substr(i,4)=="<li>")
        {
            res+="* ";i+=3;continue;
        }

        if((int)s[i]==63)
        {
            res+=" ";continue;
        }

        res+=s[i];
    }
        ve.push_back(res);

}

while(getline(cin,s))
{
    if(s=="</html>")
        break;
}

system("cls");
for(i=0;i<ve.size();i++)
    cout<<ve[i]<<endl;

cin>>s;
getchar();
}
}

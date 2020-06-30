#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  // __;
  freopen("numbers.in","r",stdin);freopen("numbers.out","w",stdout);
  map<string,int> d;
  d["million"] = 1e6;
  d["Million"] = 1e6;
  d["thousand"] = 1000;
  d["Thousand"] = 1000;
  d["hundred"] = 100;
  d["Hundred"] = 100;
  // d["two hundred"] = 200;
  // d["three hundred"] = 300;
  // d["four hundred"] = 400;
  // d["five hundred"] = 500;
  // d["six hundred"] = 600;
  // d["seven hundred"] = 700;
  // d["eight hundred"] = 800;
  // d["nine hundred"] = 900;
  d["zero"] = 0;
  d["Zero"] = 0;
  d["one"] = 1;
  d["One"] = 1;
  d["two"] = 2;
  d["Two"] = 2;
  d["three"] = 3;
  d["Three"] = 3;
  d["four"] = 4;
  d["Four"] = 4;
  d["five"] = 5;
  d["Five"] = 5;
  d["six"] = 6;
  d["Six"] = 6;
  d["seven"] = 7;
  d["Seven"] = 7;
  d["eight"] = 8;
  d["Eight"] = 8;
  d["nine"] = 9;
  d["Nine"] = 9;
  d["ten"] = 10;
  d["Ten"] = 10;
  d["eleven"] = 11;
  d["Eleven"] = 11;
  d["twelve"] = 12;
  d["Twelve"] = 12;
  d["thirteen"] = 13;
  d["Thirteen"] = 13;
  d["fourteen"] = 14;
  d["Fourteen"] = 14;
  d["fifteen"] = 15;
  d["Fifteen"] = 15;
  d["sixteen"] = 16;
  d["Sixteen"] = 16;
  d["seventeen"] = 17;
  d["Seventeen"] = 17;
  d["eighteen"] = 18;
  d["Eighteen"] = 18;
  d["nineteen"] = 19;
  d["Nineteen"] = 19;
  d["twenty"] = 20;
  d["Twenty"] = 20;
  d["thirty"] = 30;
  d["Thirty"] = 30;
  d["forty"] = 40;
  d["Forty"] = 40;
  d["fifty"] = 50;
  d["Fifty"] = 50;
  d["sixty"] = 60;
  d["Sixty"] = 60;
  d["seventy"] = 70;
  d["Seventy"] = 70;
  d["eighty"] = 80;
  d["Eighty"] = 80;
  d["ninety"] = 90;
  d["Ninety"] = 90;

  set<char> special;
  special.insert('.');
  special.insert(',');
  special.insert('!');
  special.insert('?');
  special.insert(':');
  special.insert(';');
  special.insert(')');
  special.insert('(');
  special.insert('\n');
  special.insert(' ');

  string s;
  string ans;
  int temp_number = 0;
  int number = 0;
  bool is_number = false;
  bool prev_hundred = false;
  bool continue_line = false;
  string temp_word;

  while(getline(cin,s))
  {
    // t(s,continue_line);
    
    int i = 0;
    s+='\n';

    while(i<s.size())
    {
      // t(i,temp_word,temp_number,number);
      // transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower); 
      if(special.count(s[i]))
      {
        // if(s[i] == ',') t(temp_word);
        // t(i,s[i],temp_word);
        if((temp_word == "and" || temp_word == "And") && prev_hundred)
        {
          prev_hundred = false;
          if(s[i] != ' ' && s[i] != '\n')
          {
            number += temp_number;
            temp_number = 0;
            ans += to_string(number);
            ans += " ";
            ans += temp_word;
            ans += s[i];
            number = 0;
            is_number = false;
            prev_hundred = false;
            continue_line = false;
          }
        }
        else if((temp_word == "hundred" || temp_word == "Hundred"))
        {
          if(!is_number)
          {
            ans += temp_word;
            if(s[i] != '\n') ans += s[i];
          }
          else
          {
            temp_number *= 100;
            prev_hundred = true;
            if(s[i] != ' ' && s[i] != '\n')
            {
              number += temp_number;
              temp_number = 0;
              ans += to_string(number);
              ans += s[i];
              number = 0;
              is_number = false;
              prev_hundred = false;
              continue_line = false;
            }
          }
        }
        else if((temp_word == "thousand") || (temp_word == "Thousand"))
        {
          // t(temp_number);
          if(!is_number)
          {
            ans += temp_word;
            if(s[i] != '\n') ans += s[i];
          }
          else
          {
            temp_number *= 1000;
            number += temp_number;
            temp_number = 0;
            prev_hundred = false;
            if(s[i] != ' ' && s[i] != '\n')
            {
              number += temp_number;
              temp_number = 0;
              ans += to_string(number);
              ans += s[i];
              number = 0;
              is_number = false;
              prev_hundred = false;
              continue_line = false;
            }
          }
        }
        else if((temp_word == "million") || (temp_word == "Million"))
        {
          if(is_number)
          {
            if(number >= 1000) 
            {
              ans += to_string(number);
              ans += " ";
              number = 0;
            }
            temp_number *= 1000000;
            number += temp_number;
            temp_number = 0;
            prev_hundred = false;
            temp_number = 0;
            if(s[i] != ' ' && s[i] != '\n')
            {
              number += temp_number;
              temp_number = 0;
              ans += to_string(number);
              ans += s[i];
              number = 0;
              is_number = false;
              prev_hundred = false;
              continue_line = false;
            }
          }
          else
          {
            ans += temp_word;
            if(s[i] != '\n') ans += s[i];
          }
        }
        else if(d.count(temp_word))
        {
          int a  = d[temp_word];
          if(a  < 10)
          {
            if(temp_number && (temp_number < 20 || temp_number%10))
            {
              number += temp_number;
              temp_number = 0;
              ans += to_string(number);
              ans += " ";
              number = 0;
            }
            temp_number += d[temp_word];
            is_number = true;
            prev_hundred = false;
          }
          else if(a < 100 && temp_number % 100)
          {
            if(temp_number > 0)
            {
              number += temp_number;
              temp_number = 0;
              ans += to_string(number);
              ans += " ";
              number = 0;
            }
            temp_number += d[temp_word];
            is_number = true;
            prev_hundred = false;
          }
          else if(a < 1000 && temp_number % 100)
          {
            if(temp_number > 0)
            {
              number += temp_number;
              temp_number = 0;
              ans += to_string(number);
              ans += " ";
              number = 0;
            }
            temp_number += d[temp_word];
            is_number = true;
            prev_hundred = false;
          }
          else
          {
            temp_number += d[temp_word];
            is_number = true;
            prev_hundred = false;
          }

          if(s[i] != ' ' && s[i] != '\n')
          {
            number += temp_number;
            temp_number = 0;
            ans += to_string(number);
            ans += s[i];
            number = 0;
            is_number = false;
            prev_hundred = false;
            continue_line = false;
          }
        }
        else
        {
          if(is_number)
          {
            number += temp_number;
            temp_number = 0;
            ans += to_string(number);
            ans += ' ';
            number = 0;
            is_number = false;
            prev_hundred = false;
          }
          if(continue_line) 
          {
            ans += '\n';
          }

          ans += temp_word;
          if(s[i] != '\n') ans += s[i];
        }

        continue_line = false;
        temp_word = "";
        i++;
        continue;
      }
      temp_word += s[i];
      i++;
    }

    if(temp_word != "")
    {
      if(continue_line)
      {
        continue_line = false;
        ans += '\n';
      }
      ans += temp_word;
      temp_word = "";
    }

    if(!is_number) ans += '\n';
    else continue_line = true;
  }

  if(is_number)
  {
    number += temp_number;
    ans += to_string(number);
    if(continue_line) ans += '\n';
  }

  if(temp_word != "")
  {
    if(continue_line) ans += '\n';
    ans += temp_word;
  }

  cout << ans;
  return 0;
}

/*
From three thousand one hundred and fifty teams selected
from one thousand four hundred and eleven universities
in seventy five countries competing at one hundred and
twenty seven sites and hundreds more competing at
preliminary contests worldwide, seventy three teams
of students competed for bragging rights and prizes
at The Twenty Eighth Annual ACM International Collegiate
Programming Contest World Finals sponsored by IBM on
March Thirty One, Two Thousand Four, and hosted at the
Obecni Dum, Prague by Czech Technical University in Prague.


Five hundred and
Seventy two, years ago we had eighty 
people trying to do some one million!
one Thousand one hundred and eight nonsense


*/

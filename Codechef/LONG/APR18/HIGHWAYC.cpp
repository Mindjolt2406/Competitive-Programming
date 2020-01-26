#include<iostream>
#include<utility>
#include<cmath>
#include<iomanip>
#define pu push_back
#define m make_pair
using namespace std;

double long direct(double long n)
{
  if (n==0) return -1;
  else return 1;
}

int crossed(double long pos,double long curpos)
{
  double long a = pos/abs(pos);
  double long b = curpos/abs(curpos);
  if(a/b == -1) return 1;
  else return 0;
}

pair <int, double long> goingtocross(double long pos,double long speed,double long t,double long sign,double long length)
{
  /* Returns -1 is crossing is happening right now
  Returns 1 if cross hasn't taken place
  Returns 0 if crossed already
  */
  int c = pos/abs(pos);
  double long curpos = pos + sign*speed*t;
  int d = curpos/abs(curpos);
  if(sign == 1 && curpos>= -0.000001 && length+0.000001>=curpos)
  {
    double long time2 = (length-curpos)/speed;
    return m(-1,time2);
  }
  else if(sign == -1 && curpos<= 0.000001 && length+0.000001>=abs(curpos))
  {
    double long time2 = (length-abs(curpos))/speed;
    return m(-1,time2);
  }
  else if(c!=d) return m(0,0);
  else if(c==1 && d==1 && sign == -1) return m(1,curpos);
  else if(c==1 && d==1 && sign == 1) return m(0,0);
  else if(c==-1 && d==-1 && sign == 1) return m(1,curpos);
  else if(c==-1 && d==-1 && sign == -1) return m(0,0);
  return m(1,curpos);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    double long speed,width;
    cin>>n>>speed>>width;
    double long timechef = width/speed;
    double long dist = 0;
    double long vec[n];
    double long direc[n];
    double long pos[n];
    double long length[n];
    for(int i=0;i<n;i++) cin>>vec[i];
    for(int i=0;i<n;i++) cin>>direc[i];
    for(int i=0;i<n;i++) cin>>pos[i];
    for(int i=0;i<n;i++) cin>>length[i];
    double long t = 0;
    // The ith iteration assumes the chef has crossed the (i-1)th lane
    for(int i=0;i<n;i++)
    {
      double long sign = direct(direc[i]);
      pair <int,double long> p = goingtocross(pos[i],vec[i],t,sign,length[i]);
      // double long curpos = pos[i] + sign*vec[i]*(t+timechef);
      if(p.first==0)
      {
        t+=timechef;
      }
      else if(p.first==1)
      {
        double curpos = p.second;
        // cout<<"Entered: "<<timechef-abs(curpos)/vec[i]<<endl;
        if (abs(curpos)/vec[i]-timechef>0.000001) t+=timechef;
        else t+=(abs(curpos)+length[i])/vec[i] + timechef;
      }
      else
      {
        double long time2 = p.second;
        cout<<"time2: "<<time2<<endl;
        t+= time2+timechef;
      }
    }
    cout<<fixed;
    cout<<setprecision(10)<<t<<endl;
  }
}
/*
1
1 8 177
190
0
4201
21

*/

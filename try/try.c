#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float truncfunc(float x) 
{ 
    return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4;  
}

double calcEuclideanDist(int n, double vec1[], double vec2[])
{
    double res = 0;
    for(int i=0 ; i<n ; i++)
    {
      res += (vec1[i]-vec2[i])*(vec1[i]-vec2[i]); 
    }
    res = sqrt(res);
    return res;
}

double calcManhattanDist(int n, double vec1[], double vec2[])
{
    double res = 0;
    for(int i=0 ; i<n ; i++)
    {
        res += fabs(vec1[i]-vec2[i]);
    }
    return res;
}

double calcChebyshevDist(int n, double vec1[], double vec2[])
{
    double res = 0;
    for(int i=0 ; i<n ; i++)
    {
        double sub = fabs(vec1[i]-vec2[i]);
        if(sub >= res)
        {
            res = sub;
        }
    }
    return res;
}

double calcKLdiverg(int n, double vec1[], double vec2[])
{
    double res = 0;
    for(int i=0 ; i<n ; i++)
    {
        res += vec1[i]*log(vec1[i]/vec2[i]);
    }
    return res;
}

double calcJSdiverg(int n, double vec1[], double vec2[])
{
    double res = 0;
    double avg[n];

    for(int i=0 ; i<n ; i++)
    {
        avg[i] = (vec1[i]+vec2[i])/2;
    }
    res += calcKLdiverg(n, vec1, avg)/2 + calcKLdiverg(n, vec2, avg)/2;
    return res;
}

double calcJSdist(int n, double vec1[], double vec2[])
{
    double res = sqrt(calcJSdiverg(n, vec1, vec2));
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    if(n>0)
    {
        //took 2 chars and an integer for storing ' ',-1,' '
        char delimC1;
        int delim;
        char delimC2;
        scanf("%c",&delimC1);
        scanf("%d",&delim);
        scanf("%c",&delimC2);
        
        double vec1[n];//arrays to store the vectors
        double vec2[n];
    
        if(delimC1==' ' && delim==-1 && delimC2==' ')
        {//if delimeter is given right, taking input of first vector
            char com;
            for(int i=0 ; i<n-1 ; i++)
            {
                scanf("%lf",&vec1[i]);
                scanf("%c",&com);
                if(com!=',' || vec1[i]<=0)//if the input of values of vector are not comma separated or if the values are non-positive 
                {                         //then it is an invalid input 
                    printf("-1\n");
                    return 0;
                }                
            }
            scanf("%lf",&vec1[n-1]);
            if(vec1[n-1]<=0)//if the value is non-positive, it is an invalid input
            {
                printf("-1\n");
                return 0;
            }

            scanf("%c",&delimC1);
            scanf("%d",&delim);
            scanf("%c",&delimC2);
            
            if(delimC1==' ' && delim==-1 && delimC2==' ')
            {//if delimeter is given right, taking input of second vector
                for(int i=0 ; i<n-1 ; i++)
                {
                    scanf("%lf",&vec2[i]);
                    scanf("%c",&com);
                    if(com!=',' || vec2[i]<=0)//if the input of values of vector are not comma separated or if the values are non-positive 
                    {                         //then it is an invalid input
                        printf("-1\n");
                        return 0;
                    }
                }
                scanf("%lf",&vec2[n-1]);
                if(vec2[n-1]<=0)//if the value is non-positive, it is an invalid input
                {
                    printf("-1\n");
                    return 0;
                }
                char end[3];//for the last delimeter
                fgets(end,4,stdin);
                if(end[0]==' ' && end[1]=='-' && end[2]=='1')
                {//if the final delimeter is also given right, normalizing the vectors and finding the required distances
                    double sum1 = 0;
                    double sum2 = 0;
                    for(int i=0 ; i<n ; i++)//finding sum for normalization
                    {
                        sum1 += vec1[i];
                        sum2 += vec2[i];
                    }

                    for(int i=0 ; i<n ; i++)//normalizing the vectors
                    {
                        vec1[i] = vec1[i]/sum1;
                        vec2[i] = vec2[i]/sum2;
                    }
                    //calling the required functions and printing the output(rounded to 4 decimal points)
                    double manDis = calcManhattanDist(n,vec1,vec2);
                    double eucliDis = calcEuclideanDist(n,vec1,vec2);
                    double chebeDis = calcChebyshevDist(n,vec1,vec2);
                    double klDiverg = calcKLdiverg(n,vec1,vec2) + calcKLdiverg(n,vec2,vec1);
                    double jsDis = calcJSdist(n,vec1,vec2);

                    double tmanDis = truncfunc(manDis);
                    double teucliDis = truncfunc(eucliDis);
                    double tchebeDis = truncfunc(chebeDis);
                    double tklDiverg = truncfunc(klDiverg);
                    double tjsDis = truncfunc(jsDis);

                    printf("%.4lf,%.4lf,%.4lf,%.4lf,%.4lf\n",tmanDis,teucliDis,tchebeDis,tklDiverg,tjsDis);
                   
                }
                
                else//if delimeter is not properly given, it is an invalid input
                {
                    printf("-1\n");
                }
                
            }

            else//if delimeter is not properly given, it is an invalid input
            {
               printf("-1\n");
            }
            
        }

        else//if delimeter is not properly given, it is an invalid input
        {
            printf("-1\n");
        }
    
    }

    else//if n is less than 0, it is an invalid input
    {
       printf("-1\n");
    }

    return 0;
}


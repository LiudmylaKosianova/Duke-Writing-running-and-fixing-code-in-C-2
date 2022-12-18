#include <stdio.h>
#include <stdlib.h>

//The task was to write a "retirement savings" calculator


//basic information about a person working or retired
struct _retire_info
{
int months; //the number of months it is applicable to
double contribution;//how many dollars are contributed (or spent if negative) from the account per month 
double rate_of_return;//the rate of returns
};
typedef struct _retire_info retire_info;


//this function computes and prints the retirement account balance
double alive (retire_info alive, int startAge, double initial)
{
  for (int i=0;i<alive.months;i++)
  {
  printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,initial);
  initial += (((alive.rate_of_return/100)/12)*initial)+alive.contribution;
  startAge++;  
  }
  return initial;
}

void retirement (int startAge,   //in months
                       double initial, //initial savings in dollars
                       retire_info working, //info about working
                       retire_info retired) //info about being retired
{
  initial= alive(working,startAge,initial);
  startAge += working.months;
  alive(retired,startAge,initial);
}
 
  int main(void){
    
    retire_info working;
    working.months= 489;
    working.contribution = 1000;
    working.rate_of_return = 4.5;
    
    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 1.0;
    
    int startAge = 327;//age of a person in months
    double initial = 21345;
    
    retirement(startAge,initial,working,retired);
    
  return EXIT_SUCCESS;
}

#include<iostream>
#include<math.h>
#include<cmath>
#include "coding-problems (2).h"
using namespace std;
int main()
{
   bool homerun=true;
   double distance;
   double camera_height;
    
   FindCameraHeight(20, 60, camera_height);

   FindIntersectionDistance(10, 45, distance);

   IsHomeRun(150, 30, 10, homerun);

}
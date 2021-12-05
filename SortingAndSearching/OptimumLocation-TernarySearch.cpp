#include<bits/stdc++.h>
using namespace std;
#define sq(x) ((x) * (x))
struct point {
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y){}
};
struct line {
    int a, b, c;
    line(int a, int b, int c) : a(a), b(b), c(c) {}
};
int getDistance(point p1, point p2){
  return sqrt(sq(p1.x - p2.x) + sq(p1.y - p2.y));
}
double compute(vector<point> & points, line l, int x){
  double result=0;
  double y = -1 * (l.c + l.a * x) / l.b;
  for(point p : points){
    result += getDistance(p, point(x,y));
  }
  return result;
}
double findOptimumCost(vector<point> & points, line l)
{
  double low = -1e6;
  double high = 1e6;

  while(low<=high){
    int mid1 = low + (high-low)/3;
    int mid2 = high - (high-low)/3;

    double dist1 = compute(points, l, mid1);
    double dist2 = compute(points, l, mid2);

    if(dist1<dist2)
      high = mid2;
    else
      low= mid1;
  }
  return compute(points, l, (low+high)/2);
}
int main(){
  line l(1, -1, -3);
  vector<point> p ={
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    cout<< findOptimumCost(p,l);
  
}

/* APPROACH
link : https://www.codingninjas.com/codestudio/problem-details/optimum-location_1116097
/*
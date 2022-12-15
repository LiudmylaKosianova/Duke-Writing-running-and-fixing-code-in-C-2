#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
struct rectangle_sw{
int x;
int y;
int width;
int height;
};
typedef struct rectangle_sw rectangle;

rectangle canonicalize(rectangle r) {
  //WRITE THIS FUNCTION
  if (r.width<0){
  r.x = r.x + r.width;
  r.width = r.width*-1;
  }
  if(r.height<0){
  r.y = r.y + r.height;  
  r.height = r.height*-1;   
  }
  return r;
}
rectangle intersection(rectangle r1, rectangle r2) {
  //WRITE THIS FUNCTION   
  rectangle r;
  r1 = canonicalize(r1);
  r2 = canonicalize(r2);  
  /*I think the cases when rectangles do not intersect are 
  * when r1 lies futher to the right or to the left of r2, it means 
  * the right most edge of r1 (r1.x+r1.widht) ends before the left most edge of r2 (r2.x) starts 
  * OR
  * the right most edge of r2 (r2.x+r2.width) ends before the left most edge of r1(r1.x) starts
  * r1.x+r1.widht < r2.x OR r2.x+r2.width < r1.x
  * 
  * they don't intersect, when one of the rectangles lower than the other
  * when r1 is lower than r2 or r2 is lower than r1, it means 
  * the top of r1(r1.y+r1.height) is lower than the bottom of r2(r2.y)
  * OR
  * the top of r2(r2.y+r2.height) is lower than the bottm of r1(r1.y)
  * r1.y+r1.height < r2.y OR r2.y+r2.height < r1.y  
  */ 
  
  if (r1.x+r1.width < r2.x || r2.x+r2.width < r1.x) {  
    r.x = 0;
    r.y =0;
    r.width = 0;
    r.height =0;     
    return r;
  }else if (r1.y+r1.height < r2.y || r2.y+r2.height < r1.y){
    r.x = 0;
    r.y =0;
    r.width = 0;
    r.height =0;     
    return r;
  
  }
   
    
  /*Rectangles may only share one of the edges
  * when they share left-right edge, then x values of this edge are the same for both rectangles
  * the right most edge of r1 (r1.x+r1.width) can touch left most edge of r2(r2.x)
  *OR
  * the right most edge of r2(r2.x+r2.widht) can touch left most edge of r1(r1.x)
  */
  
  if(r1.x+r1.width == r2.x || r2.x+r2.width == r1.x){
  r.x = max(r1.x,r2.x);
  r.y = max(r1.y, r2.y);
  r.width = 0;
  r.height = min(r1.y+r1.height,r2.y+r2.height)-r.y;
  return r;
  } 
    
  if(r1.y+r1.height==r2.y || r2.y+r2.height==r1.y){
  r.x = max(r1.x,r2.x); 
  r.y = min(r1.y+r1.height, r2.y+r2.height);
  r.width= min(r1.x+r1.width, r2.x+r2.width) - r.x; 
  printf("min(r1.x, r2.x):%d minus r.x:%d is:%d", min(r1.x, r2.x),r.x, r.width);
  r.height = 0;
  //printf("\n r.x and r.y:(%d,%d)\n r.width:(%d) r.height is zero\n", r.x, r.y, r.width);
  return r;}
  
  //Finally the cases when rectangles do intersect
  r.x = max(r1.x, r2.x);
  r.y = max(r1.y, r2.y);
  r.width = min(r1.x+r1.width, r2.x+r2.width)-r.x;
  r.height = min(r1.y+r1.height,r2.y+r2.height)-r.y;
   
  return r;
}



//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}

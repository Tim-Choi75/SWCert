//https://www.youtube.com/watch?v=OlpNg81Csn0&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=4

#include <stdio.h>

int get_gcd(int u, int v) {
  int t;
  while(v) {
  	t=u%v;
  	u=v;
  	v=t;
  	
  	return u;
  }
  /*
  while (u) {
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }
    u = u - v;
  }
  return v;
  */
}

int get_gcd(int u, int v) {
  int t;
  while(v) {
  	t=u%v;
  	u=v;
  	v=t;
  	
  	return u;
  }
  /*
  while (u) {
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }
    u = u - v;
  }
  return v;
  */
}

int main(void) {
  int u, v;
  int gcd;
  u = 280;
  v = 30;
  printf("get_gcd result: ");
  gcd = get_gcd(u, v);
  printf("%d\n", gcd);

  return 0;
}

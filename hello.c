#include "hal.h"

#include <stdio.h>
#include <string.h>



static void yazdir(const char *s) {
  hal_send_str(s);
}

static void intyazdir(const char *s, const int a) {
  char out[32];
  snprintf(out,32,s,a);
  hal_send_str(out);
}
int *bolme(int s1, int s2){
    static int liste[2];
    int r = s1;
    int q = 0;

    while( r >= s2 ){
        int k = 1;
        int x = s2;
        int t;

        while( ( t = x+x ) < r ){
            x = t;
            k += k;
        }

    q += k;
    r -= x;
    }
    liste[0]=q;
    liste[1]=r;
    return liste;
}
int oran(int s1, int s2){
    int count =0;
    int *p;
    int i;
    for(i=0;i<3;i++){
        p = bolme(s1,s2);
        int sonuc = p[0];
        int kalan = p[1];
        intyazdir("%d",sonuc);
        if(i == 0){
        yazdir(",");
        }
        s1 = kalan *10; 

    }
}


int main(void) {
  hal_setup(CLOCK_FAST);
  
  // marker for automated benchmarks
  oran(14,13);
  oran(1,2);
  oran(3,5);
  oran(8,3);
  while (1);

  return 0;
}

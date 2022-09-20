#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t *ys = malloc(3840*2160*2);
    uint16_t *cbs = malloc(1920*1080*2);
    uint16_t *crs = malloc(1920*1080*2);
    for(;;) {
        for(int y = 0; y < 2160; y++) {
            for(int x = 0; x < 3840; x++) {
                ys[y*3840 + x] = 100;
                if((x % 2) == 0 && (y % 2) == 0) {
                    cbs[(y / 2)*1920 + (x / 2)] = 200;
                    crs[(y / 2)*1920 + (x / 2)] = 300;
                }
            }
        }
        fwrite(ys,2,3840*2160,stdout);
        fwrite(crs,2,1920*1080,stdout);
        fwrite(cbs,2,1920*1080,stdout);
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t *ys = malloc(3840*2160*2);
    uint16_t *cbs = malloc(1920*1080*2);
    uint16_t *crs = malloc(1920*1080*2);
    for(;;) {
        for(uint16_t y = 0; y < 2160; y++) {
            for(uint16_t x = 0; x < 3840; x++) {
                ys[y*3840 + x] = 100;
                if((x & 1) == 0 && (y & 1) == 0) {
                    cbs[(y >> 1)*1920 + (x >> 1)] = 200;
                    crs[(y >> 1)*1920 + (x >> 1)] = 300;
                }
            }
        }
        fwrite(ys,2,3840*2160,stdout);
        fwrite(crs,2,1920*1080,stdout);
        fwrite(cbs,2,1920*1080,stdout);
    }
}
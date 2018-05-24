#include <stdio.h>

//#define DEBUG 1

long part_A[3];
long part_B[4][3];
long part_C[4][3];
long field_2[9];
long field_3[15];

void dump_1d(long x, long len) {
  long i;
  for (i = len-1; 0 <= i; i--) printf("%d", (x & (1 << i)) >> i);
  printf("\n");
  return;
}

void dump_2d(long *p, long height, long len) {
  long i;
  for (i = 0; i < height; i++) dump_1d(p[i], len);
  return;
}

void rotate(long *src, long *dst) {
  long i, j;
  long tmp[3];

  for (i = 0; i < 3; i++) tmp[i] = src[i];

  for (i = 0; i < 3; i++) {
    dst[i] = 0;
    for (j = 0; j < 3; j++) {
      dst[i] <<= 1;
      dst[i] |= tmp[j] & 1;
      tmp[j] >>= 1;
    }
  }

  return;
}

void data_read() {
  char strs[3][20];
  long i, j;

  for (i = 0; i < 3; i++) {
    scanf("%s%s%s", strs[0], strs[1], strs[2]); 
    for (j = 0; j < 3; j++) {
      part_A[i] <<= 1;
      if (strs[0][j] == '#') part_A[i] |= 1;
    }
    for (j = 0; j < 3; j++) {
      part_B[0][i] <<= 1;
      if (strs[1][j] == '#') part_B[0][i] |= 1;
    }
    for (j = 0; j < 3; j++) {
      part_C[0][i] <<= 1;
      if (strs[2][j] == '#') part_C[0][i] |= 1;
    }
  }

  for (i = 0; i < 3; i++) {
    rotate(part_B[i], part_B[i+1]);
    rotate(part_C[i], part_C[i+1]);
  }

  return;
}

void clear_field_2() {
  long i;

  for (i = 0; i < 3; i++) field_2[i] = 0;
  for (i = 3; i < 6; i++) field_2[i] = part_A[i-3] << 3;
  for (i = 6; i < 9; i++) field_2[i] = 0;

  return;
}

void clear_field_3() {
  long i;

  for (i =  0; i <  3; i++) field_3[i] = 0;
  for (i =  3; i < 12; i++) field_3[i] = field_2[i-3] << 3;
  for (i = 12; i < 15; i++) field_3[i] = 0;

  return;
}

long measure_field_3_height() {
  long i = 0, j = 14;
  while (field_3[i] == 0 && i < 15) i++;
  while (field_3[j] == 0 && i <= j) j--;
  return j - i + 1;
}

long field_3_column_0(long bitpos) {
  long i;
  long flag;
  for (i = 0; i < 15; i++) {
    if ((field_3[i] & (1 << bitpos)) != 0) return 0;
  }
  return 1;
}

long measure_field_3_width() {
  long i = 0, j = 14;
#ifdef DEBUG
  printf("####### width i loop");
#endif
  while (field_3_column_0(i) && i < 15) {
#ifdef DEBUG
    printf(" %d", i);
#endif
    i++;
  }
#ifdef DEBUG
  printf("\n");
  printf("####### width j loop");
#endif
  while (field_3_column_0(j) && i <= j) {
#ifdef DEBUG
    printf(" %d", j);
#endif
    j--;
  }
  while (field_3_column_0(j) && i <= j) j--;
#ifdef DEBUG
  printf("\n");
#endif
  return j - i + 1;
}

long add_part_C(long orien, long y, long x) {
  long i;
  for (i = 0; i < 3; i++) {
    if ((part_C[orien][i] << x) & field_3[y+i]) return 0;
    field_3[y+i] |= (part_C[orien][i] << x);
  }
  return 1;
}

long add_part_B(long orien, long y, long x) {
  long i;
  for (i = 0; i < 3; i++) {
    if ((part_B[orien][i] << x) & field_2[y+i]) return 0;
    field_2[y+i] |= (part_B[orien][i] << x);
  }
  return 1;
}

long loop_field_3() {
  long min_area = 300, area, orien, x, y;
  long width, height;
  for (orien = 0; orien < 4; orien++) {
    for (y = 0; y <= 12; y++) {
      for (x = 0; x <= 12; x++) {
#ifdef DEBUG
        printf("##### loop_field_3     orien=%d y=%d x=%d\n", orien, y, x);
#endif
        clear_field_3();
        if (add_part_C(orien, y, x)) {
#ifdef DEBUG
          dump_2d(field_3, 15, 15); printf("\n");
#endif
          height = measure_field_3_height();
          width = measure_field_3_width();
          area = height * width;
          if (area < min_area) min_area = area;
        }
#ifdef DEBUG
        printf("##### loop_field_3_end orien=%d y=%d x=%d, [w, h]=[%d,%d] area=%d, min_area=%d\n", orien, y, x, width, height, area, min_area);
#endif
      }
    }
  }
  return min_area;
}

long loop_field_2() {
  long min_area = 300, area, orien, x, y;
  for (orien = 0; orien < 4; orien++) {
    for (y = 0; y <= 6; y++) {
      for (x = 0; x <= 6; x++) {
#ifdef DEBUG
        printf("### loop_field_2     orien=%d y=%d x=%d\n", orien, y, x);
#endif
        clear_field_2();
#ifdef DEBUG
        dump_2d(field_2, 9, 9); printf("\n");
#endif
        if (add_part_B(orien, y, x)) {
#ifdef DEBUG
          dump_2d(field_2, 9, 9); printf("\n");
#endif
          area = loop_field_3();
          if (area < min_area) min_area = area;
        }
#ifdef DEBUG
        printf("### loop_field_2_end orien=%d y=%d x=%d area=%d min_area=%d\n",
               orien, y, x, area, min_area);
#endif
      }
    }
  }
  return min_area;
}

int main() {
  int i;
  data_read();
  //dump_2d(part_A, 3, 3); printf("\n");
  //for (i = 0; i < 4; i++) {
  //  dump_2d(part_B[i], 3, 3);
  //  printf("\n");
  //}
  //for (i = 0; i < 4; i++) {
  //  dump_2d(part_C[i], 3, 3);
  //  printf("\n");
  //}
  printf("%d\n", loop_field_2());
  return 0;
}

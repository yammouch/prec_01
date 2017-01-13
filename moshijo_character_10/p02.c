#include <stdio.h>

struct qel {
  int y;
  int x;
  int ns; // number of step
};

int h, w, n;
int field[256][256];
int step[256][256];
struct qel q[256*256];
int qhead, qtail;
int goal_y, goal_x;

void push(struct qel qe) {
  q[qhead] = qe;
  qhead = (qhead + 1) % (256*256);
}

struct qel pop() {
  struct qel retval;
  retval = q[qtail];
  qtail = (qtail + 1) % (256*256);
  return retval;
}

void data_read() {
  int i, j;
  char str[256];
  struct qel start_point;

  scanf("%d%d%d", &h, &w, &n);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      step[i][j] = -1; // not stepped
    }
  }
  for (i = 0; i < h; i++) {
    scanf("%s", str);
    for (j = 0; j < w; j++) {
      switch (str[j]) {
      case '#':
        field[i][j] = 1;
        break;
      default:
        field[i][j] = 0;
      }
    }
  }
  scanf("%d%d", &(start_point.x), &(start_point.y));
  scanf("%d%d", &goal_x, &goal_y);
  start_point.x--; start_point.y--; start_point.ns = 0;
  goal_x--; goal_y--;
  step[start_point.y][start_point.x] = 0;
  push(start_point);
  return;
}

void dump_queue() {
  int i;
  printf("qhead: %d, qtail: %d\n", qhead, qtail);
  if (qtail <= qhead) {
    for (i = qtail; i < qhead; i++) {
      printf("%d %d %d\n", q[i].y, q[i].x, q[i].ns);
    }
  } else {
    for (i = qtail; i < 256*256; i++) {
      printf("%d %d %d\n", q[i].y, q[i].x, q[i].ns);
    }
    for (i = 0; i < qhead; i++) {
      printf("%d %d %d\n", q[i].x, q[i].y, q[i].ns);
    }
  }
  return;
}

void print_solution() {
  int x, y, n_ch;
  static char solution[256*256];

  x = goal_x;
  y = goal_y;
  n_ch = 0;

  while (step[y][x] != 0) {
    if (0 < y && step[y-1][x] == step[y][x] - 1) { // up
      solution[n_ch++] = 'D';
      y--;
    } else if (0 < x && step[y][x-1] == step[y][x] - 1) { // left
      solution[n_ch++] = 'R';
      x--;
    } else if (y < h-1 && step[y+1][x] == step[y][x] - 1) { // down
      solution[n_ch++] = 'U';
      y++;
    } else if (x < w-1 && step[y][x+1] == step[y][x] - 1) { // right
      solution[n_ch++] = 'L';
      x++;
    }
  }

  while (0 < n_ch) {
    printf("%c\n", solution[--n_ch]);
  }
}

int main() {
  int n_step;
  struct qel p, pn; // point and point next

  data_read();

  while (qhead > qtail) { // queue is not empty
    //dump_queue();
    p = pop();
    if (p.x == goal_x && p.y == goal_y) {
      //printf("%d\n", p.ns);
      print_solution();
      return 0;
    }

    // Adds adjacent points to queue if they are not on edge, and not on wall,
    // and not stepped.
    if (0 < p.y && field[p.y-1][p.x] != 1 && step[p.y-1][p.x] < 0) { // up
      pn.x = p.x; pn.y = p.y - 1; pn.ns = p.ns + 1; push(pn);
      step[p.y-1][p.x] = p.ns + 1;
    }
    if (p.y < h-1 && field[p.y+1][p.x] != 1 && step[p.y+1][p.x] < 0) { // down
      pn.x = p.x; pn.y = p.y + 1; pn.ns = p.ns + 1; push(pn);
      step[p.y+1][p.x] = p.ns + 1;
    }
    if (0 < p.x && field[p.y][p.x-1] != 1 && step[p.y][p.x-1] < 0) { // left
      pn.x = p.x - 1; pn.y = p.y; pn.ns = p.ns + 1; push(pn);
      step[p.y][p.x-1] = p.ns + 1;
    }
    if (p.x < w-1 && field[p.y][p.x+1] != 1 && step[p.y][p.x+1] < 0) { // right
      pn.x = p.x + 1; pn.y = p.y; pn.ns = p.ns + 1; push(pn);
      step[p.y][p.x+1] = p.ns + 1;
    }
  }

  printf("Fail\n");
  return 0;
}

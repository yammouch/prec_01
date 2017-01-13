#include <stdio.h>

struct qel {
  int y;
  int x;
  int ns; // number of step
};

int n, m;
int field[1024][1024];
int step[1024][1024];
struct qel q[1024*1024];
int qhead, qtail;
int goal_y, goal_x;

void push(struct qel qe) {
  q[qhead] = qe;
  qhead = (qhead + 1) % (1024*1024);
}

struct qel pop() {
  struct qel retval;
  retval = q[qtail];
  qtail = (qtail + 1) % (1024*1024);
  return retval;
}

void data_read() {
  int i, j;
  char ch[16];
  struct qel start_point;

  scanf("%d%d", &m, &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      step[i][j] = -1; // not stepped
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%s", ch);
      //printf("%c", ch[0]);
      switch (ch[0]) {
      case '1':
        field[i][j] = 1;
        break;
      case 's': 
        start_point.x = j;
        start_point.y = i;
        start_point.ns = 0;
        push(start_point);
        step[start_point.y][start_point.x] = 0;
        break;
      case 'g':
        goal_x = j;
        goal_y = i;
        break;
      }
    }
  }
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
    for (i = qtail; i < 1024*1024; i++) {
      printf("%d %d %d\n", q[i].y, q[i].x, q[i].ns);
    }
    for (i = 0; i < qhead; i++) {
      printf("%d %d %d\n", q[i].x, q[i].y, q[i].ns);
    }
  }
  return;
}

int main() {
  int n_step;
  struct qel p, pn; // point and point next

  data_read();

  while (qhead > qtail) { // queue is not empty
    //dump_queue();
    p = pop();
    if (p.x == goal_x && p.y == goal_y) {
      printf("%d\n", p.ns);
      return 0;
    }

    // Adds adjacent points to queue if they are not on edge, and not on wall,
    // and not stepped.
    if (0 < p.y && field[p.y-1][p.x] != 1 && step[p.y-1][p.x] < 0) { // up
      pn.x = p.x; pn.y = p.y - 1; pn.ns = p.ns + 1; push(pn);
      step[p.y-1][p.x] = p.ns + 1;
    }
    if (p.y < n && field[p.y+1][p.x] != 1 && step[p.y+1][p.x] < 0) { // down
      pn.x = p.x; pn.y = p.y + 1; pn.ns = p.ns + 1; push(pn);
      step[p.y+1][p.x] = p.ns + 1;
    }
    if (0 < p.x && field[p.y][p.x-1] != 1 && step[p.y][p.x-1] < 0) { // left
      pn.x = p.x - 1; pn.y = p.y; pn.ns = p.ns + 1; push(pn);
      step[p.y][p.x-1] = p.ns + 1;
    }
    if (p.x < m && field[p.y][p.x+1] != 1 && step[p.y][p.x+1] < 0) { // right
      pn.x = p.x + 1; pn.y = p.y; pn.ns = p.ns + 1; push(pn);
      step[p.y][p.x+1] = p.ns + 1;
    }
  }

  printf("Fail\n");
  return 0;
}
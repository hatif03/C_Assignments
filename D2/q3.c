#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }

  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
  int i, testCases, n;
  scanf("%d", &testCases);
  for (i = 0; i < testCases; i++) {
    printf("\n##############\nTEST CASE %d\n##############\n", i + 1);
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("%d\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
  }
  return 0;
}

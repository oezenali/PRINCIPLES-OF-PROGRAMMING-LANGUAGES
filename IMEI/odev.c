#include <stdio.h>

#include <stdlib.h>

void Luhn(int * , int);

int main() {
  FILE * file = fopen("nummer.txt", "r");
  int array_length = 0;
  int * array = (int * ) malloc(sizeof(int) * array_length);
  int i = 0;

  fscanf(file, "%d", & i);
  while (!feof(file)) {
    array[array_length] = i;
    fscanf(file, "%d", & i);
    array_length++;
  }

  fclose(file);

  for (int i = 0; i < array_length; i++)
    printf("%d ", array[i]);
  printf("\nText verileri:");
  printf("\n\n");

  Luhn(array, array_length);

  return 0;
}

void Luhn(int * array, int array_length) {
  for (int i = array_length - 2; i >= 0; i -= 2)
    array[i] *= 2;

  for (int i = 0; i < array_length; i++)
    printf("%d ", array[i]);

  printf("\nSirasi cift olanlarin 2 ile carpilmis halleri\n");

  int i = 0;

  do {
    if (array[i] > 9) {
      int temp = array[i];
      int sum = (temp % 10) + 1;
      array[i] = sum;
      sum = 0;
      temp = 0;
    }

    if (i == 15)
      break;

    i++;
  } while (1 == 1);

  for (int i = 0; i < array_length; i++)
    printf("%d ", array[i]);

  printf("\nRakamlar toplami\n");

  i = 0;
  int sum = 0;
  for (int i = 0; i < array_length; i++)
    sum += array[i];

  printf("\Toplam deger: %d\n", sum);

  int mod = (sum % 10) == 0 ? printf("\nGecerli") : printf("\nGecersiz");
}

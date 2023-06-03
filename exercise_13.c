#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */
#define MAX_WORD 10 /*Length of array */

/*
 * Print histogram of length of words
 horizontal/vertical
 */

int main()
{
  int c, i, j, element, length, length_of_histogram, state;
  int word_length[MAX_WORD];

  for (i = 0; i < MAX_WORD; i++)
    word_length[i] = 0;

  length = length_of_histogram = 0;

  state = OUT;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      if (length > 0)
        word_length[length - 1]++;
      length = 0;
    }
    else if (state == OUT)
    {
      state = IN;
      length++;
    }
    else
    {
      length++;
    }
  }

  // Take into consideration EOF
  if (state = IN)
    word_length[length - 1]++;

  // Horizontal bar
  /*
  for(i = 0; i < MAX_WORD; i++){
      printf("Word Length %3d:", i+1 );
      for(j = word_length[i]; j > 0; j--)
        putchar('#');
      putchar('\n');
  }
  */

  // Vertical bar
  for (i = 0; i < MAX_WORD; i++)
  {
    if (word_length[i] > length_of_histogram)
      length_of_histogram = word_length[i];
  }

  int display[MAX_WORD * length_of_histogram];

  for (i = 0; i < MAX_WORD * length_of_histogram; i++)
    display[i] = 0;

  for (i = MAX_WORD; i > 0; i--)
  {
    for (j = word_length[i - 1]; j > 0; j--)
      display[(i - 1) + 10 * (j - 1)] = 1;
  }

  // Print bar
  for (i = 0; i < MAX_WORD * length_of_histogram; i++)
  {
    if (display[i] == 1)
      printf("#");
    else
      printf(" ");
    if (i >= (MAX_WORD - 1) && (i % (((i / MAX_WORD) * MAX_WORD) + (MAX_WORD - 1)) == 0)) // floor division
      putchar('\n');
  }
  // Print label
  for (i = 1; i <= MAX_WORD; i++)
  {
    printf("%d", i);
  }
}

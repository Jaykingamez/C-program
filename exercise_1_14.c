#include <stdio.h>

#define EXIST 1     /* CHAR is in char_array */
#define NOT_EXIST 0 /* CHAR is not in char_array */

#define MAX_CHAR 10 /*Length of array */

/*
 * Print histogram of length of words
 horizontal/vertical
 */

int main()
{
  int c, i, j, state, counter, length_of_histogram;
  int char_appearance[MAX_CHAR];
  char char_array[MAX_CHAR];

  for (i = 0; i < MAX_CHAR; i++)
  {
    char_appearance[i] = 0;
    char_array[i] = 0;
  }

  length_of_histogram = counter = 0;
  state = NOT_EXIST;
  while ((c = getchar()) != EOF)
  {
    // Check if character already exist in char_array
    for (i = 0; i < MAX_CHAR; i++)
    {
      if (c == char_array[i] && state == NOT_EXIST)
      {
        state = EXIST;
        char_appearance[i] += 1;
        if (length_of_histogram < char_appearance[i])
          length_of_histogram = char_appearance[i];
      }
    }
    // Else add them to the arrays
    if (state == NOT_EXIST)
    {
      char_array[counter] = c;
      char_appearance[counter] += 1;
      counter++;
    }
    state = NOT_EXIST;
  }

  // Horizontal bar
  /*
  for(i = 0; i < MAX_CHAR; i++){
      if(char_array[i] != 0){
        printf("Char %c:", char_array[i] );
        for(j = char_appearance[i]; j > 0; j--)
            putchar('#');
        putchar('\n');
      }

  }
  */

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

  int display[counter * length_of_histogram];

  for (i = 0; i < counter * length_of_histogram; i++)
    display[i] = 0;

  for (i = counter; i > 0; i--)
  {
    for (j = char_appearance[i - 1]; j > 0; j--)
      display[(counter * length_of_histogram) - (j * counter) + (i - 1)] = 1;
  }

  // Print bar
  for (i = 0; i < counter * length_of_histogram; i++)
  {
    if (display[i] == 1)
      printf("#");
    else
      printf(" ");
    if (i >= (counter - 1) && (i % (((i / counter) * counter) + (counter - 1)) == 0)) // floor division
      putchar('\n');
  }
  // Print label
  for (i = 0; i < counter; i++)
  {
    printf("%c", char_array[i]);
  }
}

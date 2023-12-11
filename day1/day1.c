#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
const char *DIGITS_AS_WORDS[10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};
int to_digit(char c)
{
    if (c <= '9' && c >= '0')
        return c - '0';
    return -1;
}

int to_number(char *word)
{
    for (int i = 0; i < 10; i++)
    {
        if (strncmp(word, DIGITS_AS_WORDS[i], strlen(DIGITS_AS_WORDS[i])) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char buffer[1000] = {0};

    int line_length = 0;
    int sum = 0;
    while (fgets(buffer, 1000, stdin))
    {
        char *line = buffer;
        int digit;
        for (; *line; line++)
        {
            if ((digit = to_number(line)) != -1 || (digit = to_digit(*line)) != -1)
            {
                sum += digit * 10;
                break;
            }
        }
        for (; *line; line++)
        {
            int d_char = to_digit(*line);
            int d_word = to_number(line);
            if (d_char != -1)
                digit = d_char;
            else if (d_word != -1)
                digit = d_word;
        }
        sum += digit;
    }
    printf("sum: %d\n", sum);
}
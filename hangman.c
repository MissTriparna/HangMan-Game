#include<stdio.h>;
#include<string.h>;

#define MAX_ATTEMPTS 20
#define MAX_STEPS 9

void playgame();
void print_obscured(char *text, int matched);
int match_char(char *secret, char guess, int *matched);
int get_ith_bit(int number, int i, int len);
void set_ith_bit(int *number, int i, int len);
int check_win_status(int matched, int len);
int drawHangman();
int i;
int choice;

int main()
{
printf(&quot; &quot;
&quot; | | /\\ |\\ | ____ |\\ /| /\\ |\\ | \n&quot;
&quot; |----| /--\\ | \\ | ( _ | \\ / | /--\\ | \\ | \n&quot;
&quot; | | / \\ | \\| (___| | | \\/ | / \\ | \\| \n&quot;);

printf(&quot;\n&quot;);
printf(&quot;\n&quot;);
printf(&quot;\n\t1. Instructions\n&quot;
&quot;\n\t2. Start game\n&quot;
&quot;\n\t3. Quit\n&quot;);

11

while (1)
{
printf(&quot;\n\tEnter your choice\n&quot;);
scanf(&quot;%d&quot;, &amp;choice);

switch (choice)
{
case 1:
printf(&quot;\n\tInstructions:\n&quot;);
printf(&quot;1. Hangman is a word-guessing game\n&quot;
&quot;2. Enter letter to guess the word\n&quot;
&quot;3. Guess the word before hangman dies, or you lose\n&quot;
&quot;4. Winner gets a point with each question\n&quot;);
break;
case 2:
playgame();
break;
case 3:
return 0;
break;
default:
printf(&quot;Enter a valid option\n&quot;);
}
}
}

void playgame()
{
char *secret = &quot;quarantine&quot;;
char guess;
unsigned int matched = 0;
int won = 0;
int attempt_number = 0;
while (attempt_number &lt; MAX_ATTEMPTS)

12

{
print_obscured(secret, matched);
printf(&quot;What&#39;s your guess? : &quot;);
scanf(&quot; %c&quot;, &amp;guess);
int correct_guess = match_char(secret, guess, &amp;matched);
if (!correct_guess)
{
int game_over = drawHangman();
if (game_over)
{
printf(&quot;GAME OVER\n&quot;);
return;
}
}
won = check_win_status(matched, strlen(secret));
if (won)
{
printf(&quot;YOU WIN\n&quot;);
return;
}
attempt_number++;
}

if (!won)
{
printf(&quot;GAME OVER\n&quot;);
}
}

void print_obscured(char *text, int matched)
{
int len = strlen(text);
for (i = 0; i &lt; len; i++)
{
if (text[i] == &#39; &#39;)

13

printf(&quot;%c&quot;, &#39;\t&#39;);
else
{
int ith_bit = get_ith_bit(matched, i, len);
if (ith_bit == 1)
{
// show the character if ith bit is 1
printf(&quot;%c &quot;, text[i]);
}
else
{
// hide the character if ith bit is 0
printf(&quot;%c &quot;, &#39;_&#39;);
}
}
}
printf(&quot;\n\n&quot;);
}

int match_char(char *secret, char guess, int *matched)
{
int len = strlen(secret);
for (i = 0; i &lt; len; i++)
{
int ith_bit = get_ith_bit(*matched, i, len);

if (ith_bit == 0)
{
//ith_bit==0 implies the ith character of secret is not revelead yet.
if (secret[i] == guess)
{
//if a match is found at the ith position

//set the ith bit to 1, marking this character as revealed
set_ith_bit(matched, i, len);

14

//match no more character. so break out of the loop
return 1;
}
}
}
return 0;
}

// returns the ith bit of number from left to right
int get_ith_bit(int number, int i, int len)
{
int mask = 1 &lt;&lt; (len - i - 1);
int ith_char_matched = number &amp; mask;
if (ith_char_matched == 0)
return 0;
else
return 1;
}

// sets the ith bit of number to 1
void set_ith_bit(int *number, int i, int len)
{
int mask = 1 &lt;&lt; (len - i - 1);
*number = *number | mask;
}

int check_win_status(int matched, int len)
{
// this is a len-bit number with all bits set to one
int all_ones = (1 &lt;&lt; len) - 1;
if (matched == all_ones)
{
return 1;
}
else

15

{
return 0;
}
}

// returns 1 when the figure is complete.
// 0 otherwise
int drawHangman()
{
static int step = 0;
if (step == 0)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;);
}
else if (step == 1)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;);
}
else if (step == 2)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;);
}
else if (step == 3)
{
printf( &quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;);

16

} 17
else if (step == 4)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;
&quot;\t\t\t | /\n&quot;);
}
else if (step == 5)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;
&quot;\t\t\t | /&quot;
&quot;|\n&quot;);
}
else if (step == 6)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;
&quot;\t\t\t | /&quot;
&quot;|&quot;
&quot;\\\n&quot;);
}
else if (step == 7)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;

&quot;\t\t\t | +\n&quot; 18
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;
&quot;\t\t\t | /&quot;
&quot;|&quot;
&quot;\\\n&quot;
&quot;\t\t\t\t | \n&quot;);
}
else if (step == 8)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;
&quot;\t\t\t | /&quot;
&quot;|&quot;
&quot;\\\n&quot;
&quot;\t\t\t\t | &quot;
&quot;\n\t\t\t\t/\n&quot;);
}
else if (step == 9)
{
printf(&quot; \n&quot;
&quot;\t\t\t |------+\n&quot;
&quot;\t\t\t | +\n&quot;
&quot;\t\t\t | O\n&quot;
&quot;\t\t\t | | \n&quot;
&quot;\t\t\t | /&quot;
&quot;|&quot;
&quot;\\\n&quot;
&quot;\n\t\t\t\t/&quot;
&quot; \\ \n&quot;);
}
step++;

if (step &gt; MAX_STEPS) 19
{
return 1;
}
else
{
return 0;
}
}

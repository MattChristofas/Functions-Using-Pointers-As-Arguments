/*
* Name: Matt Christofas
* Section: 02
* Lab: CIS2107_Lab08_Manual
* Goal: To design and implement functions taking pointers as arguments
to process characters and strings.
*/

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

puts("\n");

//random generator
srand(time(NULL));

//test for upperLower
const char test[] = "This iS A Test";
upperLower(test);

//test for convertStrtoInt
printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

//test for convertStrtoFloat
printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5","5.5", "6.5"));

//test for compareStr
compareStr("Test1", "Test2");

//test for comparePartialStr
comparePartialStr("Test1", "Test2", 4);

//test for randomize
randomize();

//test for tokenize number
char str[] = "(267) 436-6281";
tokenizeTelNum(str);

//test for reverse
char line[] = "Hello world";
reverse(line);

//test for countSubstr
char *line1 = "helloworldworld";
char *substring = "world";
printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1,
countSubstr(line1, substring));

//test for countChar
char w = 'w';
printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1,w));

//test for countAlpha
char str1[] = "Hello it's me.";
countAlpha(str1);

//test for countWords
char countstring[] = "hello world!";
printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

//test for startsWithB
char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
int size = sizeof(series) / sizeof(series[0]);
startsWithB(series, size);

//test for endsWithed
endsWithed(series, size);

}

// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {

    printf("Uppercase: ");
    for(int i = 0; s[i] != '\0'; i++) {
        printf("%c", toupper(s[i]));
    }

    printf("\nLowercase: ");
    for(int i = 0; s[i] != '\0'; i++) {
        printf("%c", tolower(s[i]));
    }

}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4){

    int num1 = atoi(s1);
    int num2 = atoi(s2);
    int num3 = atoi(s3);
    int num4 = atoi(s4);
    
    return num1 + num2 + num3 + num4;
}

//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {

    float num1 = atof(s1);
    float num2 = atof(s2);
    float num3 = atof(s3);
    float num4 = atof(s4);

    return num1 + num2 + num3 + num4;
}

//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {

    puts("\n");
   if (strcmp(s1, s2) == 0) {
        printf("%s is equal to %s\n", s1, s2);
    } else {
        printf("%s < %s", s1, s2);
    }
    
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {

    int result = strncmp(s1, s2, n);
    puts("\n");
    if (result == 0) {
        printf("Comparison of first %d chars: %s = %s", n, s1, s2);
    } else {
        printf("Comparison of first %d chars: %s != %s", n, s1, s2);
    }
}

//6.(Random Sentences)
void randomize(void) {

    const char *article[] = {"the", "a", "one","some","any"};
    const char *noun[] = {"boy", "girl", "dog", "town", "car"};
    const char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char *preposition[] = {"to", "from", "over", "under", "on"};

    printf("\n\nRandom Story: \n");
    for (int i = 0; i < 20; i++) {
        char story[100] = "";
        strcat(story, article[rand() % 5]);
        strcat(story, " ");
        strcat(story, noun[rand() % 5]);
        strcat(story, " ");
        strcat(story, verb[rand() % 5]);
        strcat(story, " ");
        strcat(story, preposition[rand() % 5]);
        strcat(story, " ");
        strcat(story, article[rand() % 5]);
        strcat(story, " ");
        strcat(story, noun[rand() % 5]);
        story[0] = toupper(story[0]);
        strcat(story, ".");
        printf("%s\n", story);
    }
}

//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {

    char *token;
    char areacode[4];
    char phNum[8];

    token = strtok(num, "()");
    strncpy(areacode, token, 3);
    areacode[3] = '\0';

    token = strtok(NULL, "-");
    strncpy(phNum, token, 3);

    token = strtok(NULL, "-");
    strncat(phNum, token, 4);
    phNum[7] = '\0';

    printf("\n%s %s\n", areacode, phNum);
    
}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    puts("\n");
    char *token;
    char *tokens[100];
    int i = 0;

    token = strtok(text, " ");
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%s ", tokens[j]);
    }
}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {

    int count = 0;
    int substr_len = strlen(sub);

    while (*line) {
        if (strncmp(line, sub, substr_len) == 0) {
            count++;
            line += substr_len;
        } else {
            line++;
        }
    }

    return count;
}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {

    int count = 0;
    while (*line != '\0') {
        if (*line == c) {
            count++;
        }
        line++;
    }
    return count;
}

//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    puts("\n");
    int count[26] = {0};
    int i;
    
    for(i = 0; string[i] != '\0'; i++) {
        char c = tolower(string[i]);
        if(isalpha(c)) {
            count[c - 'a']++;
        }
    }
    
    printf("Letter | Count\n");
    for(i = 0; i < 26; i++) {
        printf("%c,%c | %d\n", 'A' + i, 'a' + i, count[i]);
    }
}

//12.(Counting the Number of Words in a String)
int countWords(char *string) {

    int count = 0;
    char *token = strtok(string, " "); 
    while (token != NULL) {
        count++; 
        token = strtok(NULL, " ");
    }
    return count;
}

//13.(Strings Starting with "b")
void startsWithB(char *string[], int size) {

    printf("\nStrings that start with b: ");
    for (int i = 0; i < size; i++) {
        if (string[i][0] == 'b' || string[i][0] == 'B') {
            printf("%s ", string[i]);
        }
    }
    puts("\n");
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[], int size) {

    printf("\nStrings that end with ed: ");
    for (int i = 0; i < size; i++) {
        int len = strlen(string[i]);
        if (len >= 2 && string[i][len - 2] == 'e' && string[i][len - 1] == 'd') {
            printf("%s ", string[i]);
        }
    }
    puts("\n");
}

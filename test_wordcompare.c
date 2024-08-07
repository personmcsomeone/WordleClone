#include "wordcompare.c"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <time.h>
#include "miniunit.h"

int _no_char_match(){
    mu_start();
    //----------------
    static char* mainWord =  "world";
    static char* guessWord = "chest";
    int results[5] = {0,0,0,0,0};
    compareWords(mainWord, guessWord, results);
    mu_check((results[0] == 0));
    mu_check((results[1] == 0));
    mu_check((results[2] == 0));
    mu_check((results[3] == 0));
    mu_check((results[4] == 0));    
    //----------------
    mu_end();
}

int _one_char_match(){
    mu_start();
    //----------------
    static char* mainWord =  "world";
    static char* guessWord = "blast";
        int results[5] = {0,0,0,0,0};
    compareWords(mainWord, guessWord, results);
    mu_check((results[0] == 0));
    mu_check((results[1] == 1));
    mu_check((results[2] == 0));
    mu_check((results[3] == 0));
    mu_check((results[4] == 0));    
    //----------------
    mu_end();
}

int _two_char_match(){
    mu_start();
    //----------------
    static char* mainWord =  "world";
    static char* guessWord = "arcdq";
    int results[5] = {0,0,0,0,0};
    compareWords(mainWord, guessWord, results);
    mu_check((results[0] == 0));
    mu_check((results[1] == 1));
    mu_check((results[2] == 0));
    mu_check((results[3] == 1));
    mu_check((results[4] == 0));    
    //----------------
    mu_end();
}

int _five_char_match(){
    mu_start();
    //----------------
    static char* mainWord =  "abcde";
    static char* guessWord = "ecdba";
    int results[5] = {0,0,0,0,0};
    compareWords(mainWord, guessWord, results);
    mu_check((results[0] == 1));
    mu_check((results[1] == 1));
    mu_check((results[2] == 1));
    mu_check((results[3] == 1));
    mu_check((results[4] == 1));    
    //----------------
    mu_end();
}

int _one_char_order(){
    mu_start();
    //----------------
    static char* mainWord =  "abcde";
    static char* guessWord = "edcba";
    int results[5] = {0,0,0,0,0};
    compareWords(mainWord, guessWord, results);
    mu_check((results[0] == 1));
    mu_check((results[1] == 1));
    mu_check((results[2] == 2));
    mu_check((results[3] == 1));
    mu_check((results[4] == 1));    
    //----------------
    mu_end();
}

int _correct_word(){
    mu_start();
    //----------------
    static char* mainWord =  "abcde";
    static char* guessWord = "abcde";
    int results[5] = {0,0,0,0,0};
    compareWords(mainWord, guessWord, results);
    mu_check((results[0] == 2));
    mu_check((results[1] == 2));
    mu_check((results[2] == 2));
    mu_check((results[3] == 2));
    mu_check((results[4] == 2));    
    //----------------
    mu_end();
}


int main(int arg, char* argc[]){
    mu_run(_no_char_match);
    mu_run(_one_char_match);
    mu_run(_two_char_match);
    mu_run(_five_char_match);
    mu_run(_one_char_order);
    mu_run(_correct_word);
}
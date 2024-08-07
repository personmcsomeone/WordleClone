#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <time.h>
#define YELLOW 1
#define GREEN 2


void getInput(char** input){
}

void compareWords(char* mainWord, char* guessWord, int* results) {

    for(int g_ctr = 0; g_ctr < 5; g_ctr++){ //get guess letter
        if(g_ctr > 0){
            int repeat = checkRepeat(guessWord[g_ctr], guessWord, g_ctr);
        }
        
        for(int m_ctr = 0; m_ctr < 5; m_ctr++){ //index through secret word

            if(guessWord[g_ctr] == mainWord[m_ctr]){ //check if characters are equal 
            //TODO: deal with repeat letters in both words

                if(g_ctr == m_ctr && repeat !> 0){
                    results[g_ctr] = GREEN; //right spot right letter
                    break;
                }
                if(g_ctr == m_ctr && repeat > 0){
                    repeat--; //repeat letter hits first occourance, 
                    break;
                }                
                else{
                    results[g_ctr] = YELLOW; //wrong spot right letter
                }
            }
            else{
                continue; //just being clear
            }
        }
    }
}

int checkRepeat(char letter, char* guessWord, int g_ctr){
    int repeatCount = 0;
    for (int i = 0; i < g_ctr; i++)
    {
        if(letter == guessWord[i]){
            repeatCount++;
        } 
        else{
            continue;
        } //explicit continue
    }
    return repeatCount;
}
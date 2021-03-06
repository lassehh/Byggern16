/*
 * highscore.h
 *
 * Created: 16.11.2016 14:12:31
 *  Author: elsala
 */ 


#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <stdio.h>

#define USERNAME_LENGTH		3
#define MAX_NUM_USERS		5
#define NUM_USERS_ADDRESS	0
#define USER_START_ADDRESS	1

typedef struct user_t {
	char		name[USERNAME_LENGTH];
	uint8_t		score;
} user_t;

void HIGHSCORE_load_from_EEPROM();
void HIGHSCORE_store_to_EEPROM();

user_t* HIGHSCORE_get_users();
int HIGHSCORE_get_num_users();
void HIGHSCORE_add_user(user_t user);
void HIGHSCORE_print_to_oled();
void HIGHSCORE_clear();
void HIGHSCORE_print_users();

int compare(const void* a, const void* b);

#endif /* HIGHSCORE_H_ */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<unistd.h> for linux
#include<windows.h>
#include<string.h>
#include<ctype.h>

void header(){
    printf("\nWelcome to PassX - A simple password complexity checker tool.\n\n");
    Sleep(500);
    printf("\n\t\t\t\t\tBest password practice : \n\t\t\t\t\t1. at least 10 characters long\n\t\t\t\t\t2. include numbers\n\t\t\t\t\t3. include lowercase letters\n\t\t\t\t\t4. include uppercase letters\n\t\t\t\t\t5. include special symbols\n");
}

void footer(){
    Sleep(500);
	printf("\n\t\t\t\t\t----------------------------------- \n");
	printf("\t\t\t\t\t        Thanks for visiting \n");
	printf("\t\t\t\t\t----------------------------------- \n\n");		
}

void check(){
    char char_set_lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char char_set_uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char char_set_special_chars[32] = {'!','@','#','$','%','^','&','*','(',')','_','}','{','>','<','\'','\"','~','[',']','+','-','/','?',',','.',':',';','`','\\','|'};
    char char_set_numbers[] = "0123456789";
    int choice = 0;
    printf("\n\nEnter your choice from below options to continue : \n1. Check password complexity\n2. Exit. \n");
    scanf("%d", &choice);
    //printf("Choice : %d",choice);
    int line_num = 1;
    int find_result = 0;
    if (choice == 1){
        while (choice == 1){
            char password[30];
            printf("\nEnter password to check its complexity,bruteforce time and status : ");
            scanf("%s", password); 
            int passlength = strlen(password);
            //printf("Pass length is : %d",passlength);
            int len_char_set_lo = 0, len_char_set_up = 0, len_char_set_sp = 0, len_char_set_num = 0;
            for(int i=0; i<passlength; i++){
                for(int j=0; j<25; j++){
                    if(password[i] == char_set_lowercase[j]){
                        len_char_set_lo = 26;
                        break;
                    }
                    else if(password[i] == char_set_uppercase[j]){
                        len_char_set_up = 26;
                        break;
                    }
                    else if(password[i] == char_set_special_chars[j]){
                        len_char_set_sp = 32;
                        break;
                    }
                    else if(password[i] == char_set_numbers[j]){
                        len_char_set_num = 10;
                        break;
                    }
                }
            }            
            int total_length_of_char_sets = len_char_set_lo + len_char_set_up + len_char_set_sp + len_char_set_num;
            float pass_complexity = (log(total_length_of_char_sets)/log(2))*passlength;
			// We assume that on average, the password will be cracked when half of the possible passwords are checked.
            printf("\n==========================================================================================\n");
            printf("\n\nPassword Complexity : %0.2f", pass_complexity);
            float time_to_break_pass = round(((3 * pow(10, -11)) * (pow(total_length_of_char_sets, passlength)))/(2*60*60*24*365));
            int counter = 0;
            char ch[500];
            FILE *fptr;
            fptr = fopen("password.txt","r"); 
            while(fgets(ch, 500, fptr) != NULL) {
	        	if((strstr(ch, password))){
                    printf("\nYour password can be cracked under a minute as it is in common password list.");
                    counter ++;
                    break;
                }
            }
            fclose(fptr);
            if (time_to_break_pass <= 0.00f  && counter < 1){
                printf("\nYour password can be cracked under a year.");
            }
            else if(time_to_break_pass > 0.00f && counter < 1){
                printf("\nTime to bruteforce a password : %0.2f years", time_to_break_pass); 
            }
            //checking if password is only alphanumeric, only digits or only alphabets.
            int flag_for_alpha = 1;
            for(int i=0; i< strlen(password) && flag_for_alpha == 1; i++ ){
                if( isalpha(password[i])) flag_for_alpha = 1;
                else flag_for_alpha = 0;
            }
            if (flag_for_alpha)
                printf("\n\x1b[31m[+] WARNING!\x1b[0m Your password only contains alphabets. Make sure to include special characters to increase password strength.");
            
            int flag_for_dig = 1;    
            for(int i=0; i< strlen(password) && flag_for_dig == 1; i++ ){
                if( isdigit(password[i])) flag_for_dig = 1;
                else flag_for_dig = 0;
                }
            if (flag_for_dig)
                printf("\n\x1b[31m[+] WARNING!\x1b[0m Your password only contains digits. Make sure to include special characters to increase password strength.");
            
            int flag_for_alnum = 1;
            if (flag_for_alpha == 0 && flag_for_dig  == 0){
                for(int i=0; i< strlen(password) && flag_for_alnum == 1; i++ ){
                    if( isalnum(password[i])) flag_for_alnum = 1;
                    else flag_for_alnum = 0;
                    }
                if (flag_for_alnum)
                    printf("\n\x1b[31m[+] WARNING!\x1b[0m Your password only contains alphabets and numbers. Make sure to include special characters to increase password strength.");            
            }
            if (pass_complexity <= 50){
                printf("\nPassword Strength : \x1b[31mWeak\x1b[0m");
            }
            else if (pass_complexity > 50 && pass_complexity <= 90){
                printf("\nPassword Strength : \x1b[36mAverage password\x1b[0m");
            }
            else if (pass_complexity > 90 && pass_complexity <= 120){
                printf("\nPassword Strength : \x1b[34mGood Password\x1b[0m");
            }
            else if (pass_complexity > 120){
                printf("\nPassword Strength : \x1b[32mBest Password\x1b[0m");
            }
            printf("\n\n\n==========================================================================================");
            int sec_choice = 0;
            printf("\n\nPress 1 to check again or 2 to exit\n");
            scanf("%d", &sec_choice);
            if (sec_choice == 1){}
            else if (sec_choice == 2){
                footer();
                exit(0);
            }
            else if (sec_choice != 1 || sec_choice != 2 || isalpha(sec_choice)){
                printf("\nWrong choice!!. Choose only from 1 or 2.\n[+]Program exiting....\n\n");
                exit(0);
            }
        }
    }
    else if (choice == 2){
        footer();
        exit(0);
    } 

    else{
        printf("\nWrong input!!. Choose only from 1 or 2.\n[+]Program exiting....\n\n");
		exit(0);	
    }
    
}

int main(){
    header();
    check();
    return 0;
}

// Reference : https://thycotic.force.com/support/s/article/Calculating-Password-Complexity
// Reference : https://www.khanacademy.org/college-careers-more/personal-finance/keeping-your-information-safe/password-strength-and-other-strategies/v/math-behind-password-security
// Reference : https://en.wikipedia.org/wiki/Password_cracking
// Reference : https://projects.lambry.com/elpassword/
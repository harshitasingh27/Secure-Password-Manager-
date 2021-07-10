#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char p[] = "\nPassword : ";
    char u[] = " , Username : ";
    char dummy[] = " ";
    char select; //switch - case var
    char ch; // reading a file char
    char EnterPass[11];
    char EnterUserId[25];
    char passkey[8]; //Rssy@491
    char key[] = "Rssy@491";
    
    start:   // User Decision input
    printf("\n\n\n Please Select One Option : ");
    printf("\n To Store passwords press w");
    printf("\n To See stored passwords press r ");
    printf("\n To Exit Press e \n");

    printf("\n Enter the selected operation \t");
    select = getchar();
    
    ////////////////////////////////////
    

    switch(select){
        
        case 'w':                    //writing the file
                
    fp = fopen("myfile.txt","a+");
    gets(dummy);
    fputs(p,fp);                    //Password
    printf("\n Enter Password : ");
    gets(EnterPass);
    fputs(EnterPass,fp);

    fputs(u,fp);                    //UserName
    printf("\n Enter Username : ");
    gets(EnterUserId);
    fputs(EnterUserId,fp);
        fflush(fp);
    printf("\n \n \t PASSWORD STORED SUCCESSFULLY!!\n\n");
	
   goto start;
    //////////////////////////////////////////////////////////////////
        case 'r':  
		    
		printf("\n\n Enter Password Key To Open Vault : ");
		fflush(stdin);
		scanf("%s",&passkey);
		    
		
		if(strcmp(passkey, "Rssy@491") == 0){                  // READING THE FILE
 
         		fp = fopen("myfile.txt","r");
    			if(fp == NULL){
        			printf("File not found");
        			exit(1);
    			}
    		ch = fgetc(fp);
    		while(!feof(fp)){
        		printf("%c",ch);
        		ch = fgetc(fp);
    		}
        
		 fclose(fp);
		fflush(stdin);
		
    		goto start;
		}    // If password Entered Correct
	
		else{
			printf("\n\n\t Incorrect Password!! \n");
				exit(0);
		}
		
    	case 'e':
    		exit(0);

}
}

/*  **************************************************************NAME :- Aritra Mukherjee
    **************************************************************USN  :- 21BTRCM003 
    **************************************************************BRANCH:-CTMA
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


struct student
{
    int DOB,CN,tfpy,tfpicy,fdicy,SESSION;
    char name[30],ADDRESS [100],COURSE[10],BRANCH[10],usn[20];
};


void addstud(){
  
    char another;
     FILE *fp;
     int n,i;
     char a[10];
     struct student b;
   do{
       
 
       fp=fopen("info.dat","a"); 
         
        printf("Enter First Name     : ");
        scanf("%s",&b.name);
        

        printf("Enter your usn number?\n");
        scanf("%s",&b.usn);
      

        printf("Enter you Date of brith?\n");
        scanf("%d",&b.DOB);
      

        printf("Enter your contact number \n");
        scanf("%d",&b.CN);
       

        printf("Enter your ADDRESS?\n");
        scanf("%s",&b.ADDRESS);
       

        printf("Enter your SESSION?\n");
        scanf("%d",&b.SESSION);
       

        printf("Enter your COURSE?\n");
        scanf("%s",&b.COURSE);
       

        printf("Enter your BRANCH?\n");
        scanf("%s",&b.BRANCH);
        

        printf("Enter your TOTAL FEE COURSE YEAR?\n");
        scanf("%d",&b.tfpy);
       

        printf("Enter your TOTAL FEE PAID IN CURRENT YEAR?\n");
        scanf("%d",&b.tfpicy);
       

        printf("Enter your FEE DUE IN CURRENT YEAR?\n");
        scanf("%d",&b.fdicy);
        

       
      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\t\tRecord stored successfuly\n");
    }
    fwrite(&b, sizeof(struct student), 1, fp); 
    fclose(fp);
    
    printf("\t\t\tYou want to add another record?(y/n) : ");
    
    
    scanf("%s",&another);
    
    
   }while(another=='y'||another=='Y');
}

 void delete(){
      struct student b;
      FILE *fp, *fp1;
     
       
    char usn[10];
    int found=0;
    int value;
       printf("\t\t\t\t=======DELETE studentS RECORD=======\n\n\n");
    fp=fopen("info.dat","r");
    fp1=fopen("temp.dat","w");
    printf("\t\t\t\tEnter the usn : ");
    scanf("%s",&usn);
    if(fp==NULL){
         fprintf(fp,"can't open file\n");
         exit(0);
      }
    
    while(fread(&b,sizeof(struct student),1,fp)){

          
        if(strcmp(b.usn,usn) == 0) 
        {
          
            found=1;
        
        }else{
           fwrite(&b,sizeof(struct student),1,fp1);
        }
  
    }
     fclose(fp);
     fclose(fp1);
 
    if(!found){
          printf("\n\t\t\t\tRecord not found\n");
        }
      if(found){ 
    remove("info.dat");
        rename("temp.dat","info.dat");
        
        printf("\n\t\t\t\tRecord deleted succesfully\n");
        }
 
  getch();
  }




void searchstudent(){
       struct student b;
      FILE *fp;
      char usn[20];
      int found=0;
    
    fp=fopen("info.dat","r");
    printf("\t\t\t\t=======SEARCH studentS RECORD=======\n\n\n");
    printf("\t\t\tEnter the usn : ");
   
    scanf("%s",&usn);
     
    
    
    while(fread(&b,sizeof(struct student),1,fp)>0){
         
        if(strcmp(b.usn,usn) == 0){
           
        found=1;
        printf("\n\t\t\t\t student Name  : %s \n",b.name);
        printf("\n\t\t\t\t USN      : %s\n",b.usn);
        printf("\n\t\t\t\t SESSION         : %d\n",b.SESSION);
        printf("\n\t\t\t\t ADDRESS  : %s\n",b.ADDRESS);
        printf("\n\t\t\t\t COURSE   : %s\n",b.COURSE);
        printf("TOTAL FEE COURSE YEAR? %d\n",b.tfpy);
        printf("TOTAL FEE PAID IN CURRENT YEAR? : %d", b.tfpicy);
        printf("FEE DUE IN CURRENT YEAR?  : %d", b.tfpy - b.tfpicy);
        printf("\n\t\t\t\t ____\n");
  
         }
       
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    }
  
    fclose(fp);
    getch();

}

 void studentrecord(){
   
     FILE *fp;
 
    struct student b;
    fp=fopen("info.dat","r");
    int s;
     printf("\t\t\t\t=======studentS RECORD=======\n\n\n");
      
    if(fp==NULL){
        
        fprintf(stderr,"can't open file\n");
    }else{
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___\n\n");
    }
        
    
       while(fread(&b,sizeof(struct student),1,fp)){
        printf("\n\t\t\t\t student Name  : %s \n",b.name);
        printf("\n\t\t\t\t USN      : %s\n",b.usn);
        printf("\n\t\t\t\t SESSION         : %d\n",b.SESSION);
        printf("\n\t\t\t\t ADDRESS  : %s\n",b.ADDRESS);
        printf("\n\t\t\t\t COURSE   : %s\n",b.COURSE);
        printf("TOTAL FEE COURSE YEAR? %d\n",b.tfpy);
        printf("TOTAL FEE PAID IN CURRENT YEAR? : %d", b.tfpicy);
        printf("FEE DUE IN CURRENT YEAR?  : %d", b.tfpy - b.tfpicy);
        printf("\n\t\t\t\t ____\n");
      
       }

    fclose(fp);
    getch();
      
}

  void sorting(){
    
    
    char temp[20]; 
    struct student *b;
    struct student *s;
    int found = 0,i,j;
    FILE *fp;
    fp = fopen("info.dat","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(struct student);
    b = (struct student*)calloc(n,sizeof(struct student));
    rewind(fp);
    for (i = 0; i < n; ++i)
    {
       fread(&b[i],sizeof(struct student),1,fp);

}

for (i = 0; i < n; ++i) {
      for (j = i + 1; j < n; ++j) {

         if (strcmp(b[i].usn, b[j].usn) > 0)
          {
            strcpy(temp, b[i].usn);
            strcpy(b[i].usn, b[j].usn);
            strcpy(b[j].usn, temp);

         }
   }
}
for (int i = 0; i < j; ++i)
   {
      printf("\n\t\t\t\t student Name  : %s \n",b[i].name);
        printf("\n\t\t\t\t USN      : %s\n",b[i].usn);
       printf("\n\t\t\t\t SESSION         : %d\n",b[i].SESSION);
       printf("\n\t\t\t\t ADDRESS  : %s\n",b[i].ADDRESS);
       printf("\n\t\t\t\t COURSE   : %s\n",b[i].COURSE);
       printf("TOTAL FEE COURSE YEAR? %d\n",b[i].tfpy);
       printf("TOTAL FEE PAID IN CURRENT YEAR? : %d", b[i].tfpicy);
       printf("FEE DUE IN CURRENT YEAR?  : %d", b[i].tfpy - b[i].tfpicy);
        printf("\n\t\t\t\t ____\n");
         }
 
   fclose(fp);
}
         




void main()
{   
    int choice;
    while(choice!=6){
        
    printf("\t\t\t=====Jain University system =====");
    printf("\n\n\n\t\t\t\t     1. ADDITION OF student RECORD WHEN HE/SHE ADMITTED IN JAINUNIVERSITY\n");
    printf("\t\t\t\t     2. DELETION OF RECORD\n");
    printf("\t\t\t\t     3.  DISPLAY OF ALL RECORDS\n");
    printf("\t\t\t\t     4. DISPLAY OF ANY PARTICULAR RECORDS(SEARCHING/FILTER)\n");
    printf("\t\t\t\t     5. SORTING OF RECORDS (BASED ON USN)\n");
    printf("\t\t\t\t     6. Exit\n");
    printf("\t\t\t\t    ___\n");
    printf("\t\t\t\t     ");
    scanf("%d",&choice);
    
   switch(choice){
       case 1:
        
          addstud();
        
         break;
     case 2: 
      
        delete();
         
          printf("\t\t\t\t  press any key to exit..... \n");
          getch();
          
         break;
        
     case 3:
         studentrecord();
         printf("\n\t\t\t\t  Press any key to exit.......\n");
         
          getch();

        
         break;
  
     case 4:
        searchstudent();
        printf("\n\t\t\t\tPress any key to exit.......\n");
        getch();

        break;
     case 5:
            sorting();
       printf("\n\t\t\t\tPress any key to exit.......\n");
        getch();

        break;
        
     default :

         printf("\t\t\t\tPress any key to continue.......");
         getch();

         break;
        }
  
        }
}
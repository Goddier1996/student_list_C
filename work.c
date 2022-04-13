#include<stdlib.h>
#include<string.h>
#include<stdio.h>


struct Student//משתנים לרשימה
{
    int id;//תז
    char name[20];//שם
    char Lastname[20];//שם משפחה
    char Address[20];//כתובת
    int numberPhone;//מספר טלפון
	int old;//גיל
    int average;//ממוצע
    char Date[20];//תאריך

    struct Student *next;
  
}* head;



//הוספה לרשימה
void insert(int id, char* name, char* Lastname, char* Address, int numberPhone, int old, int average, char* Date)
{	
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));

	student->id = id;
	strcpy(student->name, name);
	strcpy(student->Lastname, Lastname);
	strcpy(student->Address, Address);
    student->numberPhone = numberPhone;
    student->old = old;
	student->average = average;
	strcpy(student->Date, Date);


	student->next = NULL;
	
	if(head==NULL)
	{
		head = student;
	}
	else
	{
		student->next = head;
		head = student;
	}
	printf("new student was Add to list\n");
}




//חיפוש תלמיד מסויים
void search(int id)
{
    struct Student * temp1;
    temp1=head;

	while(temp1!=NULL)
	{
		if(temp1->id == id)
		{
			printf("ID: %d\n", temp1->id);
			printf("Name: %s\n", temp1->name);
			printf("Last Name: %s\n", temp1->Lastname);
			printf("Address: %s\n", temp1->Address);
			printf("Number phone: %d\n", temp1->numberPhone);
			printf("Old: %d\n", temp1->old);
			printf("average: %d\n", temp1->average);
			printf("Date: %s\n", temp1->Date);

			printf("\n");
            
			return;
		}
		temp1 = temp1->next;
	}
	printf("don't have this id in List\n");
}




//עדכון ממוצע לפי תז
void update(int id)
{
  int average;//ממוצע

  struct Student * temp1;
  temp1=head;

	while(temp1!= NULL){
		
		if(temp1->id == id)
		{
			printf("Enter new Average: ");
			scanf("%d", &temp1->average);
			printf("Average was update\n");
			return;
		}
		else
		{
			temp1 = temp1->next;
        }		
	}	
}




//מחיקת תלמיד לפי תז
void Delete(int id)
{
    struct Student * temp1;    
    temp1=head;

	struct Student * temp2; 
	temp2=head;

	while(temp1!=NULL){
		
		if(temp1->id==id)
		{			
			printf("Record with roll number %d Found !!!\n", id);
			
			if(temp1==temp2){
				head = head->next;

				free(temp1);//שחרור זיכרון
			}
			else
			{
				temp2->next = temp1->next;

				free(temp1); //שחרור זיכרון
			}
			
			printf("Record Successfully Deleted !!!\n");
			return;			
		}

		temp2 = temp1;
		temp1 = temp1->next;		
	}

	printf("Student with roll number %d is not found !!!\n", id);	
}




//הצגת כל התלמידים שיש ברשימה
void display()
{
    struct Student * temp1;
	temp1=head;

	while(temp1!=NULL){
		
		printf("ID: %d\n", temp1->id);
		printf("Name: %s\n", temp1->name);
		printf("Last Name: %s\n", temp1->Lastname);
		printf("Address: %s\n", temp1->Address);
		printf("phone number: %d\n", temp1->numberPhone);
		printf("old: %d\n", temp1->old);
		printf("average: %d\n", temp1->average);
		printf("Date: %s\n\n", temp1->Date);

		temp1 = temp1->next;	
	}
}



//מחיקת כל תלמידים מהרשימה
void deleteList()
{
   struct Student* temp1;
   temp1=head;
   struct Student* next;
 
   while (temp1 != NULL) 
   {
       next = temp1->next;
       free(temp1);//שחרור זיכרון
       temp1 = next;
   }
   printf("\n");
   head = NULL;
}



//ממוצע של כל התלמידים שקיימים ברשימה
void Average()
{
    struct Student * temp1;
    temp1=head;

    double sum = 0;
    int count = 0;
	double res = 0;

    while (temp1 != NULL)
	{
        sum += temp1->average;
        count++;

		temp1 = temp1->next;	
    }
	res= sum / count;

    printf("average all Student's - ");
	printf("%f",res);
}




//ממוצע הגבוהה ביותר שיש ברשימה
void MaxAverage()
{
    struct Student * temp1;
	temp1=head;
    struct Student * temp2;
	temp2=head;

    double max= 0;
	// int ID=0;
    // int id;


    while (temp1!=NULL) //מציאת ממוצע הגבוהה ביותר
	{ 
        if (temp1 -> average > max) 
		{ 
            max = temp1 -> average; 
			// ID=temp1->id;
        } 
        temp1 = temp1 -> next; 
    }

         
         printf("The Max average was ->\n %f",max);


    while(temp2!=NULL)//הדפסת שמות של תלמידים שיש להם ממוצע גבוהה
	{
		if(temp2->average == max)
		{
           printf("\nThe max Average was To %s",temp2->name);
		   printf("\n");
		}
		temp2 = temp2 -> next; 
	}


	// while(temp2!=NULL)
	// {
	// 	if(temp2->id == ID)
	// 	{
	//      printf("The max Average was To %s",temp2->name);
    //      return;
	// 	}
	// 	 temp2 = temp2 -> next; 
	// }  
}




//ממוצע מתחת ל-60
void Failed()
{
    struct Student * temp1;
	temp1=head;

	int Min=60;
	int count=0;

    while (temp1!=NULL)
	 { 
        if (temp1 -> average < Min) 
		{ 
          printf("was Failed %s",temp1->name);  
		  printf("\n"); 
		  count++;      
        } 
        temp1 = temp1 -> next; 
    }

	if(temp1==NULL && count==0)
	{
       printf("All Average was more 60!\n");
	} 
}



void writefile()//כתיבה לקובץ
{
    FILE * newFile;

    newFile = fopen("Student's.txt", "w");

    struct Student * temp1;
	temp1=head;

        while(temp1!= NULL)
        {
            fprintf(newFile,"ID: %d\n", temp1->id);
			fprintf(newFile,"Name: %s\n", temp1->name);
			fprintf(newFile,"Last Name: %s\n", temp1->Lastname);
			fprintf(newFile,"Address: %s\n", temp1->Address);
			fprintf(newFile,"phone number: %d\n", temp1->numberPhone);
			fprintf(newFile,"old: %d\n", temp1->old);
			fprintf(newFile,"average: %d\n", temp1->average);
			fprintf(newFile,"Date: %s\n\n", temp1->Date);

            fprintf(newFile,"\n");
            
            temp1= temp1->next;
        }
    
    free(temp1);//שחרור זיכרון
    fclose(newFile);
}





                                                        //קריאה מהקובץ לרשימה זה לא עבד טוב,לכן משאיר את הפונקציה בהערה
// void ReadToList(){//קריאה מהקובץ לרשימה
  
//     struct Student *temp;
//     temp = malloc(sizeof(struct Student));

//     temp->next = NULL;
//     head = temp;

//     FILE *ifp;
//     ifp = fopen("Student's.txt", "r");

//     int c = 0;

//     char buffer[30];

//     if(ifp==NULL){
// 		printf("dont have file");
// 	}

//     //memset(buffer, 0, 1024);
	
//     //while(fgets(buffer, sizeof(buffer), ifp)){


//     while(c>1){
//         fgets(buffer, 30, ifp);
//         sscanf(buffer,"%s,%d,%s,%s,%d,%d,%d,%s\n",temp->name, temp->id,temp->Lastname,temp->Address,temp->numberPhone,temp->old,temp->average,temp->Date);
//         temp->next = malloc(sizeof(struct Student));
//         temp = temp->next;
//         temp->next = NULL;
// 		   c++;
//     }
// 	fclose(ifp);
// }





int main()
{
    head = NULL;

	// struct Student * temp1;
	// temp1=head;

    int choice;
	int phoneNumber;
    int old;

    char name[20];
	char Lastname[20];
	char Address[20];
	char Date[50];

    int id;
    int average;
	
     do
	 {
		printf("\n1 add student from File\n2 add Student to list \n3 update Average\n4 search Student\n5 display all student details\n6 delete Student\n7 delete All Student\n8 statistics All Student\n9 Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            // case 1:                                               //קריאה מהקובץ לרשימה
			//     printf("data with file to linked list:\n");
            //     ReadToList(); 
			// break;

            case 2://הוספה לרשימה
			
                printf("Enter your ID: ");
                scanf("%d", &id);

                printf("Enter name: ");
                scanf("%s", name);

				printf("Enter Last name: ");
                scanf("%s", Lastname);

				printf("Enter your Address: ");
                scanf("%s", Address);

                printf("Enter phone number: ");
                scanf("%d", &phoneNumber);

				printf("Enter your old: ");
                scanf("%d", &old);

                printf("Enter average: ");
                scanf("%d", &average);
			
				printf("Enter Date: ");
                scanf("%s", Date);

                insert(id, name,Lastname,Address,phoneNumber,old,average,Date);
            break;

            case 3://עדכון ממוצע
                printf("Enter id: ");
                scanf("%d", &id);
                update(id);
            break;

            case 4://חיפוש תלמיד מסויים
                printf("search Student: enter ID: ");
                scanf("%d", &id);
                search(id);
            break;

            case 5://הדפסת כל התלמידים
			   display();
            break;

            case 6://מחיקת תלמיד מסויים
                printf("enter ID:: ");
                scanf("%d", &id);
                Delete(id);
            break;

			case 7://מחיקת כל התלמידים
                printf("delete all Student's ");
                deleteList();
            break;

			case 8://סטטיסטיקה
                printf("statistics:\n");
			  
			    printf("Average all student's: ");
                Average();//ממוצע ציונים של כל התלמידים

				printf("\n");
                MaxAverage();//הממוצע הגבוהה ביותר לתלמיד

				printf("\n");
                Failed();//תלמידים שהממוצע שלהם מתחת ל60				
            break;

			case 9://יציאה והכנסת נתונים לקובץ
			    printf("the all data Student's write in File\n");
				writefile();
				printf("Goodbye!");
            break;


			default:
              printf("Erorr!\n\n");
			break;
        }

	 }while(choice !=9);
	         
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include<time.h>
#include<iostream>
using namespace std;


void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);


void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();


void deletefood(int serial);
int countitem();






void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);




struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};



typedef struct Node node ;

node *head, *list;

int main(){char date;
char string[50];
char command[50];
system("COLOR B0");

	system("mode con: cols=80 lines=30");


	loadingbar(); cls();
	pwellcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(1,"Burger   ",23 ,30);
	insertend(2,"Pizza    ",13 ,50);
	insertend(3,"Hot Cake ",82 ,20);
	insertend(4,"Coffee   ",46 ,30);
	insertend(5,"Ice-Cream",46 ,40);
	insertend(6,"Sandwich ",34 ,60);
	insertend(7,"MOMOS    ",34 ,20);
	insertend(8,"NOODLES  ",12 ,35);
	insertend(9,"Drinks   ",73 ,20);



	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			printf("=> 0. Main Menu ");
			foodlist();


		}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Enter secrity Password or ( 1 to Back in Main Menu ) : ");
			std::string phrase = "enter security password";
        std::string command = "espeak  \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


			fflush(stdin);  scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==12345){



				node *temp;

				temp = list;

				adminchoise:

				cls();  br(5); pre(4); echo("You are on Admin Pannel\n\n");
				std::string phrase = "you are on admin pannel";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
				pre(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Pay \n\n");Sleep(250);pre(4);
				printf(" 3. Add Food \n\n");Sleep(250);pre(4);
				printf(" 4. Delete Food \n\n");Sleep(250);pre(4);
				printf(" 5. Instant Food List \n\n");Sleep(250);pre(4);
				printf(" 6. Item Counter \n\n");Sleep(250);pre(4);
				printf(" 7. Backup System\n\n");Sleep(250);pre(4);
				printf(" 8. Instant Order Preview\n\n");Sleep(250);pre(4);
				printf(" 0. Menu \n\n");
				printf("Enter Your From 1-0: ");
				Sleep(250);

				int adminchoise;



				fflush(stdin);   scanf("%d",&adminchoise);

				if(adminchoise==1){

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);

					Sleep(2000);

					goto adminchoise;
				}
				else if(adminchoise==2){

					if(c!=0){

						cls();  br(3); pre(4);

						printf(" __\n");pre(4);
						printf("|   Card NO.   |   Money $   |\n");pre(4);
						printf("------------------------------\n");pre(4);

						for(int z=1; z<=c;z++){

							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);pre(4);
							printf("------------------------------\n");pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					printf("No Card History\n");}
					Sleep(1500);
					goto adminchoise;
				}

				else if(adminchoise==3){

					foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);      printf(" Enter Food Name :  ");
					std::string phrase = "enter food name";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);

					br(2);pre(4);
					printf(" Enter Food Quantity :  ");

					scanf("%d",&fquantity); fflush(stdin);

                        foodserial:
					br(2);pre(4);  printf(" Enter Food Serial :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  printf(" Food Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                      std::string phrase = "food serial exit please enter other";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
					   goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);  printf(" Enter Food Price :  ");
				fflush(stdin);

					scanf("%f",&fprice);



					br(2);pre(4);  printf("Submitting your data");
				for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}
					insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Food Added Successfull....\n");

					Sleep(2000);
			
					goto adminchoise;

				}
				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Food To Delete : ");
					std::string phrase = "enter serial number of food";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						std::string phrase = "please enter correct number";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
						goto fdelete;
					}


					goto adminchoise;
				}

				else if(adminchoise==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);



					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;

				}

				else if(adminchoise==6){

					citem = countitem();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						printf("Item Counting ");
						printf(" %d ",cs);
						Sleep(150);
						cls();
					}
					cls();
					middle1();pre(4);
					printf("Total Food Item is --> %d  \n",citem); Sleep(2000);
					goto adminchoise;

				}

                        ///Backup System
				else if(adminchoise==7){


					char date[35]="DATE";

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); printf("Error!"); Sleep(500);
						goto adminchoise;
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Successfull..."); Sleep(1500);
					 std::string phrase = "backup completed";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


					fclose(fptr);
					goto adminchoise;
				}
				else if(adminchoise==8){

					cls();br(2);pre(2);
					printf("\n\t\t");
					printf("__ ");
					printf("\n\t\t");
					printf("|  Order No.  |   FooD Name  |  Quantity | In Stock|");
					printf("\n\t\t");
					printf("------------------------------------------------------");
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;



				}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Thank You For Using Our System \n\n\n\n\n\n\n");
			Sleep(1000);
			std::string phrase = "Thank you For Using Our System";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


			exit(1);

		}

	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		std::string phrase = "Please Enter Correct Choice";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

		goto mainmenu;
	}


	int get_food_choice;
    	int a=21;

	br(2); pre(3); cout<<"Table number   "<<a<<endl;


	br(1); pre(3);fflush(stdin);
	printf("Enter Your choice from list: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(3);  echo("Please Choice From List: "); br(2); Sleep(1000);
			std::string phrase = "Please Choice From List";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(3);
		printf("Enter Food Quantity : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity); cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			std::string phrase = "Quantity Can Not be Zero";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf(" Sorry Out of Stock ! "); Sleep(2000);
			std::string phrase = "Sorry Out of Stock !";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


			goto foodlist;
		}

		middle1();pre(3);  printf("Choice food %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
			br(1);pre(3); printf("1. Confirm to buy this \n\n");pre(4);
			br(1);pre(3); printf("2. Food List \n\n");
			br(2);pre(3);printf("Press 1 to confirm and 2 to back to food list :");
		std::string phrase = "Press 1 to confirm      2 to back to food list";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


		confirm:
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(3);
			printf(" 1. Cash ");
			br(2);pre(3);
            printf(" 2. Credit\n");
            	br(2);pre(3); printf("Select Method Of payment 1-2: ");
            std::string phrase = "Select Method of payment    enter 1 for cash   2 for card payment";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

			payment:
			int payment;

			fflush(stdin);  scanf("%d",&payment);

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  printf("===>THANK YOU<===");
				br(2);pre(3);  printf("Food Ordered Successfully ...");
				std::string phrase = "Thank you your food ordered succesfully";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

				br(2);pre(4);  printf("1. Wanna Buy Another ? ");
				br(2);pre(4);  printf("2. Main Menu \n");
				br(2);pre(4);   printf("Select: ");
				psmenu:
				int ps_menu;

				fflush(stdin);  scanf("%d",&ps_menu);

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(3);printf("Please choose from list : "); 
				std::string phrase = "Please choose from list";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){

				int card_number[100];

				c++;

				cls();middle1();pre(3); printf("Enter Your 12 Digit Card No : ");
				std::string phrase = "enter your 12 digit card number";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

				fflush(stdin);   scanf("%d",&card_number[c]);
				
				cardno[c] = card_number[c];
				
				int pin;

				br(2);pre(3);  printf("Enter Your Card Pin");
				//std::string phrase = "Enter Your Card Pin";
        //std::string command = "espeak \"" + phrase + "\"";
        //const char *charCommand = command.c_str();
        //system(charCommand);
    

				fflush(stdin);     scanf("%d",&pin);
				 if(pin>999999)
          {	br(2);pre(3); printf("Please enter correct Pin");
          std::string phrase = "please enter correct pin";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
        br(2);pre(3);printf("1. Cash");
        br(2);pre(3);printf("2. Credit");
		goto payment;}
        if(pin<999)
        {	br(2);pre(3); printf("Please enter correct Pin");
        std::string phrase = "please enter correct pin";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
        br(2);pre(3);printf("1. Cash");
        br(2);pre(3);printf("2. Credit");
         
        goto payment;
        
		}

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				br(2);pre(4);  printf("Payment Success...");
				br(2);pre(4);    printf("1. Wanna Buy Another? ");
				br(2);pre(4);    printf("2. Main Menu \n");
				br(2);pre(4);   printf("select: ");
				psmenu2:
				int ps_menu2;

				scanf("%d",&ps_menu2);

				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choose from list ");
				std::string phrase = "please choose from list";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
 goto psmenu2;}

			}

			else{

				br(2);pre(4);   printf("choice from List : ");
				std::string phrase = "choose from list";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


				goto payment;


			}


		}



		else if(confirm == 2){

			goto foodlist;

		}

		else{
			br(2);pre(4);    printf(" Choose from List : ");
			std::string phrase = "choose from list";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


			goto confirm;


		}


	}


	else{

		br(2);pre(4);  echo("Please Choose From List ");
		std::string phrase = "please choose from list";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
 br(2); Sleep(300);

		goto foodlist;

	}
}

void cls(){

	system("cls");

}

void echo(char print[]){

	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}

}

void main_menu(){

	cls();
	br(5); pre(3); echo("  ===> 1. Food List"); Sleep(400);
	br(2); pre(3); echo("  ===> 2. Admin Panel"); Sleep(400);
	br(2); pre(3); echo("  ===> 3. Exit");  Sleep(400);
	std::string phrase = "enter 1 for food list 2 for admin panel 3 for exit";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);


	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

	//    free(temp);
}

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

			printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); Sleep(500);
			std::string phrase = "Deleted successfully";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

		}
		else{
			printf("\n\n\n\n\t\t\tFood Item Not Found\n"); Sleep(500);
			std::string phrase = "food item not found";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

		printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); Sleep(500);
		std::string phrase = "deleted sucessfully";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

		head = temp ;

		list=head;
	}
}

void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

}

int countitem(){

	node *temp;

	temp = list;

	int countitem=0;

	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}

	}


	return countitem;

}
void foodlist(){




	printf("__ ");
	printf("\n\t\t");
	printf("|  Food No.  |   FooD Name   |  Price  |   In Stock   |");
	printf("\n\t\t");
	printf("-------------------------------------------------------");

	node *temp;

	temp = list;

	while(temp != NULL){




		printf("\n\t\t");
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		printf("\n\t\t");
		printf("-------------------------------------------------------");


		temp = temp->next ;

		Sleep(100);

	}




}


void order_view(int order, int quantity, int or_no){





	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){



		printf("\n\t\t");
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);

		printf("\n\t\t");
		printf("-------------------------------------------------------");

		Sleep(100);

	}



}



void pwellcome(){


	char welcome[50]="       WELCOME";
	char welcome2[50]="     TO";
	char welcome3[50]="SMART ORDERING SYSTEM";
	
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){


		printf(" %c",welcome[wlc]);
		Sleep(200);
	}

	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){


		printf(" %c",welcome2[wlc2]);
		Sleep(200);
	}

	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){


			printf(" %c",welcome3[wlc3]);
		}
		else{


			printf(" %c",welcome3[wlc3]);
		}

		Sleep(200);
	}
   std::string phrase = "welcome to SMART ORDERING SYSTEM";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

	printf("\n\n\n\t\t\t\t ");
	
	


}
void loadingbar(void){
	    

	for (int i=15;i<=100;i+=8){

		cls();
		
        
		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){


			printf(" ");


		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}
void backuploader(void){

	for (int i=15;i<=100;i+=8){

		cls();


		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);
		std::string phrase = "backing up data";
        std::string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

		printf("");

		for (int j=0; j<i;j+=2){

			printf(" ");


		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

}


void middle1(void){

	printf("\n\n\n\n\n\n\n");
};

void middtab1(void){
	printf("\t\t\t\t\t");
};

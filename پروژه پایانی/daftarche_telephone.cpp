#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
struct tel{
	char nam[20];
	char shomareh[13];
}d[100];
FILE *fp;

void ijade_file(){
	fp=fopen("tel.txt","w");
	fclose(fp);
	printf("file ijad shod.\n");
}

void gereftan(int i){
	cout<<"Nam:\n";
	cin>>d[i].nam;
	cout<<"shomare: \n";
	cin>>d[i].shomareh;
	fp = fopen("tel.txt","a");
	fprintf(fp,"%s \t %s \n",d[i].nam,d[i].shomareh);
	fclose(fp);
	printf("ezafe shod.\n");
}

void list(){
	char mystring[34];
	fp = fopen("tel.txt","r");
	system("cls");
	int f =0;
	puts("..........................\n");
	while(!feof(fp)){
		if(fgets(mystring,34,fp)!=NULL){
			f = 1;
			puts(mystring);
		}
	}
	if(!f) 
	puts("File Khali ast.");
	puts("..........................\n");
	fclose(fp);
}

void jostojoo(){
	char mystring[34],tmp[34],*ch;
	cout<<"Lotfan nam ya shomare ra vared konid: \n";
	cin>>tmp;
	fp = fopen("tel.txt","r");
	system("cls");
	int f =0;
	puts("..........................\n");
	while(!feof(fp)){
		if(fgets(mystring,34,fp)!=NULL){
			ch = strstr(mystring,tmp);
			if(ch){
				f = 1;
			    puts(mystring);
			}
			
		}
	}
	if(!f) 
	    puts("chizi peyda nashod.");
	puts("..........................\n");
	fclose(fp);
}
int main(){
	int c,i=0;
	bool on = true;
	while(on){
		cout<<"Lotfan adadi beyne 0 ta 4 ra vared konid: \n";
		cout<<"0 - ijade file\n";
		cout<<"1 - gereftane nam va shomare\n";
		cout<<"2 - namayesh liste kamel\n";
		cout<<"3 - jostojoo dar file\n";
		cout<<"4 - khoroj\n";
		cin>>c;
		cin.clear();
		while(cin.get()!='\n'){
			c=5;
		}
		switch(c){
			case 0:
				ijade_file();
				break;
			case 1:
				gereftan(i++);
				break;
			case 2:
				list();
				break;		
			case 3:
				jostojoo();
				break;
			case 4:
				on = false;
				break;
			default:
				cout<<"Error!\n";
				break;	
		}
	}
    return 0;
}



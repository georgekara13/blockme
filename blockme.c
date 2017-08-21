#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*authors: George Karagiannis and Fotis Georgakopoulos*/
int i,x,y,playersnum,*botchk[4][2],hp=0,xp=0, *ctrltmp[7],pi=7,yaxis=100,xaxis=100,kl=200,cntobs[4]={5,5,5,5},**botmap,mav,needhelp,revertx1,reverty1,revertx2,reverty2;
char **table, *name[4][60], ctrl[7],pin[4]={'@','#','*','&'},yhalp2;


int main(void){
  void print_table();
  void obst_init();
    
  int playerschoice,z,l=0,botcount=0,obstchoice,c,k,win,ki;
  char a,conf;
  //epilogh tamplo
  do{
  	printf("Set table dimensions or use default table?\n1)Default table\n2)Custom table\n");
  	scanf("%d",&playerschoice);
  	while(playerschoice!=1 && playerschoice!=2){
  		printf("Please press 1 or 2.\n");
  		scanf("%d",&playerschoice);
	  }
  	if(playerschoice==1){
  		x=10;
  		y=10;
	
  	}else{
	  do{
		printf("Input the X axis of the table:\n");
		scanf("%d",&x);
		if (x>30 || x<5)
		printf ("Please input a number within 5 and 30\n");
   	  }while (x>30 || x<5)  ;
	

      do{
		printf("Input the Y axis of the table:\n");
		scanf("%d",&y);
		if (y>26 || y<5)
		printf ("Please input a number within 5 and 26\n");
      }while (y>26 || y<5)  ;
	  
	  
	  
	  
    }
  	
  	
  }while(playerschoice!=1 && playerschoice!=2);
   
  do{
   
    for(i=0; i<4; i++){
    	for(z=0; z<60; z++){
	
    	  name[i][z]=(char *) malloc(sizeof(char *));
    	  if(name[i][z]!=NULL){
    		l++;
		  }
	    }
    }
  }while(l==0);
  l=0;
  do{
  	for(i=0; i<4; i++){
    	for(z=0; z<2; z++){
	
    	  botchk[i][z]=(int *) malloc(sizeof(int *));
    	  if(botchk[i][z]!=NULL){
    		l++;
		  }
	    }
	    *botchk[i][0]=i;
	}
  }while(l==0);
  	
  		strcpy(*name[0],"Player 1");
  		strcpy(*name[1],"Player 2");
  		strcpy(*name[2],"Player 3");
  		strcpy(*name[3],"Player 4");
  		
	printf("Number of players:\n1)2 players\n2)4 players\n");
	scanf("%d",&playerschoice);
	while(playerschoice!=1 && playerschoice!=2){ 
	  printf("Please press 1 or 2.\n");
	  scanf("%d",&playerschoice);
    }
    if (playerschoice==1)
    	playersnum=2;
	else
	    playersnum=4;
	    
	if (playersnum==2){
		for(i=0; i<2; i++){
		
			printf("%s is a:\n1)human\n2)bot\n",*name[i]);
			scanf("%d",&playerschoice);
	    	while(playerschoice!=1 && playerschoice!=2){ 
	  			printf("Please press 1 or 2.\n");
	  			scanf("%d",&playerschoice);
	  		
			}
		    if(playerschoice==1){
			  
	  				printf("%s input your  name:\n\n",*name[i]);
					scanf("%s",*name[i]);
					printf("Your name is %s\n\n",*name[i]);
				 	*botchk[i][1]=0;
	
	    	}else{
	    		botcount++;
	    		*botchk[i][1]=1;
			}
			if(botcount==2){
				printf("One of the players must be a human.\n");
				i--;
				botcount--;
			}
		}
	}else{
		botcount=0;
		for(i=0; i<4; i++){
		
			printf("%s is a:\n1)human\n2)bot\n",*name[i]);
			scanf("%d",&playerschoice);
	    	while(playerschoice!=1 && playerschoice!=2){ 
	  			printf("Please press 1 or 2.\n");
	  			scanf("%d",&playerschoice);
	  		
			}
		    if(playerschoice==1){
			  
	  				printf("%s input your  name:\n\n",*name[i]);
					scanf("%s",*name[i]);
					printf("Your name is %s\n\n",*name[i]);
					*botchk[i][1]=0;
				 
	
	    	}else{
	    		botcount++;
	    		*botchk[i][1]=1;
			}
			if(botcount==4){
				printf("One of the players must be a human.\n");
				i--;
				botcount--;
			}
		}	
	}
	//dunamikh desmefsh gia to botmap

			l=0;
			//dunamikh ekxwrish tou botmap
			botmap=(int **) malloc(x*sizeof(int *));
			do{
				for(ki=0;ki<x;ki++) {
					botmap[ki]=(int*) malloc(y*sizeof(int));
					if(botmap[ki]!=NULL){
		    			l++;
				  	}
				}
			}while(l==0);
			

	do{
		printf("1)Start game with obstacles.\n2)Start game without obstacles.\n");
		scanf("%d",&obstchoice);
		if(obstchoice!=1 && obstchoice!=2)
			printf("Please press 1 or 2.\n");
		
	}while(obstchoice!=1 && obstchoice!=2);

	srand(time(NULL));
	l=0;
	//dunamikh ekxwrish tou table
	table=(char **) malloc(x*sizeof(char *));
	do{
		for(i=0;i<x;i++) {
			table[i]=(char *) malloc(y*sizeof(char));
			if(table[i]!=NULL){
    			l++;
		  	}
		}
	}while(l==0);
	//malloc gia to ctrl / ctrltmp
	l=0;
	do{
		for(i=0;i<7;i++) {
			ctrltmp[i]=(int *) malloc(sizeof(int));
			if(ctrltmp[i]!=NULL){
    			l++;
		  	}
		}
	}while(l==0);
	//teleies
    for (c=0; c<x; c++){

		for(k=0;k<y;k++){
		
			table[c][k]=('.');
			
		}
	}
	if(playersnum==4){
	
		for(i=0; i<playersnum; i++){
			if((x%2)==1){
				if((y%2)==1){
					if(i==0){
						table[x-1][((y+1)/2)-1]=('@');
					}
					if(i==1){
						table[((x+1)/2)-1][0]=('#');
					}
					if(i==2){
						table[0][((y+1)/2)-1]=('*');
					}
					if(i==3){
						table[((x+1)/2)-1][y-1]=('&');
					}
				
				
				}
				if((y%2)==0){
					if(i==0){
						table[x-1][y/2]=('@');
					}
					if(i==1){
						table[((x+1)/2)-1][0]=('#');
					}
					if(i==2){
						table[0][y/2]=('*');
					}
					if(i==3){
						table[((x+1)/2)-1][y-1]=('&');
					}
				
				
				}
			}
		
			if((x%2)==0){
				if((y%2)==1){
					if(i==0){
						table[x-1][((y+1)/2)-1]=('@');
					}
					if(i==1){
						table[x/2][0]=('#');
					}
					if(i==2){
						table[0][((y+1)/2)-1]=('*');
					}
					if(i==3){
						table[x/2][y-1]=('&');
					}
				
				}
				if((y%2)==0){
					if(i==0){
						table[x-1][y/2]=('@');
					}
					if(i==1){
						table[x/2][0]=('#');
					}
					if(i==2){
						table[0][y/2]=('*');
					}
					if(i==3){
						table[x/2][y-1]=('&');
					}
				
				}
			}
		
		}
	}else{
		for(i=0; i<playersnum; i++){
			if((y%2)==0){
					if(i==0){
						table[x-1][y/2]=('@');
					}
					if(i==1){
						table[0][y/2]=('#');
					}
			}
			if((y%2)==1){
					if(i==0){
						table[x-1][((y+1)/2)-1]=('@');
					}
					if(i==1){
						table[0][((y+1)/2)-1]=('#');
					}
			}
		
		}
		
		
			
	}
	if (obstchoice==1){
		obst_init();
	}
	
	print_table();
	printf("\n\n\nPress a key when ready\n");
	scanf("%s",&conf);
	hp=8;
		i=0;
		do{
			print_table();
			//winning conditions
			for(c=0; c<x; c++){
				for(k=0; k<y; k++){
					if(table[0][k]=='@'){
						win=i;
						hp=3;
					}
					if(playersnum==4 &&table[c][y-1]=='#'){
						win=1;
						hp=3;
					}
					if(playersnum==2 && table[x-1][k]=='#'){
						win=i;
						hp=3;
					}
					if(table[x-1][k]=='*'){
						win=i;
						hp=3;
					}
					if(table[c][0]=='&'){
						win=i;
						hp=3;
					}
				}
			}
			
			 
			if(i==playersnum-1){
				i=0;
			}else{
				i++;	
			}	
		}while(hp>=8);
	if(hp==3)
		printf("%s won the game!\n",*name[win]);		
	if (hp==6){
		printf("\nGAME OVER\n");
	}
	free (**name);
	free (**botchk);	
	free (table);
	free (*ctrltmp);
	free (botmap);
    return 0;
}
//sinartisi emfanishs tou table+tou paixnidiou 
void print_table(){
	void testinput();
	void controls1();
    void controls2();
	char a=0;
	int c, k,j=65;
	printf(" ");
	printf(" ");
	printf(" ");
    printf(" ");
	for(c=0;c<y;c++){
 		a=j;	
	    printf("%2c ",a);
		j++;}
	    printf("\n");
	    printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		for(c=0;c<y;c++)
	   		printf("---");	
		for (c=0; c<x; c++){
			printf("\n");
			printf("%2d| ",c+1);
			
		
		
			for(k=0;k<y;k++){
		
				printf(" %c ",table[c][k]);
			}	
		}
		
	if(hp==8 ){
	
				kl=200;
				printf("\n\n%s(%c) you have %d obstacles left.Make your move:\n",*name[i],pin[i],cntobs[i]);
						
				if(*botchk[i][1]==0){
					do{
						testinput();
						
						if(hp!=6 && hp!=9)
							controls1();
					
					}while(kl==200);
				}else{
					controls2();	
				}
				
						
	
	}
}
//sunarthsh gia thn arxikh topo8ethsh empodiwn
void obst_init(){


	int w,p,nextobs,f=100,r=100;
	for (i=0; i<((5*(x*y))/100); i++){
		do{
		
			w=rand()%(x-2);
			if(w==0)
				w++;
			p=rand()%(y-2);
			if(p==0)
				p++;
		}while(table[w][p]!=('.'));	
		
		do{
			nextobs=rand()%40;
			if(nextobs>=0 && nextobs<=9){
				if(table[w+1][p]==('.') && (w+1)<(x-1)){
					f=w+1;
					r=p;
				}
			}else if(nextobs>=10 && nextobs<=19){
				if(table[w-1][p]==('.') && (w-1)>0){
					f=w-1;
					r=p;
				}
				
			}else if(nextobs>=20 && nextobs<=29){
				if(table[w][p+1]==('.') && (p+1)<(y-1)){
					f=w;
					r=p+1;
				}
			}else{
				if(table[w][p-1]==('.') && (p-1)>0){
					f=w;
					r=p-1;
				}	
			}
		}while(f==100 && r==100);
		table[w][p]=('X');
		table[f][r]=('X');
		f=100;
		r=100;
	}	
	
}
//sunarthsh gia tis kinhseis an8rwpou
void controls1(){
	int  xi,yi;
	void blockcaller();
	void testinput();
	hp=8;
	pi=7;
	do{
	
		
		if((ctrl[0]!=('e') && ctrl[1]!=('x') && ctrl[2]!=('i') && ctrl[3]!=('t')) || (ctrl[0]!=('h') && ctrl[1]!=('e') && ctrl[2]!=('l') && ctrl[3]!=('p')) && strlen(ctrl)<=3){
			for(xi=0; xi<x; xi++){
			
				for(yi=0; yi<y; yi++){
					if( table[xi][yi]==pin[i]){
						
						if(((xaxis==xi+1) || (xaxis==xi-1)) && yaxis==yi){
							if(xaxis==xi+1 && table[xi+1][yi]==('.')){
								table[xi+1][yi]=pin[i];
								table[xi][yi]=('.');
							
								pi=0;
								kl=0;
								break;
							}else if(xaxis==xi-1 && table[xi-1][yi]==('.')){
								table[xi-1][yi]=pin[i];
								table[xi][yi]=('.');
							
								pi=0;
								kl=0;
								break;
							}else{
								printf("Cannot move there.Try again:\n");
								pi=0;
								break;
							}
							
							
						}
						
						else if(((yaxis==yi+1) || (yaxis==yi-1)) && xaxis==xi){
							if(yaxis==yi+1 && table[xi][yi+1]==('.')){
								table[xi][yi+1]=pin[i];
								table[xi][yi]=('.');
							
								pi=0;
								kl=0;
								break;
							}else if(yaxis==yi-1 && table[xi][yi-1]==('.')){
								table[xi][yi-1]=pin[i];
								table[xi][yi]=('.');
							
								pi=0;
								kl=0;
								break;
							}else{
								printf("Cannot move there.Try again:\n");
								pi=0;
								break;
							}	
							
						}else{
							printf("Cannot move there.Try again:\n");
							pi=0;
							break;
						}
						
					
						
						
						
						
				}
					if(pi==0)
						break;
			
				
			}
		 }
		}
	}while(pi!=0);
}
//sunarthsh gia thn topo8ethsh empodiwn apto xrhsth
void blockcaller(){
	void testinput();
	void controls1();
	int xaxis2=100,yaxis2=100,trigger=100;
	do{
		//A8A9 A8A10
		if(!(*ctrltmp[0]>48 && *ctrltmp[0]<=57) && (*ctrltmp[2]>=65 && *ctrltmp[2]<=90) ){
			yaxis2= *ctrltmp[2]-65;
			if((ctrl[4]=='\0')){
				xaxis2=*ctrltmp[3]-48;
			}else{
				xaxis2=(*ctrltmp[3]-48)*10+(*ctrltmp[4]-48);
			}
		}
		//a8a9 a8a10
		else if(!(*ctrltmp[0]>48 && *ctrltmp[0]<=57) && (*ctrltmp[2]>=97 && *ctrltmp[2]<=122) ){
			yaxis2= *ctrltmp[2]-97;
			if((ctrl[4]=='\0')){
				xaxis2=*ctrltmp[3]-48;
			}else{
				xaxis2=(*ctrltmp[3]-48)*10+(*ctrltmp[4]-48);
			}
		}
		//A10A9 A10A11
		else if(!(*ctrltmp[0]>48 && *ctrltmp[0]<=57) && (*ctrltmp[3]>=65 && *ctrltmp[3]<=90) ){
			yaxis2= *ctrltmp[3]-65;
			if((ctrl[5]=='\0')){
				xaxis2=*ctrltmp[4]-48;
			}else{
				xaxis2=(*ctrltmp[4]-48)*10+(*ctrltmp[5]-48);
			}
		}
		//a10a9 a10a11
		else if(!(*ctrltmp[0]>48 && *ctrltmp[0]<=57) && (*ctrltmp[3]>=97 && *ctrltmp[3]<=122) ){
			yaxis2= *ctrltmp[3]-97;
			if((ctrl[5]=='\0')){
				xaxis2=*ctrltmp[4]-48;
			}else{
				xaxis2=(*ctrltmp[4]-48)*10+(*ctrltmp[5]-48);
			}
		}
		//9a8a 9A8A
		else if((*ctrltmp[0]>48 && *ctrltmp[0]<=57) && !(*ctrltmp[1]>48 && *ctrltmp[1]<=57) && ctrl[4]=='\0' ){
			xaxis2= *ctrltmp[2]-48;
			if(*ctrltmp[3]>=65 && *ctrltmp[3]<=90){
				yaxis2=*ctrltmp[3]-65;
			}else{
				yaxis2=*ctrltmp[3]-97;
			}
			
		}
		//9a10a  9A10A
		else if((*ctrltmp[0]>48 && *ctrltmp[0]<=57) && !(*ctrltmp[1]>=48 && *ctrltmp[1]<=57) && ctrl[4]!='\0' ){
			xaxis2= (*ctrltmp[2]-48)*10+(*ctrltmp[3]-48);
			if(*ctrltmp[4]>=65 && *ctrltmp[4]<=90){
				yaxis2=*ctrltmp[4]-65;
			}else{
				yaxis2=*ctrltmp[4]-97;
			}
			
		}
		//10b9b 10B9B
		else if((*ctrltmp[0]>48 && *ctrltmp[0]<=57) && (*ctrltmp[1]>=48 && *ctrltmp[1]<=57) && ctrl[5]=='\0' ){
			xaxis2= *ctrltmp[3]-48;
			if(*ctrltmp[4]>=65 && *ctrltmp[4]<=90){
				yaxis2=*ctrltmp[4]-65;
			}else{
				yaxis2=*ctrltmp[4]-97;
			}	
			
		}
		//10a11b 10A11B
		else{
			if(*ctrltmp[5]>=65 && *ctrltmp[5]<=90)	
				yaxis2= *ctrltmp[5]-65;
			else
				yaxis2=*ctrltmp[5]-97;
			xaxis2=(*ctrltmp[3]-48)*10+(*ctrltmp[4]-48);
			
		}
		xaxis2--;
		//printf("xaxis %d xaxis2 %d yaxis %d yaxis2 %d\n",xaxis,xaxis2,yaxis,yaxis2);
		
		if(cntobs[i]!=0 && (xaxis2==(xaxis-1) || xaxis2==(xaxis+1))&& yaxis2==yaxis){
			if(table[xaxis2][yaxis2]==('.')&& table[xaxis][yaxis]==('.')){
				
				
				table[xaxis][yaxis]='X';
				table[xaxis2][yaxis]='X';
				
				trigger=0;
				hp=8;
				kl=0;
				cntobs[i]--;
				
					
				
			}
			else{
				printf("Cannot put an obstacle there.Try again:\n");
				trigger=0;
				testinput();
				if(strlen(ctrl)<=3)	
					controls1();
			}
		}
		
	    else if(cntobs[i]!=0 && (yaxis2==(yaxis-1) || yaxis2==(yaxis+1))&& xaxis2==xaxis){
	    	
			if(table[xaxis2][yaxis2]==('.')&& table[xaxis][yaxis]==('.')){
				
				table[xaxis][yaxis]='X';
				table[xaxis][yaxis2]='X';
				trigger=0;
				hp=8;
				kl=0;
				cntobs[i]--;
			}
			else{
				printf("Cannot put an obstacle there.Try again\n");
				trigger=0;
				testinput();
				if(strlen(ctrl)<=3)	
					controls1();
			}
		}else{
		
				printf("Cannot do that.Give another input\n");
				trigger=0;
				testinput();
				if(strlen(ctrl)<=3){	
					controls1();
					
				}
			}
					
		
	}while(trigger!=0);

	
	
}
//sunarthsh gia ton elegxo tou input tou xrhsth
void testinput(){
	int countin=0,j;
	
	void controls2();
	void blockcaller();
	do{
			do{
				needhelp=0;
				do{
					while (getchar() != '\n');
					scanf("%s",ctrl);
					if(strlen(ctrl)>6){
						printf("Input can't be more than 6 characters.\n");
						printf("\n\n%s(%c) you have %d obstacles left.Make your move:\n",*name[i],pin[i],cntobs[i]);
					}
				
				}while(strlen(ctrl)>6);	
			
			
				if(ctrl[0]==('h') && ctrl[1]==('e') && ctrl[2]==('l') && ctrl[3]==('p')){
			
					needhelp=1;
					controls2();
		
					
				}else if(ctrl[0]==('e') && ctrl[1]==('x') && ctrl[2]==('i') && ctrl[3]==('t')){
					
					
					countin=9;
					yaxis=0;
					xaxis=0;
					hp=6;
					kl=0;
					
					
				
			
				}else{
					for(j=0; j<strlen(ctrl); j++){
						*ctrltmp[j]=ctrl[j];
						//printf("Element %d ASCII value:%d\n",j,*ctrltmp[j]);	
					}
					for(j=0; j<strlen(ctrl); j++){
					
						if (*ctrltmp[j]>=65 && *ctrltmp[j]<=90){
							if(ctrl[j+1]!=('\0') && (*ctrltmp[j+1]<48 || *ctrltmp[j+1]>57)){
								printf("Please give proper input(example: A3):\n");
								break;
							}else{
							
								yaxis= *ctrltmp[j]-65;
								if( strlen(ctrl)>=4){
								
									if(*ctrltmp[j+2]>=48 && *ctrltmp[j+2]<=57){
									
										xaxis=(*ctrltmp[j+1]-48)*10+(*ctrltmp[j+2]-48);
										xaxis--;
										countin=countin+3;
										
									}else{
									
										xaxis=*ctrltmp[j+1]-48;
										xaxis--;
										countin=countin+2;
									}
									blockcaller();
									countin=9;
									yaxis=0;
									xaxis=0;
		
									break;
								}else{
									countin++;
								}
								
							}
						
						}else if(*ctrltmp[j]>=97 && *ctrltmp[j]<=122){
							if(ctrl[j+1]!=('\0') && (*ctrltmp[j+1]<48 || *ctrltmp[j+1]>57)){
								printf("Please give proper input(example: B3):\n");
								break;
							}else{
								yaxis=*ctrltmp[j]-97;
								if(strlen(ctrl)>=4){
								
									if(*ctrltmp[j+2]>=48 && *ctrltmp[j+2]<=57){
									
										xaxis=(*ctrltmp[j+1]-48)*10+(*ctrltmp[j+2]-48);
										xaxis--;
										countin=countin+3;
									}
									else{
									
										xaxis=*ctrltmp[j+1]-48;	
										xaxis--;
										countin=countin+2;
									}
									blockcaller();
									yaxis=0;
									xaxis=0;
									countin=9;
									
									break;
								}else{
									countin++;
								}
								
							}
						}else if(*ctrltmp[j]>48 && *ctrltmp[j]<=57){
							
							if(ctrl[j+1]!=('\0') && (*ctrltmp[j+1]>=48 && *ctrltmp[j+1]<=57)){
								xaxis=(*ctrltmp[j]-48)*10+(*ctrltmp[j+1]-48);
								xaxis--;
								if(strlen(ctrl)>=4){
								
									if(*ctrltmp[j+1]>=65 && *ctrltmp[j+1]<=90)
										yaxis=*ctrltmp[j+1]-65;
									else
										yaxis=*ctrltmp[j+1]-97;	
									blockcaller();
									yaxis=0;
									xaxis=0;
									countin=9;
									
									break;
								}else{
								
									countin=countin+2;
									j++;
								}
							}
							else if(ctrl[j+1]==('\0') || !(*ctrltmp[j+1]>=48 && *ctrltmp[j+1]<=57)){
								xaxis=*ctrltmp[j]-48;
								xaxis--;
								if(strlen(ctrl)>=4){
								
									if(*ctrltmp[j+1]>=65 && *ctrltmp[j+1]<=90)
										yaxis=*ctrltmp[j+1]-65;
									else
										yaxis=*ctrltmp[j+1]-97;	
									blockcaller();
									yaxis=0;
									xaxis=0;
									countin=9;
									
									break;
								}else{
								
										countin++;
								}
							}else{
								printf("Please give proper input(example: C3):\n");
								break;	
							}
						}else{	
							printf ("Please give proper input(example: D3):\n");
							countin=0;
							break;
						}
						
					}
				
				}
				//printf("yaxis: %d xaxis: %d\n",yaxis,xaxis);
			}while(countin<strlen(ctrl));		
			
			if((yaxis>=y) || (xaxis>=x)){
				printf("Coords not found,please give proper input:\n");
				countin=0;
				yaxis=100;
				xaxis=100;
			}
	}while((yaxis>y) && (xaxis>x));
			
	
			
	
}
//sunarthsh gia tis kinhseis tou bot
void controls2(){
	
	void botblockcaller();
	int xk,yk,blockvalx=0,blockvaly=0,saveval=1,min=1000,mk,path,pathcount,spasetox=0,rcount=0,rllook=0,lrchk,revertx,reverty,indexposx,indexposy;
	char a=0;
	int c, k,j=65;
	mav=0;	
	revertx1=4000;
	botblockcaller();
	if(needhelp==1 && revertx1!=4000){
		table[revertx1][reverty1]='.';
		table[revertx2][reverty2]='.';
		reverty1=reverty1+65;
		reverty2=reverty2+65;
		revertx1=revertx1+1;
		revertx2=revertx2+1;
		printf("Block at %c%d%c%d\n",reverty2,revertx2,reverty1,revertx1);
		reverty1=reverty1-65;
		reverty2=reverty2-65;
		revertx1=revertx1-1;
		revertx2=revertx2-1;
	
		needhelp=0;
	}				
	if(mav==0){
	    //dunato bot @
		if(pin[i]=='@'){
			//evresh ths 8eshs tou bot @
			for(xk=0; xk<x; xk++){
				for(yk=0; yk<y; yk++){
					if(table[xk][yk]==pin[i]){
						botmap[xk][yk]=0;
						indexposx=xk;
						indexposy=yk;
					} 	
				}	
			}
			//ana8esh timwn sto botmap me vash th 8esh tou @
			for(xk=indexposx; xk>=0; xk--){
					//aksonas y sta deksia
					
					for(yk=indexposy+1; yk<y; yk++){
						if(table[xk][yk]=='.'){
							botmap[xk][yk]=blockvaly+1;
							blockvaly++;
							
						}else if(table[xk][yk]=='X'){
							botmap[xk][yk]=400;
							blockvaly++;
						}else{
							botmap[xk][yk]=500;
							blockvaly++;
						}
					}
					if(blockvalx==0)
						blockvaly=1;
					else
						blockvaly=blockvalx+1;	
					
					//aksonas y sta aristera
					for(yk=indexposy-1; yk>=0; yk--){
						if(table[xk][yk]=='.'){
							botmap[xk][yk]=blockvaly;
							blockvaly++;
							
						}else if(table[xk][yk]=='X'){
							botmap[xk][yk]=400;
							blockvaly++;
						}else{
							botmap[xk][yk]=500;
							blockvaly++;
						}	
					}
					if(blockvalx==0)
						blockvaly=1;
					else
						blockvaly=blockvalx+1;
				
					//aksonas x pros ta panw
					yk=indexposy;
					if(table[xk][yk]=='@'){
						blockvalx++;
					
					}else if(table[xk][yk]=='.' ){
						botmap[xk][yk]=blockvalx;
						blockvalx++;
						
					}else if(table[xk][yk]=='X'){
						botmap[xk][yk]=400;
						blockvalx++;
					}else{
						botmap[xk][yk]=500;
						blockvalx++;
				    }
				    
				    
			}
			
			
			//kanontas kinhsh
			
				do{	
					pathcount=1;
					//evresh tou kontinoterou path  gia termatismo
					for(yk=0;yk<y;yk++){
					
						if(botmap[0][yk]<min){
							xk=0;
							min=botmap[xk][yk];
							mk=yk;
						}
					
					}
					path=min;
					table[xk][mk]='!';
					//printf("vrhke path %d\n",path);
					
						for(saveval=min;saveval>1;){	
								if(botmap[xk+1][mk]==min-1 && botmap[xk][mk]==min && xk<(x-1)){
									
									
										min=botmap[xk+1][mk];
										saveval--;
										table[xk+1][mk]='!';
										xk=xk+1;
										pathcount++;
										//printf("mprostinh 8esh\n");
										if(xk==x-1){
											pathcount++;
											saveval--;
										}
								
								}
								
								else if(botmap[xk][mk+1]==min-1 && botmap[xk][mk]==min && mk<(y-1)){
									
										min=botmap[xk][mk+1];
										saveval--;
										table[xk][mk+1]='!';
										mk=mk+1;
										pathcount++;
										//printf("deksia\n");
										if(mk==y-1){
											pathcount++;
											saveval--;
										}
									
								}
								
								else if(botmap[xk][mk-1]==min-1 && botmap[xk][mk]==min && mk>0){
									min=botmap[xk][mk-1];
									saveval--;
									table[xk][mk-1]='!';
									mk=mk-1;
									pathcount++;
									//printf("aristera\n");
									if(mk==0){
										pathcount++;
										saveval--;
									}
									
								}
								else{
									
									//printf("den vrhke epomenh 8esh\n");
								
									break;
								}
							
						}
						//vazei megales times sto botmap ekei pou mphke to ! sthn akrh tou table gia na to kanei revert se . kai na mhn koitaksei ksana ekeinh th 8esh. 
						if(pathcount!=path){
							min=1000;
							saveval=1;
							for(xk=0;xk<x;xk++){
								for(yk=0;yk<y;yk++){
									
									if(table[xk][yk]=='!'){
										
										if(xk==0){
											botmap[xk][yk]=2000;
										}
										table[xk][yk]='.';
										//printf("ekane revert se .\n");
									}
									
								}
							}
						}
						
						for(yk=0;yk<y;yk++){
							if(botmap[0][yk]>=400){
								rcount++;
								
							}
							if(rcount==y){
								pathcount=path;
								break;
							}
							
						}
						
					}while(pathcount!=path);
	
					//printf("prin thn ana8esh\n");
					
						for(xk=0;xk<x;xk++){
								for(yk=0;yk<y;yk++){
									if(table[xk][yk]=='@' && table[xk-1][yk]=='!'){
										table[xk][yk]='.';
										table[xk-1][yk]='@';
										spasetox=2;
										revertx=xk-1;
										reverty=yk;
										break;
									}
									else if(table[xk][yk]=='@' && table[xk][yk+1]=='!'){
										table[xk][yk]='.';
										table[xk][yk+1]='@';
										spasetox=2;
										revertx=xk;
										reverty=yk+1;
										break;	
									}
									else if(table[xk][yk]=='@' && table[xk][yk-1]=='!'){
										table[xk][yk]='.';
										table[xk][yk-1]='@';
										spasetox=2;
										revertx=xk;
										reverty=yk-1;
										break;
										
									}
									else if(table[xk][yk]=='@' && table[xk][yk-1]!='!' && table[xk][yk+1]!='!' && table[xk-1][yk]!='!' ){
										if(xk<(x-1) && table[xk+1][yk]=='.'){
											table[xk][yk]='.';
											table[xk+1][yk]='@';
											spasetox=2;
											revertx=xk+1;
											reverty=yk;
											break;
										}else{
											lrchk=rand()%100; 
											//aristerh kinhsh
											if((lrchk<50 || yk>0) && table[xk][yk-1]=='.'  ){
												table[xk][yk]='.';
												table[xk][yk-1]='@';
												revertx=xk;
												reverty=yk-1;
												spasetox=2;
												break;
													
											}else if((lrchk>=50 || yk<(y-1)) && table[xk][yk+1]=='.'){
												table[xk][yk]='.';
												table[xk][yk+1]='@';
												spasetox=2;
												revertx=xk;
												reverty=yk+1;
												break;		
											}
											
											
										}
									}
									 
								}
								if(spasetox==2)
									break;
						}
	     //adeiasma tou table apo ta "!"
			for(xk=0;xk<x;xk++){
				for(yk=0;yk<y;yk++){
					if(table[xk][yk]=='!'){
						table[xk][yk]='.';
					}
				}
			}
		
		//topo8ethsh 300 sto botmap gia ksanagemisma(menei to 300 pisw apto botaki)
		for(xk=0; xk<x; xk++){
				for(yk=0; yk<y; yk++){
					botmap[xk][yk]=300;
				}
		}
	  }
	  //bot &
	  else if(pin[i]=='&'){
	  	for(xk=0; xk<x; xk++){
				for(yk=0; yk<y; yk++){
					if(table[xk][yk]==pin[i]){
						indexposx=xk;
						indexposy=yk;
					} 	
				}	
			}
			if(table[indexposx][indexposy-1]=='.' && indexposy>0){
				table[indexposx][indexposy-1]='&';
				table[indexposx][indexposy]='.';
				revertx=indexposx;
				reverty=indexposy-1;
			}
			else if((table[indexposx-1][indexposy]=='.' || table[indexposx+1][indexposy]=='.') && indexposx>0 && indexposy>0  ){
				do{
					lrchk=rand()%100;
					if(lrchk<50 && table[indexposx+1][indexposy]=='.'){
						table[indexposx+1][indexposy]='&';
						table[indexposx][indexposy]='.';
						revertx=indexposx+1;
						reverty=indexposy;
						break;
						
					}else if(lrchk>=50 && table[indexposx-1][indexposy]=='.'){
						table[indexposx-1][indexposy]='&';
						table[indexposx][indexposy]='.';
						revertx=indexposx-1;
						reverty=indexposy;
						break;
						
						
					}
				}while(indexposx!=10000);	
				
			}else{
				table[indexposx][indexposy+1]='&';
				table[indexposx][indexposy]='.';
				revertx=indexposx;
				reverty=indexposy+1;
			}
	  	
	  
	  }
	  //bot *
	  else if(pin[i]=='*'){
	  	for(xk=0; xk<x; xk++){
				for(yk=0; yk<y; yk++){
					if(table[xk][yk]==pin[i]){
						indexposx=xk;
						indexposy=yk;
					} 	
				}	
			}
			if(table[indexposx+1][indexposy]=='.' && indexposx>=0){
				table[indexposx+1][indexposy]='*';
				table[indexposx][indexposy]='.';
				revertx=indexposx+1;
				reverty=indexposy;
			}
			else if((table[indexposx][indexposy-1]=='.' || table[indexposx][indexposy+1]=='.') && indexposx>=0 && indexposy>0  ){
				do{
					lrchk=rand()%100;
					if(lrchk<50 && table[indexposx][indexposy+1]=='.'){
						table[indexposx][indexposy+1]='*';
						table[indexposx][indexposy]='.';
						revertx=indexposx;
						reverty=indexposy+1;
						break;
						
					}else if(lrchk>=50 && table[indexposx][indexposy-1]=='.'){
						table[indexposx][indexposy-1]='*';
						table[indexposx][indexposy]='.';
						revertx=indexposx;
						reverty=indexposy-1;
						break;
						
						
					}
				}while(indexposx!=10000);	
				
			}else{
				table[indexposx-1][indexposy]='*';
				table[indexposx][indexposy]='.';
				revertx=indexposx-1;
				reverty=indexposy;
			}
	  	
	  
	  }
	  //bot #
	  	else{
	  		for(xk=0; xk<x; xk++){
				for(yk=0; yk<y; yk++){
					if(table[xk][yk]==pin[i]){
						indexposx=xk;
						indexposy=yk;
					} 	
				}	
			}
			
			
	  		if(playersnum==2){
					if(table[indexposx+1][indexposy]=='.' && indexposx>=0){
						table[indexposx+1][indexposy]='#';
						table[indexposx][indexposy]='.';
						revertx=indexposx+1;
						reverty=indexposy;
					}
					else if((table[indexposx][indexposy-1]=='.' || table[indexposx][indexposy+1]=='.') && indexposx>=0 && indexposy>0  ){
						do{
							lrchk=rand()%100;
							if(lrchk<50 && table[indexposx][indexposy+1]=='.'){
								table[indexposx][indexposy+1]='#';
								table[indexposx][indexposy]='.';
								revertx=indexposx;
								reverty=indexposy+1;
								break;
								
							}else if(lrchk>=50 && table[indexposx][indexposy-1]=='.'){
								table[indexposx][indexposy-1]='#';
								table[indexposx][indexposy]='.';
								revertx=indexposx;
								reverty=indexposy-1;
								break;
								
								
							}
						}while(indexposx!=10000);	
						
					}else{
						table[indexposx-1][indexposy]='#';
						table[indexposx][indexposy]='.';
						revertx=indexposx-1;
						reverty=indexposy;
					}	
			}else{
				
				
			
					if(table[indexposx][indexposy+1]=='.' && indexposy>=0){
						table[indexposx][indexposy+1]='#';
						table[indexposx][indexposy]='.';
						revertx=indexposx;
						reverty=indexposy+1;
					}
					else if((table[indexposx-1][indexposy]=='.' || table[indexposx+1][indexposy]=='.') && indexposx>0 && indexposy>=0  ){
						do{
							lrchk=rand()%100;
							if(lrchk<50 && table[indexposx+1][indexposy]=='.'){
								table[indexposx+1][indexposy]='#';
								table[indexposx][indexposy]='.';
								revertx=indexposx+1;
								reverty=indexposy;
								break;
								
							}else if(lrchk>=50 && table[indexposx-1][indexposy]=='.'){
								table[indexposx-1][indexposy]='#';
								table[indexposx][indexposy]='.';
								revertx=indexposx-1;
								reverty=indexposy;
								break;
								
								
							}
						}while(indexposx!=10000);	
						
					}else{
						table[indexposx][indexposy-1]='#';
						table[indexposx][indexposy]='.';
						revertx=indexposx;
						reverty=indexposy-1;
					}
		
			}
	  	
	  	
	  	
	  	
	  	}
	  	if(needhelp==1){
			yhalp2=reverty+65;
			printf("Move to %c%d\n",yhalp2,revertx+1);
			table[indexposx][indexposy]=pin[i];
			table[revertx][reverty]='.';
	    }
	  }
	 
}
//synarthsh gia thn topo8ethsh empodiwn apo botakia
void botblockcaller(){
	int p,j,k,d,timh;
	timh=rand()%100;
	if(timh<50){
		for(d=0; d<playersnum ;d++){		
						for(j=1;j<x-1;j++){
							for(k=1;k<y-1;k++){
								//current bot @,konta sth nikh
								if(pin[d]=='@' && pin[i]=='@' && pin[d]==table[j][k] && j<=3){				
									j=x;
									d=playersnum;
									break;	
								//current bot *,konta sth nikh	
								}else if(pin[d]=='*' && pin[i]=='*' && j>=x-3 && pin[d]==table[j][k]){
									j=x;
									d=playersnum;
									break;
								//current bot &,konta sth nikh	
								}else if(pin[d]=='&' && pin[i]=='&' && pin[d]==table[j][k] && k<=3){
									j=x;
									d=playersnum;
									break;
								//current bot #,2 paiktes,konta sth nikh	
								}else if(pin[d]=='#' && pin[i]=='#' && pin[d]==table[j][k] && j>=x-3 && playersnum==2){
									j=x;
									d=playersnum;
									break;
								//current bot #,4 paiktes,konta sth nikh	
								}else if(pin[d]=='#' && pin[i]=='#' && pin[d]==table[j][k] && k>=y-3 && playersnum==4){
									j=x;
									d=playersnum;
									break;
								
								}else{
									//vs #(gia 2 paixtes)
									if(pin[i]!='#' && table[j][k]=='#' && playersnum==2 && j>=x-4 && cntobs[i]>0){
										if(table[j+1][k]=='.'){
											//katw deksia
											if(table[j+1][k+1]=='.' && k+1<y-1){
												table[j+1][k]='X';
												table[j+1][k+1]='X';
												cntobs[i]--;
												revertx1=j+1;
												reverty1=k;
												revertx2=j+1;
												reverty2=k+1;
												j=x;
												d=playersnum;
												mav=1;	
												break;
												
												
											}
											//katw aristera
											if(table[j+1][k-1]=='.' && k-1>1){
												table[j+1][k]='X';
												table[j+1][k-1]='X';
												cntobs[i]--;
												revertx1=j+1;
												reverty1=k;
												revertx2=j+1;
												reverty2=k-1;
												j=x;
												d=playersnum;
												mav=1;
												break;
												
											}
											//katw katw
											if(table[j+2][k]=='.' && j+1<x-1){
												table[j+1][k]='X';
												table[j+2][k]='X';
												cntobs[i]--;
												revertx1=j+1;
												reverty1=k;
												revertx2=j+2;
												reverty2=k;
												j=x;
												d=playersnum;
												mav=1;
												break;
												
											}
											
										}
										
									}
									//vs #(gia 4 paixtes)
									else if(pin[i]!='#' && table[j][k]=='#' && playersnum==4 && k>=y-4  && cntobs[i]>0){
										if(table[j][k+1]=='.'){
											//katw deksia
											if(table[j+1][k+1]=='.' && j+1<x-1){
												table[j][k+1]='X';
												table[j+1][k+1]='X';
												cntobs[i]--;
												revertx1=j;
												reverty1=k+1;
												revertx2=j+1;
												reverty2=k+1;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
												
											}
											//katw aristera
											if(table[j-1][k+1]=='.' && j-1>1){
												table[j][k+1]='X';
												table[j-1][k+1]='X';
												cntobs[i]--;
												revertx1=j;
												reverty1=k+1;
												revertx2=j-1;
												reverty2=k+1;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
											}
											//deksia deksia
											if(table[j][k+2]=='.' && k+2<y-1){
												table[j][k+1]='X';
												table[j][k+2]='X';
												cntobs[i]--;
												revertx1=j;
												reverty1=k+1;
												revertx2=j;
												reverty2=k+2;
												j=x;
												d=playersnum;
												mav=1;

												break;
												
											}
											
										}
										
									}
									//vs *
									else if(pin[i]!='*' && table[j][k]=='*' &&  j>=x-4 && cntobs[i]>0){
										if(table[j+1][k]=='.'){
											//katw deksia
											if(table[j+1][k+1]=='.' && k+1<y-1){
												table[j+1][k]='X';
												table[j+1][k+1]='X';
												cntobs[i]--;
												revertx1=j+1;
												reverty1=k;
												revertx2=j+1;
												reverty2=k+1;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
												
											}
											//katw aristera
											if(table[j+1][k-1]=='.' && k-1>1){
												table[j+1][k]='X';
												table[j+1][k-1]='X';
												cntobs[i]--;
												revertx1=j+1;
												reverty1=k;
												revertx2=j+1;
												reverty2=k-1;
												j=x;
												d=playersnum;
												mav=1;
											
												break;
												
											}
											//katw katw
											if(table[j+2][k]=='.' && j+1<x-1){
												table[j+1][k]='X';
												table[j+2][k]='X';
												cntobs[i]--;
												revertx1=j+1;
												reverty1=k;
												revertx2=j+2;
												reverty2=k;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
											}
											
										}
										
									}
									//vs &
									else if(pin[i]!='&' && table[j][k]=='&'  && k<=4 && cntobs[i]>0){
										if(table[j][k-1]=='.'){
											//katw deksia
											if(table[j+1][k-1]=='.' && j+1<x-1){
												table[j][k-1]='X';
												table[j+1][k-1]='X';
												cntobs[i]--;
												revertx1=j;
												reverty1=k-1;
												revertx2=j+1;
												reverty2=k-1;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
												
											}
											//katw aristera
											if(table[j-1][k-1]=='.' && j-1>1){
												table[j][k-1]='X';
												table[j-1][k-1]='X';
												cntobs[i]--;
												revertx1=j;
												reverty1=k-1;
												revertx2=j-1;
												reverty2=k-1;
												j=x;
												d=playersnum;
												mav=1;
											
												break;
												
											}
											//deksia deksia
											if(table[j][k-2]=='.' && k-1>1){
												table[j][k-1]='X';
												table[j][k-2]='X';
												cntobs[i]--;
												revertx1=j;
												reverty1=k-1;
												revertx2=j;
												reverty2=k-2;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
											}
											
										  }
										}
										// vs @
										if( pin[i]!='@' && table[j][k]=='@' &&  j<=4 && cntobs[i]>0){
										  if(table[j-1][k]=='.'){
											//panw deksia
											if(table[j-1][k+1]=='.' && k+1<y-1){
												table[j-1][k]='X';
												table[j-1][k+1]='X';
												cntobs[i]--;
												revertx1=j-1;
												reverty1=k;
												revertx2=j-1;
												reverty2=k+1;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
												
											}
											//panw aristera
											if(table[j-1][k-1]=='.' && k-1>1){
												table[j-1][k]='X';
												table[j-1][k-1]='X';
												cntobs[i]--;
												revertx1=j-1;
												reverty1=k;
												revertx2=j-1;
												reverty2=k-1;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
											}
											//panw panw
											if(table[j-2][k]=='.' && j-1>1){
												table[j-1][k]='X';
												table[j-2][k]='X';
												cntobs[i]--;
												revertx1=j-1;
												reverty1=k;
												revertx2=j-2;
												reverty2=k;
												j=x;
												d=playersnum;
												mav=1;
												
												break;
												
											}
											
										  }  
										
										}
															
									}
									
									
								}
								
								
							}
						}
						
		
			
		}
		
}
								
		
					
				
					
				
			
	
		
	





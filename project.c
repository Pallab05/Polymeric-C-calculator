#include<stdio.h>
#include<stdlib.h>
#define max 20
float mfi(float);

int transpose(int [],int);
int Kconstant(int [],int);
int Force(int [],int,int);
int main()
{
	int ch,ch1,i,j,k;
	float Re,p,u,L,mu;
	
	float ts[3][1],a[3][1],f[3][3]={0};
	float minforce,maxforce;
	
	float w;
	
	int K[max],X[max],F[max][max]={0},z,x;
	int newval,loc;
	int ch2,ch3;
	int temp;
	int y,v;
	
	
	float J,T,I,*p1,*p2;
	p1=&J;
	p2=&T;
	
	
	do
	{
		printf("|===========================Calculator============================|");
		printf("\n1-Reynolds number\n2-Tensile force\n3-Melt flow index\n4-Hooke's Law\n5-Impact strength");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\n|-----------------Calculationg the flow property of a polymer-----------------|");
				printf("\nEnter density of the fluid(p) :  ");// SI unit 
	            scanf("%f",&p); 
	            printf("\nEnter flow speed(u) : ");
	            scanf("%f",&u);
	            printf("\nEnter characteristic linear dimension(L) : ");
	            scanf("%f",&L);
	            printf("\nEnter dynamic viscosity of the fluid(mu) : ");
	            scanf("%f",&mu);
	
               	Re=p*u*L/mu;//Reynolds number formula
	            printf("\nReynolds number for fluid is : %f",Re);
	            if(Re<2000)
	            {
		            printf("\nFlow of the fluid is laminar");
	            }
             	else if(Re>2000 && Re<4000)
             	{
		            printf("\nFlow of the fluid is unstable");
	            }
	            else
	            {
		            printf("\nFlow of the fluid is turbulent");
	            }
		        break;
		    
		    case 2:
		    	
		    	printf("\n|--------------------------Calculating the tensile force of 3 polymers-------------------------|");
		    	
		    	printf("\nEnter peak tensile strength of the polymers(ts) : ");
		    	for(i=0;i<3;i++)
		    	{
		    		for(j=0;j<1;j++)
		    		{
		    			scanf("%f",&ts[i][j]);//Tensile strength matrix
					}
				}
				
			    printf("\nEnter cross section area of the polymers(a) : ");
				for(j=0;j<3;j++)
				{
					for(k=0;k<1;k++)
					{
						scanf("%f",&a[j][k]);//Cross sectional area matrix
					}
				}
				
				//transpose of matrix a is 1/a
		        printf("\n-------Matrix of transpose 1/a is-------");
				for(j=0;j<1;j++)
				{
					for(k=0;k<3;k++)
					{
						printf("\n%.2fPa",a[k][j]);
					}
				}
				//multiplication of matrix f and a
				
				//Tensile force of 3 polymers is
				for(i=0;i<3;i++)
               	{
		            for(k=0;k<3;k++)
		            {
			            for(j=0;j<1;j++)
			            {
			            	f[i][k]=f[i][k]+ts[i][j]*a[k][j];//Tensile force=Tensile strength*Cross sectional area
			            }
		            }
	            }
	            
	            printf("\n-----------Tensile force of 3 polymers------------\n");
	            for(i=0;i<3;i++)
	            {
		            for(k=0;k<3;k++)
		            {
			            printf("%.2fN  ",f[i][k]);//Tensile force matrix
		            }
		            printf("\n");
		        
	            }
	            //finding the maximum & minimum force among 3 polymers
	            maxforce=f[0][0];
	            minforce=f[0][0];
	            for(i=0;i<3;i++)
	            {
	             	for(k=0;k<3;k++)
	             	{
	             		if(f[i][k]>maxforce)
		                {
			               maxforce=f[i][k];
		                }
		                else if(f[i][k]<minforce)
		                {  
			               minforce=f[i][k];
		                }
					}
	            }
	            printf("\nGreatest tensile force among 3 polymers is : %.2f N",maxforce);
	            printf("\nSmallest tensile force among 3 polymers is: %.2f N",minforce);
	
		    	break;
		    	
		    case 3:
		    	printf("\n|-----------------------Calculating melt flow index(MFI) of a polymer--------------------------|");
		    	printf("\nEnter weight of the sample in grams : ");
		    	scanf("%f",&w);
				printf("\nMFI of the polymer is : %.2f",mfi(w));
		    	
			    break;	
			    
			case 4:
					menu:
					printf("\n|-------------------------Hooke's Law--------------------------|");
					printf("\n1-Create\n2-Display\n3-Insert\n4-Delete\n5-Sort\n6-Matrix X\n7-X matrix\n8-K matrix\n9-F=kx");
					printf("\nEnter your choice : ");
					scanf("%d",&ch2);
					switch(ch2)
					{
						case 1:
							printf("\nEnter how many values of K you want : ");
					        scanf("%d",&z);
					
					        printf("\nEnter the values for k : ");
					        for(i=0;i<z;i++)
					        {
					            scanf("%d",&K[i]);	
					        }
							break;
							
						case 2:
							//display
				          	printf("\nValues of k are : ");
					        for(i=0;i<z;i++)
					        {
						        printf("%5d",K[i]);
					        }
							break;
							
						case 3:
							//insertion
					        printf("\nEnter value and location to insert : ");  
					        scanf("%d %d",&newval,&loc);
					        for(i=newval-1;i>=loc-1;i--)
					        {
						        K[i+1]=K[i];
					        }
					        K[loc-1]=newval;
					        z++;
					        printf("\n%d value of K inserted",newval); 
							break;
							
						case 4:
							temp=K[loc-1];
				            printf("\nEnter value to delete : ");
				            scanf("%d",&z);
				            for(i=loc-1;i<z;i++)
				            {
					            K[i]=K[i+1];
					
				            }
				            z--;
				            printf("\n %d value  deleted from array",newval);
							break;
							
					    case 5:
					    
			                for(i=0;i<z;i++)
				            {
				                for(j=i+1;j<z;j++)
					            {
					                if(K[i]>K[j])
					            	{
						                temp=K[i];
							            K[i]=K[j];
							            K[j]=temp;	
						            }	
					            }	
				            }
							printf("\n Sorted values of k in order are : ");
	                        for(i=0;i<z;i++)
	                        {
		                        printf("%3d",K[i]);
                            }		
					    	break;
					    	
					    case 6:
					    	printf("\n------Matrix of x-------");
					    	printf("\nEnter the number of values of x : ");
					    	scanf("%d",&x);
					    	printf("\nEnter the values of x : ");
					    	for(i=0;i<x;i++)
					    	{
					    		scanf("%3d",&X[i]);
							}
					    	
					    
					    	printf("\nTranspose of matrix x is 1/x");
					    	//Multiplication of matrices,F=kx
					    	//transpose of matrix x=1/x
					    	for(i=0;i<x;i++)
					    	{

					    		printf("\n%2d",X[i]);
								
							}
					    break;
					    
					    case 7:
					    	
					    	transpose(X,x);
					    	break;
					    	
					    case 8:
					    	Kconstant(K,z);
					    	
					        break;
					        
					    case 9:
					      	printf("\nF=kx");
					       	
					       	for(i=0;i<x;i++)
					       	{
					       		for(j=0;j<z;j++)
					       		{
					       			F[i][j]=F[i][j]+transpose(X,x)* Kconstant(K,z);
								}
								   
							   }
					    	
					    	printf("\nF matrix is :");
					    	for(i=0;i<x;i++)
					       	{
					       		for(j=0;j<z;j++)
					       		{
					       			printf("%d",F[i][j]);
								}
								   printf("\n");
							   }
					    	
	                        break;
					    	
					}
					printf("\nTry again press 1:");
					scanf("%d",&ch3);
					if(ch3==1);
					{
						goto menu;
					}
					
			break;   
			
			case 5:
				printf("\n-------------Impact strength-------------");
				printf("\nEnter the energy of impact and thickness of specimen : ");
				scanf("%f,%f",&J,&T);
				I=*p1/ *p2;
				printf("\nImpact strength is : %f kJ/m2",I);
				
				
				break;
				
			case 6:
				printf("\n-------------");
				break;
		}
		printf("\nIf you want to try again press 1 : ");
		scanf("%d",&ch1);
	}while(ch1==1);
	
	return 0;
}

float mfi(float n)
{
	float meltfi;//formula of MFI=weight of polymer in grams/10 minutes
	meltfi=n/10;
	
	return meltfi;
}

int transpose(int U[],int x)
{
	int X[max],y;
	int j;
	int *p3;
	
	p3=&X[j];
	printf("\n------Matrix of x-------");
	printf("\nEnter the number of values of x : ");
	scanf("%d",&y);
	printf("\nEnter the values of x : ");
	for(j=0;j<y;j++)
	{
		scanf("%3d",&X[j]);
	}
					    	
					    
	printf("\nTranspose of matrix x is 1/x");
	//Multiplication of matrices,F=kx
	//transpose of matrix x=1/x
	for(j=0;j<y;j++)
	{
        printf("\n%d",X[j]);
								
	}
	
	return *p3;
}

int Kconstant(int V[],int z )
{
	int K[max],v;
	int i;
	int *p4;
	p4=&K[i]; 
	printf("\nEnter how many values of K you want : ");
	scanf("%d",&v);
					
	printf("\nEnter the values for k : ");
	for(i=0;i<v;i++)
	{
		scanf("%d",&K[i]);	
	}
	
	printf("\n-------K matrix------");
	printf("\n");
	for(i=0;i<v;i++)
	{
		
		printf("%3d",K[i]);
	}
							
	return *p4;					
}






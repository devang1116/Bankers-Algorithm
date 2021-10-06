//
//  main.c
//  Bankers Algo
//
//  Created by Devang Papinwar on 06/10/21.
//

#include <stdio.h>

//int main(int argc, const char * argv[])
//{
//    int processes , resources , finish = 0 , counter = 0 , status;
//    int p, r, i, j, process, count;
//    count = 0;
//
//
//    printf("Enter the Number of Processes : ");
//    scanf("%d",&processes);
//
//    printf("Enter the Number of Resources : ");
//    scanf("%d",&resources);
//
//    int available[resources] , need[processes][resources] , max[processes][resources] , allocated[processes][resources] , safeSequence[processes] , completed[resources];
//
//    for(int i = 0 ; i < processes ; i++)
//    {
//        completed[i] = 0;
//    }
//
//    for(int i = 0 ; i < processes ; i++)
//    {
//        printf("Process %d Max : " , i+1);
//        for(int j = 0 ; j < resources ; j++)
//        {
//            scanf("%d" , &max[i][j]);
//
//        }
//    }
//
//    for(int i = 0 ; i < processes ; i++)
//    {
//        printf("Process %d Allocated : " , i+1);
//        for(int j = 0 ; j < resources ; j++)
//        {
//            scanf("%d" , &allocated[i][j]);
//        }
//    }
//
//    printf("Enter the Available Resources : ");
//    for(int i = 0 ; i < resources ; i++)
//    {
//        scanf("%d" , &available[i]);
//    }
//
//    for(int i = 0 ; i < processes ; i++)
//    {
//        for(int j = 0 ; j < resources ; j++)
//        {
//            need[i][j] = max[i][j] - allocated[i][j];
//            printf("hey");
//        }
//    }
//
//
//    do
//    {
//        printf("\n Max matrix:\tNeed Matrix\tAllocation matrix:\n");
//        for(i = 0 ; i < processes ; i++)
//        {
//            for( j = 0; j < resources ; j++)
//                printf("%d  ", max[i][j]);
//            printf("\t\t");
//            for( j = 0; j < resources ; j++)
//                printf("%d  ", need[i][j]);
//            printf("\n");
//            for( j = 0; j < resources ; j++)
//                printf("%d  ", allocated[i][j]);
//            printf("\n");
//        }
//
//        status = -1;
//
//        for(i = 0; i < processes ; i++)
//        {
//            if(completed[i] == 0)//if not completed
//            {
//                status = i ;
//                for(j = 0 ; j < resources ; j++)
//                {
//                    if(available[j] < need[i][j])
//                    {
//                        status = -1;
//                        break;
//                    }
//                }
//            }
//            if(status != -1)
//                break;
//        }
//
//        if(status != -1)
//        {
//            printf("\nProcess %d runs to completion!", status + 1);
//            safeSequence[count] = status + 1;
//            counter++;
//            for(j = 0; j < resources ; j++)
//            {
//                available[j] += allocated[status][j];
//                allocated[status][j] = 0;
//                need[status][j] = 0;
//                max[status][j] = 0;
//                completed[status] = 1;
//            }
//        }
//    }while(count != processes && status != -1);
//
//    printf("COunt : %d" , &count);
//    if(count >= processes)
//    {
//        printf("\nThe system is in a safe state!!\n");
//        printf("Safe Sequence : < ");
//        for( i = 0; i < processes; i++)
//                printf("%d  ", safeSequence[i]);
//        printf(">\n");
//    }
//    else
//        printf("\nThe system is in an unsafe state!!");
//    return 0;
//}




 
 int main()
 {
 int max[10][10], need[10][10], allocated[10][10], available[10], completed[10], safeSequence[10];
 int processes, resources, i, j, process, count;
 count = 0;

     printf("Enter the Number of Processes : ");
     scanf("%d",&processes);
     
     printf("Enter the Number of Resources : ");
     scanf("%d",&resources);
     
     //int available[resources] , need[processes][resources] , max[processes][resources] , allocated[processes][resources] , safeSequence[processes] , completed[resources];
     
     for(int i = 0 ; i < processes ; i++)
     {
         completed[i] = 0;
     }
     
     for(int i = 0 ; i < processes ; i++)
     {
         printf("Process %d Max : " , i+1);
         for(int j = 0 ; j < resources ; j++)
         {
             scanf("%d" , &max[i][j]);
             
         }
     }
     
     for(int i = 0 ; i < processes ; i++)
     {
         printf("Process %d Allocated : " , i+1);
         for(int j = 0 ; j < resources ; j++)
         {
             scanf("%d" , &allocated[i][j]);
         }
     }
     
     printf("Enter the Available Resources : ");
     for(int i = 0 ; i < resources ; i++)
     {
         scanf("%d" , &available[i]);
     }
     
     for(int i = 0 ; i < processes ; i++)
     {
         for(int j = 0 ; j < resources ; j++)
         {
             need[i][j] = max[i][j] - allocated[i][j];
             printf("hey");
         }
     }
 do
 {
     printf("\n Max matrix:\tAllocation matrix:\n");
     for(i = 0; i < processes; i++)
     {
         for( j = 0; j < resources; j++)
             printf("%d  ", max[i][j]);
         printf("\t\t");
         for( j = 0; j < resources; j++)
             printf("%d  ", allocated[i][j]);
         printf("\n");
     }

     process = -1;

     for(i = 0; i < processes; i++)
     {
         if(completed[i] == 0)//if not completed
         {
             process = i ;
             for(j = 0; j < resources; j++)
             {
                 if(available[j] < need[i][j])
                 {
                     process = -1;
                     break;
                 }
             }
         }
         if(process != -1)
             break;
     }

     if(process != -1)
     {
         printf("\nProcess %d runs to completion!", process + 1);
         safeSequence[count] = process + 1;
         count++;
         for(j = 0; j < resources; j++)
         {
             available[j] += allocated[process][j];
             allocated[process][j] = 0;
             max[process][j] = 0;
             completed[process] = 1;
         }
     }
 }while(count != processes && process != -1);

 if(count == processes)
 {
     printf("\nThe system is in a safe state!!\n");
     printf("Safe Sequence : < ");
     for( i = 0; i < processes; i++)
             printf("%d  ", safeSequence[i]);
     printf(">\n");
 }
 else
     printf("\nThe system is in an unsafe state!!");

 }

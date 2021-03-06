//
//  main.c
//  Bankers Algo
//
//  Created by Devang Papinwar on 06/10/21.
//

#include <stdio.h>

int main()
{
    int processes, resources, process = 0, count = 0;
    
    //MARK: Input
    printf("Enter the Number of Processes : ");
    scanf("%d",&processes);
    
    printf("Enter the Number of Resources : ");
    scanf("%d",&resources);
    
    int max[processes][processes], need[processes][processes], allocated[processes][processes], available[resources], completed[processes], safeSequence[processes];
    
    for(int i = 0 ; i < processes ; i++)
    {
        completed[i] = 0;
    }
    
    for(int i = 0 ; i < processes ; i++)
    {
        printf("Process %d Max Resources : " , i+1);
        for(int j = 0 ; j < resources ; j++)
        {
            scanf("%d" , &max[i][j]);
        }
    }
    
    for(int i = 0 ; i < processes ; i++)
    {
        printf("Process %d Allocated Resources : " , i+1);
        for(int j = 0 ; j < resources ; j++)
        {
            scanf("%d" , &allocated[i][j]);
        }
    }
    
    printf("Enter the Available Resources : ");
    for(int i = 0 ; i < resources ; i++)
    {
        scanf("%d" , &available[i]);
        printf("%d" , available[i]);
    }
    
    // Calculate Process Requirements
    for(int i = 0 ; i < processes ; i++)
    {
        for(int j = 0 ; j < resources ; j++)
        {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    
    int done = processes;
    
    //MARK: Bankers Algorithm
    while(done != 0)
    {
        int safeOrNot = 0;
        
        // iterating over the number of processes
        for(int i = 0 ; i < processes ; i++)
        {
            count = 0;
            
            // if the process hasnt completed its execution
            if(completed[i] == 0)
            {
                for(int j = 0 ; j < resources ; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        count = -1;
                        break;
                    }
                }
                
                // if the current process executed successfully
                if(count == 0)
                {
                    completed[i] = 1;
                    safeOrNot = 1;
                    safeSequence[process++] = i + 1;
                    for(int j = 0 ; j < resources ; j++)
                    {
                        available[j] += allocated[i][j];
                        allocated[i][j] = 0;
                    }
                    done--;
                }
                
                printf("\nMax matrix:\tAllocation matrix:\t\tNeed Matrix\t\tAvailable Matrix\n");
                for(int a = 0; a < processes; a++)
                {
                    for(int b = 0; b < resources; b++)
                        printf("%d  ", max[a][b]);
                    printf("\t\t\t\t");
                    for(int b = 0; b < resources; b++)
                        printf("%d  ", allocated[a][b]);
                    printf("\t\t\t\t");
                    for(int b = 0; b < resources; b++)
                        printf("%d  ", need[a][b]);
                    printf("\t\t\t\t");
                    for(int b = 0; b < resources; b++)
                        printf("%d  ", available[b]);
                    printf("\n");
                }
            }
        }
        
        // if over a loop no change in var then it is in deadlock
        if(safeOrNot == 0)
        {
            break;
        }
    }
    
    printf("%d",done);
    
    //MARK: Conclusion
    if(done == 0)
    {
        printf("\nThe system is in a safe state \n");
        printf("Safe Sequence : ");
        
        for(int i = 0; i < processes; i++)
        {
            printf("%d", safeSequence[i]);
        }
        
        printf("\n");
    }
    else
        printf("\nThe system is in an unsafe state. ");
}

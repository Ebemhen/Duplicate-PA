#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int testCases;
    int num_of_files;

    FILE*fp;
    // open the file  and read first line for the number of test cases N

    fp = fopen("duplicatefiles.txt", "r");
    if (fp == NULL)
    {
        printf("Error, File does not exist");
        exit(0);
    }

    // Read in number of testcases
    fscanf(fp, "%d", &testCases);

    // Print out number of testcases
    printf("Number of test cases:%d \n", testCases);

    // READ IN EACH INPUT IN THE FILE, SPLIT IT AND STORE THE STRING IN ONE ARRAY AND THE INTEGER VALUE IN ANOTHER ARRAY
    for (int i = 0; i < testCases; i++)
    {
        fscanf(fp,"%d", &num_of_files);
        //declaring arrays for filenames and fileIds
        char file_names[num_of_files][50];
        int files_id[num_of_files];
        
        for (int j = 0; j < num_of_files; j++)
        {   
            int newId;
            char file_name[50];
            fscanf(fp, "%s", file_name);
            printf("output: %s\n", file_name);
            int file_exists;

            for (int k = 0; k < num_of_files; k++)
            {
                if (!strcmp(file_names[k],file_name))
                {
                    file_exists = k;
                    break;
            
                }
                else
                {
                    file_exists = -1;
                }

            }
            
            
            fscanf(fp, "%d", &newId);

            
            if (file_exists == -1)
            {
                strcpy(file_names[j], file_name);
                files_id[j] = newId;
            }
            else
            {
                if (files_id[file_exists] <= newId)
                {
                    strcpy(file_names[j], file_name);
                    files_id[j]= -1;
                }
                else
                {
                    strcpy(file_names[j], file_name);
                    files_id[file_exists] = newId;
                    files_id[j] = -1;
                }    
            }
        }  


        //loop to sort the file ids stored, in an ascending order
        int sortId;
        for (int i = 0; i < num_of_files; i++)
        {
            for (int j = i + 1; j < num_of_files; j++)
            {
                if(files_id[i] > files_id[j]){
                    sortId = files_id[i];
                    files_id[i] = files_id[j];
                    files_id[j] = sortId;
                }
            }
            
        }

        //loop to print the file ids
        for(int i= 0; i < num_of_files; i++){
            if (files_id[i] != -1)
            {
                printf("%d\t", files_id[i]);
            }
            
        }
        printf("\n");
    }    
      
    return 0;
}
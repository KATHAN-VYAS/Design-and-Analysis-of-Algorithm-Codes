#include<stdio.h>
#include<string.h>
#include<math.h>

struct node{
    char city[40];
    int x_coord;
    int y_coord;
};

struct node cities[100];
int count = 0;
void insert_data(char city [],int x_coord, int y_coord)
{
    strcpy(cities[count].city,city);
    cities[count].x_coord = x_coord;
    cities[count].y_coord = y_coord;
    count ++;
}
void print_cities()
{
    for (int i = 0 ; i <count ;i ++)
    {
        printf("city :%s | x,y:(%d,%d)\n",cities[i].city,cities[i].x_coord,cities[i].y_coord);
    }
}
void delete_byname(char city[])
{int a = count ; 
    for (int i = 0;i<count; i ++)
    {
        if(strcmp(cities[i].city,city)==0)
        {
            for (int j = i ; j<count-1; j++)
            {
                cities[j] = cities[j+1];
            }
            count--;
            break;
        }
    }
    if (a== count)
    {
        printf("no such city in database\n");
    }
}
void delete_bycoordinates(int x_coord,int y_coord)
{
    int a = count;
    for (int i = 0;i<count; i ++)
    {
        if(cities[i].x_coord == x_coord && cities[i].y_coord == y_coord)
        {
            for (int j = i ; j<count-1; j++)
            {
                cities[j] = cities[j+1];
            }
            count--;
            break;
        }
    }
    if (a == count)
    {
        printf("no such sordinates in database\n");
    } 
}
void print_city_inrange(int a, int b, float distance)
{   printf("cities which are in range of given distance :\n");
    for ( int i = 0; i <count; i ++)
    {
        int p = cities[i].x_coord - a;
        int q = cities[i].y_coord - b;
        float dist = sqrt(p*p + q*q);
        if (distance>=dist)
        {
            printf("%s\n",cities[i].city);
        }
    }
}
void search_byname (char city[])
{
    int flag;
    for(int i = 0; i <count; i ++)
    {
        if (strcmp(cities[i].city, city)==0)
        {
            flag ++;
        }
    }
    if (flag)
    {
        printf("%s is there in database\n",city );
    }
    else 
    {
        printf("no such city found in database\n");
    }
}
void search_bycoordinates (int x , int y)
{
    int flag;
    for(int i = 0; i <count; i ++)
    {
        if (cities[i].x_coord == x && cities[i].y_coord == y)
        {
            flag ++;
        }
    }
    if (flag) 
    {
        printf("%d,%d is there in database\n",x,y);
    }
    else 
    {
        printf("no such coordinates found in database\n");
    }
}
int main() {
    insert_data("Surat", 1,1);
    insert_data("Botad",2,3);
    insert_data("vadodara",3,3);
    insert_data("ahmedabad",34,55);
    insert_data("rajkot",23,2);
    //delete_bycoordinates(2,3);
    //delete_byname("Serat");
    //search_bycoordinates(23,2);
    print_city_inrange(0,0,2);

    //print_cities();

    return 0;
}
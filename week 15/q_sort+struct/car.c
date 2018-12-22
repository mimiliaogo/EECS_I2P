#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct {
    char name[40];
    int score;
    int sn;
} User;
void show(User *u)
{
    printf("%d %s: %d\n", u->sn, u->name, u->score);
}
int cmp1(const void *a, const void *b)
{
    User *pa = (User *)a;
    User *pb = (User *)b;
    return (pa->score)-(pb->score);
}
int cmp2(const void *a, const void *b)
{
    User **pa = (User **)a;
    User **pb = (User **)b;
    return ((*pa)->score)-((*pb)->score);

}
int main()
{
    User *users;
    User* *p_users;
    size_t size = 5; //number of User
    size_t num;
    int i;
    time_t start, end;
    users = (User*) malloc(size*sizeof(User));
    p_users = (User * *) malloc(size*sizeof(User*));
    for (i=0; i<size; i++) p_users[i] = &users[i];
    num = size;
    for (i=0; i<num; i++) {
        users[i].score = rand()%1000;
        users[i].sn = i;
        scanf("%s", users[i].name);
    }
    for (i=0; i<num; i++) show(&users[i]);
    start = clock();
    qsort(users, num, sizeof(User), cmp1);
    end = clock();
    printf("users: %lf\n", (double) end-start);
    for (i=0; i<num; i++) show(&users[i]);
    printf("===============\n");
    start = clock();
    qsort(p_users, num, sizeof(User*), cmp2);
    end = clock();
    printf("pusers: %lf\n", (double) end-start);
    for (i=0; i<num; i++) show(&users[i]);
    free(users);
    free(p_users);
}

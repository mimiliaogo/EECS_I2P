#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct {
  int zipcode;
  char name[15];
} Letter;

int compare(const void *a, const void *b)
{
    Letter*pa = (Letter*)a;
    Letter*pb = (Letter*)b;
    int tempa=0,tempb=0,i=0;
    if (pa->zipcode<pb->zipcode) return -1;
    else if (pa->zipcode>pb->zipcode) return 1;

    else {
        while (pa->name[i]!='\0') {
            if (islower(pa->name[i])) tempa+=pa->name[i]-96;
            else tempa+=pa->name[i]-63;
            i++;
        }
        i = 0;
        while (pb->name[i]!='\0') {
            if (islower(pb->name[i])) tempb+=pb->name[i]-96;
            else tempb+=pb->name[i]-63;
            i++;
        }
        if (tempa<tempb) return 1;
        else if (tempa>tempb) return -1;
        else {
            return (strcmp(pa->name, pb->name));
        }

    }


}

#endif

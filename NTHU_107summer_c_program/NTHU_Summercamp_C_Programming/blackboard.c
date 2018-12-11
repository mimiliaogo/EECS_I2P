#include <stdio.h>
int main()
{
    /*123.456
    321.654&*/

    float n;
    int n_ger;
    int d_1, d_10, d_100;
    int n_floi;
    float n_flo;
    float sum;

    scanf("%f", &n);
    n_ger = (int)n;
    n_flo = n - n_ger;
    n_floi = 1000*n_flo;
    d_100 = n_ger/100;
    d_1 = n_ger%100%10;
    d_10 = n_ger%100-d_1;
    sum = d_100+d_10+100*d_1;
    d_100 = n_floi/100;
    d_1 = n_floi%100%10;
    d_10 = n_floi%100-d_1;
    sum = 1000*sum +d_100+d_10+100*d_1;
    sum  = sum/1000;
    printf("%0.3f", (sum+n)/2);




    return 0;
}

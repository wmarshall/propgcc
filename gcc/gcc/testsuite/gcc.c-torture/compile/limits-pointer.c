/* { dg-xfail-if "" { alpha*-dec-osf5* } { "-g" } { "" } } */
#define PTR1 * * * * * * * * * *
#define PTR2 PTR1 PTR1 PTR1 PTR1 PTR1 PTR1 PTR1 PTR1 PTR1 PTR1
#define PTR3 PTR2 PTR2 PTR2 PTR2 PTR2 PTR2 PTR2 PTR2 PTR2 PTR2
#define PTR4 PTR3 PTR3 PTR3 PTR3 PTR3 PTR3 PTR3 PTR3 PTR3 PTR3
#define PTR5 PTR4 PTR4 PTR4 PTR4 PTR4 PTR4 PTR4 PTR4 PTR4 PTR4
#define PTR6 PTR5 PTR5 PTR5 PTR5 PTR5 PTR5 PTR5 PTR5 PTR5 PTR5

int PTR4 q3_var = 0;

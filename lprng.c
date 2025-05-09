/*
Lepore Pseudo-Random Number Generator (LPRNG) is free software
Lepore Pseudo-Random Number Generator (LPRNG)  is Alberico Lepore creation
this file is free software
The Lepore Pseudo-Random Number Generator (LPRNG)  is free software; you can redistribute it and/or modify
it under the terms of either:
    the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.
You should have received copies of the
GNU Lesser General Public License here https://www.gnu.org/licenses/.
*/



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gmp.h>

int prendi_numero(char in[]);


int main() {
  mpz_t M,copia_M,N, N_squared, X, mod_base, power, a, k, i,comp,count_0,count_pari,count_dispari,salto,parity;
    
    // Inizializzazione delle variabili GMP
    mpz_init(M);
    mpz_init(copia_M);
    mpz_init(N);
    mpz_init(N_squared);
    mpz_init(X);
    mpz_init(mod_base);
    mpz_init(power);
    mpz_init(a);
    mpz_init_set_str(count_0,"0", 10);
    mpz_init_set_str(count_pari,"0", 10);
     mpz_init_set_str(count_dispari,"0", 10);
    mpz_init_set_str(salto,"1", 10);
     mpz_init(parity);
     
    char numero_M[10000];/*set this value*/
    prendi_numero(numero_M);
    mpz_init_set_str(M, numero_M, 10);
    mpz_init_set_str(i,"0", 10);
    
    gmp_printf ("\ninput=%Zd\n",M);
    // Lettura dell'input k da terminale
    gmp_printf("Enter the number of random TRUE FALSE bits you want to generate: ");
    gmp_scanf("%Zd", k);
    //mpz_mul_ui(k,k,2);
    //mpz_set(copia_M,M);

    while(mpz_cmp(i,k)<0){
      mpz_add_ui(salto,salto,1);
      mpz_add(M,M,salto);
      mpz_set(comp,M);
    mpz_mul(N,M,M);
    

    // Calcolo di M^2
    mpz_mul(N_squared, N, N);

    // Calcolo del modulo di base 2*M^2
    mpz_mul_ui(mod_base, N_squared, 2);

    // Calcolo di 2^(M^2) mod (2*M^2) usando mpz_powm
    mpz_set_ui(power, 2); 
    mpz_powm(power, power, N_squared, mod_base); // 2^(M^2) mod (2*M^2)

    // Calcolo finale di X = (2^(M^2) - 2) mod (2*M^2)
    mpz_sub_ui(X, power, 2);

    // Determinazione di a = GCD(X, M)
    mpz_gcd(a, X, N);

    // Stampa dei risultati
    gmp_printf("N^2 = %Zd\n", N_squared);
    gmp_printf("X = %Zd\n", X);
    gmp_printf("GCD(X, N) = %Zd\n", a);
    if(mpz_cmp(comp,a)==0 ){
      mpz_mod_ui(parity,count_0,2);
      if(mpz_cmp_ui(parity,0)==0){
	mpz_add_ui(count_pari,count_pari,1);
	printf("\n0\n");
      }else{
	mpz_add_ui(count_dispari,count_dispari,1);
	printf("\n1\n");
      }
      mpz_set_ui(count_0,0);
      mpz_add_ui(i,i,1);
      mpz_set_ui(salto,1);
    }else{
      mpz_add_ui(count_0,count_0,1);
      mpz_set(salto,a);
    }
    
    
    }
    gmp_printf("\nTRUE = %Zd\nFALSE = %Zd\n", count_dispari,count_pari);
    return 0;
}


int prendi_numero(char in[]){

    char decimale[1000];
    int numero_di_cifre_decimali=0;
    FILE *fp;
    int i=0;

    fp = fopen("input0.txt", "r");
    if (fp==NULL){
        printf("\nImpossibile aprire file\n");
        system("PAUSE");
        exit(1);
    }
    while(!feof(fp)){
        fscanf(fp,"%s",decimale);

    }
    fclose(fp);

    numero_di_cifre_decimali=strlen(decimale)-1;
    while(i<=numero_di_cifre_decimali){
        in[i]=decimale[i];
        i++;
    }
    return numero_di_cifre_decimali;
}

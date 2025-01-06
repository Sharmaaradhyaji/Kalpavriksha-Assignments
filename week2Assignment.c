#include <stdio.h>

long long evaluate(long long base, long long int powerOfBase, long long modulus){
    if (powerOfBase==0) 
        return 1%modulus; 
    long long answer=evaluate(base,powerOfBase/2,modulus);  
    answer=(answer*answer)%modulus;
    if(powerOfBase%2==1) 
        answer=(answer*base)%modulus;
    return answer;
}

int main(){
    long long base, powerOfBase, modulus;
    printf("Base: ");
    scanf("%lld", &base);
    printf("Exponent: ");
    scanf("%lld", &powerOfBase);
    printf("Modulus: ");
    scanf("%lld", &modulus);
    if(modulus<=1){
        printf("Invalid input: Modulus must be > 1\n");
        return 1;
    }
    if(base<=0){
        printf("Invalid input: Base must be > 1\n");
    }
    printf("Result: %lld\n", evaluate(base, powerOfBase, modulus));
    return 0;
}

#include <stdio.h>

long long evaluate(long long base, long long int pow, long long mod){
    if (pow==0) 
        return 1%mod; 
    long long ans=evaluate(base,pow/2,mod);  
    ans=(ans*ans)%mod;
    if(pow%2==1) 
        ans=(ans*base)%mod;
    return ans;
}

int main(){
    long long base, pow, mod;
    printf("Base: ");
    scanf("%lld", &base);
    printf("Exponent: ");
    scanf("%lld", &pow);
    printf("Modulus: ");
    scanf("%lld", &mod);
    if(mod<=1){
        printf("Invalid input: Modulus must be > 1\n");
        return 1;
    }
    if(base<=0){
        printf("Invalid input: Base must be > 1\n");
    }
    printf("Result: %lld\n", evaluate(base, pow, mod));
    return 0;
}
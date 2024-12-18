#include <stdio.h>

int precedence(char operator) {
    if (operator == '*' || operator == '/') {
        return 2;  
    } 
    else if (operator == '+' || operator == '-') {
        return 1; 
    }
    return 0;  
}

int main(){
    char inputString[100];
    char operatorStack[100];
    int operandStack[100];
    int topOperator = -1;
    int topOperand = -1;

    printf("Input string for calculation.\n");
    scanf(" %[^\n]", inputString);

    int i=0;
    while (inputString[i]!='\0')
    {
        if(inputString[i]>='0' && inputString[i]<='9'){
            int num = 0;
            while(inputString[i]>='0' && inputString[i]<='9'){
                num = num * 10 + (inputString[i] - '0');
                i++;
            }
            operandStack[++topOperand] = num;
        
        }
        else if(inputString[i]=='+' || inputString[i]=='-' ||inputString[i]=='*' ||inputString[i]=='/'){
            int currentOperator = inputString[i];
            while (topOperator>=0)
            {
                if(precedence(currentOperator)<=precedence(operatorStack[topOperator])){
                    char operator = operatorStack[topOperator];
                    topOperator--;
            
                if (operator=='+')
                {
                    int b=operandStack[topOperand--];  
                    int a= operandStack[topOperand--]; 
                    operandStack[++topOperand] = a+b; 
                }
                else if (operator=='-')
                {
                    int b= operandStack[topOperand--];
                    int a = operandStack[topOperand--];
                    operandStack[++topOperand] = a - b;
                    
                }                     
                else if (operator=='*')
                {
                    int b= operandStack[topOperand--];
                    int a= operandStack[topOperand--];
                    operandStack[++topOperand] = a*b;
                }                     
                else 
                {
                    int b= operandStack[topOperand--];
                    int a= operandStack[topOperand--];
                    operandStack[++topOperand] = a / b;
                }                     
            }
            }
            operatorStack[++topOperator] = currentOperator;
           
            i++;
        }
        else if (inputString[i]==' ')
        {
            i++;
        }
        
        else{
            printf("Invalid Expression. ");
            return 1;
        } 
    }

    while (topOperator >= 0) {
        char operator = operatorStack[topOperator--];
        
        int b = operandStack[topOperand--];
        int a = operandStack[topOperand--];
        if (operator == '+') {
            operandStack[++topOperand] = a+b;
        }
        else if(operator== '-') {
            operandStack[++topOperand] = a- b;
        
        } else if (operator=='*') {
            operandStack[++topOperand] = a *b;
        }else if(operator =='/') 
        {
            if (b==0) {
                printf("Error: Division by zero.");
                return 1;
            }
            operandStack[++topOperand] =a/b;
        }

    }
    
    printf("Result is %d", operandStack[topOperand]);

    return 0;
}
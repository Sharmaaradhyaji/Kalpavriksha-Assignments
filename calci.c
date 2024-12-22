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

    int counter=0;
    int firstOperand;
    int secondOperand;
    while (inputString[counter]!='\0')
    {
        if(inputString[counter]>='0' && inputString[counter]<='9'){
            int num = 0;
            while(inputString[counter]>='0' && inputString[counter]<='9'){
                num = num * 10 + (inputString[counter] - '0');
                counter++;
            }
            operandStack[++topOperand] = num;
        
        }
        else if(inputString[counter]=='+' || inputString[counter]=='-' ||inputString[counter]=='*' ||inputString[counter]=='/'){
            int currentOperator = inputString[counter];
            while (topOperator>=0)
            {
                if(precedence(currentOperator)<=precedence(operatorStack[topOperator])){
                    char operator = operatorStack[topOperator];
                    topOperator--;
                    
                if (operator=='+')
                {
                    secondOperand=operandStack[topOperand--];  
                    firstOperand= operandStack[topOperand--]; 
                    operandStack[++topOperand] = firstOperand+secondOperand; 
                }
                else if (operator=='-')
                {
                    secondOperand= operandStack[topOperand--];
                    firstOperand = operandStack[topOperand--];
                    operandStack[++topOperand] = firstOperand - secondOperand;
                    
                }                     
                else if (operator=='*')
                {
                    secondOperand= operandStack[topOperand--];
                    firstOperand= operandStack[topOperand--];
                    operandStack[++topOperand] = firstOperand*secondOperand;
                }                     
                else 
                {
                    secondOperand= operandStack[topOperand--];
                    firstOperand= operandStack[topOperand--];
                    operandStack[++topOperand] = firstOperand / secondOperand;
                }                     
            }
            }
            operatorStack[++topOperator] = currentOperator;
           
            counter++;
        }
        else if (inputString[counter]==' ')
        {
            counter++;
        }
        
        else{
            printf("Invalid Expression. ");
            return 1;
        } 
    }

    while (topOperator >= 0) {
        char operator = operatorStack[topOperator--];
        
        secondOperand = operandStack[topOperand--];
        firstOperand = operandStack[topOperand--];
        if (operator == '+') {
            operandStack[++topOperand] = firstOperand+secondOperand;
        }
        else if(operator== '-') {
            operandStack[++topOperand] = firstOperand- secondOperand;
        
        } else if (operator=='*') {
            operandStack[++topOperand] = firstOperand *secondOperand;
        }else if(operator =='/') 
        {
            if (secondOperand==0) {
                printf("Error: Division by zero.");
                return 1;
            }
            operandStack[++topOperand] =firstOperand/secondOperand;
        }

    }
    
    printf("Result is %d", operandStack[topOperand]);

    return 0;
}

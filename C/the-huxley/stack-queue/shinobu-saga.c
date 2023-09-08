#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
STACK* Create_stack()
{
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->head = NULL;
    return stack;
}

NODE* create_node(int element)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->element = element;
    node->next = NULL;
    return node;
}

int IS_EMPTY(STACK* stack)
{
    return (stack->head == NULL);
}

int POP(STACK* stack)
{
    if (IS_EMPTY(stack))
    {
        printf("Erro: A pilha est� vazia.\n");
        exit(EXIT_FAILURE);
    }
    
    NODE* temp = stack->head;
    int element = temp->element;
    stack->head = temp->next;
    free(temp);
    return element;
}

void PUSH(STACK* stack, int element)
{
    NODE* node = create_node(element);
    node->next = stack->head;
    stack->head = node;
}

void result(STACK* stack, char operation)
{
    int operand2 = POP(stack);
    int operand1 = POP(stack);
    int result;

    switch (operation)
    {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Erro: Opera��o inv�lida.\n");
            exit(EXIT_FAILURE);
    }

    PUSH(stack, result);
}

void Calculadora(STACK* calculadora, int size)
{
    for (int i = 0; i < size; i++)
    {
        char expression[10];
        scanf("%s", expression);
        
        int is_digit = 1;

        for (int j = 0; expression[j] != '\0'; j++)
        {
            if (expression[j] < '0' || expression[j] > '9')
            {
                is_digit = 0;
                break;
            }
        }

        if (is_digit)
        {
            int value = atoi(expression);
            PUSH(calculadora, value);
        }
        else
        {
            result(calculadora, expression[0]);
        }
    }
}

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
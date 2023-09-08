#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int nota;
    int posicao;
} Student;

int compGrade(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->nota - studentA->nota;
};

int main() {
    int N;
    scanf("%d", &N);

    int i = 0;
    while (i < N) {
        int M;
        scanf("%d", &M);

        Student alunos[M];

        for (int i = 0; i < M; i++) {
            scanf("%d", &alunos[i].nota);
            alunos[i].posicao = i;
        }

        qsort(alunos, M, sizeof(Student), compGrade);

        int naoPrecisouTrocar = 0;
        for (int i = 0; i < M; i++) {
            if (alunos[i].posicao == i) {
                naoPrecisouTrocar++;
            }
        }
        printf("%d\n", naoPrecisouTrocar);
        i++;
    }

    return 0;
};
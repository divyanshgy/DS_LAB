#include <stdio.h>
#include <stdlib.h>


struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
};


struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = newTerm;
    newTerm->prev = newTerm;
    return newTerm;
}

void insertAfter(struct Term* term, struct Term* newTerm) {
    newTerm->next = term->next;
    newTerm->prev = term;
    term->next->prev = newTerm;
    term->next = newTerm;
}

struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* current1 = poly1;
    struct Term* current2;

    do {
        current2 = poly2;
        do {
            int coefficient = current1->coefficient * current2->coefficient;
            int exponent = current1->exponent + current2->exponent;

            struct Term* newTerm = createTerm(coefficient, exponent);
            if (result == NULL) {
                result = newTerm;
            } else {
                struct Term* currentResult = result;
                do {
                    if (currentResult->exponent == exponent) {
                        currentResult->coefficient += coefficient;
                        free(newTerm);
                        break;
                    }
                    if (currentResult->exponent < exponent) {
                        insertAfter(currentResult, newTerm);
                        break;
                    }
                    currentResult = currentResult->next;
                } while (currentResult != result);
            }

            current2 = current2->next;
        } while (current2 != poly2);

        current1 = current1->next;
    } while (current1 != poly1);

    return result;
}


void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Term* current = poly;
    int firstTerm = 1;
    do {
        if (current->coefficient != 0) {
            if (firstTerm) {
                firstTerm = 0;
                if (current->coefficient < 0) {
                    printf("-");
                }
            } else {
                if (current->coefficient > 0) {
                    printf("+");
                }
            }
            printf("%d", abs(current->coefficient));
            if (current->exponent > 0) {
                printf("x");
                if (current->exponent > 1) {
                    printf("^%d", current->exponent);
                }
            }
        }
        current = current->next;
    } while (current != poly);

    printf("\n");
}


void freePolynomial(struct Term* poly) {
    if (poly == NULL) {
        return;
    }

    struct Term* current = poly->next;
    while (current != poly) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }

    free(poly);
}

int main() {
    struct Term* poly1 = createTerm(0, 0);
    struct Term* poly2 = createTerm(0, 0);

    int coefficient, exponent;
    int numTerms;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        struct Term* newTerm = createTerm(coefficient, exponent);
        insertAfter(poly1, newTerm);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        struct Term* newTerm = createTerm(coefficient, exponent);
        insertAfter(poly2, newTerm);
    }

    struct Term* result = multiplyPolynomials(poly1->next, poly2->next);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}

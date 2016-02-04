 #include <stdio.h>
  #include <stdlib.h>
  int top = -1, size;

  /* push the given data into the stack */
  void push(int *stack, int data) {
        if (top >= size - 1) {
                printf("Stack Overflow\n");
                return;
        }
        top++;
        stack[top] = data;
        printf("Pushed %d into the stack!!\n", stack[top]);
        return;
  }

  /* pop the top element from the stack */
  void pop(int *stack) {
        if (top <= -1) {
                printf("Stack Underflow!!\n");
                return;
        }
        printf("Popped %d from the stack!!\n", stack[top]);
        stack[top] = 0;
        top--;
        return;
  }

  /* dumps the stack contents */
  void dumpStack(int *stack) {
        int i;
        if (top == -1) {
                printf("Stack Underflow!!\n");
                return;
        }
        printf("Stack:\n");
        for (i = top; i >= 0; i--) {
                printf("%d -> ", stack[i]);
        }
        printf("NULL\n");
        return;
  }

  int main() {
        int *stack, ch, data;

        /* get the size of the stack from the user */
        printf("Enter the size of the stack:");
        scanf("%d", &size);

        /* allocate memory for the stack */
        stack = (int *)malloc(sizeof(int) * size);

        while (1) {
                printf("1. Push\n2. Pop\n3. Dump Stack\n");
                printf("4. Exit\nEnter your choice:");
                scanf("%d", &ch);

                switch (ch) {
                        case 1:
                                /* push given data into the stack */
                                printf("Enter your i/p to push:");
                                scanf("%d", &data);
                                push(stack, data);
                                break;
                        case 2:
                                /* pops first element from the stack */
                                pop(stack);
                                break;
                        case 3:
                                /* dump the stack contents */
                                dumpStack(stack);
                                break;

                        case 4:
                                exit(0);
                        default:
                                printf("Wrong Option!!\n");
                                break;
                }
        }

        return 0;
  }
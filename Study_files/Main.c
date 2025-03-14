#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 100

// void swap(int* a, int* b){
//     // 이 함수는 Main함수의 배열실습 3(내림차순 정렬)에 필요한 swap함수이다.
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void test(int* p, char* cp)
// {
//     printf("test : p = %p, cp = %p\n", p, cp);
//     test : p = 0x7fff840d4d0c;
//     cp = 0x7fff840d4d0b;
//     *p = 60;
//     p++;
//     cp++;
// }

// void inputRandomArray(int* array, int size)
// {
//     for(int i=0; i<size; i++){
//         *(array+i) = rand() % 100;
//     }
// }

// void printArray(int* array, int size)
// {
//     for(int i=0; i<size; i++){
//         printf("%3d\n", *(array+i));
//         if((i+1) % 10 == 0){
//             printf("\n");
//         }
//     }
// }

// 구조체 실습 
/*
typedef struct point{
    int x;
    int y;
}POINT;
*/

/*
void input_random_point(POINT* p, int size)
{
    srand(((time(NULL))));
    for(int i=0; i<SIZE; i++){
        (p+i)->x = rand() % 101;
        (p+i)->y = rand() % 101;
    }
}

void swap_point(POINT* p1, POINT* p2)
{
    POINT temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void print_pointer_array(POINT p[], int size){
    for(int i=0; i<size; i++){
        printf("p[%3d] : (%3d, %3d)\n", i, p[i].x, p[i].y);
    }
}

void selection_sort_point(POINT* point, int size){
    int least;
    for(int i=0; i<SIZE; i++){
    printf("point[%d] : (%d, %d)\n", i, point[i].x, point[i].y);
    }
    for(int i=0; i<SIZE; i++){
        least = i;
        for(int j=i+1; j<SIZE; j++){
            if(point[least].x > point[j].x) least = j;
            else if((point+least)->x == point[j].x && point[least].y > point[j].y){
                least = j;
            }
        }
        swap_point(&point[i], point + least);
    }
}
*/

// typedef struct circle{
//     POINT center;   // 원의 중심
//     double radius;  // 반지름
// }CIRCLE;

// typedef struct rect{
//     POINT lb;   // left bottom
//     POINT rt;   // right top
// }RECT;

// double dist(POINT p1, POINT p2){
//     return sqrt(pow((p2.x - p1.x),2)+pow((p2.y - p1.y),2));
// }

// 10주차 바이너리 실습3
/*
typedef struct point{
    int x;
    int y;
}POINT;
POINT makePoint(void){
    POINT p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}
void makeRandomPoints(POINT p[], int size){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}
void printPoints(POINT p[], int size){
    for(int i=0; i<size; i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}
void saveFILE(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if(fp == NULL) exit(-1);
    fwrite(p, sizeof(POINT), size, fp);
    fclose(fp);
}
void loadFILE(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if(fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);
    fclose(fp);
}
*/

// 11주차 동적할당 활용 1~2(함수화, 메뉴추가)
typedef struct point{
    int x;
    int y;
}POINT;

int inputMenu(void){
    int input;
    printf("메 뉴 입 력 ================");
    printf("1. 만들기, 2.출력하기, 3. 클리어, 4. 파일저장, 5. 파일로드, -1. 종료 : ");
    scanf("%d", &input);
    return input;
}

POINT* makePoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));
        p->x = rand() % 100;
        p->y = rand() % 100; 
        return p;
}

void printPoint(POINT* p[], int size){
    for(int i=0; i<size; i++){
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
    }
}

void freePoints(POINT* p[], int size){
    for(int i=0; i<size; i++){
        free(p[i]);
    }
}

int saveFile(POINT* p[], int count){
    FILE* fp;
    fp = fopen("points.bin", "ab");
    if(fp == NULL) return 0;
    for(int i=0; i<count; i++){
        fwrite(p[i], sizeof(POINT), 1, fp);
    }
    fclose(fp);
    return 1;
}

int loadFile(POINT* p[], int max){
    FILE* fp;
    int fSize, fCount;
    fp = fopen("points.bin", "rb");
    if(fp == NULL) return 0;

    fseek(fp, 0, SEEK_END);
    fSize = ftell(fp);
    fCount = fSize / sizeof(POINT);
    return(fp);

    for(int i=0; i<fCount; i++){
        if(i == max) break;
        p[i] = (POINT*)malloc(sizeof(POINT));
        fread(p[i], sizeof(POINT), 1, fp);
    }
    fclose(fp);
    return fCount;
}

int main()
{
    /* int i = 0;
    // i = rand();
    // printf("i = %d", i);

    // repaet 10 times
    // int number[10];

    // srand(time(NULL));

    // for (int i = 0; i < 10; i++)
    // {
    //     number[i] = (rand() % 100) + 1;
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("random_number = %d\n", number[i]);
    // }

    // int rand() 와 void srand()의 차이점
    // > int rand가 동일한 seed를 가지고 0부터 RAND_MAX 사이의 의사 난수를 반환한다면
    // > void srand는 seed를 초기화한다. 보통 seed는 time(NULL)로 설정된다.

    // number를 변수로 만드는 것보다, number[n]의 리스트 형태로 정의하면 할 수 있는 작업들이 많아진다.

    // -> srand를 이용한 난수 출력, 평균, 최대, 최소 구하기 (재열 실습2)
    // int number[SIZE];
    // int total = 0;
    // int max, min;
    // float avg = 0.0;
    // srand(time(NULL));
    // for (int i=0; i<SIZE; i++){
    //     number[i] = (rand() % 100) + 1;
    // }
    // for(int i=0; i<SIZE; i++){
    //     printf("%3d\t", number[i]);
    //     if((i+1) % 10 == 0) {
    //         printf("\n");
    //     }
    // }
    // for(int i=0; i<SIZE; i++){
    //     total += number[i];
    // }
    // avg = (float)total / SIZE;

    // max = number[0];
    // min = number[0];

    // for(int i=1; i<SIZE; i++){
    //     if(max < number[i]){
    //         max = number[i];
    //     }
    //     if(max > number[i]){
    //         min = number[i];
    //     }
    // }
    // printf("avg = %f, max = %d, min = %d", avg, max, min);
    */

    // 배열 실습3
    // 내림차순 정렬
    // int number[SIZE] = {0};
    // int most;
    // int temp;
    // srand(time(NULL));

    // for (int i=0; i<SIZE; i++){
    //     number[i] = (rand() % 100) + 1;
    // }

    // for (int i=0; i<SIZE-1; i++){
    //     most = i;
    //     for (int j = i+1; j < SIZE; j++){
    //         if(number[most] < number[j]){
    //             most = j;
    //         }
    //     }
    //     swap(&number[i], &number[most]);
    // }

    // for(int i=0; i<SIZE; i++){
    //     printf("%3d\t", number[i]);
    //     if((i+1) % 10 == 0) {
    //         printf("\n");
    //     }
    // }

    // test 함수
    // int a = 50;
    // char ch = '*';
    // printf("main : a = %d, ch = %d\n", a, ch);
    // main : a = 50, ch = 42;
    // test(&a, &ch);

    // int number[SIZE];
    // srand(time(NULL));
    // inputRandomArray(&number[0], SIZE);
    // printArray(number, SIZE);

    // 문자열 입문
    // char Message2[5] = {'a', 'b', 'c', 'd', 'e'};
    // char Message[5] = {'a', 'b', 'c', '\0'};
    
    // printf("message = %s, message2 = %s", Message, Message2);

    // int ch;
    // char message[100];
    // int i = 0;
    // while((ch = getchar()) != '\n'){
    //     message[i++] = ch;
    // }
    // message[i] = '\0';
    // printf("%s", message);

    // char input[200] = "";
    // int count[26] = {0};
    // int ch;
    // int i = 0;
    
    // while((ch = getchar()) != EOF){
    //     input[i++] = ch;
    // }
    // i = 0;
    // while(input[i] != '\0'){
    //     if(input[i] >= 'a' && input[i] <= 'z'){
    //         count[input[i] - 'a']++;
    //     }
    //     i++;
    // }
    
    // printf("입력문자열 : %s\n", input);
    // for(int i=0;i<26;i++){
    //     printf("%c 출연횟수 : %d\n", 'a' + i, count[i]);
    // }

    // CIRCLE c1 = {{10, 10}, 4.5};
    // CIRCLE c2;
    // c2.radius = 5.5;
    // c2.center.x = 10;
    // c2.center.y = 20;
    // POINT point = {10,15};
    // double distance;

    // printf("CIRCLE1 = (%d, %d), r : %lf\n", c1.center.x, c1.center.y, c1.radius);
    // printf("CIRCLE2 = (%d, %d), r : %lf\n", c2.center.x, c2.center.y, c2.radius);
    // printf("point = (%d, %d)\n", point.x, point.y);

    // distance = dist(c1.center, point);
    // if(distance <= c1.radius){
    //     printf("원 안에 있습니다.\n");
    // }else{
    //     printf("원 밖체 있습니다.\n");
    // }

    // POINT point[SIZE] = {0};
    // POINT temp = {0, 0};
    // int least;

    // input_random_point(point, SIZE);
    // print_pointer_array(point, SIZE);
    // selection_sort_point(point, SIZE);
    // printf("after sorting>>>>>>>>>>>>>>\n");
    // print_pointer_array(point, SIZE);
    // return 0;

    // 10주차 바이너리 실습1
    /*
    char input[SIZE];
    FILE* fp = NULL;
    int i = 0;

    if((fp = fopen("output.bin", "wb")) == NULL){
        printf("error...");
        return 0;
    }
    while(!feof(fp)){
        fread(&input[i], sizeof(char), 1, fp);
        i++;
    }
    input[--i] = '\0';
    puts(input);

    fclose(fp);
    */

    // 10주차 바이너리 실습2
    /*
    int array[1000];
    FILE* fp;
    int i = 0;
    fp = fopen("array.bin", "wb");
    if(fp == NULL) return -1;

    fread(&array, sizeof(int), 100, fp);

    for(int i=0; i<100; i++) printf("%d", array[i]);
    fclose(fp);
    */

    // 10주차 바이너리 실습3
    /*
    FILE* fp;
    POINT p[10];
    POINT p2;
    int pi;
    //vmakeRandomPoints(p, 10);
    loadFILE(p, 10);
    printPoints(p, 10);
    // saveFILE(p, 10);

    fp = open("struct.bin", "rb");
    if(fp == NULL) exit(-1);
    fseek(fp, sizeof(POINT)*3, SEEK_SET);
    pi = ftell(fp);
    printf("pi = %d\n", pi);
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    fseek(fp, sizeof(POINT)*-1, SEEK_END);
    printf("pi = %d\n", ftell(fp));
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    fseek(fp, 0, SEEK_END);
    printf("size = %ld\n", ftell(fp));
    fclose(fp);
    */

    // 11주차 동적할당 실습
    /*
    char* pChar;
    int* pInt;
    int count;

    scanf("%d", &count);
    pInt = (int*)malloc(count*sizeof(int));

    for(int i=0; i<count; i++) pInt[i] = rand() % 100;
    for(int i=0; i<count; i++) printf("%d ", pInt[i]);

    pChar = (char*)pInt;

    while(getchar() != '\n');
    gets(pChar);
    puts(pChar);

    free(pInt);
    */

    // 11주차 동적할당 활용 1~3(함수화, 메뉴추가)
    int menu;
    int count;
    POINT* points[100];

    do{
        menu = inputMenu();
        switch(menu){
            case 1:
                points[count] = makePoint();
                count++;
                break;
            case 2:
                printPoint(points, count);
                break;
            case 3:
                system("clear"); // Windows = system("cls");
                break;
            case 4: // file save
                if(!saveFile(points, count)){
                    printf("file open error...\n");
                }else {
                    printf("file writing success...\n");
                }
                break;
            case 5: // load file
                count = loadFile(points, 100);
                break;
            case -1:
                freePoints(points, count);
                printf("프로그램을 종료합니다.\n");
                break;
        }
    }while(menu > 0);

    /*
    POINT* points;
    int count;
    scanf("%d", &count);

    points = (POINT*)malloc(sizeof(POINT) * count);

    for(int i=0; i<count; i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    for(int i=0; i<count; i++){
        printf("x = %d, y - %d\n", points[i].x, points[i].y);
    }
    free(points);
    */
    return 0;
}
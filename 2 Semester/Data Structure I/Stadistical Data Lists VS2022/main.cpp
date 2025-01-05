// Author: reDragonCoder

//LIBRARIES
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//GLOBAL CONSTANTS
#define vTile 32 

//DEFINITIONS
typedef int type;

typedef struct Element{
    type data;
    struct Element* left;
    struct Element* right;
}Node;

Node* start;
Node* end;

//PROTOTYPES
void statData();
float media();
float median();
int mode();
float variance(float median);
float standDev(float variance);
void null(int vec[]);
Node* createNode(type x, Node* l, Node* r);
void showList(void);
void insertEnd(type x);
bool isEmpty(void);
void freeMemory(void);

//MAIN
int main(){ 
    end=start=NULL;
    end=start=createNode(6, NULL, NULL);
    insertEnd(1);
    insertEnd(4);
    insertEnd(5);
    insertEnd(2);
    insertEnd(3);
    insertEnd(2);
    showList();
    statData();
    freeMemory();
    return 0;
}

//IMPLEMENTATIONS
void statData(){
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_DISPLAY* display = al_create_display(660, 660);
    ALLEGRO_FONT* font = al_load_ttf_font("Minecraft.ttf", 24, 0);
    al_clear_to_color(al_map_rgb(128, 128, 128));

    //Media
    float showMedia;
    showMedia=media();
    al_draw_textf(font, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_LEFT, "Media: %.2f ", showMedia); 

    //Mediana
    float showMedian;
    showMedian=median();
    al_draw_textf(font, al_map_rgb(255, 255, 255), 100, 150, ALLEGRO_ALIGN_LEFT, "Median: %.2f ", showMedian); 

    //Moda
    int showMode;
    showMode=mode();
    if(showMode==0){
        al_draw_textf(font, al_map_rgb(255, 255, 255), 100, 200, ALLEGRO_ALIGN_LEFT, "Mode: does not exists"); 
    }else{
        al_draw_textf(font, al_map_rgb(255, 255, 255), 100, 200, ALLEGRO_ALIGN_LEFT, "Mode: %d ", showMode); 
    }

    //Varianza
    float showVariance;
    showVariance=variance(showMedian);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 100, 250, ALLEGRO_ALIGN_LEFT, "Variance: %.2f ", showVariance); 

    //Desviacion estandar
    float showstandDev;
    showstandDev=standDev(showVariance);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 100, 300, ALLEGRO_ALIGN_LEFT, "Standard deviation: %.2f ", showstandDev); 

    al_flip_display();
    al_rest(120);

    al_destroy_font(font);
    al_destroy_display(display);
}

//STADISTICAL DATA
float media(){
    Node* q=start;
    float addList=0, counter=0;
    float media=0;

    //Media 
    while(q!=NULL){
        addList+=q->data;
        counter++;
        q=q->right;
    }
    media=addList/counter;
    return media;
}

float median(){
    Node *aux=start;
    int vec[300];
    int x=0, temp=0, intHalf=0;
    float half=0, xCopy=0,  median=0, addition=0;
    null(vec);
    while(aux){
        vec[x]=aux->data;
        aux=aux->right;
        x++;
    }
    for(int i=0; i<x-1; i++){
        for(int j=0; j<x-i-1; j++) {
            if(vec[j]>vec[j+1]) {
                temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }
    for(int i=0; i<x; i++) { //temp
        printf("%d ",vec[i]);
    }
    xCopy=x;
    half=xCopy/2;
    if(half=(int)half){
        intHalf=half-1;
        addition+=vec[intHalf];
        intHalf++;
        addition+=vec[intHalf];
        median=addition/2;
    }
    else if(half!=(int)half){
        half+=0.5;
        intHalf=half;
        median=vec[intHalf];
    }
    return median;
}

int mode(){
    Node *aux=start;
    int vec[300];
    int x=0, temp=0, mode=0, count=0, maxCount=0;
    null(vec);
    while(aux){
        vec[x]=aux->data;
        aux=aux->right;
        x++;
    }
    for(int i=0; i<x-1; i++){
        for(int j=0; j<x-i-1; j++) {
            if(vec[j]>vec[j+1]) {
                temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }

    for(int i=0; i<x; i++){
        count=0;
        for(int j=0; j<x; j++){
            if(vec[j]==vec[i]){
                count++;
            }
        }
        if(count>maxCount){
            mode=vec[i];
            maxCount=count;
        }
    }
    if(mode==1){
        mode=0;
    }
    return mode;
}

float variance(float median){
    Node *aux=start;
    float half=0, addition=0, variance=0, tempData=0;
    int vec[300];
    float secVec[300];
    int x=0, temp=0;
    null(vec);
    while(aux){
        vec[x]=aux->data;
        aux=aux->right;
        x++;
    }
    for(int i=0; i<x-1; i++){
        for(int j=0; j<x-i-1; j++) {
            if(vec[j]>vec[j+1]) {
                temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }

    for(int i=0; i<x; i++){
        tempData=vec[i];
        tempData-=median;
        tempData=pow(tempData, 2);
        secVec[i]=tempData;
    }

    for(int i=0; i<x; i++){
        addition+=secVec[i];
    }

    variance=addition/x;

    return variance;
}

float standDev(float variance){
    float standDev;
    standDev=sqrt(variance);
    return standDev;
}
//FIN DE DATOS ESTADISTICOS


void null(int vec[]){
    for (int i=0;i<50; i++) {
        vec[i]=0;
    }
}

void showList(void) {
    int k;
    Node* q = start;

    puts("\nLIST: ");
    for (k = 0; q; q = q->right) {
        printf("%d ", q->data);
        k++;
    }
    printf("\n");
}

Node* createNode(type x, Node* l, Node* r) {
    Node* neweishon;
    neweishon = (Node*)malloc(sizeof(Node));
    neweishon->data = x;
    neweishon->left = l;
    neweishon->right = r;
    return neweishon;
}

void insertEnd(type x) {
    Node* neweishon = createNode(x, NULL, NULL);
    neweishon->left = end;
    end->right = neweishon;
    end = neweishon;
}

void freeMemory(void) {
    printf("\n");
    printf("Freeing memory \n");
    if (!isEmpty()) {
        while (start) {
            Node* temp = start;
            start = start->right;
            printf("Freeing %d\n", temp->data);
            free(temp);
        }
    }
}

bool isEmpty(void) {
    if (start==NULL) {
        return true;
    }

    return false;
}


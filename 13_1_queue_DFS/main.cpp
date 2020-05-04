#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// =============== DEFINE ==================
#define MAX 11
#define DB_MAX 20
typedef struct node{
    char name[MAX];
    struct node *next;
}NODE;
typedef struct list{
    char name[MAX];
    int status;
    NODE *next;
}LIST;
typedef struct queueHead{
    char name[MAX];
    NODE *rear;
    NODE *next;
}QUEUE;
// ============= FUNCTION_ANNOUCEMENT ===============
void FILE_GET(char *file, LIST *DB, int *DB_size);

void DB_INIT(LIST *DB, char *element, int site);
void DB_INSERT(LIST *DB, char *element, int site);
void DB_PRINT(LIST *DB, int DB_size);
void DB_BSF(LIST *DB, char *start, int DB_size);
void DB_BSF_SECOND(LIST *DB, char *start, int DB_size);
void DB_DSF(LIST *DB, char *start, int DB_size);
LIST* DB_FIND(LIST *DB, char *target, int DB_size);
void DB_RECORD_CLEAR(LIST *DB, int DB_size);
void DB_DSF_FIND_PATH(LIST *DB, char *start, char *end, int DB_size);

char* DE_QUEUE(QUEUE *head);
void EN_QUEUE(QUEUE *head, char *element);
char* POP(NODE *head);
void PUSH(NODE *head, char *element);
// ============= MAIN ===============
int main(void){
    char file[] = "graph.cpp";
    LIST DB[DB_MAX];
    int DB_size=0;
    char start[]="John", end[]="Mary";

    FILE_GET(file, DB, &DB_size);
    DB_PRINT(DB, DB_size);
    DB_BSF(DB, start, DB_size);
    DB_RECORD_CLEAR(DB, DB_size);
    DB_DSF(DB, start, DB_size);
    DB_RECORD_CLEAR(DB, DB_size);
    DB_BSF_SECOND(DB, start, DB_size);
    DB_RECORD_CLEAR(DB, DB_size);

    return 0;
}
// ================ FUNCTION ===============
void DB_DSF_FIND_PATH(LIST *DB, char *start, char *end, int DB_size){
    NODE *stack = (NODE*)malloc(sizeof(NODE)); // stack
    stack->next = NULL;
    int flag=0, find=0, count=0; // flag:紀錄該路是否已到終點; find:紀錄是否能從start到end
    LIST *tmp=NULL;
    PUSH(stack, start);
    tmp = DB_FIND(DB, start, DB_size);
    tmp->status = 1;
    while(stack->next){ // stack is empty or not?
        if( strcmp(stack->next->name, end)){ //找到 end 
            find = 1; // record: 該圖start可到end 
            // print result
            while(stack->next){
                tmp = DB_FIND(DB, POP(stack), DB_size);
                if(tmp->status){
                    printf("[%s]-", tmp->name);
                    count+=1;
                }
            }
            printf("Count: %d\n", count);
            return;
        }
        else{ // 未找到 end
            tmp = DB_FIND(DB, stack->next->name, DB_size);
            NODE *node_tmp = tmp;
            while()
            for(int i=0;i<DB_size;i++){
                //周遭是否還有未拜訪的點
                if( !(DB_FIND(DB, temp;, DB_size)->status)){ 
                    STACK_PUSH(stack,-i); 
                    flag = 1;               
                }
            }
            if(!flag){ //該路已到終點, 回到分支點
                while(stack->next && stack->next->val >= 0 ) check[STACK_POP(stack)]=0;
                // 如果走完
                if(! stack->next)
                    { for(int i=0;i<minpath_Size;i++) path[i]=min_path[i]; pathSize[0]=minpath_Size; pathWeight[0]=min_weight; return find; }       
            }
            stack->next->val *= -1; // 將stack.top 改為 造訪中狀態
            STACK *tmp = stack; 
            // 將造訪中的點 紀錄至 check[] 
            while(tmp->next) { if(tmp->next->val>=0) check[tmp->next->val]=1; tmp = tmp->next; }
        }
    }
    printf("[ 未找到 ]\n"); 
}
void DB_BSF_SECOND(LIST *DB, char *start, int DB_size){
    NODE *S = (NODE*)malloc(sizeof(NODE));
    S->next = NULL;
    LIST *site = DB_FIND(DB, start, DB_size);
    site->status = 1;
    printf("Nod have two distance from [%s]: ", site->name);
    NODE *tmp = site->next;
    while(tmp){
        PUSH(S, tmp->name);
        tmp = tmp->next;
    }
    while(S->next){
        site = DB_FIND(DB, POP(S), DB_size);
        if( ! site->status){
            site->status = 1;
            //printf("[%s]-", site->name);
            tmp = site->next;
            LIST *second = NULL;
            while(tmp){
                second = DB_FIND(DB, tmp->name, DB_size);
                if(!second->status){
                    second->status = 1;
                    printf("[%s]-", second->name);
                }
                tmp = tmp->next;
            }          
        }
    } 
    printf("|\n");     
}
void DB_BSF(LIST *DB, char *start, int DB_size){
    QUEUE *Q = (QUEUE*)malloc(sizeof(QUEUE));
    Q->next = NULL; Q->rear = NULL;
    LIST *site = DB_FIND(DB, start, DB_size);
    site->status = 1;
    printf("BSF start [%s]: ", site->name);
    NODE *tmp = site->next;
    while(tmp){
        EN_QUEUE(Q, tmp->name);
        tmp = tmp->next;
    }
    while(Q->next){
        site = DB_FIND(DB, DE_QUEUE(Q), DB_size);
        if( ! site->status){
            site->status = 1;
            printf("[%s]-", site->name);
            tmp = site->next;
            while(tmp){
                EN_QUEUE(Q, tmp->name);
                tmp = tmp->next;
            }          
        }
    }
    printf("|\n");
}
void DB_DSF(LIST *DB, char *start, int DB_size){
    NODE *S = (NODE*)malloc(sizeof(NODE));
    S->next = NULL;
    LIST *site = DB_FIND(DB, start, DB_size);
    site->status = 1;
    printf("DSF start [%s]: ", site->name);
    NODE *tmp = site->next;
    while(tmp){
        PUSH(S, tmp->name);
        tmp = tmp->next;
    }
    while(S->next){
        site = DB_FIND(DB, POP(S), DB_size);
        if( ! site->status){
            site->status = 1;
            printf("[%s]-", site->name);
            tmp = site->next;
            while(tmp){
                PUSH(S, tmp->name);
                tmp = tmp->next;
            }          
        }
    }
    printf("|\n");    
}
LIST* DB_FIND(LIST *DB, char *target, int DB_size){
    for(int i=0;i<DB_size;i++)
        if(strcmp(DB[i].name, target) == 0)
            return &DB[i];
    printf("[ Not Find: %s ]\n", target);
    return NULL;
}
char* POP(NODE *head){
    NODE *tmp = head->next;
    char *ret = (char*)malloc(sizeof(char)*MAX);
    strcpy(ret, tmp->name);
    head->next = head->next->next;
    free(tmp);
    return ret;
}
void PUSH(NODE *head, char *element){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    strcpy(newnode->name, element);
    newnode->next = head->next;
    head->next = newnode;
}
void EN_QUEUE(QUEUE *head, char *element){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if( !newnode ) {printf("[ QUEUE is full ]"); return; } 
    strcpy(newnode->name, element);
    newnode->next = NULL;
    if(head->next)
        head->rear->next = newnode;
    else
        head->next = newnode;
    head->rear = newnode;
}
char* DE_QUEUE(QUEUE *head){
    char *ret = (char*)malloc(sizeof(char)*MAX);
    memset(ret,'\0',MAX);
    NODE *tmp=NULL;
    if( !head->next ) { printf("[ QUEUE is empty ]\n"); return ret; }
    strcpy(ret, head->next->name);
    tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return ret;
}
void FILE_GET(char *file, LIST *DB, int *DB_size){
    FILE *fptr = fopen(file, "r");
    char ori[MAX*20]={'\0'};
    char copy[MAX*20]={'\0'};
    if(fptr){
        while( fgets(ori,MAX*20,fptr) ){
            if( isspace(ori[0]) ) continue;
            strcpy(copy,ori);
            char *take = strtok(copy," \n");
            DB_INIT(DB, take, DB_size[0]);
            take = strtok(NULL, " ");
            while(take){ DB_INSERT(DB, take, DB_size[0]); take = strtok(NULL," \n"); }
            DB_size[0]+=1;
        }
    }
    else printf("can't open the file\n");
    fclose(fptr);
}
void DB_INIT(LIST *DB, char *element, int site){
    strcpy(DB[site].name, element); 
    DB[site].status = 0;
    DB[site].next = NULL;
}
void DB_INSERT(LIST *DB, char *element, int site){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    strcpy(newnode->name, element);
    newnode->next = NULL;
    if( ! DB[site].next) { DB[site].next = newnode; return; }
    NODE *tmp = DB[site].next;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newnode; 
}
void DB_PRINT(LIST *DB, int DB_size){
    NODE *tmp = NULL;
    for(int i=0;i<DB_size;i++){
        if(DB[i].next){
            tmp = DB[i].next;
            printf("%4d. %s: ",i+1, DB[i].name);
            while(tmp){
                printf("[%s]-", tmp->name);
                tmp = tmp->next;
            }
            printf("|\n");
        }
    }
}
void DB_RECORD_CLEAR(LIST *DB, int DB_size){
    for(int i=0;i<DB_size;i++)
        DB[i].status = 0;
}

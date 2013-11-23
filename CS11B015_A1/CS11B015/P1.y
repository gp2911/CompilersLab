%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pNode{
    char* s;
    struct pNode* next;
};

struct pFrag{
    struct pNode* head;
    struct pNode* tail;
};

struct mNode{
	
	char* macro;
	int no_of_args;
	struct pFrag exp;
	char *args[5];
};

typedef struct mNode macroNode;
typedef struct pNode progNode;
typedef struct pFrag progFrag;
macroNode* macros;

int no_of_macros=0;
int i;
int j;
int k;

void AddMacro( macroNode*, macroNode*, int );
%}

%union{
	struct pFrag* frag;
	char* str;
};

%token <str> MACRO_DEF ID BRACE_OPEN BRACE_CLOSE PARA_OPEN PARA_CLOSE STATIC
%token <str> SQ_OPEN SQ_CLOSE INT TRUE FALSE THIS NEW INT_DECL DOT VOID
%token <str> NOT AND LT WHILE IF ELSE BOOL_DECL CLASS_DECL LEN
%token <str> MAIN EQ SEMICOLON EF COMMA EXT PUB RET MAIN_KEY
%token <str> ADD SUB MUL DIV MOD PRINT STRING_DECL

%type <frag> Goal mainClass args idList exprList exprList1 declList funcArgs
%type <frag> typeIDList methodDeclList methodDecl macroDefnList typeDecl
%type <frag> typeDeclList Type Stmt Stmt1 matchedIf unmatchedIf Expr
%type <frag> Expression primaryExpr macroDefn macroDefStmt
%type <frag> stmtList macroDefExpr

%right EQ
%left AND
%left LT
%left ADD SUB
%left MUL DIV

%error-verbose


%%
//TODO: mainClass, typeDecl(2), 

Goal: macroDefnList mainClass typeDeclList { 
			
			                                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=$2->head;
                                                                            $2->tail->next=$3->head;
			                                                                $3->tail->next=NULL;
                                                                            frag->tail=$3->tail;
                                                                            $$=frag;
			                                                                progNode* tmp1=$$->head;
                                                                            printf("Expression:\n");
                                                                            while(tmp1!=NULL){
                                                                                printf("%s ", tmp1->s);
                                                                                tmp1=tmp1->next;
                                                                            }
                                            }
mainClass: CLASS_DECL ID BRACE_OPEN MAIN PARA_OPEN STRING_DECL SQ_OPEN SQ_CLOSE ID PARA_CLOSE BRACE_OPEN PRINT PARA_OPEN Expr PARA_CLOSE SEMICOLON BRACE_CLOSE BRACE_CLOSE 				                                   {                                                                  
                                                                            progNode* tmp=(progNode*)malloc(17*sizeof(progNode));
						                                                    tmp[0].s=$1; 
                                                                            tmp[1].s=$2; 
                                                                            tmp[2].s=$3; 
                                                                            tmp[3].s=$4; 
                                                                            tmp[4].s=$5; 
                                                                            tmp[5].s=$6; 
                                                                            tmp[6].s=$7; 
                                                                            tmp[7].s=$8; 
                                                                            tmp[8].s=$9; 
                                                                            tmp[9].s=$10; 
                                                                            tmp[10].s=$11; 
                                                                            tmp[11].s=$12; 
                                                                            tmp[12].s=$13; 
                                                                            tmp[13].s=$15; 
                                                                            tmp[14].s=$16; 
                                                                            tmp[15].s=$17; 
                                                                            tmp[16].s=$18;
						                                                    i=0;
			                                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
						                                                    progNode* space=(progNode*)malloc(17*sizeof(progNode));
                                                    						frag->head=&tmp[0];
                                                    						for(i=0; i<16; i++)
                                                    							tmp[i].next=&tmp[i+1];
                                                    						tmp[12].next=$14->head;
                                                    						$14->tail->next=&tmp[13];
                                                    						tmp[16].next=NULL;
                                                    						frag->tail=&tmp[16];
                                                    						$$=frag; 
                                            }
args:      /* NULL */                       
                                            { 
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
	                                                                        progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                        	tmp_head->s="";
                                                                        	tmp_head->next=NULL;
                                                                        	tmp->head=tmp_head;
                                                                        	tmp->tail=tmp_head;
                                                                        	$$=tmp;
                                            }
        | ID idList                         { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=$1;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=tmp1;
                                                                            tmp1->next=$2->head;
                                                                            $2->tail->next=NULL;
                                                                            frag->tail=$2->tail;
                                                                            $$=frag;
 		                                    }


idList: idList COMMA ID                     {  
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=$2;
                                                                            tmp2->s=$3;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=tmp1;
                                                                            tmp1->next=tmp2;
                                                                            frag->tail= tmp2;
                                                                            $$=frag;
		                                    }
        | /* NULL */                        {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }
        
exprList: Expr exprList1                    {
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=$2->head;
                                                                            $2->tail->next=NULL;
                                                                            frag->tail=$2->tail;
                                                                            $$=frag;
 		                                    }
	   |  /* NULL */                        { 
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }
        
exprList1:  exprList1 COMMA Expr            {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=$2;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=tmp1;
                                                                            tmp1->next=$3->head;
                                                                            frag->tail= $3->tail;
                            						                        $3->tail->next=NULL;
                                                                            $$=frag;
                                    		}
	   |   /* NULL */                       {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }

declList:   declList Type ID SEMICOLON      {   
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=$3;
                                                                            tmp2->s=$4;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=$2->head;
                                                                            $2->tail->next=tmp1;
                                                                            tmp1->next=tmp2;
                                                                            frag->tail= tmp2;
                            						                        tmp2->next=NULL;
                                                                            $$ = frag;
		                                    }
	   | declList ID ID SEMICOLON           {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                            						                        tmp1->s=$2;
                                                                            tmp2->s=$3;
                            						                        tmp3->s=$4;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=tmp1;
                                                                            tmp1->next=tmp2;
                                                                            tmp2->next=tmp3;
                                                                            frag->tail= tmp3;
                                                                            tmp3->next=NULL;
                                                                            $$ = frag;

                                            }
	   | /* NULL */                         { 
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }
        
funcArgs: Type ID typeIDList 
                                            {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=$2;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=tmp1;
                                                                            tmp1->next=$3->head;
                                                                            frag->tail= $3->tail;
                                                                            $3->tail->next=NULL;
                                                                            $$=frag;

                                             }
	   |  /* NULL */                         {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }

typeIDList: typeIDList COMMA Type ID 
                                            {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                            						                        progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=$2;
                            						                        tmp2->s=$4;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=tmp1;
                                                                            tmp1->next=$3->head;
                            						                        $3->tail->next=tmp2;
                                                                            frag->tail= tmp2;
                                                                            tmp2->next=NULL;
                                                                            $$=frag;
                                            }
        |  /* NULL */                       {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }
        
methodDeclList: methodDeclList methodDecl   {   
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=$2->head;
                                                                            $2->tail->next=NULL;
                                                                            frag->tail=$2->tail;
                                                                            $$=frag;
                                            }
	| /* NULL */                            {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }

methodDecl: PUB Type ID PARA_OPEN funcArgs PARA_CLOSE BRACE_OPEN declList stmtList RET Expr SEMICOLON BRACE_CLOSE 
                                            {
                                                                        	progNode* tmp= (progNode*)malloc(8*sizeof(progNode));
                                                                        	tmp[0].s=$1;
                                                                        	tmp[1].s=$3;
                                                                        	tmp[2].s=$4;
                                                                        	tmp[3].s=$6;
                                                                        	tmp[4].s=$7;
                                                                        	tmp[5].s=$10;
                                                                        	tmp[6].s=$12;
                                                                        	tmp[7].s=$13;
                                                                        	progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                        	frag->head=&tmp[0];
                                                                        	tmp[0].next=$2->head;
                                                                        	printf("#@#@#@$ %d \n",(int) $2->tail);
                                                                        	$2->tail->next=&tmp[1];
                                                                        	tmp[1].next=&tmp[2];
                                                                        	tmp[2].next=$5->head;
                                                                        	$5->tail->next=&tmp[3];
                                                                        	tmp[3].next=&tmp[4];
                                                                        	tmp[4].next=$8->head;
                                                                        	$8->tail->next=$9->head;
                                                                        	if($9->tail!=NULL)
                                                                        	$9->tail->next=&tmp[5];
                                                                        	else
                                                                        	$8->tail->next=&tmp[5];
                                                                        	tmp[5].next=$11->head;
                                                                        	$11->tail->next=&tmp[6];
                                                                        	tmp[6].next=&tmp[7];
                                                                        	tmp[7].next=NULL;
                                                                        	frag->tail=&tmp[7];
                                                                        	$$ = frag;
                                            }

macroDefnList: macroDefn macroDefnList      { 
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                			if($1!=NULL){
                                                                                frag->head=$1->head;
                                                                                $1->tail->next=$2->head;
                                                                            }
                                                                			else{
                                                                			    frag->head=$2->head;
                                                                			}
                                                                                $2->tail->next=NULL;
                                                                                frag->tail=$2->tail;
                                                                                $$=frag;
                                            }
        | /* NULL */                        {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }
        
typeDeclList: typeDeclList typeDecl         {  
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=$1->head;
                                                                            $1->tail->next=$2->head;
                                                                            $2->tail->next=NULL;
                                                                            frag->tail=$2->tail;
                                                                            $$=frag;
                                            }
        | /* NULL */                        {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            $$=tmp;
                                            }

typeDecl: CLASS_DECL ID BRACE_OPEN declList methodDeclList BRACE_CLOSE {
			 progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
				tmp1->s=$1;
				tmp2->s=$2;
				tmp3->s=$3;
				tmp4->s=$6;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=tmp2;
				tmp2->next=tmp3;
				tmp3->next= $4->head;
				$4->tail->next=$5->head;
				$5->tail->next=tmp4;
				tmp4->next=NULL;
				frag->tail=tmp4;
				$$=frag;
}
        | CLASS_DECL ID EXT ID BRACE_OPEN declList methodDeclList BRACE_CLOSE {
			progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                progNode* tmp5= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp6= (progNode*)malloc(sizeof(progNode));
				tmp1->s=$1;
                                tmp2->s=$2;
                                tmp3->s=$3;
                                tmp4->s=$4;
				tmp5->s=$5;
				tmp6->s=$8;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=tmp3;
				tmp3->next=tmp4;
				tmp4->next=tmp5;
                                tmp5->next= $6->head;
                                $6->tail->next=$7->head;
                                $7->tail->next=tmp6;
                                tmp6->next=NULL;
                                frag->tail=tmp6;
                                $$=frag;
				
}

Type: INT_DECL SQ_OPEN SQ_CLOSE { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
				 progNode* tmp2= (progNode*)malloc(sizeof(progNode)); 
				 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
				tmp1->s=$1;
				tmp2->s=$2;
				tmp3->s=$3;
				progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=tmp2;
				tmp2->next=tmp3;
				tmp3->next=NULL;
				frag->tail=tmp3;
				$$=frag;

 }
        | BOOL_DECL { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
			tmp1->s=$1;
			tmp1->next=NULL;
			progFrag* frag=(progFrag*)malloc(sizeof(progNode));
			frag->head=tmp1;
			frag->tail=tmp1;
			$$=frag;
 }
        | INT_DECL { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        tmp1->next=NULL;
                        progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        $$=frag;
 }
        | ID { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        tmp1->next=NULL;
                        progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        $$=frag;
} 

Stmt: Stmt1 { $$=$1; }
	| unmatchedIf {$$=$1;}

Stmt1: BRACE_OPEN stmtList BRACE_CLOSE { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
				tmp1->s=$1;
				tmp2->s=$3;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=$2->head;
				if($2->tail!=NULL)
				$2->tail->next=tmp2;
				else
				tmp1->next=tmp2;
				tmp2->next=NULL;
				frag->tail=tmp2;
				$$=frag;

 }
        | PRINT PARA_OPEN Expr PARA_CLOSE SEMICOLON { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
				tmp3->s=$4;
				tmp4->s=$5;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
				tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
				tmp3->next=tmp4;
                                tmp4->next=NULL;
                                frag->tail=tmp2;
                                $$=frag;
 }
        | ID EQ Expr SEMICOLON { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
				tmp3->s=$4;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
				tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
                                tmp3->next=NULL;
                                frag->tail=tmp3;
                                $$=frag;

 }
        | ID SQ_OPEN Expr SQ_CLOSE EQ Expr SEMICOLON {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
				 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp5= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
                                tmp3->s=$4;
				tmp4->s=$5;
				tmp5->s=$7;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
				tmp3->next=tmp4;
                                tmp4->next=$6->head;
                                $6->tail->next=tmp5;
				tmp5->next=NULL;
                                frag->tail=tmp5;
                                $$=frag;

 }
	| matchedIf { $$=$1; }
        | WHILE PARA_OPEN Expr PARA_CLOSE Stmt {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
                                tmp3->s=$4;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
                                tmp3->next=$5->head;
                                $5->tail->next=NULL;
                                frag->tail=$5->tail;
                                $$=frag;
				

 }
        | ID exprList SEMICOLON {} //Macro Expansion
	| PRINT PARA_OPEN { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
				tmp1->s=$1;	
				tmp2->s=$2;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=tmp2;
				tmp2->next=NULL;
				frag->tail=tmp2;
				$$= frag;
				
 }
        
matchedIf: IF PARA_OPEN Expr PARA_CLOSE Stmt1 ELSE Stmt1 { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
                                tmp3->s=$4;
                                tmp4->s=$6;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
                                tmp3->next=$5->head;
				if($5->tail!=NULL)
				$5->tail->next=tmp4;
				else
				tmp3->next=tmp4;
                                tmp4->next=$7->head;
				$7->tail=NULL;
				frag->tail=$7->tail;
                                $$=frag;

 }

unmatchedIf: IF PARA_OPEN Expr PARA_CLOSE Stmt1 ELSE unmatchedIf {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
                                tmp3->s=$4;
                                tmp4->s=$6;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
                                tmp3->next=$5->head;
                                $5->tail->next=tmp4;
                                tmp4->next=$7->head;
                                $7->tail=NULL;
                                frag->tail=$7->tail;
                                $$=frag;

 }
	| IF PARA_OPEN Expr PARA_CLOSE Stmt {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=$1;
                                tmp2->s=$2;
                                tmp3->s=$4;
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=$3->head;
                                $3->tail->next=tmp3;
                                tmp3->next=$5->head;
				$5->tail->next=NULL;
                                frag->tail=$5->tail;
                                $$=frag;

 }

Expr: Expression {
			$$= $1;
		}
        | primaryExpr { 
			$$= $1;
			}

Expression: primaryExpr ADD primaryExpr { 	progNode* tmp= (progNode*)malloc(sizeof(progNode));
						tmp->s=$2;
						progFrag* frag=(progFrag*)malloc(sizeof(progFrag));

						frag->head=$1->head;
						$1->tail->next=tmp;
						tmp->next=$3->head;
						frag->tail= $3->tail;
						$$=frag;

						}
	| primaryExpr SUB primaryExpr {         progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=$2;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp;
                                                tmp->next=$3->head;
                                                frag->tail= $3->tail;
						$$=frag;

                                                }

        | primaryExpr MUL primaryExpr {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=$2;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp;
                                                tmp->next=$3->head;
                                                frag->tail= $3->tail;
						$$=frag;
		                                
                }

        | primaryExpr DIV primaryExpr {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=$2;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp;
                                                tmp->next=$3->head;
                                                frag->tail= $3->tail;
						$$=frag;
        
			                }

        | primaryExpr AND primaryExpr {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=$2;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp;
                                                tmp->next=$3->head;
                                                frag->tail= $3->tail;
						$$=frag;
	        
	                                }

        | primaryExpr LT primaryExpr {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=$2;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp;
                                                tmp->next=$3->head;
                                                frag->tail= $3->tail;
						$$=frag;
                
	                        }

        | primaryExpr SQ_OPEN primaryExpr SQ_CLOSE {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=$2;
						tmp2->s=$4;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp1;
                                                tmp1->next=$3->head;
						$3->tail=tmp2;
                                                frag->tail= tmp2;
						$$=frag;

                                                }

        | primaryExpr DOT LEN {			progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                        	progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=$2;
						tmp2->s=$3;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp1;
                                                tmp1->next=tmp2;
                                                frag->tail= tmp2;
						$$=frag;

                                               }

        | primaryExpr DOT ID PARA_OPEN exprList PARA_CLOSE {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=$2;
						tmp2->s=$3;
						tmp3->s=$4;
						tmp4->s=$6;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=$1->head;
                                                $1->tail->next=tmp1;
                                                tmp1->next=tmp2;
						tmp2->next=tmp3;
						tmp3->next=$5->head;
						$5->tail->next=tmp4;
                                                frag->tail= tmp4;
						$$ = frag;
                                                }

        | ID PARA_OPEN exprList PARA_CLOSE {    progNode* tmp1= (progNode*)malloc(sizeof(progNode));
						progNode* tmp2= (progNode*)malloc(sizeof(progNode));
						progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=$1;
						tmp2->s=$2;	
						tmp3->s=$4;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=tmp1;
                                                tmp1->next=tmp2;
                                                tmp2->next=$3->head;
						$3->tail->next=tmp3;
                                                frag->tail= tmp3;
						$$ = frag;
					    }
 //Macro expansion
        
primaryExpr: INT {	progNode* tmp1= (progNode*)malloc(sizeof(progNode));
			tmp1->s=$1;
			progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
			frag->head=tmp1;
			frag->tail=tmp1;
			tmp1->next=NULL;
			$$=frag;
			}
	| ID {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        $$=frag;
                      }

	| PARA_OPEN Expr PARA_CLOSE {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=$1;
                                                tmp2->s=$3;
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=tmp1;
                                                tmp1->next=$2->head;
                                                $2->tail->next=tmp2;
                                                frag->tail= tmp2;
                                                $$ = frag;

		}
        | TRUE {     progNode* tmp1= (progNode*)malloc(sizeof(progNode));
   
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        $$=frag;
                       }

        | FALSE {     progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        $$=frag;
                      }

        | THIS {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        $$=frag;
                      }
 
        | NEW INT_DECL SQ_OPEN Expr SQ_CLOSE {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
			progNode* tmp2= (progNode*)malloc(sizeof(progNode));
			progNode* tmp3= (progNode*)malloc(sizeof(progNode));
			progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
			tmp2->s=$2;
			tmp3->s=$3;
			tmp4->s=$5;
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
			tmp1->next=tmp2;
			tmp2->next=tmp3;
			tmp3->next=$4->head;
			$4->tail->next=tmp4;
                        frag->tail=tmp4;
                        tmp4->next=NULL;
                        $$=frag;
	}
        | NEW ID PARA_OPEN PARA_CLOSE {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                        progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                        progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        tmp2->s=$2;
                        tmp3->s=$3;
                        tmp4->s=$4;
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        tmp1->next=tmp2;
                        tmp2->next=tmp3;
                        tmp3->next=tmp4;
                        frag->tail=tmp4;
                        tmp4->next=NULL;
                        $$=frag;

	}
        | NOT Expr {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=$1;
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        tmp1->next=$2->head;
                        $2->tail->next=NULL;
			frag->tail=$2->tail;
                        $$=frag;
	} 

macroDefn: macroDefExpr { $$=$1;} 
	| macroDefStmt { $$=$1;}
	
macroDefStmt: MACRO_DEF ID PARA_OPEN args PARA_CLOSE BRACE_OPEN stmtList BRACE_CLOSE { 
	no_of_macros++;
    int no_args=0;
	char* body=$7;
	macroNode *m=(macroNode*) malloc(sizeof(macroNode));
	m->macro=$2;
	char* args=$4;
	for(i=0; i<strlen(args);i++)
       		 if(args[i]==',')
               		no_args++;
	m->no_of_args=no_args+1;
    j=0;
    k=0;
	 for(i=0; i<strlen(args); i++){
                        m->args[j][k]=args[i];
                        if(args[i]==','){
                                j++;
                                k=0;
                        }
	}
    AddMacro(m, macros, no_of_macros);
} 
	
stmtList:Stmt {$$=$1;}
	|stmtList Stmt {  progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=$1->head;
			if($1->tail==NULL)
			$1->tail=(progNode*)malloc(sizeof(progNode));
                        $1->tail->next=$2->head;
			if($2->tail!=NULL){
                        $2->tail->next=NULL;
			frag->tail=$2->tail;
			}
			else{
			$1->tail->next=NULL;
                        frag->tail=$1->tail;
			}
                        $$=frag;
 }
	| { progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
         progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
        tmp_head->s="";
        tmp_head->next=NULL;
        tmp->head=tmp_head;
        tmp->tail=tmp_head;
        $$=tmp;
}

macroDefExpr: MACRO_DEF ID PARA_OPEN args PARA_CLOSE PARA_OPEN Expr PARA_CLOSE {
  	no_of_macros++;
 	char* body=$7;
    int no_args;
        macroNode *m=(macroNode*) malloc(sizeof(macroNode));
        m->macro=$2;
        char* args=$4;
        for(i=0; i<strlen(args);i++)
                 if(args[i]==',')
                        no_args++;
        m->no_of_args=no_args+1;
         for(i=0; i<strlen(args); i++){
                        m->args[j][k]=args[i];
                        if(args[i]==','){
                                j++;
                                k=0;
                        }
        }
        AddMacro(m, macros, no_of_macros);
 
}
	
%%

int main( int argc, char** argv){
//extern int yydebug;
//yydebug=1;
	yyparse();
	//int count= countMacros();
	//macroNode* macros=(macroNode*)malloc(count*sizeof(macroNode));	
	//initMacros(macros);
}

yyerror(char *s){
	fprintf(stderr, "Parse error...: %s\n", s);
}

void AddMacro(macroNode* m, macroNode* macroList, int i){
	macroList[i]=*m;
}


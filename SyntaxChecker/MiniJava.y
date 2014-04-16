//MiniJava.y
%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

	struct pNode{
		char* s;
		struct pNode* next;
	};

	struct pFrag{
		pNode* head;
		pNode* tail;
	}

	typedef struct pNode progNode;
	typedef struct pFrag progFrag;
%}

%union{
	progFrag* frag;
	char* str;
}

progFrag* program;

//Declaration of all tokens (terminals)
%token <str> ID BRACE_OPEN BRACE_CLOSE PARA_OPEN PARA_CLOSE STATIC
%token <str> SQ_OPEN SQ_CLOSE INT TRUE FALSE THIS NEW INT_DECL DOT VOID
%token <str> NOT AND LT WHILE IF ELSE BOOL_DECL CLASS_DECL LEN
%token <str> MAIN EQ SEMICOLON EF COMMA EXT PUB RET MAIN_KEY
%token <str> ADD SUB MUL DIV MOD PRINT STRING_DECL

//Declaration of all non-terminals
%type <frag> Goal mainClass exprList exprList1 varDeclList funcArgs
%type <frag> typeIDList methodDeclList methodDecl typeDecl classDecl
%type <frag> typeDeclList Type Stmt Stmt1 matchedIf unmatchedIf Expr
%type <frag> Expression primaryExpr printStmt classExtendsDecl
%type <frag> stmtList varDecl

//Precedence relations
%right EQ
%left AND
%left LT
%left ADD SUB
%left MUL DIV

%error-verbose

%%

Goal : mainClass typeDeclList EF{
																				printf("Matching Goal...\n");
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				tmp3->s = $3;
																				program = $1;
																				$1->tail->next = $2;
																				$2->tail->next = tmp3;
																				tmp3->next = NULL;
																				progNode* tmp = program;
																				while(tmp!=NULL){
                                                                                	printf("%s ", tmp->s);
                                                                                	tmp=tmp->next;
                                                                            	}

															}
mainClass : CLASS_DECL ID BRACE_OPEN MAIN PARA_OPEN STRING_DECL SQ_OPEN SQ_CLOSE ID PARA_CLOSE BRACE_OPEN printStmt BRACE_CLOSE BRACE_CLOSE{
																				printf("Matching main class...\n");
																				progNode* tmp1 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp2 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp4 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp5 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp6 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp7 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp8 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp9 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp10 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp11 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp13 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp14 = (progNode*)malloc(sizeof(progNode));
																				tmp1->s=$1;
																				tmp2->s=$2;
																				tmp3->s=$3;
																				tmp4->s=$4;
																				tmp5->s=$5;
																				tmp6->s=$6;
																				tmp7->s=$7;
																				tmp8->s=$8;
																				tmp9->s=$9;
																				tmp10->s=$10;
																				tmp11->s=$11;
																				tmp13->s=$13;
																				tmp14->s=$14;
																				tmp1->next = tmp2;
																				tmp2->next = tmp3;
																				tmp3->next = tmp4;
																				tmp4->next = tmp5;
																				tmp5->next = tmp6;
																				tmp6->next = tmp7;
																				tmp7->next = tmp8;
																				tmp8->next = tmp9;
																				tmp9->next = tmp10;
																				tmp10->next = tmp11;
																				tmp11->next = $12->head;
																				$12->tail->next = tmp13;
																				tmp13->next = tmp14;
																				tmp14->next = NULL;
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				frag->head = tmp1;
																				frag->tail = tmp14;
																				$$ = frag;
															}
typeDeclList : typeDecl{
																				progFrag* tmp = $1;
																				progNode* tmp1 = (progNode*) malloc(sizeof(progNode));
																				tmp1->s = "\n";
																				tmp->tail->next = tmp1;
																				tmp1->next = NULL;
																				tmp->tail = tmp1;
																				$$ = tmp;
															}
		| typeDeclList typeDecl{
																				progFrag* frag =$1;
																				progFrag* td = $2;
																				frag->tail->next = td->head;
																				td->tail->next = NULL;
																				frag->tail = td->tail;
																				$$ = frag;
															
															}
		| /* NULL */{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s = "";
																				tmp->next=NULL
																				frag->head=tmp;
																				frag->tail=tmp;
																				$$ = frag;
															}


typeDecl : classDecl{
																				$$ = $1;
															}
		| classExtendsDecl{
																				$$ = $1;
															}


classDecl : CLASS_DECL ID BRACE_OPEN varDeclList methodDeclList BRACE_CLOSE{
																				progNode* tmp1 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp2 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp6 = (progNode*)malloc(sizeof(progNode));
																				tmp1->s = $1;
																				tmp2->s = $2;
																				tmp3->s = $3;
																				tmp6->s = $6;
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				frag->head=tmp1;
																				tmp1->next=tmp2;
																				tmp2->next=tmp3;
																				tmp3->next=$4->head;
																				$4->tail->next=$5->head;
																				$5->tail->next=tmp6;
																				tmp6->next=NULL;
																				frag->tail=tmp6;
																				$$ = frag;

															}
classExtendsDecl : CLASS_DECL ID EXT ID BRACE_OPEN varDeclList methodDeclList BRACE_CLOSE{
																				progNode* tmp1 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp2 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp4 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp5 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp8 = (progNode*)malloc(sizeof(progNode));
																				tmp1->s = $1;
																				tmp2->s = $2;
																				tmp3->s = $3;
																				tmp4->s = $4;
																				tmp5->s = $5;
																				tmp8->s = $8;
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				frag->head=tmp1;
																				tmp1->next=tmp2;
																				tmp2->next=tmp3;
																				tmp3->next=tmp4;
																				tmp4->next=tmp5;
																				tmp5->next=$6->head;
																				$6->tail->next=$7->head;
																				$7->tail->next=tmp8;
																				tmp8->next=NULL;
																				frag->tail=tmp8;
																				$$ = frag;
															}
varDeclList : varDecl{
																				progFrag* tmp = $1;
																				progNode* tmp1 = (progNode*) malloc(sizeof(progNode));
																				tmp1->s = "\n";
																				tmp->tail->next = tmp1;
																				tmp1->next = NULL;
																				tmp->tail = tmp1;
																				$$ = tmp;
															}
		| varDeclList varDeclList{
																				progFrag* frag =$1;
																				progFrag* td = $2;
																				frag->tail->next = td->head;
																				td->tail->next = NULL;
																				frag->tail = td->tail;
																				$$ = frag;
															}
		|/* NULL */{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s = "";
																				tmp->next=NULL
																				frag->head=tmp;
																				frag->tail=tmp;
																				$$ = frag;
															}
methodDeclList : methodDecl{
																				progFrag* tmp = $1;
																				progNode* tmp1 = (progNode*) malloc(sizeof(progNode));
																				tmp1->s = "\n";
																				tmp->tail->next = tmp1;
																				tmp1->next = NULL;
																				tmp->tail = tmp1;
																				$$ = tmp;
															}
		| methodDeclList methodDecl{
																				progFrag* frag =$1;
																				progFrag* td = $2;
																				frag->tail->next = td->head;
																				td->tail->next = NULL;
																				frag->tail = td->tail;
																				$$ = frag;
															}
		|/* NULL */{	
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s = "";
																				tmp->next=NULL
																				frag->head=tmp;
																				frag->tail=tmp;
																				$$ = frag;
															}
varDecl : Type ID SEMICOLON{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp2 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				tmp2->s = $2;
																				tmp3->s = $3;
																				frag->head = $1->head;
																				$1->tail->next = tmp2;
																				tmp2->next = tmp3;
																				tmp3->next = NULL;
																				$$ = frag;
															}
methodDecl : PUB Type ID PARA_OPEN argList PARA_CLOSE BRACE_OPEN varDeclList stmtList RET Expr SEMICOLON BRACE_CLOSE{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp1 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp4 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp6 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp7 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp10 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp12 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp13 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmpn1 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmpn2 = (progNode*)malloc(sizeof(progNode));
																				tmpn1->s = "\n";
																				tmpn2->s = "\n";
																				tmp1->s = $1;
																				tmp3->s = $3;
																				tmp4->s = $4;
																				tmp6->s = $6;
																				tmp7->s = $7;
																				tmp10->s = $10;
																				tmp12->s = $12;
																				tmp13->s = $13;
																				tmp1->next = $2->head;
																				$2->tail->next = tmp3;
																				tmp3->next = tmp4;
																				tmp4->next = $5->head;
																				$5->tail->next = tmp6;
																				tmp6->next = tmp7;
																				tmp7->next=tmpn1;
																				tmpn1->next = $8->head
																				$8->tail->next = $9->head;
																				$9->tail->next = tmp10;
																				tmp10->next = $11->head;
																				$11->tail->next=tmp12;
																				tmp12->next=tmpn2;
																				tmpn2->next=tmp13;
																				tmp13->next=NULL;
																				frag->head = tmp1;
																				frag->tail = tmp13;
																				$$=frag;
															}
argList : funcArg{
																				$$ = $1;
															}
		| argList COMMA funcArg{
																				progFrag* frag =$1;
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s=$2;
																				progFrag* td = $3;
																				frag->tail->next = tmp;
																				tmp->next=td->head;
																				td->tail->next = NULL;
																				frag->tail = td->tail;
																				$$ = frag;
															}
		| /* NULL */{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s = "";
																				tmp->next=NULL
																				frag->head=tmp;
																				frag->tail=tmp;
																				$$ = frag;
															}
funcArg : Type ID{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				frag=$1;
																				tmp->s = $2;
																				frag->tail->next=tmp;
																				tmp->next=NULL;
																				$$=frag;
															}
Type : INT_DECL SQ_OPEN SQ_CLOSE{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp1 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp2 = (progNode*)malloc(sizeof(progNode));
																				progNode* tmp3 = (progNode*)malloc(sizeof(progNode));
																				tmp1->s=$1;
																				tmp2->s=$2;
																				tmp3->s=$3;
																				tmp1->next = tmp2;
																				tmp2->next=tmp3;
																				tmp3->next=NULL;
																				frag->head=tmp1;
																				frag->tail=tmp3;
																				$$=frag;
															}
		| BOOL_DECL{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s=$1;
																				$1->next=NULL;
																				frag->head=tmp;
																				frag->tail=tmp;
																				$$=frag;
															}
		| INT_DECL{
																				progFrag* frag = (progFrag*)malloc(sizeof(progFrag));
																				progNode* tmp = (progNode*)malloc(sizeof(progNode));
																				tmp->s=$1;
																				$1->next=NULL;
																				frag->head=tmp;
																				frag->tail=tmp;
																				$$=frag;					
															}
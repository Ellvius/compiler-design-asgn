#ifndef _yy_defines_h_
#define _yy_defines_h_

#define START_BLOCK 257
#define END_BLOCK 258
#define DECL 259
#define ENDDECL 260
#define READ 261
#define WRITE 262
#define IF 263
#define THEN 264
#define ELSE 265
#define ENDIF 266
#define WHILE 267
#define DO 268
#define ENDWHILE 269
#define REPEAT 270
#define UNTIL 271
#define PLUS 272
#define MINUS 273
#define MUL 274
#define DIV 275
#define MOD 276
#define LT 277
#define GT 278
#define LE 279
#define GE 280
#define NE 281
#define EQ 282
#define ASSGN 283
#define EOS 284
#define COMMA 285
#define INT 286
#define NUM 287
#define ID 288
#define OR 289
#define AND 290
#define NOT 291
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
    struct ASTNode *node;
    char* idName;
    int intVal;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */

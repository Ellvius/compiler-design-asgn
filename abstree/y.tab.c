/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "abstree.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include "../abstree/abstree.h"
    #include "../codegen/codegen.h"
    #include "../symboltable/symboltable.h"

    extern FILE *yyin;

    int yylex(void);
    int yyerror(const char *s);


#line 85 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    START_BLOCK = 258,             /* START_BLOCK  */
    END_BLOCK = 259,               /* END_BLOCK  */
    DECL = 260,                    /* DECL  */
    ENDDECL = 261,                 /* ENDDECL  */
    READ = 262,                    /* READ  */
    WRITE = 263,                   /* WRITE  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSE = 266,                    /* ELSE  */
    ENDIF = 267,                   /* ENDIF  */
    WHILE = 268,                   /* WHILE  */
    DO = 269,                      /* DO  */
    ENDWHILE = 270,                /* ENDWHILE  */
    REPEAT = 271,                  /* REPEAT  */
    UNTIL = 272,                   /* UNTIL  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    MUL = 275,                     /* MUL  */
    DIV = 276,                     /* DIV  */
    MOD = 277,                     /* MOD  */
    LT = 278,                      /* LT  */
    GT = 279,                      /* GT  */
    LE = 280,                      /* LE  */
    GE = 281,                      /* GE  */
    NE = 282,                      /* NE  */
    EQ = 283,                      /* EQ  */
    ASSGN = 284,                   /* ASSGN  */
    EOS = 285,                     /* EOS  */
    COMMA = 286,                   /* COMMA  */
    INT = 287,                     /* INT  */
    NUM = 288,                     /* NUM  */
    ID = 289,                      /* ID  */
    OR = 290,                      /* OR  */
    AND = 291,                     /* AND  */
    NOT = 292                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define START_BLOCK 258
#define END_BLOCK 259
#define DECL 260
#define ENDDECL 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define REPEAT 271
#define UNTIL 272
#define PLUS 273
#define MINUS 274
#define MUL 275
#define DIV 276
#define MOD 277
#define LT 278
#define GT 279
#define LE 280
#define GE 281
#define NE 282
#define EQ 283
#define ASSGN 284
#define EOS 285
#define COMMA 286
#define INT 287
#define NUM 288
#define ID 289
#define OR 290
#define AND 291
#define NOT 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "abstree.y"

    struct ASTNode *node;
    char* idName;
    int intVal;

#line 218 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_START_BLOCK = 3,                /* START_BLOCK  */
  YYSYMBOL_END_BLOCK = 4,                  /* END_BLOCK  */
  YYSYMBOL_DECL = 5,                       /* DECL  */
  YYSYMBOL_ENDDECL = 6,                    /* ENDDECL  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ENDIF = 12,                     /* ENDIF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_ENDWHILE = 15,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 16,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 17,                     /* UNTIL  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MUL = 20,                       /* MUL  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_NE = 27,                        /* NE  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_ASSGN = 29,                     /* ASSGN  */
  YYSYMBOL_EOS = 30,                       /* EOS  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_NUM = 33,                       /* NUM  */
  YYSYMBOL_ID = 34,                        /* ID  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_Code = 44,                      /* Code  */
  YYSYMBOL_Slist = 45,                     /* Slist  */
  YYSYMBOL_Stmt = 46,                      /* Stmt  */
  YYSYMBOL_Declarations = 47,              /* Declarations  */
  YYSYMBOL_DeclList = 48,                  /* DeclList  */
  YYSYMBOL_Decl = 49,                      /* Decl  */
  YYSYMBOL_VarList = 50,                   /* VarList  */
  YYSYMBOL_IfStmt = 51,                    /* IfStmt  */
  YYSYMBOL_IterativeStmt = 52,             /* IterativeStmt  */
  YYSYMBOL_InputStmt = 53,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 54,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 55,                   /* AsgStmt  */
  YYSYMBOL_Identifier = 56,                /* Identifier  */
  YYSYMBOL_Expr = 57                       /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    53,    56,    62,    63,    64,    67,    68,
      69,    70,    71,    74,    75,    78,    79,    82,    85,    86,
      87,    88,    91,    92,    95,    96,    97,   100,   103,   106,
     110,   111,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "START_BLOCK",
  "END_BLOCK", "DECL", "ENDDECL", "READ", "WRITE", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "NE", "EQ", "ASSGN", "EOS",
  "COMMA", "INT", "NUM", "ID", "OR", "AND", "NOT", "'['", "']'", "'('",
  "')'", "$accept", "Program", "Code", "Slist", "Stmt", "Declarations",
  "DeclList", "Decl", "VarList", "IfStmt", "IterativeStmt", "InputStmt",
  "OutputStmt", "AsgStmt", "Identifier", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    -5,     8,    12,   -29,   -17,    -3,   -29,   -29,    50,
     -29,    -4,     2,   -29,   -29,   -29,   -12,     9,    10,    11,
      95,    95,    18,    61,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,     6,    27,   -29,    28,    33,    39,    39,    39,   150,
     117,    39,   -29,   -29,    39,    22,    40,    30,   -29,    39,
      39,   -29,   167,   191,   215,    41,    42,   311,   333,   -29,
      47,    53,   371,   239,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    59,    80,    77,
      39,    39,   -29,   -29,    60,   -29,   -29,     3,     3,   -29,
     -29,   -29,   157,   157,   157,   157,   382,   382,   352,   371,
     -29,    95,    95,   263,   287,   -29,   105,   128,   -10,    75,
      95,    85,    90,   -29,   -29,   140,   -29,   -29,    92,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    14,     0,     0,    16,     1,     0,
       2,    21,     0,    13,    15,     4,     0,     0,     0,     0,
       0,     0,    31,     0,     6,     7,     8,     9,    10,    11,
      12,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     5,     0,     0,    19,     0,    48,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    29,     0,    27,    40,    32,    33,    34,
      35,    36,    41,    42,    43,    44,    45,    46,    38,    37,
      28,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,    23,    24,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,   -14,   -21,   107,   -29,   104,   -29,   -29,
     -29,   -29,   -29,   -29,    -9,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,    23,    24,    25,     6,     7,    12,    26,
      27,    28,    29,    30,    51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,     4,    43,    13,   102,     1,    39,    40,     8,    53,
      54,    31,    31,    57,    31,     9,    58,    11,    43,    43,
     113,    62,    63,    66,    67,    68,    47,     5,    35,     5,
      31,    31,    33,    34,    32,    44,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    36,
      37,    38,   103,   104,    15,     1,    41,    16,    17,    18,
      45,    59,    46,    19,    20,    42,    21,    22,    16,    17,
      18,    61,    48,    22,    19,    20,    49,    21,    60,    50,
      84,    80,    81,    85,    22,    43,    43,   106,   107,   100,
     101,   102,    31,    31,    43,    22,   115,    31,    31,   105,
       1,    31,    16,    17,    18,   114,    31,     3,    19,    20,
      14,    21,    16,    17,    18,   116,   110,   111,    19,    20,
     117,    21,   119,     0,    16,    17,    18,     0,     0,    22,
      19,    20,     0,    21,    56,    16,    17,    18,     0,    22,
       0,    19,    20,   112,    21,     0,     0,    16,    17,    18,
       0,    22,   118,    19,    20,     0,    21,    16,    17,    18,
       0,     0,    22,    55,    20,     0,    21,     0,     0,     0,
       0,     0,     0,     0,    22,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    22,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,    77,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,    75,    76,     0,     0,
       0,     0,    78,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,    79,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,    75,    76,     0,     0,     0,     0,
      86,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,    75,    76,
       0,     0,     0,     0,   108,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,   109,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,    75,    76,     0,     0,
      82,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,    83,     0,     0,     0,     0,    75,    76,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,    76,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1
};

static const yytype_int8 yycheck[] =
{
       9,     6,    23,     6,    14,     5,    20,    21,     0,    37,
      38,    20,    21,    41,    23,     3,    44,    34,    39,    40,
      30,    49,    50,    20,    21,    22,    35,    32,    40,    32,
      39,    40,    30,    31,    38,    29,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    40,
      40,    40,    80,    81,     4,     5,    38,     7,     8,     9,
      33,    39,    34,    13,    14,     4,    16,    34,     7,     8,
       9,    41,    33,    34,    13,    14,    37,    16,    38,    40,
      33,    40,    40,    30,    34,   106,   107,   101,   102,    30,
      10,    14,   101,   102,   115,    34,   110,   106,   107,    39,
       5,   110,     7,     8,     9,    30,   115,     0,    13,    14,
       6,    16,     7,     8,     9,    30,    11,    12,    13,    14,
      30,    16,    30,    -1,     7,     8,     9,    -1,    -1,    34,
      13,    14,    -1,    16,    17,     7,     8,     9,    -1,    34,
      -1,    13,    14,    15,    16,    -1,    -1,     7,     8,     9,
      -1,    34,    12,    13,    14,    -1,    16,     7,     8,     9,
      -1,    -1,    34,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    34,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    41,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    41,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      41,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    41,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      39,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    -1,    35,    36,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    43,    47,     6,    32,    48,    49,     0,     3,
      44,    34,    50,     6,    49,     4,     7,     8,     9,    13,
      14,    16,    34,    45,    46,    47,    51,    52,    53,    54,
      55,    56,    38,    30,    31,    40,    40,    40,    40,    45,
      45,    38,     4,    46,    29,    33,    34,    56,    33,    37,
      40,    56,    57,    57,    57,    13,    17,    57,    57,    39,
      38,    41,    57,    57,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    35,    36,    41,    41,    41,
      40,    40,    39,    30,    33,    30,    41,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      30,    10,    14,    57,    57,    39,    45,    45,    41,    41,
      11,    12,    15,    30,    30,    45,    30,    30,    12,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    50,    50,
      50,    50,    51,    51,    52,    52,    52,    53,    54,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     1,     3,     6,     3,
       4,     1,    10,     8,     8,     7,     7,     5,     5,     4,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Declarations Code  */
#line 46 "abstree.y"
                                                    {
                                                        (yyval.node) = (yyvsp[0].node);
                                                        printSymbolTable();
                                                        codeGen((yyvsp[0].node));
                                                        exit(0);
                                                    }
#line 1384 "y.tab.c"
    break;

  case 3: /* Code: START_BLOCK Slist END_BLOCK  */
#line 53 "abstree.y"
                                                    {
                                                        (yyval.node) = (yyvsp[-1].node);
                                                    }
#line 1392 "y.tab.c"
    break;

  case 4: /* Code: START_BLOCK END_BLOCK  */
#line 56 "abstree.y"
                                                    {
                                                        fprintf(stdout, "Empty program\n");
                                                        exit(0);
                                                    }
#line 1401 "y.tab.c"
    break;

  case 5: /* Slist: Slist Stmt  */
#line 62 "abstree.y"
                                        {(yyval.node) = makeConnNode((yyvsp[-1].node), (yyvsp[0].node));}
#line 1407 "y.tab.c"
    break;

  case 6: /* Slist: Stmt  */
#line 63 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1413 "y.tab.c"
    break;

  case 7: /* Slist: Declarations  */
#line 64 "abstree.y"
                                        {}
#line 1419 "y.tab.c"
    break;

  case 8: /* Stmt: IfStmt  */
#line 67 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1425 "y.tab.c"
    break;

  case 9: /* Stmt: IterativeStmt  */
#line 68 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1431 "y.tab.c"
    break;

  case 10: /* Stmt: InputStmt  */
#line 69 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1437 "y.tab.c"
    break;

  case 11: /* Stmt: OutputStmt  */
#line 70 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1443 "y.tab.c"
    break;

  case 12: /* Stmt: AsgStmt  */
#line 71 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1449 "y.tab.c"
    break;

  case 13: /* Declarations: DECL DeclList ENDDECL  */
#line 74 "abstree.y"
                                        {}
#line 1455 "y.tab.c"
    break;

  case 14: /* Declarations: DECL ENDDECL  */
#line 75 "abstree.y"
                                        {}
#line 1461 "y.tab.c"
    break;

  case 15: /* DeclList: DeclList Decl  */
#line 78 "abstree.y"
                                        {}
#line 1467 "y.tab.c"
    break;

  case 16: /* DeclList: Decl  */
#line 79 "abstree.y"
                                        {}
#line 1473 "y.tab.c"
    break;

  case 17: /* Decl: INT VarList EOS  */
#line 82 "abstree.y"
                                       {}
#line 1479 "y.tab.c"
    break;

  case 18: /* VarList: VarList COMMA ID '[' NUM ']'  */
#line 85 "abstree.y"
                                                        {GInstall((yyvsp[-3].idName), TYPE_INT, (yyvsp[-1].intVal));}
#line 1485 "y.tab.c"
    break;

  case 19: /* VarList: VarList COMMA ID  */
#line 86 "abstree.y"
                                                        {GInstall((yyvsp[0].idName), TYPE_INT, 1);}
#line 1491 "y.tab.c"
    break;

  case 20: /* VarList: ID '[' NUM ']'  */
#line 87 "abstree.y"
                                                        {GInstall((yyvsp[-3].idName), TYPE_INT, (yyvsp[-1].intVal));}
#line 1497 "y.tab.c"
    break;

  case 21: /* VarList: ID  */
#line 88 "abstree.y"
                                                        {GInstall((yyvsp[0].idName), TYPE_INT, 1);}
#line 1503 "y.tab.c"
    break;

  case 22: /* IfStmt: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF EOS  */
#line 91 "abstree.y"
                                                                    {(yyval.node) = makeIfElseNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));}
#line 1509 "y.tab.c"
    break;

  case 23: /* IfStmt: IF '(' Expr ')' THEN Slist ENDIF EOS  */
#line 92 "abstree.y"
                                                                    {(yyval.node) = makeIfElseNode((yyvsp[-5].node), (yyvsp[-2].node), NULL);}
#line 1515 "y.tab.c"
    break;

  case 24: /* IterativeStmt: WHILE '(' Expr ')' DO Slist ENDWHILE EOS  */
#line 95 "abstree.y"
                                                                    {(yyval.node) = makeIterationNode(NODE_WHILE, (yyvsp[-5].node), (yyvsp[-2].node));}
#line 1521 "y.tab.c"
    break;

  case 25: /* IterativeStmt: DO Slist WHILE '(' Expr ')' EOS  */
#line 96 "abstree.y"
                                                                    {(yyval.node) = makeIterationNode(NODE_DOWHILE, (yyvsp[-2].node), (yyvsp[-5].node));}
#line 1527 "y.tab.c"
    break;

  case 26: /* IterativeStmt: REPEAT Slist UNTIL '(' Expr ')' EOS  */
#line 97 "abstree.y"
                                                                    {(yyval.node) = makeIterationNode(NODE_REPEAT, (yyvsp[-2].node), (yyvsp[-5].node));}
#line 1533 "y.tab.c"
    break;

  case 27: /* InputStmt: READ '(' Identifier ')' EOS  */
#line 100 "abstree.y"
                                                    {(yyval.node) = makeReadNode((yyvsp[-2].node));}
#line 1539 "y.tab.c"
    break;

  case 28: /* OutputStmt: WRITE '(' Expr ')' EOS  */
#line 103 "abstree.y"
                                                    {(yyval.node) = makeWriteNode((yyvsp[-2].node));}
#line 1545 "y.tab.c"
    break;

  case 29: /* AsgStmt: Identifier ASSGN Expr EOS  */
#line 106 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-3].node), (yyvsp[-1].node));}
#line 1551 "y.tab.c"
    break;

  case 30: /* Identifier: ID '[' Expr ']'  */
#line 110 "abstree.y"
                                            {(yyval.node) = makeArrayNode((yyvsp[-3].idName), TYPE_ID, (yyvsp[-1].node));}
#line 1557 "y.tab.c"
    break;

  case 31: /* Identifier: ID  */
#line 111 "abstree.y"
                                            {(yyval.node) = makeLeafNode(0, TYPE_ID, (yyvsp[0].idName));}
#line 1563 "y.tab.c"
    break;

  case 32: /* Expr: Expr PLUS Expr  */
#line 114 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1569 "y.tab.c"
    break;

  case 33: /* Expr: Expr MINUS Expr  */
#line 115 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1575 "y.tab.c"
    break;

  case 34: /* Expr: Expr MUL Expr  */
#line 116 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1581 "y.tab.c"
    break;

  case 35: /* Expr: Expr DIV Expr  */
#line 117 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1587 "y.tab.c"
    break;

  case 36: /* Expr: Expr MOD Expr  */
#line 118 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1593 "y.tab.c"
    break;

  case 37: /* Expr: Expr AND Expr  */
#line 119 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1599 "y.tab.c"
    break;

  case 38: /* Expr: Expr OR Expr  */
#line 120 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1605 "y.tab.c"
    break;

  case 39: /* Expr: NOT Expr  */
#line 121 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_NOT, (yyvsp[0].node), NULL);}
#line 1611 "y.tab.c"
    break;

  case 40: /* Expr: '(' Expr ')'  */
#line 122 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1617 "y.tab.c"
    break;

  case 41: /* Expr: Expr LT Expr  */
#line 123 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1623 "y.tab.c"
    break;

  case 42: /* Expr: Expr GT Expr  */
#line 124 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1629 "y.tab.c"
    break;

  case 43: /* Expr: Expr LE Expr  */
#line 125 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1635 "y.tab.c"
    break;

  case 44: /* Expr: Expr GE Expr  */
#line 126 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1641 "y.tab.c"
    break;

  case 45: /* Expr: Expr NE Expr  */
#line 127 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1647 "y.tab.c"
    break;

  case 46: /* Expr: Expr EQ Expr  */
#line 128 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1653 "y.tab.c"
    break;

  case 47: /* Expr: Identifier  */
#line 129 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1659 "y.tab.c"
    break;

  case 48: /* Expr: NUM  */
#line 130 "abstree.y"
                                        {(yyval.node) = makeLeafNode((yyvsp[0].intVal), TYPE_INT, NULL);}
#line 1665 "y.tab.c"
    break;


#line 1669 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 133 "abstree.y"


int yyerror(const char *s){
    printf("yyerror %s\n",s);
    exit(1);
}


int main(int argc, char* argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Couldn't find the input file!\n");
            return 1;
        }
    }
    else {
        yyin = stdin;
    }
    
    yyparse();

    if(yyin != stdin) fclose(yyin);
    return 0;
}

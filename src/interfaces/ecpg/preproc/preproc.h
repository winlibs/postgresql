/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_BASE_YY_PREPROC_H_INCLUDED
# define YY_BASE_YY_PREPROC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int base_yydebug;
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
    SQL_ALLOCATE = 258,            /* SQL_ALLOCATE  */
    SQL_AUTOCOMMIT = 259,          /* SQL_AUTOCOMMIT  */
    SQL_BOOL = 260,                /* SQL_BOOL  */
    SQL_BREAK = 261,               /* SQL_BREAK  */
    SQL_CARDINALITY = 262,         /* SQL_CARDINALITY  */
    SQL_CONNECT = 263,             /* SQL_CONNECT  */
    SQL_COUNT = 264,               /* SQL_COUNT  */
    SQL_DATETIME_INTERVAL_CODE = 265, /* SQL_DATETIME_INTERVAL_CODE  */
    SQL_DATETIME_INTERVAL_PRECISION = 266, /* SQL_DATETIME_INTERVAL_PRECISION  */
    SQL_DESCRIBE = 267,            /* SQL_DESCRIBE  */
    SQL_DESCRIPTOR = 268,          /* SQL_DESCRIPTOR  */
    SQL_DISCONNECT = 269,          /* SQL_DISCONNECT  */
    SQL_FOUND = 270,               /* SQL_FOUND  */
    SQL_FREE = 271,                /* SQL_FREE  */
    SQL_GET = 272,                 /* SQL_GET  */
    SQL_GO = 273,                  /* SQL_GO  */
    SQL_GOTO = 274,                /* SQL_GOTO  */
    SQL_IDENTIFIED = 275,          /* SQL_IDENTIFIED  */
    SQL_INDICATOR = 276,           /* SQL_INDICATOR  */
    SQL_KEY_MEMBER = 277,          /* SQL_KEY_MEMBER  */
    SQL_LENGTH = 278,              /* SQL_LENGTH  */
    SQL_LONG = 279,                /* SQL_LONG  */
    SQL_NULLABLE = 280,            /* SQL_NULLABLE  */
    SQL_OCTET_LENGTH = 281,        /* SQL_OCTET_LENGTH  */
    SQL_OPEN = 282,                /* SQL_OPEN  */
    SQL_OUTPUT = 283,              /* SQL_OUTPUT  */
    SQL_REFERENCE = 284,           /* SQL_REFERENCE  */
    SQL_RETURNED_LENGTH = 285,     /* SQL_RETURNED_LENGTH  */
    SQL_RETURNED_OCTET_LENGTH = 286, /* SQL_RETURNED_OCTET_LENGTH  */
    SQL_SCALE = 287,               /* SQL_SCALE  */
    SQL_SECTION = 288,             /* SQL_SECTION  */
    SQL_SHORT = 289,               /* SQL_SHORT  */
    SQL_SIGNED = 290,              /* SQL_SIGNED  */
    SQL_SQLERROR = 291,            /* SQL_SQLERROR  */
    SQL_SQLPRINT = 292,            /* SQL_SQLPRINT  */
    SQL_SQLWARNING = 293,          /* SQL_SQLWARNING  */
    SQL_START = 294,               /* SQL_START  */
    SQL_STOP = 295,                /* SQL_STOP  */
    SQL_STRUCT = 296,              /* SQL_STRUCT  */
    SQL_UNSIGNED = 297,            /* SQL_UNSIGNED  */
    SQL_VAR = 298,                 /* SQL_VAR  */
    SQL_WHENEVER = 299,            /* SQL_WHENEVER  */
    S_ADD = 300,                   /* S_ADD  */
    S_AND = 301,                   /* S_AND  */
    S_ANYTHING = 302,              /* S_ANYTHING  */
    S_AUTO = 303,                  /* S_AUTO  */
    S_CONST = 304,                 /* S_CONST  */
    S_DEC = 305,                   /* S_DEC  */
    S_DIV = 306,                   /* S_DIV  */
    S_DOTPOINT = 307,              /* S_DOTPOINT  */
    S_EQUAL = 308,                 /* S_EQUAL  */
    S_EXTERN = 309,                /* S_EXTERN  */
    S_INC = 310,                   /* S_INC  */
    S_LSHIFT = 311,                /* S_LSHIFT  */
    S_MEMPOINT = 312,              /* S_MEMPOINT  */
    S_MEMBER = 313,                /* S_MEMBER  */
    S_MOD = 314,                   /* S_MOD  */
    S_MUL = 315,                   /* S_MUL  */
    S_NEQUAL = 316,                /* S_NEQUAL  */
    S_OR = 317,                    /* S_OR  */
    S_REGISTER = 318,              /* S_REGISTER  */
    S_RSHIFT = 319,                /* S_RSHIFT  */
    S_STATIC = 320,                /* S_STATIC  */
    S_SUB = 321,                   /* S_SUB  */
    S_VOLATILE = 322,              /* S_VOLATILE  */
    S_TYPEDEF = 323,               /* S_TYPEDEF  */
    CSTRING = 324,                 /* CSTRING  */
    CVARIABLE = 325,               /* CVARIABLE  */
    CPP_LINE = 326,                /* CPP_LINE  */
    IP = 327,                      /* IP  */
    IDENT = 328,                   /* IDENT  */
    UIDENT = 329,                  /* UIDENT  */
    FCONST = 330,                  /* FCONST  */
    SCONST = 331,                  /* SCONST  */
    USCONST = 332,                 /* USCONST  */
    BCONST = 333,                  /* BCONST  */
    XCONST = 334,                  /* XCONST  */
    Op = 335,                      /* Op  */
    ICONST = 336,                  /* ICONST  */
    PARAM = 337,                   /* PARAM  */
    TYPECAST = 338,                /* TYPECAST  */
    DOT_DOT = 339,                 /* DOT_DOT  */
    COLON_EQUALS = 340,            /* COLON_EQUALS  */
    EQUALS_GREATER = 341,          /* EQUALS_GREATER  */
    LESS_EQUALS = 342,             /* LESS_EQUALS  */
    GREATER_EQUALS = 343,          /* GREATER_EQUALS  */
    NOT_EQUALS = 344,              /* NOT_EQUALS  */
    ABORT_P = 345,                 /* ABORT_P  */
    ABSOLUTE_P = 346,              /* ABSOLUTE_P  */
    ACCESS = 347,                  /* ACCESS  */
    ACTION = 348,                  /* ACTION  */
    ADD_P = 349,                   /* ADD_P  */
    ADMIN = 350,                   /* ADMIN  */
    AFTER = 351,                   /* AFTER  */
    AGGREGATE = 352,               /* AGGREGATE  */
    ALL = 353,                     /* ALL  */
    ALSO = 354,                    /* ALSO  */
    ALTER = 355,                   /* ALTER  */
    ALWAYS = 356,                  /* ALWAYS  */
    ANALYSE = 357,                 /* ANALYSE  */
    ANALYZE = 358,                 /* ANALYZE  */
    AND = 359,                     /* AND  */
    ANY = 360,                     /* ANY  */
    ARRAY = 361,                   /* ARRAY  */
    AS = 362,                      /* AS  */
    ASC = 363,                     /* ASC  */
    ASENSITIVE = 364,              /* ASENSITIVE  */
    ASSERTION = 365,               /* ASSERTION  */
    ASSIGNMENT = 366,              /* ASSIGNMENT  */
    ASYMMETRIC = 367,              /* ASYMMETRIC  */
    ATOMIC = 368,                  /* ATOMIC  */
    AT = 369,                      /* AT  */
    ATTACH = 370,                  /* ATTACH  */
    ATTRIBUTE = 371,               /* ATTRIBUTE  */
    AUTHORIZATION = 372,           /* AUTHORIZATION  */
    BACKWARD = 373,                /* BACKWARD  */
    BEFORE = 374,                  /* BEFORE  */
    BEGIN_P = 375,                 /* BEGIN_P  */
    BETWEEN = 376,                 /* BETWEEN  */
    BIGINT = 377,                  /* BIGINT  */
    BINARY = 378,                  /* BINARY  */
    BIT = 379,                     /* BIT  */
    BOOLEAN_P = 380,               /* BOOLEAN_P  */
    BOTH = 381,                    /* BOTH  */
    BREADTH = 382,                 /* BREADTH  */
    BY = 383,                      /* BY  */
    CACHE = 384,                   /* CACHE  */
    CALL = 385,                    /* CALL  */
    CALLED = 386,                  /* CALLED  */
    CASCADE = 387,                 /* CASCADE  */
    CASCADED = 388,                /* CASCADED  */
    CASE = 389,                    /* CASE  */
    CAST = 390,                    /* CAST  */
    CATALOG_P = 391,               /* CATALOG_P  */
    CHAIN = 392,                   /* CHAIN  */
    CHAR_P = 393,                  /* CHAR_P  */
    CHARACTER = 394,               /* CHARACTER  */
    CHARACTERISTICS = 395,         /* CHARACTERISTICS  */
    CHECK = 396,                   /* CHECK  */
    CHECKPOINT = 397,              /* CHECKPOINT  */
    CLASS = 398,                   /* CLASS  */
    CLOSE = 399,                   /* CLOSE  */
    CLUSTER = 400,                 /* CLUSTER  */
    COALESCE = 401,                /* COALESCE  */
    COLLATE = 402,                 /* COLLATE  */
    COLLATION = 403,               /* COLLATION  */
    COLUMN = 404,                  /* COLUMN  */
    COLUMNS = 405,                 /* COLUMNS  */
    COMMENT = 406,                 /* COMMENT  */
    COMMENTS = 407,                /* COMMENTS  */
    COMMIT = 408,                  /* COMMIT  */
    COMMITTED = 409,               /* COMMITTED  */
    COMPRESSION = 410,             /* COMPRESSION  */
    CONCURRENTLY = 411,            /* CONCURRENTLY  */
    CONFIGURATION = 412,           /* CONFIGURATION  */
    CONFLICT = 413,                /* CONFLICT  */
    CONNECTION = 414,              /* CONNECTION  */
    CONSTRAINT = 415,              /* CONSTRAINT  */
    CONSTRAINTS = 416,             /* CONSTRAINTS  */
    CONTENT_P = 417,               /* CONTENT_P  */
    CONTINUE_P = 418,              /* CONTINUE_P  */
    CONVERSION_P = 419,            /* CONVERSION_P  */
    COPY = 420,                    /* COPY  */
    COST = 421,                    /* COST  */
    CREATE = 422,                  /* CREATE  */
    CROSS = 423,                   /* CROSS  */
    CSV = 424,                     /* CSV  */
    CUBE = 425,                    /* CUBE  */
    CURRENT_P = 426,               /* CURRENT_P  */
    CURRENT_CATALOG = 427,         /* CURRENT_CATALOG  */
    CURRENT_DATE = 428,            /* CURRENT_DATE  */
    CURRENT_ROLE = 429,            /* CURRENT_ROLE  */
    CURRENT_SCHEMA = 430,          /* CURRENT_SCHEMA  */
    CURRENT_TIME = 431,            /* CURRENT_TIME  */
    CURRENT_TIMESTAMP = 432,       /* CURRENT_TIMESTAMP  */
    CURRENT_USER = 433,            /* CURRENT_USER  */
    CURSOR = 434,                  /* CURSOR  */
    CYCLE = 435,                   /* CYCLE  */
    DATA_P = 436,                  /* DATA_P  */
    DATABASE = 437,                /* DATABASE  */
    DAY_P = 438,                   /* DAY_P  */
    DEALLOCATE = 439,              /* DEALLOCATE  */
    DEC = 440,                     /* DEC  */
    DECIMAL_P = 441,               /* DECIMAL_P  */
    DECLARE = 442,                 /* DECLARE  */
    DEFAULT = 443,                 /* DEFAULT  */
    DEFAULTS = 444,                /* DEFAULTS  */
    DEFERRABLE = 445,              /* DEFERRABLE  */
    DEFERRED = 446,                /* DEFERRED  */
    DEFINER = 447,                 /* DEFINER  */
    DELETE_P = 448,                /* DELETE_P  */
    DELIMITER = 449,               /* DELIMITER  */
    DELIMITERS = 450,              /* DELIMITERS  */
    DEPENDS = 451,                 /* DEPENDS  */
    DEPTH = 452,                   /* DEPTH  */
    DESC = 453,                    /* DESC  */
    DETACH = 454,                  /* DETACH  */
    DICTIONARY = 455,              /* DICTIONARY  */
    DISABLE_P = 456,               /* DISABLE_P  */
    DISCARD = 457,                 /* DISCARD  */
    DISTINCT = 458,                /* DISTINCT  */
    DO = 459,                      /* DO  */
    DOCUMENT_P = 460,              /* DOCUMENT_P  */
    DOMAIN_P = 461,                /* DOMAIN_P  */
    DOUBLE_P = 462,                /* DOUBLE_P  */
    DROP = 463,                    /* DROP  */
    EACH = 464,                    /* EACH  */
    ELSE = 465,                    /* ELSE  */
    ENABLE_P = 466,                /* ENABLE_P  */
    ENCODING = 467,                /* ENCODING  */
    ENCRYPTED = 468,               /* ENCRYPTED  */
    END_P = 469,                   /* END_P  */
    ENUM_P = 470,                  /* ENUM_P  */
    ESCAPE = 471,                  /* ESCAPE  */
    EVENT = 472,                   /* EVENT  */
    EXCEPT = 473,                  /* EXCEPT  */
    EXCLUDE = 474,                 /* EXCLUDE  */
    EXCLUDING = 475,               /* EXCLUDING  */
    EXCLUSIVE = 476,               /* EXCLUSIVE  */
    EXECUTE = 477,                 /* EXECUTE  */
    EXISTS = 478,                  /* EXISTS  */
    EXPLAIN = 479,                 /* EXPLAIN  */
    EXPRESSION = 480,              /* EXPRESSION  */
    EXTENSION = 481,               /* EXTENSION  */
    EXTERNAL = 482,                /* EXTERNAL  */
    EXTRACT = 483,                 /* EXTRACT  */
    FALSE_P = 484,                 /* FALSE_P  */
    FAMILY = 485,                  /* FAMILY  */
    FETCH = 486,                   /* FETCH  */
    FILTER = 487,                  /* FILTER  */
    FINALIZE = 488,                /* FINALIZE  */
    FIRST_P = 489,                 /* FIRST_P  */
    FLOAT_P = 490,                 /* FLOAT_P  */
    FOLLOWING = 491,               /* FOLLOWING  */
    FOR = 492,                     /* FOR  */
    FORCE = 493,                   /* FORCE  */
    FOREIGN = 494,                 /* FOREIGN  */
    FORWARD = 495,                 /* FORWARD  */
    FREEZE = 496,                  /* FREEZE  */
    FROM = 497,                    /* FROM  */
    FULL = 498,                    /* FULL  */
    FUNCTION = 499,                /* FUNCTION  */
    FUNCTIONS = 500,               /* FUNCTIONS  */
    GENERATED = 501,               /* GENERATED  */
    GLOBAL = 502,                  /* GLOBAL  */
    GRANT = 503,                   /* GRANT  */
    GRANTED = 504,                 /* GRANTED  */
    GREATEST = 505,                /* GREATEST  */
    GROUP_P = 506,                 /* GROUP_P  */
    GROUPING = 507,                /* GROUPING  */
    GROUPS = 508,                  /* GROUPS  */
    HANDLER = 509,                 /* HANDLER  */
    HAVING = 510,                  /* HAVING  */
    HEADER_P = 511,                /* HEADER_P  */
    HOLD = 512,                    /* HOLD  */
    HOUR_P = 513,                  /* HOUR_P  */
    IDENTITY_P = 514,              /* IDENTITY_P  */
    IF_P = 515,                    /* IF_P  */
    ILIKE = 516,                   /* ILIKE  */
    IMMEDIATE = 517,               /* IMMEDIATE  */
    IMMUTABLE = 518,               /* IMMUTABLE  */
    IMPLICIT_P = 519,              /* IMPLICIT_P  */
    IMPORT_P = 520,                /* IMPORT_P  */
    IN_P = 521,                    /* IN_P  */
    INCLUDE = 522,                 /* INCLUDE  */
    INCLUDING = 523,               /* INCLUDING  */
    INCREMENT = 524,               /* INCREMENT  */
    INDEX = 525,                   /* INDEX  */
    INDEXES = 526,                 /* INDEXES  */
    INHERIT = 527,                 /* INHERIT  */
    INHERITS = 528,                /* INHERITS  */
    INITIALLY = 529,               /* INITIALLY  */
    INLINE_P = 530,                /* INLINE_P  */
    INNER_P = 531,                 /* INNER_P  */
    INOUT = 532,                   /* INOUT  */
    INPUT_P = 533,                 /* INPUT_P  */
    INSENSITIVE = 534,             /* INSENSITIVE  */
    INSERT = 535,                  /* INSERT  */
    INSTEAD = 536,                 /* INSTEAD  */
    INT_P = 537,                   /* INT_P  */
    INTEGER = 538,                 /* INTEGER  */
    INTERSECT = 539,               /* INTERSECT  */
    INTERVAL = 540,                /* INTERVAL  */
    INTO = 541,                    /* INTO  */
    INVOKER = 542,                 /* INVOKER  */
    IS = 543,                      /* IS  */
    ISNULL = 544,                  /* ISNULL  */
    ISOLATION = 545,               /* ISOLATION  */
    JOIN = 546,                    /* JOIN  */
    KEY = 547,                     /* KEY  */
    LABEL = 548,                   /* LABEL  */
    LANGUAGE = 549,                /* LANGUAGE  */
    LARGE_P = 550,                 /* LARGE_P  */
    LAST_P = 551,                  /* LAST_P  */
    LATERAL_P = 552,               /* LATERAL_P  */
    LEADING = 553,                 /* LEADING  */
    LEAKPROOF = 554,               /* LEAKPROOF  */
    LEAST = 555,                   /* LEAST  */
    LEFT = 556,                    /* LEFT  */
    LEVEL = 557,                   /* LEVEL  */
    LIKE = 558,                    /* LIKE  */
    LIMIT = 559,                   /* LIMIT  */
    LISTEN = 560,                  /* LISTEN  */
    LOAD = 561,                    /* LOAD  */
    LOCAL = 562,                   /* LOCAL  */
    LOCALTIME = 563,               /* LOCALTIME  */
    LOCALTIMESTAMP = 564,          /* LOCALTIMESTAMP  */
    LOCATION = 565,                /* LOCATION  */
    LOCK_P = 566,                  /* LOCK_P  */
    LOCKED = 567,                  /* LOCKED  */
    LOGGED = 568,                  /* LOGGED  */
    MAPPING = 569,                 /* MAPPING  */
    MATCH = 570,                   /* MATCH  */
    MATERIALIZED = 571,            /* MATERIALIZED  */
    MAXVALUE = 572,                /* MAXVALUE  */
    METHOD = 573,                  /* METHOD  */
    MINUTE_P = 574,                /* MINUTE_P  */
    MINVALUE = 575,                /* MINVALUE  */
    MODE = 576,                    /* MODE  */
    MONTH_P = 577,                 /* MONTH_P  */
    MOVE = 578,                    /* MOVE  */
    NAME_P = 579,                  /* NAME_P  */
    NAMES = 580,                   /* NAMES  */
    NATIONAL = 581,                /* NATIONAL  */
    NATURAL = 582,                 /* NATURAL  */
    NCHAR = 583,                   /* NCHAR  */
    NEW = 584,                     /* NEW  */
    NEXT = 585,                    /* NEXT  */
    NFC = 586,                     /* NFC  */
    NFD = 587,                     /* NFD  */
    NFKC = 588,                    /* NFKC  */
    NFKD = 589,                    /* NFKD  */
    NO = 590,                      /* NO  */
    NONE = 591,                    /* NONE  */
    NORMALIZE = 592,               /* NORMALIZE  */
    NORMALIZED = 593,              /* NORMALIZED  */
    NOT = 594,                     /* NOT  */
    NOTHING = 595,                 /* NOTHING  */
    NOTIFY = 596,                  /* NOTIFY  */
    NOTNULL = 597,                 /* NOTNULL  */
    NOWAIT = 598,                  /* NOWAIT  */
    NULL_P = 599,                  /* NULL_P  */
    NULLIF = 600,                  /* NULLIF  */
    NULLS_P = 601,                 /* NULLS_P  */
    NUMERIC = 602,                 /* NUMERIC  */
    OBJECT_P = 603,                /* OBJECT_P  */
    OF = 604,                      /* OF  */
    OFF = 605,                     /* OFF  */
    OFFSET = 606,                  /* OFFSET  */
    OIDS = 607,                    /* OIDS  */
    OLD = 608,                     /* OLD  */
    ON = 609,                      /* ON  */
    ONLY = 610,                    /* ONLY  */
    OPERATOR = 611,                /* OPERATOR  */
    OPTION = 612,                  /* OPTION  */
    OPTIONS = 613,                 /* OPTIONS  */
    OR = 614,                      /* OR  */
    ORDER = 615,                   /* ORDER  */
    ORDINALITY = 616,              /* ORDINALITY  */
    OTHERS = 617,                  /* OTHERS  */
    OUT_P = 618,                   /* OUT_P  */
    OUTER_P = 619,                 /* OUTER_P  */
    OVER = 620,                    /* OVER  */
    OVERLAPS = 621,                /* OVERLAPS  */
    OVERLAY = 622,                 /* OVERLAY  */
    OVERRIDING = 623,              /* OVERRIDING  */
    OWNED = 624,                   /* OWNED  */
    OWNER = 625,                   /* OWNER  */
    PARALLEL = 626,                /* PARALLEL  */
    PARSER = 627,                  /* PARSER  */
    PARTIAL = 628,                 /* PARTIAL  */
    PARTITION = 629,               /* PARTITION  */
    PASSING = 630,                 /* PASSING  */
    PASSWORD = 631,                /* PASSWORD  */
    PLACING = 632,                 /* PLACING  */
    PLANS = 633,                   /* PLANS  */
    POLICY = 634,                  /* POLICY  */
    POSITION = 635,                /* POSITION  */
    PRECEDING = 636,               /* PRECEDING  */
    PRECISION = 637,               /* PRECISION  */
    PRESERVE = 638,                /* PRESERVE  */
    PREPARE = 639,                 /* PREPARE  */
    PREPARED = 640,                /* PREPARED  */
    PRIMARY = 641,                 /* PRIMARY  */
    PRIOR = 642,                   /* PRIOR  */
    PRIVILEGES = 643,              /* PRIVILEGES  */
    PROCEDURAL = 644,              /* PROCEDURAL  */
    PROCEDURE = 645,               /* PROCEDURE  */
    PROCEDURES = 646,              /* PROCEDURES  */
    PROGRAM = 647,                 /* PROGRAM  */
    PUBLICATION = 648,             /* PUBLICATION  */
    QUOTE = 649,                   /* QUOTE  */
    RANGE = 650,                   /* RANGE  */
    READ = 651,                    /* READ  */
    REAL = 652,                    /* REAL  */
    REASSIGN = 653,                /* REASSIGN  */
    RECHECK = 654,                 /* RECHECK  */
    RECURSIVE = 655,               /* RECURSIVE  */
    REF_P = 656,                   /* REF_P  */
    REFERENCES = 657,              /* REFERENCES  */
    REFERENCING = 658,             /* REFERENCING  */
    REFRESH = 659,                 /* REFRESH  */
    REINDEX = 660,                 /* REINDEX  */
    RELATIVE_P = 661,              /* RELATIVE_P  */
    RELEASE = 662,                 /* RELEASE  */
    RENAME = 663,                  /* RENAME  */
    REPEATABLE = 664,              /* REPEATABLE  */
    REPLACE = 665,                 /* REPLACE  */
    REPLICA = 666,                 /* REPLICA  */
    RESET = 667,                   /* RESET  */
    RESTART = 668,                 /* RESTART  */
    RESTRICT = 669,                /* RESTRICT  */
    RETURN = 670,                  /* RETURN  */
    RETURNING = 671,               /* RETURNING  */
    RETURNS = 672,                 /* RETURNS  */
    REVOKE = 673,                  /* REVOKE  */
    RIGHT = 674,                   /* RIGHT  */
    ROLE = 675,                    /* ROLE  */
    ROLLBACK = 676,                /* ROLLBACK  */
    ROLLUP = 677,                  /* ROLLUP  */
    ROUTINE = 678,                 /* ROUTINE  */
    ROUTINES = 679,                /* ROUTINES  */
    ROW = 680,                     /* ROW  */
    ROWS = 681,                    /* ROWS  */
    RULE = 682,                    /* RULE  */
    SAVEPOINT = 683,               /* SAVEPOINT  */
    SCHEMA = 684,                  /* SCHEMA  */
    SCHEMAS = 685,                 /* SCHEMAS  */
    SCROLL = 686,                  /* SCROLL  */
    SEARCH = 687,                  /* SEARCH  */
    SECOND_P = 688,                /* SECOND_P  */
    SECURITY = 689,                /* SECURITY  */
    SELECT = 690,                  /* SELECT  */
    SEQUENCE = 691,                /* SEQUENCE  */
    SEQUENCES = 692,               /* SEQUENCES  */
    SERIALIZABLE = 693,            /* SERIALIZABLE  */
    SERVER = 694,                  /* SERVER  */
    SESSION = 695,                 /* SESSION  */
    SESSION_USER = 696,            /* SESSION_USER  */
    SET = 697,                     /* SET  */
    SETS = 698,                    /* SETS  */
    SETOF = 699,                   /* SETOF  */
    SHARE = 700,                   /* SHARE  */
    SHOW = 701,                    /* SHOW  */
    SIMILAR = 702,                 /* SIMILAR  */
    SIMPLE = 703,                  /* SIMPLE  */
    SKIP = 704,                    /* SKIP  */
    SMALLINT = 705,                /* SMALLINT  */
    SNAPSHOT = 706,                /* SNAPSHOT  */
    SOME = 707,                    /* SOME  */
    SQL_P = 708,                   /* SQL_P  */
    STABLE = 709,                  /* STABLE  */
    STANDALONE_P = 710,            /* STANDALONE_P  */
    START = 711,                   /* START  */
    STATEMENT = 712,               /* STATEMENT  */
    STATISTICS = 713,              /* STATISTICS  */
    STDIN = 714,                   /* STDIN  */
    STDOUT = 715,                  /* STDOUT  */
    STORAGE = 716,                 /* STORAGE  */
    STORED = 717,                  /* STORED  */
    STRICT_P = 718,                /* STRICT_P  */
    STRIP_P = 719,                 /* STRIP_P  */
    SUBSCRIPTION = 720,            /* SUBSCRIPTION  */
    SUBSTRING = 721,               /* SUBSTRING  */
    SUPPORT = 722,                 /* SUPPORT  */
    SYMMETRIC = 723,               /* SYMMETRIC  */
    SYSID = 724,                   /* SYSID  */
    SYSTEM_P = 725,                /* SYSTEM_P  */
    TABLE = 726,                   /* TABLE  */
    TABLES = 727,                  /* TABLES  */
    TABLESAMPLE = 728,             /* TABLESAMPLE  */
    TABLESPACE = 729,              /* TABLESPACE  */
    TEMP = 730,                    /* TEMP  */
    TEMPLATE = 731,                /* TEMPLATE  */
    TEMPORARY = 732,               /* TEMPORARY  */
    TEXT_P = 733,                  /* TEXT_P  */
    THEN = 734,                    /* THEN  */
    TIES = 735,                    /* TIES  */
    TIME = 736,                    /* TIME  */
    TIMESTAMP = 737,               /* TIMESTAMP  */
    TO = 738,                      /* TO  */
    TRAILING = 739,                /* TRAILING  */
    TRANSACTION = 740,             /* TRANSACTION  */
    TRANSFORM = 741,               /* TRANSFORM  */
    TREAT = 742,                   /* TREAT  */
    TRIGGER = 743,                 /* TRIGGER  */
    TRIM = 744,                    /* TRIM  */
    TRUE_P = 745,                  /* TRUE_P  */
    TRUNCATE = 746,                /* TRUNCATE  */
    TRUSTED = 747,                 /* TRUSTED  */
    TYPE_P = 748,                  /* TYPE_P  */
    TYPES_P = 749,                 /* TYPES_P  */
    UESCAPE = 750,                 /* UESCAPE  */
    UNBOUNDED = 751,               /* UNBOUNDED  */
    UNCOMMITTED = 752,             /* UNCOMMITTED  */
    UNENCRYPTED = 753,             /* UNENCRYPTED  */
    UNION = 754,                   /* UNION  */
    UNIQUE = 755,                  /* UNIQUE  */
    UNKNOWN = 756,                 /* UNKNOWN  */
    UNLISTEN = 757,                /* UNLISTEN  */
    UNLOGGED = 758,                /* UNLOGGED  */
    UNTIL = 759,                   /* UNTIL  */
    UPDATE = 760,                  /* UPDATE  */
    USER = 761,                    /* USER  */
    USING = 762,                   /* USING  */
    VACUUM = 763,                  /* VACUUM  */
    VALID = 764,                   /* VALID  */
    VALIDATE = 765,                /* VALIDATE  */
    VALIDATOR = 766,               /* VALIDATOR  */
    VALUE_P = 767,                 /* VALUE_P  */
    VALUES = 768,                  /* VALUES  */
    VARCHAR = 769,                 /* VARCHAR  */
    VARIADIC = 770,                /* VARIADIC  */
    VARYING = 771,                 /* VARYING  */
    VERBOSE = 772,                 /* VERBOSE  */
    VERSION_P = 773,               /* VERSION_P  */
    VIEW = 774,                    /* VIEW  */
    VIEWS = 775,                   /* VIEWS  */
    VOLATILE = 776,                /* VOLATILE  */
    WHEN = 777,                    /* WHEN  */
    WHERE = 778,                   /* WHERE  */
    WHITESPACE_P = 779,            /* WHITESPACE_P  */
    WINDOW = 780,                  /* WINDOW  */
    WITH = 781,                    /* WITH  */
    WITHIN = 782,                  /* WITHIN  */
    WITHOUT = 783,                 /* WITHOUT  */
    WORK = 784,                    /* WORK  */
    WRAPPER = 785,                 /* WRAPPER  */
    WRITE = 786,                   /* WRITE  */
    XML_P = 787,                   /* XML_P  */
    XMLATTRIBUTES = 788,           /* XMLATTRIBUTES  */
    XMLCONCAT = 789,               /* XMLCONCAT  */
    XMLELEMENT = 790,              /* XMLELEMENT  */
    XMLEXISTS = 791,               /* XMLEXISTS  */
    XMLFOREST = 792,               /* XMLFOREST  */
    XMLNAMESPACES = 793,           /* XMLNAMESPACES  */
    XMLPARSE = 794,                /* XMLPARSE  */
    XMLPI = 795,                   /* XMLPI  */
    XMLROOT = 796,                 /* XMLROOT  */
    XMLSERIALIZE = 797,            /* XMLSERIALIZE  */
    XMLTABLE = 798,                /* XMLTABLE  */
    YEAR_P = 799,                  /* YEAR_P  */
    YES_P = 800,                   /* YES_P  */
    ZONE = 801,                    /* ZONE  */
    NOT_LA = 802,                  /* NOT_LA  */
    NULLS_LA = 803,                /* NULLS_LA  */
    WITH_LA = 804,                 /* WITH_LA  */
    MODE_TYPE_NAME = 805,          /* MODE_TYPE_NAME  */
    MODE_PLPGSQL_EXPR = 806,       /* MODE_PLPGSQL_EXPR  */
    MODE_PLPGSQL_ASSIGN1 = 807,    /* MODE_PLPGSQL_ASSIGN1  */
    MODE_PLPGSQL_ASSIGN2 = 808,    /* MODE_PLPGSQL_ASSIGN2  */
    MODE_PLPGSQL_ASSIGN3 = 809,    /* MODE_PLPGSQL_ASSIGN3  */
    UMINUS = 810                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 612 "preproc.y"

	double	dval;
	char	*str;
	int		ival;
	struct	when		action;
	struct	index		index;
	int		tagname;
	struct	this_type	type;
	enum	ECPGttype	type_enum;
	enum	ECPGdtype	dtype_enum;
	struct	fetch_desc	descriptor;
	struct  su_symbol	struct_union;
	struct	prep		prep;
	struct	exec		exec;
	struct describe		describe;

#line 636 "preproc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE base_yylval;
extern YYLTYPE base_yylloc;

int base_yyparse (void);


#endif /* !YY_BASE_YY_PREPROC_H_INCLUDED  */

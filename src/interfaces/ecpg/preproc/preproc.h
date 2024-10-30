/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
    ABSENT = 346,                  /* ABSENT  */
    ABSOLUTE_P = 347,              /* ABSOLUTE_P  */
    ACCESS = 348,                  /* ACCESS  */
    ACTION = 349,                  /* ACTION  */
    ADD_P = 350,                   /* ADD_P  */
    ADMIN = 351,                   /* ADMIN  */
    AFTER = 352,                   /* AFTER  */
    AGGREGATE = 353,               /* AGGREGATE  */
    ALL = 354,                     /* ALL  */
    ALSO = 355,                    /* ALSO  */
    ALTER = 356,                   /* ALTER  */
    ALWAYS = 357,                  /* ALWAYS  */
    ANALYSE = 358,                 /* ANALYSE  */
    ANALYZE = 359,                 /* ANALYZE  */
    AND = 360,                     /* AND  */
    ANY = 361,                     /* ANY  */
    ARRAY = 362,                   /* ARRAY  */
    AS = 363,                      /* AS  */
    ASC = 364,                     /* ASC  */
    ASENSITIVE = 365,              /* ASENSITIVE  */
    ASSERTION = 366,               /* ASSERTION  */
    ASSIGNMENT = 367,              /* ASSIGNMENT  */
    ASYMMETRIC = 368,              /* ASYMMETRIC  */
    ATOMIC = 369,                  /* ATOMIC  */
    AT = 370,                      /* AT  */
    ATTACH = 371,                  /* ATTACH  */
    ATTRIBUTE = 372,               /* ATTRIBUTE  */
    AUTHORIZATION = 373,           /* AUTHORIZATION  */
    BACKWARD = 374,                /* BACKWARD  */
    BEFORE = 375,                  /* BEFORE  */
    BEGIN_P = 376,                 /* BEGIN_P  */
    BETWEEN = 377,                 /* BETWEEN  */
    BIGINT = 378,                  /* BIGINT  */
    BINARY = 379,                  /* BINARY  */
    BIT = 380,                     /* BIT  */
    BOOLEAN_P = 381,               /* BOOLEAN_P  */
    BOTH = 382,                    /* BOTH  */
    BREADTH = 383,                 /* BREADTH  */
    BY = 384,                      /* BY  */
    CACHE = 385,                   /* CACHE  */
    CALL = 386,                    /* CALL  */
    CALLED = 387,                  /* CALLED  */
    CASCADE = 388,                 /* CASCADE  */
    CASCADED = 389,                /* CASCADED  */
    CASE = 390,                    /* CASE  */
    CAST = 391,                    /* CAST  */
    CATALOG_P = 392,               /* CATALOG_P  */
    CHAIN = 393,                   /* CHAIN  */
    CHAR_P = 394,                  /* CHAR_P  */
    CHARACTER = 395,               /* CHARACTER  */
    CHARACTERISTICS = 396,         /* CHARACTERISTICS  */
    CHECK = 397,                   /* CHECK  */
    CHECKPOINT = 398,              /* CHECKPOINT  */
    CLASS = 399,                   /* CLASS  */
    CLOSE = 400,                   /* CLOSE  */
    CLUSTER = 401,                 /* CLUSTER  */
    COALESCE = 402,                /* COALESCE  */
    COLLATE = 403,                 /* COLLATE  */
    COLLATION = 404,               /* COLLATION  */
    COLUMN = 405,                  /* COLUMN  */
    COLUMNS = 406,                 /* COLUMNS  */
    COMMENT = 407,                 /* COMMENT  */
    COMMENTS = 408,                /* COMMENTS  */
    COMMIT = 409,                  /* COMMIT  */
    COMMITTED = 410,               /* COMMITTED  */
    COMPRESSION = 411,             /* COMPRESSION  */
    CONCURRENTLY = 412,            /* CONCURRENTLY  */
    CONFIGURATION = 413,           /* CONFIGURATION  */
    CONFLICT = 414,                /* CONFLICT  */
    CONNECTION = 415,              /* CONNECTION  */
    CONSTRAINT = 416,              /* CONSTRAINT  */
    CONSTRAINTS = 417,             /* CONSTRAINTS  */
    CONTENT_P = 418,               /* CONTENT_P  */
    CONTINUE_P = 419,              /* CONTINUE_P  */
    CONVERSION_P = 420,            /* CONVERSION_P  */
    COPY = 421,                    /* COPY  */
    COST = 422,                    /* COST  */
    CREATE = 423,                  /* CREATE  */
    CROSS = 424,                   /* CROSS  */
    CSV = 425,                     /* CSV  */
    CUBE = 426,                    /* CUBE  */
    CURRENT_P = 427,               /* CURRENT_P  */
    CURRENT_CATALOG = 428,         /* CURRENT_CATALOG  */
    CURRENT_DATE = 429,            /* CURRENT_DATE  */
    CURRENT_ROLE = 430,            /* CURRENT_ROLE  */
    CURRENT_SCHEMA = 431,          /* CURRENT_SCHEMA  */
    CURRENT_TIME = 432,            /* CURRENT_TIME  */
    CURRENT_TIMESTAMP = 433,       /* CURRENT_TIMESTAMP  */
    CURRENT_USER = 434,            /* CURRENT_USER  */
    CURSOR = 435,                  /* CURSOR  */
    CYCLE = 436,                   /* CYCLE  */
    DATA_P = 437,                  /* DATA_P  */
    DATABASE = 438,                /* DATABASE  */
    DAY_P = 439,                   /* DAY_P  */
    DEALLOCATE = 440,              /* DEALLOCATE  */
    DEC = 441,                     /* DEC  */
    DECIMAL_P = 442,               /* DECIMAL_P  */
    DECLARE = 443,                 /* DECLARE  */
    DEFAULT = 444,                 /* DEFAULT  */
    DEFAULTS = 445,                /* DEFAULTS  */
    DEFERRABLE = 446,              /* DEFERRABLE  */
    DEFERRED = 447,                /* DEFERRED  */
    DEFINER = 448,                 /* DEFINER  */
    DELETE_P = 449,                /* DELETE_P  */
    DELIMITER = 450,               /* DELIMITER  */
    DELIMITERS = 451,              /* DELIMITERS  */
    DEPENDS = 452,                 /* DEPENDS  */
    DEPTH = 453,                   /* DEPTH  */
    DESC = 454,                    /* DESC  */
    DETACH = 455,                  /* DETACH  */
    DICTIONARY = 456,              /* DICTIONARY  */
    DISABLE_P = 457,               /* DISABLE_P  */
    DISCARD = 458,                 /* DISCARD  */
    DISTINCT = 459,                /* DISTINCT  */
    DO = 460,                      /* DO  */
    DOCUMENT_P = 461,              /* DOCUMENT_P  */
    DOMAIN_P = 462,                /* DOMAIN_P  */
    DOUBLE_P = 463,                /* DOUBLE_P  */
    DROP = 464,                    /* DROP  */
    EACH = 465,                    /* EACH  */
    ELSE = 466,                    /* ELSE  */
    ENABLE_P = 467,                /* ENABLE_P  */
    ENCODING = 468,                /* ENCODING  */
    ENCRYPTED = 469,               /* ENCRYPTED  */
    END_P = 470,                   /* END_P  */
    ENUM_P = 471,                  /* ENUM_P  */
    ESCAPE = 472,                  /* ESCAPE  */
    EVENT = 473,                   /* EVENT  */
    EXCEPT = 474,                  /* EXCEPT  */
    EXCLUDE = 475,                 /* EXCLUDE  */
    EXCLUDING = 476,               /* EXCLUDING  */
    EXCLUSIVE = 477,               /* EXCLUSIVE  */
    EXECUTE = 478,                 /* EXECUTE  */
    EXISTS = 479,                  /* EXISTS  */
    EXPLAIN = 480,                 /* EXPLAIN  */
    EXPRESSION = 481,              /* EXPRESSION  */
    EXTENSION = 482,               /* EXTENSION  */
    EXTERNAL = 483,                /* EXTERNAL  */
    EXTRACT = 484,                 /* EXTRACT  */
    FALSE_P = 485,                 /* FALSE_P  */
    FAMILY = 486,                  /* FAMILY  */
    FETCH = 487,                   /* FETCH  */
    FILTER = 488,                  /* FILTER  */
    FINALIZE = 489,                /* FINALIZE  */
    FIRST_P = 490,                 /* FIRST_P  */
    FLOAT_P = 491,                 /* FLOAT_P  */
    FOLLOWING = 492,               /* FOLLOWING  */
    FOR = 493,                     /* FOR  */
    FORCE = 494,                   /* FORCE  */
    FOREIGN = 495,                 /* FOREIGN  */
    FORMAT = 496,                  /* FORMAT  */
    FORWARD = 497,                 /* FORWARD  */
    FREEZE = 498,                  /* FREEZE  */
    FROM = 499,                    /* FROM  */
    FULL = 500,                    /* FULL  */
    FUNCTION = 501,                /* FUNCTION  */
    FUNCTIONS = 502,               /* FUNCTIONS  */
    GENERATED = 503,               /* GENERATED  */
    GLOBAL = 504,                  /* GLOBAL  */
    GRANT = 505,                   /* GRANT  */
    GRANTED = 506,                 /* GRANTED  */
    GREATEST = 507,                /* GREATEST  */
    GROUP_P = 508,                 /* GROUP_P  */
    GROUPING = 509,                /* GROUPING  */
    GROUPS = 510,                  /* GROUPS  */
    HANDLER = 511,                 /* HANDLER  */
    HAVING = 512,                  /* HAVING  */
    HEADER_P = 513,                /* HEADER_P  */
    HOLD = 514,                    /* HOLD  */
    HOUR_P = 515,                  /* HOUR_P  */
    IDENTITY_P = 516,              /* IDENTITY_P  */
    IF_P = 517,                    /* IF_P  */
    ILIKE = 518,                   /* ILIKE  */
    IMMEDIATE = 519,               /* IMMEDIATE  */
    IMMUTABLE = 520,               /* IMMUTABLE  */
    IMPLICIT_P = 521,              /* IMPLICIT_P  */
    IMPORT_P = 522,                /* IMPORT_P  */
    IN_P = 523,                    /* IN_P  */
    INCLUDE = 524,                 /* INCLUDE  */
    INCLUDING = 525,               /* INCLUDING  */
    INCREMENT = 526,               /* INCREMENT  */
    INDENT = 527,                  /* INDENT  */
    INDEX = 528,                   /* INDEX  */
    INDEXES = 529,                 /* INDEXES  */
    INHERIT = 530,                 /* INHERIT  */
    INHERITS = 531,                /* INHERITS  */
    INITIALLY = 532,               /* INITIALLY  */
    INLINE_P = 533,                /* INLINE_P  */
    INNER_P = 534,                 /* INNER_P  */
    INOUT = 535,                   /* INOUT  */
    INPUT_P = 536,                 /* INPUT_P  */
    INSENSITIVE = 537,             /* INSENSITIVE  */
    INSERT = 538,                  /* INSERT  */
    INSTEAD = 539,                 /* INSTEAD  */
    INT_P = 540,                   /* INT_P  */
    INTEGER = 541,                 /* INTEGER  */
    INTERSECT = 542,               /* INTERSECT  */
    INTERVAL = 543,                /* INTERVAL  */
    INTO = 544,                    /* INTO  */
    INVOKER = 545,                 /* INVOKER  */
    IS = 546,                      /* IS  */
    ISNULL = 547,                  /* ISNULL  */
    ISOLATION = 548,               /* ISOLATION  */
    JOIN = 549,                    /* JOIN  */
    JSON = 550,                    /* JSON  */
    JSON_ARRAY = 551,              /* JSON_ARRAY  */
    JSON_ARRAYAGG = 552,           /* JSON_ARRAYAGG  */
    JSON_OBJECT = 553,             /* JSON_OBJECT  */
    JSON_OBJECTAGG = 554,          /* JSON_OBJECTAGG  */
    KEY = 555,                     /* KEY  */
    KEYS = 556,                    /* KEYS  */
    LABEL = 557,                   /* LABEL  */
    LANGUAGE = 558,                /* LANGUAGE  */
    LARGE_P = 559,                 /* LARGE_P  */
    LAST_P = 560,                  /* LAST_P  */
    LATERAL_P = 561,               /* LATERAL_P  */
    LEADING = 562,                 /* LEADING  */
    LEAKPROOF = 563,               /* LEAKPROOF  */
    LEAST = 564,                   /* LEAST  */
    LEFT = 565,                    /* LEFT  */
    LEVEL = 566,                   /* LEVEL  */
    LIKE = 567,                    /* LIKE  */
    LIMIT = 568,                   /* LIMIT  */
    LISTEN = 569,                  /* LISTEN  */
    LOAD = 570,                    /* LOAD  */
    LOCAL = 571,                   /* LOCAL  */
    LOCALTIME = 572,               /* LOCALTIME  */
    LOCALTIMESTAMP = 573,          /* LOCALTIMESTAMP  */
    LOCATION = 574,                /* LOCATION  */
    LOCK_P = 575,                  /* LOCK_P  */
    LOCKED = 576,                  /* LOCKED  */
    LOGGED = 577,                  /* LOGGED  */
    MAPPING = 578,                 /* MAPPING  */
    MATCH = 579,                   /* MATCH  */
    MATCHED = 580,                 /* MATCHED  */
    MATERIALIZED = 581,            /* MATERIALIZED  */
    MAXVALUE = 582,                /* MAXVALUE  */
    MERGE = 583,                   /* MERGE  */
    METHOD = 584,                  /* METHOD  */
    MINUTE_P = 585,                /* MINUTE_P  */
    MINVALUE = 586,                /* MINVALUE  */
    MODE = 587,                    /* MODE  */
    MONTH_P = 588,                 /* MONTH_P  */
    MOVE = 589,                    /* MOVE  */
    NAME_P = 590,                  /* NAME_P  */
    NAMES = 591,                   /* NAMES  */
    NATIONAL = 592,                /* NATIONAL  */
    NATURAL = 593,                 /* NATURAL  */
    NCHAR = 594,                   /* NCHAR  */
    NEW = 595,                     /* NEW  */
    NEXT = 596,                    /* NEXT  */
    NFC = 597,                     /* NFC  */
    NFD = 598,                     /* NFD  */
    NFKC = 599,                    /* NFKC  */
    NFKD = 600,                    /* NFKD  */
    NO = 601,                      /* NO  */
    NONE = 602,                    /* NONE  */
    NORMALIZE = 603,               /* NORMALIZE  */
    NORMALIZED = 604,              /* NORMALIZED  */
    NOT = 605,                     /* NOT  */
    NOTHING = 606,                 /* NOTHING  */
    NOTIFY = 607,                  /* NOTIFY  */
    NOTNULL = 608,                 /* NOTNULL  */
    NOWAIT = 609,                  /* NOWAIT  */
    NULL_P = 610,                  /* NULL_P  */
    NULLIF = 611,                  /* NULLIF  */
    NULLS_P = 612,                 /* NULLS_P  */
    NUMERIC = 613,                 /* NUMERIC  */
    OBJECT_P = 614,                /* OBJECT_P  */
    OF = 615,                      /* OF  */
    OFF = 616,                     /* OFF  */
    OFFSET = 617,                  /* OFFSET  */
    OIDS = 618,                    /* OIDS  */
    OLD = 619,                     /* OLD  */
    ON = 620,                      /* ON  */
    ONLY = 621,                    /* ONLY  */
    OPERATOR = 622,                /* OPERATOR  */
    OPTION = 623,                  /* OPTION  */
    OPTIONS = 624,                 /* OPTIONS  */
    OR = 625,                      /* OR  */
    ORDER = 626,                   /* ORDER  */
    ORDINALITY = 627,              /* ORDINALITY  */
    OTHERS = 628,                  /* OTHERS  */
    OUT_P = 629,                   /* OUT_P  */
    OUTER_P = 630,                 /* OUTER_P  */
    OVER = 631,                    /* OVER  */
    OVERLAPS = 632,                /* OVERLAPS  */
    OVERLAY = 633,                 /* OVERLAY  */
    OVERRIDING = 634,              /* OVERRIDING  */
    OWNED = 635,                   /* OWNED  */
    OWNER = 636,                   /* OWNER  */
    PARALLEL = 637,                /* PARALLEL  */
    PARAMETER = 638,               /* PARAMETER  */
    PARSER = 639,                  /* PARSER  */
    PARTIAL = 640,                 /* PARTIAL  */
    PARTITION = 641,               /* PARTITION  */
    PASSING = 642,                 /* PASSING  */
    PASSWORD = 643,                /* PASSWORD  */
    PLACING = 644,                 /* PLACING  */
    PLANS = 645,                   /* PLANS  */
    POLICY = 646,                  /* POLICY  */
    POSITION = 647,                /* POSITION  */
    PRECEDING = 648,               /* PRECEDING  */
    PRECISION = 649,               /* PRECISION  */
    PRESERVE = 650,                /* PRESERVE  */
    PREPARE = 651,                 /* PREPARE  */
    PREPARED = 652,                /* PREPARED  */
    PRIMARY = 653,                 /* PRIMARY  */
    PRIOR = 654,                   /* PRIOR  */
    PRIVILEGES = 655,              /* PRIVILEGES  */
    PROCEDURAL = 656,              /* PROCEDURAL  */
    PROCEDURE = 657,               /* PROCEDURE  */
    PROCEDURES = 658,              /* PROCEDURES  */
    PROGRAM = 659,                 /* PROGRAM  */
    PUBLICATION = 660,             /* PUBLICATION  */
    QUOTE = 661,                   /* QUOTE  */
    RANGE = 662,                   /* RANGE  */
    READ = 663,                    /* READ  */
    REAL = 664,                    /* REAL  */
    REASSIGN = 665,                /* REASSIGN  */
    RECHECK = 666,                 /* RECHECK  */
    RECURSIVE = 667,               /* RECURSIVE  */
    REF_P = 668,                   /* REF_P  */
    REFERENCES = 669,              /* REFERENCES  */
    REFERENCING = 670,             /* REFERENCING  */
    REFRESH = 671,                 /* REFRESH  */
    REINDEX = 672,                 /* REINDEX  */
    RELATIVE_P = 673,              /* RELATIVE_P  */
    RELEASE = 674,                 /* RELEASE  */
    RENAME = 675,                  /* RENAME  */
    REPEATABLE = 676,              /* REPEATABLE  */
    REPLACE = 677,                 /* REPLACE  */
    REPLICA = 678,                 /* REPLICA  */
    RESET = 679,                   /* RESET  */
    RESTART = 680,                 /* RESTART  */
    RESTRICT = 681,                /* RESTRICT  */
    RETURN = 682,                  /* RETURN  */
    RETURNING = 683,               /* RETURNING  */
    RETURNS = 684,                 /* RETURNS  */
    REVOKE = 685,                  /* REVOKE  */
    RIGHT = 686,                   /* RIGHT  */
    ROLE = 687,                    /* ROLE  */
    ROLLBACK = 688,                /* ROLLBACK  */
    ROLLUP = 689,                  /* ROLLUP  */
    ROUTINE = 690,                 /* ROUTINE  */
    ROUTINES = 691,                /* ROUTINES  */
    ROW = 692,                     /* ROW  */
    ROWS = 693,                    /* ROWS  */
    RULE = 694,                    /* RULE  */
    SAVEPOINT = 695,               /* SAVEPOINT  */
    SCALAR = 696,                  /* SCALAR  */
    SCHEMA = 697,                  /* SCHEMA  */
    SCHEMAS = 698,                 /* SCHEMAS  */
    SCROLL = 699,                  /* SCROLL  */
    SEARCH = 700,                  /* SEARCH  */
    SECOND_P = 701,                /* SECOND_P  */
    SECURITY = 702,                /* SECURITY  */
    SELECT = 703,                  /* SELECT  */
    SEQUENCE = 704,                /* SEQUENCE  */
    SEQUENCES = 705,               /* SEQUENCES  */
    SERIALIZABLE = 706,            /* SERIALIZABLE  */
    SERVER = 707,                  /* SERVER  */
    SESSION = 708,                 /* SESSION  */
    SESSION_USER = 709,            /* SESSION_USER  */
    SET = 710,                     /* SET  */
    SETS = 711,                    /* SETS  */
    SETOF = 712,                   /* SETOF  */
    SHARE = 713,                   /* SHARE  */
    SHOW = 714,                    /* SHOW  */
    SIMILAR = 715,                 /* SIMILAR  */
    SIMPLE = 716,                  /* SIMPLE  */
    SKIP = 717,                    /* SKIP  */
    SMALLINT = 718,                /* SMALLINT  */
    SNAPSHOT = 719,                /* SNAPSHOT  */
    SOME = 720,                    /* SOME  */
    SQL_P = 721,                   /* SQL_P  */
    STABLE = 722,                  /* STABLE  */
    STANDALONE_P = 723,            /* STANDALONE_P  */
    START = 724,                   /* START  */
    STATEMENT = 725,               /* STATEMENT  */
    STATISTICS = 726,              /* STATISTICS  */
    STDIN = 727,                   /* STDIN  */
    STDOUT = 728,                  /* STDOUT  */
    STORAGE = 729,                 /* STORAGE  */
    STORED = 730,                  /* STORED  */
    STRICT_P = 731,                /* STRICT_P  */
    STRIP_P = 732,                 /* STRIP_P  */
    SUBSCRIPTION = 733,            /* SUBSCRIPTION  */
    SUBSTRING = 734,               /* SUBSTRING  */
    SUPPORT = 735,                 /* SUPPORT  */
    SYMMETRIC = 736,               /* SYMMETRIC  */
    SYSID = 737,                   /* SYSID  */
    SYSTEM_P = 738,                /* SYSTEM_P  */
    SYSTEM_USER = 739,             /* SYSTEM_USER  */
    TABLE = 740,                   /* TABLE  */
    TABLES = 741,                  /* TABLES  */
    TABLESAMPLE = 742,             /* TABLESAMPLE  */
    TABLESPACE = 743,              /* TABLESPACE  */
    TEMP = 744,                    /* TEMP  */
    TEMPLATE = 745,                /* TEMPLATE  */
    TEMPORARY = 746,               /* TEMPORARY  */
    TEXT_P = 747,                  /* TEXT_P  */
    THEN = 748,                    /* THEN  */
    TIES = 749,                    /* TIES  */
    TIME = 750,                    /* TIME  */
    TIMESTAMP = 751,               /* TIMESTAMP  */
    TO = 752,                      /* TO  */
    TRAILING = 753,                /* TRAILING  */
    TRANSACTION = 754,             /* TRANSACTION  */
    TRANSFORM = 755,               /* TRANSFORM  */
    TREAT = 756,                   /* TREAT  */
    TRIGGER = 757,                 /* TRIGGER  */
    TRIM = 758,                    /* TRIM  */
    TRUE_P = 759,                  /* TRUE_P  */
    TRUNCATE = 760,                /* TRUNCATE  */
    TRUSTED = 761,                 /* TRUSTED  */
    TYPE_P = 762,                  /* TYPE_P  */
    TYPES_P = 763,                 /* TYPES_P  */
    UESCAPE = 764,                 /* UESCAPE  */
    UNBOUNDED = 765,               /* UNBOUNDED  */
    UNCOMMITTED = 766,             /* UNCOMMITTED  */
    UNENCRYPTED = 767,             /* UNENCRYPTED  */
    UNION = 768,                   /* UNION  */
    UNIQUE = 769,                  /* UNIQUE  */
    UNKNOWN = 770,                 /* UNKNOWN  */
    UNLISTEN = 771,                /* UNLISTEN  */
    UNLOGGED = 772,                /* UNLOGGED  */
    UNTIL = 773,                   /* UNTIL  */
    UPDATE = 774,                  /* UPDATE  */
    USER = 775,                    /* USER  */
    USING = 776,                   /* USING  */
    VACUUM = 777,                  /* VACUUM  */
    VALID = 778,                   /* VALID  */
    VALIDATE = 779,                /* VALIDATE  */
    VALIDATOR = 780,               /* VALIDATOR  */
    VALUE_P = 781,                 /* VALUE_P  */
    VALUES = 782,                  /* VALUES  */
    VARCHAR = 783,                 /* VARCHAR  */
    VARIADIC = 784,                /* VARIADIC  */
    VARYING = 785,                 /* VARYING  */
    VERBOSE = 786,                 /* VERBOSE  */
    VERSION_P = 787,               /* VERSION_P  */
    VIEW = 788,                    /* VIEW  */
    VIEWS = 789,                   /* VIEWS  */
    VOLATILE = 790,                /* VOLATILE  */
    WHEN = 791,                    /* WHEN  */
    WHERE = 792,                   /* WHERE  */
    WHITESPACE_P = 793,            /* WHITESPACE_P  */
    WINDOW = 794,                  /* WINDOW  */
    WITH = 795,                    /* WITH  */
    WITHIN = 796,                  /* WITHIN  */
    WITHOUT = 797,                 /* WITHOUT  */
    WORK = 798,                    /* WORK  */
    WRAPPER = 799,                 /* WRAPPER  */
    WRITE = 800,                   /* WRITE  */
    XML_P = 801,                   /* XML_P  */
    XMLATTRIBUTES = 802,           /* XMLATTRIBUTES  */
    XMLCONCAT = 803,               /* XMLCONCAT  */
    XMLELEMENT = 804,              /* XMLELEMENT  */
    XMLEXISTS = 805,               /* XMLEXISTS  */
    XMLFOREST = 806,               /* XMLFOREST  */
    XMLNAMESPACES = 807,           /* XMLNAMESPACES  */
    XMLPARSE = 808,                /* XMLPARSE  */
    XMLPI = 809,                   /* XMLPI  */
    XMLROOT = 810,                 /* XMLROOT  */
    XMLSERIALIZE = 811,            /* XMLSERIALIZE  */
    XMLTABLE = 812,                /* XMLTABLE  */
    YEAR_P = 813,                  /* YEAR_P  */
    YES_P = 814,                   /* YES_P  */
    ZONE = 815,                    /* ZONE  */
    FORMAT_LA = 816,               /* FORMAT_LA  */
    NOT_LA = 817,                  /* NOT_LA  */
    NULLS_LA = 818,                /* NULLS_LA  */
    WITH_LA = 819,                 /* WITH_LA  */
    WITHOUT_LA = 820,              /* WITHOUT_LA  */
    MODE_TYPE_NAME = 821,          /* MODE_TYPE_NAME  */
    MODE_PLPGSQL_EXPR = 822,       /* MODE_PLPGSQL_EXPR  */
    MODE_PLPGSQL_ASSIGN1 = 823,    /* MODE_PLPGSQL_ASSIGN1  */
    MODE_PLPGSQL_ASSIGN2 = 824,    /* MODE_PLPGSQL_ASSIGN2  */
    MODE_PLPGSQL_ASSIGN3 = 825,    /* MODE_PLPGSQL_ASSIGN3  */
    UMINUS = 826                   /* UMINUS  */
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

#line 652 "preproc.h"

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

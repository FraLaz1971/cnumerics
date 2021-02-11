#define EX_OK  0              /* successful termination */
#define EX_SYNERR  2          /* syntax error */

#define EX_BASE  64          /* base value for error messages */

#define EX_USAGE  64          /* command line usage error */
#define EX_DATAERR  65        /* data format error */
#define EX_NOINPUT  66        /* cannot open input */
#define EX_NOUSER  67         /* addressee unknown */
#define EX_NOHOST  68         /* host name unknown */
#define EX_UNAVAILABLE  69       /* service unavailable */
#define EX_SOFTWARE  70       /* internal software error */
#define EX_OSERR  71          /* system error (e.g., can't fork) */
#define EX_OSFILE  72         /* critical OS file missing */
#define EX_CANTCREAT  73      /* can't create (user) output file */
#define EX_IOERR  74          /* input/output error */
#define EX_TEMPFAIL  75       /* temp failure; user is invited to retry */
#define EX_PROTOCOL  76       /* remote error in protocol */
#define EX_NOPERM  77         /* permission denied */
#define EX_CONFIG  78         /* configuration error */
#define EX_MAX  78           /* maximum listed value */
/* mendel cooper abs guide example exit codes */
#define EX_BADARGS  85          /* Wrong number of arguments */
#define EX_ARGSLIMITS  86       /* an argument is out of allowed limits */
#define EX_UNSUPPORTED  87      /* unsupported system */


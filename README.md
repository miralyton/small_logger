# small_logger header file

Just include the header file in your project and get slightly fancier logs.
Auto detects whether stdout/stderr is a terminal. I haven't measured any
performance numbers.

## Color customization

You may customize the color and style of output by using the following
macros before including `small_logger.h`. These must be done before each
time `small_logger.h` is included or globally using compiler flags.
- `LOG_CODE_DEBUG`
- `LOG_CODE_INFO`
- `LOG_CODE_WARN`
- `LOG_CODE_ERR`

**Examples**: Want to make your errors really pop out? Try these out!

```c
/* Set err color to bright red and bold */
#define LOG_CODE_ERR LOG_CODE_BOLD LOG_CODE_COLOR_BRIGHT_RED
#include "small_logger.h"
```

```c
/* Set err color to bold, bright red, and blinking (if supported) */
#define LOG_CODE_ERR LOG_CODE_BOLD LOG_CODE_BLINKING LOG_CODE_COLOR_BRIGHT_RED
#include "small_logger.h"
```

```c
/* If your terminal supports true color, you can try these */
#define LOG_CODE_INFO LOG_CODE_TRUE_COLOR(190,189,127)
#include "small_logger.h"
```

To set a compiler flag globally add the flag(s)
```shell
-D<option>='<value>'
```
e.g.
```shell
gcc -o test/test -DLOG_CODE_ERR='LOG_CODE_BOLD LOG_CODE_COLOR_BRIGHT_RED'
```

## Log level

To set the log level, define `LOG_LEVEL` (default = 4). Logs are enabled for the
following log level thresholds:

|type|Enabled if LOG_LEVEL is|
|---|---|
|`DEBUG`|>=4|
|`INFO`|>=3|
|`WARN`|>=2|
|`ERR`|>=1|

A log level of 0 disables the `small_logger`.

As with color changes, you must set these before each time `small_logger.h` is
included, or globally using compiler flags.

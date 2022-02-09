# Trace with DBUG package

- MySQL 5.7 Reference Manual 5.8.1.2 Creating Trace Files
- MySQL 5.7 Reference Manual 5.8.3 The DBUG Package
- include/my_dbug.h

启动程序:

```
--debug[=debug_options]
-#[debug_options]
```

默认的 **debug_options**: `d:t:i:o,/tmp/mysqld.trace`.

对 **mysqld**, 可以通过运行时设置**debug**系统变量来修改DBUG设置:

```
SET GLOBAL debug = 'debug_options';
SET SESSION debug = 'debug_options';
```

## debug_options

```
debug_options := field[:field]*
field         := [+|-]flag[,modifier]*
flag          := d | D
              | f | F
              | i
              | L
              | n | N
              | o | O
              | P | p
              | r
              | S
              | t
```

- 无`+`/`-`: `flag`的值设置为`modifier`列表指定的值;
- 有`+`/`-`: `modifier`列表中的值添加到当前`modifier`列表中或从当前`modifier`列表中移除.


|Flag|Description|
|:---|:---|
| <u>d</u> | Enable output from `DBUG_XXX` macros for the **current state**. May be followed by a list of keywords, which enables output only for the DBUG macros with that keyword. An empty list of keywords enables output for all macros.<br/> In MySQL, common debug macro keywords to enable are `enter`, `exit`, `error`, `warning`, `info`, and `loop`.|
| D | **Delay** after each debugger output line. The argument is the delay, in tenths of seconds, subject to machine capabilities. For example, `D,20` specifies a delay of two seconds.|
| f | Limit debugging, tracing, and profiling to the list of **named functions**. An empty list enables all functions. The appropriate `d` or `t` flags must still be given; this flag only limits their actions if they are enabled.|
| F | Identify the **source file name** for each line of debug or trace output.|
| <u>i</u> | Identify the process with the **PID** or **thread ID** for each line of debug or trace output.|
| L | Identify the **source file line number** for each line of debug or trace output.|
| n | Print **the current function nesting depth** for each line of debug or trace output.|
| N | **Number each line** of debug output.|
| <u>o</u> | **Redirect** the debugger output stream to the specified file. The default output is `stderr`.|
| O | Like o, but the file is really **flushed between each write**. When needed, the file is closed and reopened between each write.|
| p | Limit debugger actions to **specified processes**. A process must be identified with the `DBUG_PROCESS` macro and match one in the list for debugger actions to occur.|
| P | Print the **current process name** for each line of debug or trace output.|
| r | When pushing a new state, do **not** inherit the previous state's function nesting level. Useful when the output is to start at the left margin.|
| S | Do function `_sanity(_file_,_line_)` at each debugged function until `_sanity()` returns something that differs from 0.|
| <u>t</u> | Enable **function call/exit** trace lines. May be followed by a list (containing only one modifier) giving a numeric maximum trace level, beyond which no output occurs for either debugging or tracing macros. The default is a compile time option.|


## 例

``` sql
CREATE TABLE `t1` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'ID',
  `c1` varchar(45) COLLATE utf8mb4_bin NOT NULL COMMENT 'col 1',
  `c2` varchar(45) COLLATE utf8mb4_bin DEFAULT NULL COMMENT 'col 2',
  PRIMARY KEY (`id`),
  KEY `idx_c1` (`c1`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin COMMENT='table test';
```

```
SET SESSION debug = 'd:t:i:f:F:L:N:o,/Users/zhang/GoogleDrive/workcache/mysql_debug/trace/insert.trace';
INSERT INTO `test`.`t1` (`c1`, `c2`) VALUES ('1', '1');
SET SESSION debug = '';
```

```
...
T@3:   245:   sql_parse.cc:  1481: | | query: INSERT INTO `test`.`t1` (`c1`, `c2`) VALUES ('1', '1')
...
T@3:   506:  sql_insert.cc:   430: | | | | >mysql_insert
...
T@3:   891:   sql_class.cc:  4749: | | >send_statement_status
T@3:   892: protocol_classic.cc:   647: | | | >Protocol_classic::send_ok
T@3:   893: protocol_classic.cc:   277: | | | | >net_send_ok
T@3:   894: protocol_classic.cc:   318: | | | | | info: affected_rows: 1  id: 1  status: 1  warning_count: 0
```
